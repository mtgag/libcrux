use crate::{
    constant_time_ops::{
        compare_ciphertexts_in_constant_time, select_shared_secret_in_constant_time,
    },
    constants::{CPA_PKE_KEY_GENERATION_SEED_SIZE, H_DIGEST_SIZE, SHARED_SECRET_SIZE},
    hash_functions::Hash,
    ind_cpa::serialize_public_key,
    serialize::deserialize_ring_elements_reduced,
    types::{MlKemCiphertext, MlKemKeyPair, MlKemPrivateKey, MlKemPublicKey},
    utils::into_padded_array,
    vector::Operations,
};

/// Seed size for key generation
pub const KEY_GENERATION_SEED_SIZE: usize = CPA_PKE_KEY_GENERATION_SEED_SIZE + SHARED_SECRET_SIZE;

/// Seed size for encapsulation
pub const ENCAPS_SEED_SIZE: usize = SHARED_SECRET_SIZE;

// TODO: We should make this an actual type as opposed to alias so we can enforce
// some checks at the type level. This is being tracked in:
// https://github.com/cryspen/libcrux/issues/123
/// An ML-KEM shared secret.
///
/// A byte array of size [`SHARED_SECRET_SIZE`].
pub type MlKemSharedSecret = [u8; SHARED_SECRET_SIZE];

/// This module instantiates the functions in this file and multiplexes between
/// different implementations at runtime.
#[cfg(not(eurydice))]
pub(crate) mod multiplexing;

/// This module instantiates the functions in this file for each platform.
/// To use these, runtime checks must be performed before calling them.
pub(crate) mod instantiations;

/// Serialize the secret key.
#[inline(always)]
fn serialize_kem_secret_key<const K: usize, const SERIALIZED_KEY_LEN: usize, Hasher: Hash<K>>(
    private_key: &[u8],
    public_key: &[u8],
    implicit_rejection_value: &[u8],
) -> [u8; SERIALIZED_KEY_LEN] {
    let mut out = [0u8; SERIALIZED_KEY_LEN];
    let mut pointer = 0;
    out[pointer..pointer + private_key.len()].copy_from_slice(private_key);
    pointer += private_key.len();
    out[pointer..pointer + public_key.len()].copy_from_slice(public_key);
    pointer += public_key.len();
    out[pointer..pointer + H_DIGEST_SIZE].copy_from_slice(&Hasher::H(public_key));
    pointer += H_DIGEST_SIZE;
    out[pointer..pointer + implicit_rejection_value.len()]
        .copy_from_slice(implicit_rejection_value);
    out
}

#[inline(always)]
fn validate_public_key<
    const K: usize,
    const RANKED_BYTES_PER_RING_ELEMENT: usize,
    const PUBLIC_KEY_SIZE: usize,
    Vector: Operations,
>(
    public_key: &[u8; PUBLIC_KEY_SIZE],
) -> bool {
    let deserialized_pk = deserialize_ring_elements_reduced::<PUBLIC_KEY_SIZE, K, Vector>(
        &public_key[..RANKED_BYTES_PER_RING_ELEMENT],
    );
    let public_key_serialized =
        serialize_public_key::<K, RANKED_BYTES_PER_RING_ELEMENT, PUBLIC_KEY_SIZE, Vector>(
            deserialized_pk,
            &public_key[RANKED_BYTES_PER_RING_ELEMENT..],
        );

    let mut valid = *public_key == public_key_serialized;

    #[cfg(all(feature = "std", test))]
    if !valid {
        std::eprintln!("Invalid public key");
    }

    // Do some additional checks on the distribution of the key.
    // XXX: This is for linting only and not usually performed.
    // Move to a different function
    if valid {
        let seed = &public_key[RANKED_BYTES_PER_RING_ELEMENT..];

        // ML_KEM_DIS_01: # zeroes <= 11
        let zeroes_bytes = seed.iter().filter(|&b| *b == 0).count();
        valid &= zeroes_bytes <= 11;
        #[cfg(all(feature = "std", test))]
        if !valid {
            std::eprintln!("too many zeroes in public key");
        }

        // ML_KEM_DIS_02: not more than 2 sequential elements are the same
        valid &= no_sequential_elements(seed);

        // ML_KEM_DIS_03: not more than 27 values over or under 128
        let over_128 = seed.iter().filter(|&b| *b > 128).count();
        let under_128 = seed.iter().filter(|&b| *b < 128).count();
        let balanced = over_128 <= 27 && under_128 <= 27;
        #[cfg(all(feature = "std", test))]
        if !balanced {
            std::eprintln!("too large or small values in public key");
        }

        valid &= balanced;

        // ML_KEM_DIS_04: not more than 14, 18, 21 same elements in A'
        // ML_KEM_DIS_05: no more than 3 sequential elements in A (not transposed - not fully defined)
        // ML_KEM_DIS_06: no more than 656, 1369, 2338 over or under 1664
    }

    valid
}

