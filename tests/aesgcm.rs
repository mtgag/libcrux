#[cfg(aes_ni)]
use libcrux::{
    aead::{
        decrypt, encrypt, Aes128Key, Aes256Key,
        Algorithm::{Aes128Gcm, Aes256Gcm},
        Iv, Key,
    },
    digest,
    drbg::Drbg,
};

#[cfg(aes_ni)]
#[test]
fn aesgcm_self_test() {
    let _ = pretty_env_logger::try_init();

    let orig_msg = b"hacspec rulez";
    let mut msg = orig_msg.clone();
    let aad = b"associated data" as &[u8];
    let raw_key = Aes256Key([
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
        26, 27, 28, 29, 30, 31, 32,
    ]);
    let key = Key::Aes256(raw_key);
    let iv = Iv([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]);

    let tag = encrypt(&key, &mut msg, iv, aad).unwrap();

    let iv = Iv([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]);
    assert!(decrypt(&key, &mut msg, iv, aad, &tag).is_ok());
    assert_eq!(orig_msg, &msg);

    let raw_key = Aes128Key([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]);
    let key = Key::Aes128(raw_key);
    let iv = Iv([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]);

    let tag = encrypt(&key, &mut msg, iv, aad).unwrap();

    let iv = Iv([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]);
    assert!(decrypt(&key, &mut msg, iv, aad, &tag).is_ok());
    assert_eq!(orig_msg, &msg);
}

#[cfg(aes_ni)]
#[test]
fn aesgcm_self_test_rand() {
    let _ = pretty_env_logger::try_init();

    let orig_msg = b"hacspec rulez";
    let mut msg = orig_msg.clone();
    let aad = b"associated data" as &[u8];

    let mut drbg = Drbg::new(digest::Algorithm::Sha256).unwrap();
    let key = Key::generate(Aes256Gcm, &mut drbg);
    let iv = Iv::generate(&mut drbg);
    let iv2 = Iv(iv.0);

    let tag = encrypt(&key, &mut msg, iv, aad).unwrap();
    assert!(decrypt(&key, &mut msg, iv2, aad, &tag).is_ok());

    assert_eq!(orig_msg, &msg);

    let iv = Iv::generate(&mut drbg);
    let iv2 = Iv(iv.0);
    let key = Key::generate(Aes128Gcm, &mut drbg);
    let tag = encrypt(&key, &mut msg, iv, aad).unwrap();
    assert!(decrypt(&key, &mut msg, iv2, aad, &tag).is_ok());

    assert_eq!(orig_msg, &msg);
}
