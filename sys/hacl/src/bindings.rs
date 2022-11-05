/* automatically generated by rust-bindgen 0.59.2 */

pub type FStar_UInt128_uint128 = u128;
extern "C" {
    #[doc = "Encrypt a message `m` with key `k`."]
    #[doc = ""]
    #[doc = "The arguments `k`, `n`, `aadlen`, and `aad` are same in encryption/decryption."]
    #[doc = "Note: Encryption and decryption can be executed in-place, i.e., `m` and `cipher` can point to the same memory."]
    #[doc = ""]
    #[doc = "@param k Pointer to 32 bytes of memory where the AEAD key is read from."]
    #[doc = "@param n Pointer to 12 bytes of memory where the AEAD nonce is read from."]
    #[doc = "@param aadlen Length of the associated data."]
    #[doc = "@param aad Pointer to `aadlen` bytes of memory where the associated data is read from."]
    #[doc = ""]
    #[doc = "@param mlen Length of the message."]
    #[doc = "@param m Pointer to `mlen` bytes of memory where the message is read from."]
    #[doc = "@param cipher Pointer to `mlen` bytes of memory where the ciphertext is written to."]
    #[doc = "@param mac Pointer to 16 bytes of memory where the mac is written to."]
    pub fn Hacl_Chacha20Poly1305_32_aead_encrypt(
        k: *mut u8,
        n: *mut u8,
        aadlen: u32,
        aad: *mut u8,
        mlen: u32,
        m: *mut u8,
        cipher: *mut u8,
        mac: *mut u8,
    );
}
extern "C" {
    #[doc = "Decrypt a ciphertext `cipher` with key `k`."]
    #[doc = ""]
    #[doc = "The arguments `k`, `n`, `aadlen`, and `aad` are same in encryption/decryption."]
    #[doc = "Note: Encryption and decryption can be executed in-place, i.e., `m` and `cipher` can point to the same memory."]
    #[doc = ""]
    #[doc = "If decryption succeeds, the resulting plaintext is stored in `m` and the function returns the success code 0."]
    #[doc = "If decryption fails, the array `m` remains unchanged and the function returns the error code 1."]
    #[doc = ""]
    #[doc = "@param k Pointer to 32 bytes of memory where the AEAD key is read from."]
    #[doc = "@param n Pointer to 12 bytes of memory where the AEAD nonce is read from."]
    #[doc = "@param aadlen Length of the associated data."]
    #[doc = "@param aad Pointer to `aadlen` bytes of memory where the associated data is read from."]
    #[doc = ""]
    #[doc = "@param mlen Length of the ciphertext."]
    #[doc = "@param m Pointer to `mlen` bytes of memory where the message is written to."]
    #[doc = "@param cipher Pointer to `mlen` bytes of memory where the ciphertext is read from."]
    #[doc = "@param mac Pointer to 16 bytes of memory where the mac is read from."]
    #[doc = ""]
    #[doc = "@returns 0 on succeess; 1 on failure."]
    pub fn Hacl_Chacha20Poly1305_32_aead_decrypt(
        k: *mut u8,
        n: *mut u8,
        aadlen: u32,
        aad: *mut u8,
        mlen: u32,
        m: *mut u8,
        cipher: *mut u8,
        mac: *mut u8,
    ) -> u32;
}
extern "C" {
    #[doc = "Compute the scalar multiple of a point."]
    #[doc = ""]
    #[doc = "@param out Pointer to 32 bytes of memory, allocated by the caller, where the resulting point is written to."]
    #[doc = "@param priv Pointer to 32 bytes of memory where the secret/private key is read from."]
    #[doc = "@param pub Pointer to 32 bytes of memory where the public point is read from."]
    pub fn Hacl_Curve25519_51_scalarmult(out: *mut u8, priv_: *mut u8, pub_: *mut u8);
}
extern "C" {
    #[doc = "Calculate a public point from a secret/private key."]
    #[doc = ""]
    #[doc = "This computes a scalar multiplication of the secret/private key with the curve's basepoint."]
    #[doc = ""]
    #[doc = "@param pub Pointer to 32 bytes of memory, allocated by the caller, where the resulting point is written to."]
    #[doc = "@param priv Pointer to 32 bytes of memory where the secret/private key is read from."]
    pub fn Hacl_Curve25519_51_secret_to_public(pub_: *mut u8, priv_: *mut u8);
}
extern "C" {
    #[doc = "Execute the diffie-hellmann key exchange."]
    #[doc = ""]
    #[doc = "@param out Pointer to 32 bytes of memory, allocated by the caller, where the resulting point is written to."]
    #[doc = "@param priv Pointer to 32 bytes of memory where **our** secret/private key is read from."]
    #[doc = "@param pub Pointer to 32 bytes of memory where **their** public point is read from."]
    pub fn Hacl_Curve25519_51_ecdh(out: *mut u8, priv_: *mut u8, pub_: *mut u8) -> bool;
}
extern "C" {
    pub fn Hacl_Hash_SHA2_update_multi_224(s: *mut u32, blocks: *mut u8, n_blocks: u32);
}
extern "C" {
    pub fn Hacl_Hash_SHA2_update_multi_256(s: *mut u32, blocks: *mut u8, n_blocks: u32);
}
extern "C" {
    pub fn Hacl_Hash_SHA2_update_last_224(
        s: *mut u32,
        prev_len: u64,
        input: *mut u8,
        input_len: u32,
    );
}
extern "C" {
    pub fn Hacl_Hash_SHA2_update_last_256(
        s: *mut u32,
        prev_len: u64,
        input: *mut u8,
        input_len: u32,
    );
}
extern "C" {
    pub fn Hacl_Hash_SHA2_hash_224(input: *mut u8, input_len: u32, dst: *mut u8);
}
extern "C" {
    pub fn Hacl_Hash_SHA2_hash_256(input: *mut u8, input_len: u32, dst: *mut u8);
}
extern "C" {
    pub fn Hacl_Hash_SHA2_hash_384(input: *mut u8, input_len: u32, dst: *mut u8);
}
extern "C" {
    pub fn Hacl_Hash_SHA2_hash_512(input: *mut u8, input_len: u32, dst: *mut u8);
}
#[repr(C)]
pub struct Hacl_Streaming_SHA2_state_sha2_224_s {
    pub block_state: *mut u32,
    pub buf: *mut u8,
    pub total_len: u64,
}
pub type Hacl_Streaming_SHA2_state_sha2_224 = Hacl_Streaming_SHA2_state_sha2_224_s;
pub type Hacl_Streaming_SHA2_state_sha2_256 = Hacl_Streaming_SHA2_state_sha2_224;
#[repr(C)]
pub struct Hacl_Streaming_SHA2_state_sha2_384_s {
    pub block_state: *mut u64,
    pub buf: *mut u8,
    pub total_len: u64,
}
pub type Hacl_Streaming_SHA2_state_sha2_384 = Hacl_Streaming_SHA2_state_sha2_384_s;
pub type Hacl_Streaming_SHA2_state_sha2_512 = Hacl_Streaming_SHA2_state_sha2_384;
extern "C" {
    pub fn Hacl_Streaming_SHA2_create_in_224() -> *mut Hacl_Streaming_SHA2_state_sha2_224;
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_init_224(s: *mut Hacl_Streaming_SHA2_state_sha2_224);
}
extern "C" {
    #[doc = "0 = success, 1 = max length exceeded"]
    pub fn Hacl_Streaming_SHA2_update_224(
        p: *mut Hacl_Streaming_SHA2_state_sha2_224,
        data: *mut u8,
        len: u32,
    ) -> u32;
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_finish_224(p: *mut Hacl_Streaming_SHA2_state_sha2_224, dst: *mut u8);
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_free_224(s: *mut Hacl_Streaming_SHA2_state_sha2_224);
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_create_in_256() -> *mut Hacl_Streaming_SHA2_state_sha2_224;
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_init_256(s: *mut Hacl_Streaming_SHA2_state_sha2_224);
}
extern "C" {
    #[doc = "0 = success, 1 = max length exceeded"]
    pub fn Hacl_Streaming_SHA2_update_256(
        p: *mut Hacl_Streaming_SHA2_state_sha2_224,
        data: *mut u8,
        len: u32,
    ) -> u32;
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_finish_256(p: *mut Hacl_Streaming_SHA2_state_sha2_224, dst: *mut u8);
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_free_256(s: *mut Hacl_Streaming_SHA2_state_sha2_224);
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_create_in_384() -> *mut Hacl_Streaming_SHA2_state_sha2_384;
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_init_384(s: *mut Hacl_Streaming_SHA2_state_sha2_384);
}
extern "C" {
    #[doc = "0 = success, 1 = max length exceeded"]
    pub fn Hacl_Streaming_SHA2_update_384(
        p: *mut Hacl_Streaming_SHA2_state_sha2_384,
        data: *mut u8,
        len: u32,
    ) -> u32;
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_finish_384(p: *mut Hacl_Streaming_SHA2_state_sha2_384, dst: *mut u8);
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_free_384(s: *mut Hacl_Streaming_SHA2_state_sha2_384);
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_create_in_512() -> *mut Hacl_Streaming_SHA2_state_sha2_384;
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_init_512(s: *mut Hacl_Streaming_SHA2_state_sha2_384);
}
extern "C" {
    #[doc = "0 = success, 1 = max length exceeded"]
    pub fn Hacl_Streaming_SHA2_update_512(
        p: *mut Hacl_Streaming_SHA2_state_sha2_384,
        data: *mut u8,
        len: u32,
    ) -> u32;
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_finish_512(p: *mut Hacl_Streaming_SHA2_state_sha2_384, dst: *mut u8);
}
extern "C" {
    pub fn Hacl_Streaming_SHA2_free_512(s: *mut Hacl_Streaming_SHA2_state_sha2_384);
}
extern "C" {
    #[doc = "Compute the scalar multiple of a point."]
    #[doc = ""]
    #[doc = "@param out Pointer to 32 bytes of memory, allocated by the caller, where the resulting point is written to."]
    #[doc = "@param priv Pointer to 32 bytes of memory where the secret/private key is read from."]
    #[doc = "@param pub Pointer to 32 bytes of memory where the public point is read from."]
    pub fn Hacl_Curve25519_64_scalarmult(out: *mut u8, priv_: *mut u8, pub_: *mut u8);
}
extern "C" {
    #[doc = "Calculate a public point from a secret/private key."]
    #[doc = ""]
    #[doc = "This computes a scalar multiplication of the secret/private key with the curve's basepoint."]
    #[doc = ""]
    #[doc = "@param pub Pointer to 32 bytes of memory, allocated by the caller, where the resulting point is written to."]
    #[doc = "@param priv Pointer to 32 bytes of memory where the secret/private key is read from."]
    pub fn Hacl_Curve25519_64_secret_to_public(pub_: *mut u8, priv_: *mut u8);
}
extern "C" {
    #[doc = "Execute the diffie-hellmann key exchange."]
    #[doc = ""]
    #[doc = "@param out Pointer to 32 bytes of memory, allocated by the caller, where the resulting point is written to."]
    #[doc = "@param priv Pointer to 32 bytes of memory where **our** secret/private key is read from."]
    #[doc = "@param pub Pointer to 32 bytes of memory where **their** public point is read from."]
    pub fn Hacl_Curve25519_64_ecdh(out: *mut u8, priv_: *mut u8, pub_: *mut u8) -> bool;
}