fn no_sequential_elements(seed: &[u8]) -> bool {
    let mut current_value = seed[0];
    let mut current_len = 1;
    let mut _longest_value = current_value;
    let mut longest_len = current_len;

    for &byte in seed.iter().skip(1) {
        if byte == current_value {
            // Count the values
            current_len += 1;
            if current_len > longest_len {
                _longest_value = current_value;
                longest_len = current_len;
            }
        } else {
            // Value changed
            current_value = byte;
            current_len = 1;
        }
    }

    if longest_len > 2 {
        #[cfg(all(feature = "std", test))]
        std::eprintln!(
            "too many sequential values in public key ({_longest_value} {longest_len}x)"
        );

        false
    } else {
        true
    }
}

/// Generate a key pair.
///
/// Depending on the `Vector` and `Hasher` used, this requires different hardware
/// features
fn generate_keypair<
    const K: usize,
    const CPA_PRIVATE_KEY_SIZE: usize,
    const PRIVATE_KEY_SIZE: usize,
    const PUBLIC_KEY_SIZE: usize,
    const BYTES_PER_RING_ELEMENT: usize,
    const ETA1: usize,
    const ETA1_RANDOMNESS_SIZE: usize,
    Vector: Operations,
    Hasher: Hash<K>,
>(
    randomness: [u8; KEY_GENERATION_SEED_SIZE],
) -> MlKemKeyPair<PRIVATE_KEY_SIZE, PUBLIC_KEY_SIZE> {
    let ind_cpa_keypair_randomness = &randomness[0..CPA_PKE_KEY_GENERATION_SEED_SIZE];
    let implicit_rejection_value = &randomness[CPA_PKE_KEY_GENERATION_SEED_SIZE..];

    let (ind_cpa_private_key, public_key) = crate::ind_cpa::generate_keypair::<
        K,
        CPA_PRIVATE_KEY_SIZE,
        PUBLIC_KEY_SIZE,
        BYTES_PER_RING_ELEMENT,
        ETA1,
        ETA1_RANDOMNESS_SIZE,
        Vector,
        Hasher,
    >(ind_cpa_keypair_randomness);

    let secret_key_serialized = serialize_kem_secret_key::<K, PRIVATE_KEY_SIZE, Hasher>(
        &ind_cpa_private_key,
        &public_key,
        implicit_rejection_value,
    );
    let private_key: MlKemPrivateKey<PRIVATE_KEY_SIZE> =
        MlKemPrivateKey::from(secret_key_serialized);

    MlKemKeyPair::from(private_key, MlKemPublicKey::from(public_key))
}

fn encapsulate<
    const K: usize,
    const CIPHERTEXT_SIZE: usize,
    const PUBLIC_KEY_SIZE: usize,
    const T_AS_NTT_ENCODED_SIZE: usize,
    const C1_SIZE: usize,
    const C2_SIZE: usize,
    const VECTOR_U_COMPRESSION_FACTOR: usize,
    const VECTOR_V_COMPRESSION_FACTOR: usize,
    const VECTOR_U_BLOCK_LEN: usize,
    const ETA1: usize,
    const ETA1_RANDOMNESS_SIZE: usize,
    const ETA2: usize,
    const ETA2_RANDOMNESS_SIZE: usize,
    Vector: Operations,
    Hasher: Hash<K>,
    Scheme: Variant,
