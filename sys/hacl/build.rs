#[cfg(not(windows))]
extern crate bindgen;

use std::{env, path::Path};

macro_rules! svec {
    ($($x:expr),*$(,)?) => (vec![$($x.to_string()),*]);
}

fn includes(home_dir: &Path, include_str: &str) -> Vec<String> {
    let c_path = home_dir.join("c");
    vec![
        format!("{}{}", include_str, c_path.join("include").display()),
        format!(
            "{}{}",
            include_str,
            c_path.join("karamel").join("include").display()
        ),
        format!(
            "{}{}",
            include_str,
            c_path
                .join("karamel")
                .join("krmllib")
                .join("dist")
                .join("minimal")
                .display()
        ),
    ]
}

fn append_simd128_flags(flags: &mut Vec<String>) {
    // Platform detection
    if cfg!(simd128) {
        panic!("fooo");
        if cfg!(any(target_arch = "x86", target_arch = "x86_64")) {
            flags.push("-msse4.1".to_string());
            flags.push("-msse4.2".to_string());
            flags.push("-mavx".to_string());
        }
    }
}

fn append_simd256_flags(flags: &mut Vec<String>) {
    // Platform detection
    if cfg!(simd256) {
        flags.push("-mavx2".to_string());
    }
}

#[cfg(not(windows))]
fn create_bindings(home_dir: &Path) {
    let mut clang_args = includes(home_dir, "-I");
    append_simd128_flags(&mut clang_args);
    append_simd256_flags(&mut clang_args);

    let bindings = bindgen::Builder::default()
        // Header to wrap HACL headers
        .header("c/include/hacl.h")
        // Set include paths for HACL headers
        .clang_args(clang_args)
        // Allow function we want to have in
        .allowlist_function("Hacl_Chacha20Poly1305.*")
        .allowlist_function("Hacl_Curve25519.*")
        .allowlist_function("Hacl_Hash_SHA2.*")
        .allowlist_function("Hacl_Streaming_SHA2.*")
        .allowlist_function("Hacl_SHA3.*")
        .allowlist_function("Hacl_Streaming_SHA3.*")
        .allowlist_function("Hacl_Blake2.*")
        // .allowlist_var("Spec_.*")
        .allowlist_type("Spec_.*")
        .allowlist_type("Hacl_Streaming_SHA2.*")
        // Block everything we don't need or define ourselves.
        .blocklist_type("__.*")
        // XXX: These functions can't be used right now in Rust
        .blocklist_function("Hacl_Hash_SHA2_update_.*_384")
        .blocklist_function("Hacl_Hash_SHA2_update_.*_512")
        .blocklist_function("Hacl_Hash_SHA2_finish_.*_384")
        .blocklist_function("Hacl_Hash_SHA2_finish_.*_512")
        // Disable tests to avoid warnings and keep it portable
        .layout_tests(false)
        // Generate bindings
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");

    let home_bindings = home_dir.join("src/bindings.rs");
    bindings
        .write_to_file(home_bindings)
        .expect("Couldn't write bindings!");
}

#[cfg(windows)]
fn create_bindings(_: &Path, _: &Path) {}

fn copy_files(home_path: &Path, out_path: &Path) {
    let mut options = fs_extra::dir::CopyOptions::new();
    options.overwrite = true;
    fs_extra::dir::copy(home_path.join("c"), out_path, &options).unwrap();
}

fn compile_files(library_name: &str, files: &[String], out_path: &Path, args: &[String]) {
    let src_prefix = out_path.join("c").join("src");

    let mut build = cc::Build::new();
    build
        .files(files.iter().map(|fname| src_prefix.join(fname)))
        // .warnings_into_errors(true)
        .no_default_flags(true);

    for include in includes(out_path, "") {
        build.include(include);
    }
    build.flag("-O3").flag("-c");
    for arg in args {
        build.flag(arg);
    }

    build.compile(library_name);
}

fn build(out_path: &Path) {
    let files = svec![
        "Hacl_Chacha20.c",
        "Hacl_Chacha20Poly1305_32.c",
        "Hacl_Poly1305_32.c",
        "Hacl_Curve25519_51.c",
        "Hacl_Curve25519_64.c",
        "Hacl_Hash_SHA2.c",
        "Hacl_Streaming_SHA2.c",
        "Hacl_SHA3.c",
        "Hacl_Streaming_SHA3.c",
        "Lib_Memzero0.c",
        "Hacl_Hash_Blake2.c",
    ];
    let mut all_files = files.clone();

    // Platform detection
    if cfg!(simd128) {
        let files128 = svec![
            "Hacl_Chacha20Poly1305_128.c",
            "Hacl_Chacha20_Vec128.c",
            "Hacl_Poly1305_128.c",
            "Hacl_Hash_Blake2s_128.c",
        ];
        all_files.extend_from_slice(&files128);

        let mut simd128_flags = vec![];
        append_simd128_flags(&mut simd128_flags);
        compile_files("libhacl_128.a", &files128, out_path, &simd128_flags);
    }
    if cfg!(simd256) {
        let files256 = svec![
            "Hacl_Chacha20Poly1305_256.c",
            "Hacl_Chacha20_Vec256.c",
            "Hacl_Poly1305_256.c",
            "Hacl_Hash_Blake2b_256.c",
        ];
        all_files.extend_from_slice(&files256);

        let mut simd256_flags = vec![];
        append_simd256_flags(&mut simd256_flags);
        compile_files("libhacl_256.a", &files256, out_path, &simd256_flags);
    }

    compile_files("libhacl.a", &files, out_path, &[]);
}

fn main() {
    // Get ENV variables
    let home_dir = env::var("CARGO_MANIFEST_DIR").unwrap();
    let home_path = Path::new(&home_dir);
    let out_dir = env::var("OUT_DIR").unwrap();
    let out_path = Path::new(&out_dir);

    // Check platform support
    let simd128 = libcrux_platform::simd128_support();
    let simd256 = libcrux_platform::simd256_support();
    let aes_ni = libcrux_platform::aes_ni_support();

    // Set re-run trigger for all of c
    println!("cargo:rerun-if-changed=c");
    println!("cargo:rerun-if-changed=h");

    // Moving C library to output to make build easier.
    copy_files(home_path, out_path);
    eprintln!(" >>> out {:?}", out_path);

    // Build the C files
    build(out_path);

    // Set library name to look up
    let library_name = "hacl";

    // Generate new bindings. This is a no-op on Windows.
    create_bindings(home_path);

    // Link hacl library.
    let mode = "static";
    println!("cargo:rustc-link-lib={}={}", mode, library_name);
    if cfg!(simd128) {
        println!("cargo:rustc-link-lib={}={}", mode, "hacl_128");
    }
    if cfg!(simd256) {
        println!("cargo:rustc-link-lib={}={}", mode, "hacl_256");
    }
    println!("cargo:rustc-link-search=native={}", out_path.display());
    println!("cargo:lib={}", out_path.display());
}