/* automatically generated by rust-bindgen 0.69.4 */

pub const JADE_HASH_SHA256_AMD64_REF_BYTES: u32 = 32;
pub const JADE_HASH_SHA256_AMD64_REF_ALGNAME: &[u8; 7] = b"SHA256\0";
pub const JADE_SCALARMULT_CURVE25519_AMD64_REF5_BYTES: u32 = 32;
pub const JADE_SCALARMULT_CURVE25519_AMD64_REF5_SCALARBYTES: u32 = 32;
pub const JADE_SCALARMULT_CURVE25519_AMD64_REF5_ALGNAME: &[u8; 11] = b"Curve25519\0";
pub const JADE_SCALARMULT_CURVE25519_AMD64_MULX_BYTES: u32 = 32;
pub const JADE_SCALARMULT_CURVE25519_AMD64_MULX_SCALARBYTES: u32 = 32;
pub const JADE_SCALARMULT_CURVE25519_AMD64_MULX_ALGNAME: &[u8; 11] = b"Curve25519\0";
pub const JADE_HASH_SHA3_224_AMD64_REF_BYTES: u32 = 28;
pub const JADE_HASH_SHA3_224_AMD64_REF_ALGNAME: &[u8; 9] = b"SHA3-224\0";
pub const JADE_HASH_SHA3_256_AMD64_REF_BYTES: u32 = 32;
pub const JADE_HASH_SHA3_256_AMD64_REF_ALGNAME: &[u8; 9] = b"SHA3-256\0";
pub const JADE_HASH_SHA3_384_AMD64_REF_BYTES: u32 = 48;
pub const JADE_HASH_SHA3_384_AMD64_REF_ALGNAME: &[u8; 9] = b"SHA3-384\0";
pub const JADE_HASH_SHA3_512_AMD64_REF_BYTES: u32 = 64;
pub const JADE_HASH_SHA3_512_AMD64_REF_ALGNAME: &[u8; 9] = b"SHA3-512\0";
pub const JADE_ONETIMEAUTH_POLY1305_AMD64_REF_BYTES: u32 = 16;
pub const JADE_ONETIMEAUTH_POLY1305_AMD64_REF_KEYBYTES: u32 = 32;
pub const JADE_ONETIMEAUTH_POLY1305_AMD64_REF_ALGNAME: &[u8; 9] = b"Poly1305\0";
pub const JADE_STREAM_CHACHA_CHACHA20_IETF_AMD64_REF_KEYBYTES: u32 = 32;
pub const JADE_STREAM_CHACHA_CHACHA20_IETF_AMD64_REF_NONCEBYTES: u32 = 12;
pub const JADE_STREAM_CHACHA_CHACHA20_IETF_AMD64_REF_ALGNAME: &[u8; 14] = b"ChaCha20-ietf\0";
pub const JADE_KEM_KYBER_KYBER768_AMD64_REF_SECRETKEYBYTES: u32 = 2400;
pub const JADE_KEM_KYBER_KYBER768_AMD64_REF_PUBLICKEYBYTES: u32 = 1184;
pub const JADE_KEM_KYBER_KYBER768_AMD64_REF_CIPHERTEXTBYTES: u32 = 1088;
pub const JADE_KEM_KYBER_KYBER768_AMD64_REF_KEYPAIRCOINBYTES: u32 = 64;
pub const JADE_KEM_KYBER_KYBER768_AMD64_REF_ENCCOINBYTES: u32 = 32;
pub const JADE_KEM_KYBER_KYBER768_AMD64_REF_BYTES: u32 = 32;
pub const JADE_KEM_KYBER_KYBER768_AMD64_REF_ALGNAME: &[u8; 9] = b"Kyber768\0";
pub const JADE_HASH_SHA3_224_AMD64_AVX2_BYTES: u32 = 28;
pub const JADE_HASH_SHA3_224_AMD64_AVX2_ALGNAME: &[u8; 9] = b"SHA3-224\0";
pub const JADE_HASH_SHA3_256_AMD64_AVX2_BYTES: u32 = 32;
pub const JADE_HASH_SHA3_256_AMD64_AVX2_ALGNAME: &[u8; 9] = b"SHA3-256\0";
pub const JADE_HASH_SHA3_384_AMD64_AVX2_BYTES: u32 = 48;
pub const JADE_HASH_SHA3_384_AMD64_AVX2_ALGNAME: &[u8; 9] = b"SHA3-384\0";
pub const JADE_HASH_SHA3_512_AMD64_AVX2_BYTES: u32 = 64;
pub const JADE_HASH_SHA3_512_AMD64_AVX2_ALGNAME: &[u8; 9] = b"SHA3-512\0";
pub const JADE_ONETIMEAUTH_POLY1305_AMD64_AVX2_BYTES: u32 = 16;
pub const JADE_ONETIMEAUTH_POLY1305_AMD64_AVX2_KEYBYTES: u32 = 32;
pub const JADE_ONETIMEAUTH_POLY1305_AMD64_AVX2_ALGNAME: &[u8; 9] = b"Poly1305\0";
pub const JADE_STREAM_CHACHA_CHACHA20_IETF_AMD64_AVX2_KEYBYTES: u32 = 32;
pub const JADE_STREAM_CHACHA_CHACHA20_IETF_AMD64_AVX2_NONCEBYTES: u32 = 12;
pub const JADE_STREAM_CHACHA_CHACHA20_IETF_AMD64_AVX2_ALGNAME: &[u8; 14] = b"ChaCha20-ietf\0";
pub const JADE_ONETIMEAUTH_POLY1305_AMD64_AVX_BYTES: u32 = 16;
pub const JADE_ONETIMEAUTH_POLY1305_AMD64_AVX_KEYBYTES: u32 = 32;
pub const JADE_ONETIMEAUTH_POLY1305_AMD64_AVX_ALGNAME: &[u8; 9] = b"Poly1305\0";
pub const JADE_STREAM_CHACHA_CHACHA20_IETF_AMD64_AVX_KEYBYTES: u32 = 32;
pub const JADE_STREAM_CHACHA_CHACHA20_IETF_AMD64_AVX_NONCEBYTES: u32 = 12;
pub const JADE_STREAM_CHACHA_CHACHA20_IETF_AMD64_AVX_ALGNAME: &[u8; 14] = b"ChaCha20-ietf\0";
extern "C" {
    pub fn __jasmin_syscall_randombytes__(_x: *mut u8, xlen: u64) -> *mut u8;
}
extern "C" {
    pub fn randombytes(_x: *mut u8, xlen: u64);
}
extern "C" {
    pub fn jade_hash_sha256_amd64_ref(
        out: *mut u8,
        in_: *mut u8,
        length: u64,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_scalarmult_curve25519_amd64_ref5(
        r: *mut u8,
        k: *mut u8,
        u: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_scalarmult_curve25519_amd64_ref5_base(r: *mut u8, k: *mut u8)
        -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_scalarmult_curve25519_amd64_mulx(
        r: *mut u8,
        k: *mut u8,
        u: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_scalarmult_curve25519_amd64_mulx_base(r: *mut u8, k: *mut u8)
        -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_hash_sha3_224_amd64_ref(
        out: *mut u8,
        in_: *mut u8,
        length: u64,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_hash_sha3_256_amd64_ref(
        out: *mut u8,
        in_: *mut u8,
        length: u64,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_hash_sha3_384_amd64_ref(
        out: *mut u8,
        in_: *mut u8,
        length: u64,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_hash_sha3_512_amd64_ref(
        out: *mut u8,
        in_: *mut u8,
        length: u64,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_onetimeauth_poly1305_amd64_ref(
        out: *mut u8,
        in_: *mut u8,
        inlen: u64,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_onetimeauth_poly1305_amd64_ref_verify(
        h: *mut u8,
        in_: *mut u8,
        inlen: u64,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_stream_chacha_chacha20_ietf_amd64_ref_xor(
        ciphertext: *mut u8,
        plaintext: *mut u8,
        length: u64,
        nonce: *mut u8,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_stream_chacha_chacha20_ietf_amd64_ref(
        stream: *mut u8,
        length: u64,
        nonce: *mut u8,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_kem_kyber_kyber768_amd64_ref_keypair_derand(
        public_key: *mut u8,
        secret_key: *mut u8,
        coins: *const u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_kem_kyber_kyber768_amd64_ref_enc_derand(
        ciphertext: *mut u8,
        shared_secret: *mut u8,
        public_key: *const u8,
        coins: *const u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_kem_kyber_kyber768_amd64_ref_dec(
        shared_secret: *mut u8,
        ciphertext: *const u8,
        secret_key: *const u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_hash_sha3_224_amd64_avx2(
        out: *mut u8,
        in_: *mut u8,
        length: u64,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_hash_sha3_256_amd64_avx2(
        out: *mut u8,
        in_: *mut u8,
        length: u64,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_hash_sha3_384_amd64_avx2(
        out: *mut u8,
        in_: *mut u8,
        length: u64,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_hash_sha3_512_amd64_avx2(
        out: *mut u8,
        in_: *mut u8,
        length: u64,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_onetimeauth_poly1305_amd64_avx2(
        out: *mut u8,
        in_: *mut u8,
        inlen: u64,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_onetimeauth_poly1305_amd64_avx2_verify(
        h: *mut u8,
        in_: *mut u8,
        inlen: u64,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_stream_chacha_chacha20_ietf_amd64_avx2_xor(
        ciphertext: *mut u8,
        plaintext: *mut u8,
        length: u64,
        nonce: *mut u8,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_stream_chacha_chacha20_ietf_amd64_avx2(
        stream: *mut u8,
        length: u64,
        nonce: *mut u8,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_kem_kyber_kyber768_amd64_avx2_keypair_derand(
        public_key: *mut u8,
        secret_key: *mut u8,
        coins: *const u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_kem_kyber_kyber768_amd64_avx2_keypair(
        public_key: *mut u8,
        secret_key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_kem_kyber_kyber768_amd64_avx2_enc_derand(
        ciphertext: *mut u8,
        shared_secret: *mut u8,
        public_key: *const u8,
        coins: *const u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_kem_kyber_kyber768_amd64_avx2_enc(
        ciphertext: *mut u8,
        shared_secret: *mut u8,
        public_key: *const u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_kem_kyber_kyber768_amd64_avx2_dec(
        shared_secret: *mut u8,
        ciphertext: *const u8,
        secret_key: *const u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_onetimeauth_poly1305_amd64_avx(
        out: *mut u8,
        in_: *mut u8,
        inlen: u64,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_onetimeauth_poly1305_amd64_avx_verify(
        h: *mut u8,
        in_: *mut u8,
        inlen: u64,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_stream_chacha_chacha20_ietf_amd64_avx_xor(
        ciphertext: *mut u8,
        plaintext: *mut u8,
        length: u64,
        nonce: *mut u8,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
extern "C" {
    pub fn jade_stream_chacha_chacha20_ietf_amd64_avx(
        stream: *mut u8,
        length: u64,
        nonce: *mut u8,
        key: *mut u8,
    ) -> ::core::ffi::c_int;
}