>(
    public_key: &MlKemPublicKey<PUBLIC_KEY_SIZE>,
    randomness: [u8; SHARED_SECRET_SIZE],
) -> (MlKemCiphertext<CIPHERTEXT_SIZE>, MlKemSharedSecret) {
    let randomness = Scheme::entropy_preprocess::<K, Hasher>(&randomness);
    let mut to_hash: [u8; 2 * H_DIGEST_SIZE] = into_padded_array(&randomness);
    to_hash[H_DIGEST_SIZE..].copy_from_slice(&Hasher::H(public_key.as_slice()));

    let hashed = Hasher::G(&to_hash);
    let (shared_secret, pseudorandomness) = hashed.split_at(SHARED_SECRET_SIZE);

    let ciphertext = crate::ind_cpa::encrypt::<
        K,
        CIPHERTEXT_SIZE,
        T_AS_NTT_ENCODED_SIZE,
        C1_SIZE,
        C2_SIZE,
        VECTOR_U_COMPRESSION_FACTOR,
        VECTOR_V_COMPRESSION_FACTOR,
        VECTOR_U_BLOCK_LEN,
        ETA1,
        ETA1_RANDOMNESS_SIZE,
        ETA2,
        ETA2_RANDOMNESS_SIZE,
        Vector,
        Hasher,
    >(public_key.as_slice(), randomness, pseudorandomness);

    let ciphertext = MlKemCiphertext::from(ciphertext);
    let shared_secret_array = Scheme::kdf::<K, CIPHERTEXT_SIZE, Hasher>(shared_secret, &ciphertext);

    (ciphertext, shared_secret_array)
}

pub(crate) fn decapsulate<
    const K: usize,
    const SECRET_KEY_SIZE: usize,
    const CPA_SECRET_KEY_SIZE: usize,
    const PUBLIC_KEY_SIZE: usize,
    const CIPHERTEXT_SIZE: usize,
    const T_AS_NTT_ENCODED_SIZE: usize,
    const C1_SIZE: usize,
    const C2_SIZE: usize,
    const VECTOR_U_COMPRESSION_FACTOR: usize,
    const VECTOR_V_COMPRESSION_FACTOR: usize,
    const C1_BLOCK_SIZE: usize,
    const ETA1: usize,
    const ETA1_RANDOMNESS_SIZE: usize,
    const ETA2: usize,
    const ETA2_RANDOMNESS_SIZE: usize,
    const IMPLICIT_REJECTION_HASH_INPUT_SIZE: usize,
    Vector: Operations,
    Hasher: Hash<K>,
    Scheme: Variant,
>(
    private_key: &MlKemPrivateKey<SECRET_KEY_SIZE>,
    ciphertext: &MlKemCiphertext<CIPHERTEXT_SIZE>,
) -> MlKemSharedSecret {
    let (ind_cpa_secret_key, secret_key) = private_key.value.split_at(CPA_SECRET_KEY_SIZE);
    let (ind_cpa_public_key, secret_key) = secret_key.split_at(PUBLIC_KEY_SIZE);
    let (ind_cpa_public_key_hash, implicit_rejection_value) = secret_key.split_at(H_DIGEST_SIZE);

    let decrypted = crate::ind_cpa::decrypt::<
        K,
        CIPHERTEXT_SIZE,
        C1_SIZE,
        VECTOR_U_COMPRESSION_FACTOR,
        VECTOR_V_COMPRESSION_FACTOR,
        Vector,
    >(ind_cpa_secret_key, &ciphertext.value);

    let mut to_hash: [u8; SHARED_SECRET_SIZE + H_DIGEST_SIZE] = into_padded_array(&decrypted);
    to_hash[SHARED_SECRET_SIZE..].copy_from_slice(ind_cpa_public_key_hash);

    let hashed = Hasher::G(&to_hash);
    let (shared_secret, pseudorandomness) = hashed.split_at(SHARED_SECRET_SIZE);

    let mut to_hash: [u8; IMPLICIT_REJECTION_HASH_INPUT_SIZE] =
        into_padded_array(implicit_rejection_value);
    to_hash[SHARED_SECRET_SIZE..].copy_from_slice(ciphertext.as_ref());
    let implicit_rejection_shared_secret: [u8; SHARED_SECRET_SIZE] = Hasher::PRF(&to_hash);

    let expected_ciphertext = crate::ind_cpa::encrypt::<
        K,
        CIPHERTEXT_SIZE,
        T_AS_NTT_ENCODED_SIZE,
        C1_SIZE,
        C2_SIZE,
        VECTOR_U_COMPRESSION_FACTOR,
        VECTOR_V_COMPRESSION_FACTOR,
        C1_BLOCK_SIZE,
        ETA1,
        ETA1_RANDOMNESS_SIZE,
        ETA2,
        ETA2_RANDOMNESS_SIZE,
        Vector,
        Hasher,
    >(ind_cpa_public_key, decrypted, pseudorandomness);

    let selector = compare_ciphertexts_in_constant_time(ciphertext.as_ref(), &expected_ciphertext);

    let implicit_rejection_shared_secret =
        Scheme::kdf::<K, CIPHERTEXT_SIZE, Hasher>(&implicit_rejection_shared_secret, ciphertext);
    let shared_secret = Scheme::kdf::<K, CIPHERTEXT_SIZE, Hasher>(shared_secret, ciphertext);

    select_shared_secret_in_constant_time(
        &shared_secret,
        &implicit_rejection_shared_secret,
        selector,
    )
}

/// This trait collects differences in specification between ML-KEM
/// (Draft FIPS 203) and the Round 3 CRYSTALS-Kyber submission in the
/// NIST PQ competition.
///
/// cf. FIPS 203 (Draft), section 1.3
pub(crate) trait Variant {
    fn kdf<const K: usize, const CIPHERTEXT_SIZE: usize, Hasher: Hash<K>>(
        shared_secret: &[u8],
        ciphertext: &MlKemCiphertext<CIPHERTEXT_SIZE>,
    ) -> [u8; 32];
    fn entropy_preprocess<const K: usize, Hasher: Hash<K>>(randomness: &[u8]) -> [u8; 32];
}

/// Implements [`Variant`], to perform the Kyber-specific actions
/// during encapsulation and decapsulation.
/// Specifically,
/// * during encapsulation, the initial randomness is hashed before being used,
/// * the derivation of the shared secret includes a hash of the Kyber ciphertext.
#[cfg(feature = "kyber")]
pub(crate) struct Kyber {}

#[cfg(feature = "kyber")]
impl Variant for Kyber {
    #[inline(always)]
    fn kdf<const K: usize, const CIPHERTEXT_SIZE: usize, Hasher: Hash<K>>(
        shared_secret: &[u8],
        ciphertext: &MlKemCiphertext<CIPHERTEXT_SIZE>,
    ) -> [u8; 32] {
        let mut kdf_input: [u8; 2 * H_DIGEST_SIZE] = into_padded_array(&shared_secret);
        kdf_input[H_DIGEST_SIZE..].copy_from_slice(&Hasher::H(ciphertext.as_slice()));
        Hasher::PRF::<32>(&kdf_input)
    }

    #[inline(always)]
    fn entropy_preprocess<const K: usize, Hasher: Hash<K>>(randomness: &[u8]) -> [u8; 32] {
        Hasher::H(&randomness)
    }
}

/// Implements [`Variant`], to perform the ML-KEM-specific actions
/// during encapsulation and decapsulation.
/// Specifically,
/// * during encapsulation, the initial randomness is used without prior hashing,
/// * the derivation of the shared secret does not include a hash of the ML-KEM ciphertext.
pub(crate) struct MlKem {}

impl Variant for MlKem {
    #[inline(always)]
    fn kdf<const K: usize, const CIPHERTEXT_SIZE: usize, Hasher: Hash<K>>(
        shared_secret: &[u8],
        _: &MlKemCiphertext<CIPHERTEXT_SIZE>,
    ) -> [u8; 32] {
        let mut out = [0u8; 32];
        out.copy_from_slice(shared_secret);
        out
    }

    #[inline(always)]
    fn entropy_preprocess<const K: usize, Hasher: Hash<K>>(randomness: &[u8]) -> [u8; 32] {
        let mut out = [0u8; 32];
        out.copy_from_slice(randomness);
        out
    }
}
