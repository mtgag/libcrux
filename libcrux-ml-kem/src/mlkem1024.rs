//! ML-KEM 1024

use super::{constants::*, ind_cca::*, *};

// Kyber 1024 parameters
const RANK_1024: usize = 4;
const RANKED_BYTES_PER_RING_ELEMENT_1024: usize = RANK_1024 * BITS_PER_RING_ELEMENT / 8;
const T_AS_NTT_ENCODED_SIZE_1024: usize =
    (RANK_1024 * COEFFICIENTS_IN_RING_ELEMENT * BITS_PER_COEFFICIENT) / 8;
const VECTOR_U_COMPRESSION_FACTOR_1024: usize = 11;
// [hax]: hacspec/hacspec-v2#27 stealing error
// block_len::<VECTOR_U_COMPRESSION_FACTOR_1024>();
const C1_BLOCK_SIZE_1024: usize =
    (COEFFICIENTS_IN_RING_ELEMENT * VECTOR_U_COMPRESSION_FACTOR_1024) / 8;
// [hax]: hacspec/hacspec-v2#27 stealing error
// serialized_len::<RANK_1024, C1_BLOCK_SIZE_1024>();
const C1_SIZE_1024: usize = C1_BLOCK_SIZE_1024 * RANK_1024;
const VECTOR_V_COMPRESSION_FACTOR_1024: usize = 5;
// [hax]: hacspec/hacspec-v2#27 stealing error
// block_len::<VECTOR_V_COMPRESSION_FACTOR_1024>()
const C2_SIZE_1024: usize = (COEFFICIENTS_IN_RING_ELEMENT * VECTOR_V_COMPRESSION_FACTOR_1024) / 8;
const CPA_PKE_SECRET_KEY_SIZE_1024: usize =
    (RANK_1024 * COEFFICIENTS_IN_RING_ELEMENT * BITS_PER_COEFFICIENT) / 8;
pub(crate) const CPA_PKE_PUBLIC_KEY_SIZE_1024: usize = T_AS_NTT_ENCODED_SIZE_1024 + 32;
const CPA_PKE_CIPHERTEXT_SIZE_1024: usize = C1_SIZE_1024 + C2_SIZE_1024;
pub(crate) const SECRET_KEY_SIZE_1024: usize = CPA_PKE_SECRET_KEY_SIZE_1024
    + CPA_PKE_PUBLIC_KEY_SIZE_1024
    + H_DIGEST_SIZE
    + SHARED_SECRET_SIZE;

const ETA1: usize = 2;
const ETA1_RANDOMNESS_SIZE: usize = ETA1 * 64;
const ETA2: usize = 2;
const ETA2_RANDOMNESS_SIZE: usize = ETA2 * 64;

const IMPLICIT_REJECTION_HASH_INPUT_SIZE: usize = SHARED_SECRET_SIZE + CPA_PKE_CIPHERTEXT_SIZE_1024;

// Kyber 1024 types
/// An ML-KEM 1024 Ciphertext
pub type MlKem1024Ciphertext = MlKemCiphertext<CPA_PKE_CIPHERTEXT_SIZE_1024>;
/// An ML-KEM 1024 Private key
pub type MlKem1024PrivateKey = MlKemPrivateKey<SECRET_KEY_SIZE_1024>;
/// An ML-KEM 1024 Public key
pub type MlKem1024PublicKey = MlKemPublicKey<CPA_PKE_PUBLIC_KEY_SIZE_1024>;
/// Am ML-KEM 1024 Key pair
pub type MlKem1024KeyPair = MlKemKeyPair<SECRET_KEY_SIZE_1024, CPA_PKE_PUBLIC_KEY_SIZE_1024>;

// Instantiate the different functions.
macro_rules! instantiate {
    ($modp:ident, $p:path) => {
        pub mod $modp {
            use super::*;
            use $p as p;

            /// Validate a public key.
            ///
            /// Returns `Some(public_key)` if valid, and `None` otherwise.
            pub fn validate_public_key(
                public_key: MlKem1024PublicKey,
            ) -> Option<MlKem1024PublicKey> {
                if p::validate_public_key::<
                    RANK_1024,
                    RANKED_BYTES_PER_RING_ELEMENT_1024,
                    CPA_PKE_PUBLIC_KEY_SIZE_1024,
                >(&public_key.value)
                {
                    Some(public_key)
                } else {
                    None
                }
            }

            /// Generate ML-KEM 1024 Key Pair
            pub fn generate_key_pair(
                randomness: [u8; KEY_GENERATION_SEED_SIZE],
            ) -> MlKem1024KeyPair {
                p::generate_keypair::<
                    RANK_1024,
                    CPA_PKE_SECRET_KEY_SIZE_1024,
                    SECRET_KEY_SIZE_1024,
                    CPA_PKE_PUBLIC_KEY_SIZE_1024,
                    RANKED_BYTES_PER_RING_ELEMENT_1024,
                    ETA1,
                    ETA1_RANDOMNESS_SIZE,
                >(randomness)
            }

            /// Encapsulate ML-KEM 1024
            ///
            /// Generates an ([`MlKem1024Ciphertext`], [`MlKemSharedSecret`]) tuple.
            /// The input is a reference to an [`MlKem1024PublicKey`] and [`SHARED_SECRET_SIZE`]
            /// bytes of `randomness`.
            pub fn encapsulate(
                public_key: &MlKem1024PublicKey,
                randomness: [u8; SHARED_SECRET_SIZE],
            ) -> (MlKem1024Ciphertext, MlKemSharedSecret) {
                p::encapsulate::<
                    RANK_1024,
                    CPA_PKE_CIPHERTEXT_SIZE_1024,
                    CPA_PKE_PUBLIC_KEY_SIZE_1024,
                    T_AS_NTT_ENCODED_SIZE_1024,
                    C1_SIZE_1024,
                    C2_SIZE_1024,
                    VECTOR_U_COMPRESSION_FACTOR_1024,
                    VECTOR_V_COMPRESSION_FACTOR_1024,
                    C1_BLOCK_SIZE_1024,
                    ETA1,
                    ETA1_RANDOMNESS_SIZE,
                    ETA2,
                    ETA2_RANDOMNESS_SIZE,
                >(public_key, randomness)
            }

            /// Encapsulate Kyber 1024
            ///
            /// Generates an ([`MlKem1024Ciphertext`], [`MlKemSharedSecret`]) tuple.
            /// The input is a reference to an [`MlKem1024PublicKey`] and [`SHARED_SECRET_SIZE`]
            /// bytes of `randomness`.
            #[cfg(feature = "kyber")]
            pub fn kyber_encapsulate(
                public_key: &MlKem1024PublicKey,
                randomness: [u8; SHARED_SECRET_SIZE],
            ) -> (MlKem1024Ciphertext, MlKemSharedSecret) {
                p::kyber_encapsulate::<
                    RANK_1024,
                    CPA_PKE_CIPHERTEXT_SIZE_1024,
                    CPA_PKE_PUBLIC_KEY_SIZE_1024,
                    T_AS_NTT_ENCODED_SIZE_1024,
                    C1_SIZE_1024,
                    C2_SIZE_1024,
                    VECTOR_U_COMPRESSION_FACTOR_1024,
                    VECTOR_V_COMPRESSION_FACTOR_1024,
                    C1_BLOCK_SIZE_1024,
                    ETA1,
                    ETA1_RANDOMNESS_SIZE,
                    ETA2,
                    ETA2_RANDOMNESS_SIZE,
                >(public_key, randomness)
            }

            /// Decapsulate ML-KEM 1024
            ///
            /// Generates an [`MlKemSharedSecret`].
            /// The input is a reference to an [`MlKem1024PrivateKey`] and an [`MlKem1024Ciphertext`].
            pub fn decapsulate(
                private_key: &MlKem1024PrivateKey,
                ciphertext: &MlKem1024Ciphertext,
            ) -> MlKemSharedSecret {
                p::decapsulate::<
                    RANK_1024,
                    SECRET_KEY_SIZE_1024,
                    CPA_PKE_SECRET_KEY_SIZE_1024,
                    CPA_PKE_PUBLIC_KEY_SIZE_1024,
                    CPA_PKE_CIPHERTEXT_SIZE_1024,
                    T_AS_NTT_ENCODED_SIZE_1024,
                    C1_SIZE_1024,
                    C2_SIZE_1024,
                    VECTOR_U_COMPRESSION_FACTOR_1024,
                    VECTOR_V_COMPRESSION_FACTOR_1024,
                    C1_BLOCK_SIZE_1024,
                    ETA1,
                    ETA1_RANDOMNESS_SIZE,
                    ETA2,
                    ETA2_RANDOMNESS_SIZE,
                    IMPLICIT_REJECTION_HASH_INPUT_SIZE,
                >(private_key, ciphertext)
            }

            /// Decapsulate Kyber 1024
            ///
            /// Generates an [`MlKemSharedSecret`].
            /// The input is a reference to an [`MlKem1024PrivateKey`] and an [`MlKem1024Ciphertext`].
            #[cfg(feature = "kyber")]
            pub fn kyber_decapsulate(
                private_key: &MlKem1024PrivateKey,
                ciphertext: &MlKem1024Ciphertext,
            ) -> MlKemSharedSecret {
                p::kyber_decapsulate::<
                    RANK_1024,
                    SECRET_KEY_SIZE_1024,
                    CPA_PKE_SECRET_KEY_SIZE_1024,
                    CPA_PKE_PUBLIC_KEY_SIZE_1024,
                    CPA_PKE_CIPHERTEXT_SIZE_1024,
                    T_AS_NTT_ENCODED_SIZE_1024,
                    C1_SIZE_1024,
                    C2_SIZE_1024,
                    VECTOR_U_COMPRESSION_FACTOR_1024,
                    VECTOR_V_COMPRESSION_FACTOR_1024,
                    C1_BLOCK_SIZE_1024,
                    ETA1,
                    ETA1_RANDOMNESS_SIZE,
                    ETA2,
                    ETA2_RANDOMNESS_SIZE,
                    IMPLICIT_REJECTION_HASH_INPUT_SIZE,
                >(private_key, ciphertext)
            }
        }
    };
}

// Instantiations

instantiate! {portable, ind_cca::instantiations::portable}
#[cfg(feature = "simd256")]
instantiate! {avx2, ind_cca::instantiations::avx2}
#[cfg(feature = "simd128")]
instantiate! {neon, ind_cca::instantiations::neon}

/// Validate a public key.
///
/// Returns `Some(public_key)` if valid, and `None` otherwise.
#[cfg(not(eurydice))]
pub fn validate_public_key(public_key: MlKem1024PublicKey) -> Option<MlKem1024PublicKey> {
    if multiplexing::validate_public_key::<
        RANK_1024,
        RANKED_BYTES_PER_RING_ELEMENT_1024,
        CPA_PKE_PUBLIC_KEY_SIZE_1024,
    >(&public_key.value)
    {
        Some(public_key)
    } else {
        None
    }
}

/// Generate ML-KEM 1024 Key Pair
///
/// Generate an ML-KEM key pair. The input is a byte array of size
/// [`KEY_GENERATION_SEED_SIZE`].
///
/// This function returns an [`MlKem1024KeyPair`].
#[cfg(not(eurydice))]
pub fn generate_key_pair(
    randomness: [u8; KEY_GENERATION_SEED_SIZE],
) -> MlKemKeyPair<SECRET_KEY_SIZE_1024, CPA_PKE_PUBLIC_KEY_SIZE_1024> {
    multiplexing::generate_keypair::<
        RANK_1024,
        CPA_PKE_SECRET_KEY_SIZE_1024,
        SECRET_KEY_SIZE_1024,
        CPA_PKE_PUBLIC_KEY_SIZE_1024,
        RANKED_BYTES_PER_RING_ELEMENT_1024,
        ETA1,
        ETA1_RANDOMNESS_SIZE,
    >(randomness)
}

/// Encapsulate ML-KEM 1024
///
/// Generates an ([`MlKem1024Ciphertext`], [`MlKemSharedSecret`]) tuple.
/// The input is a reference to an [`MlKem1024PublicKey`] and [`SHARED_SECRET_SIZE`]
/// bytes of `randomness`.
#[cfg(not(eurydice))]
pub fn encapsulate(
    public_key: &MlKem1024PublicKey,
    randomness: [u8; SHARED_SECRET_SIZE],
) -> (MlKem1024Ciphertext, MlKemSharedSecret) {
    multiplexing::encapsulate::<
        RANK_1024,
        CPA_PKE_CIPHERTEXT_SIZE_1024,
        CPA_PKE_PUBLIC_KEY_SIZE_1024,
        T_AS_NTT_ENCODED_SIZE_1024,
        C1_SIZE_1024,
        C2_SIZE_1024,
        VECTOR_U_COMPRESSION_FACTOR_1024,
        VECTOR_V_COMPRESSION_FACTOR_1024,
        C1_BLOCK_SIZE_1024,
        ETA1,
        ETA1_RANDOMNESS_SIZE,
        ETA2,
        ETA2_RANDOMNESS_SIZE,
    >(public_key, randomness)
}

/// Decapsulate ML-KEM 1024
///
/// Generates an [`MlKemSharedSecret`].
/// The input is a reference to an [`MlKem1024PrivateKey`] and an [`MlKem1024Ciphertext`].
#[cfg(not(eurydice))]
pub fn decapsulate(
    private_key: &MlKem1024PrivateKey,
    ciphertext: &MlKem1024Ciphertext,
) -> MlKemSharedSecret {
    multiplexing::decapsulate::<
        RANK_1024,
        SECRET_KEY_SIZE_1024,
        CPA_PKE_SECRET_KEY_SIZE_1024,
        CPA_PKE_PUBLIC_KEY_SIZE_1024,
        CPA_PKE_CIPHERTEXT_SIZE_1024,
        T_AS_NTT_ENCODED_SIZE_1024,
        C1_SIZE_1024,
        C2_SIZE_1024,
        VECTOR_U_COMPRESSION_FACTOR_1024,
        VECTOR_V_COMPRESSION_FACTOR_1024,
        C1_BLOCK_SIZE_1024,
        ETA1,
        ETA1_RANDOMNESS_SIZE,
        ETA2,
        ETA2_RANDOMNESS_SIZE,
        IMPLICIT_REJECTION_HASH_INPUT_SIZE,
    >(private_key, ciphertext)
}

#[cfg(all(not(eurydice), feature = "kyber"))]
pub(crate) mod kyber {
    use super::*;

    /// Encapsulate Kyber 1024
    ///
    /// Generates an ([`MlKem1024Ciphertext`], [`MlKemSharedSecret`]) tuple.
    /// The input is a reference to an [`MlKem1024PublicKey`] and [`SHARED_SECRET_SIZE`]
    /// bytes of `randomness`.
    pub fn encapsulate(
        public_key: &MlKem1024PublicKey,
        randomness: [u8; SHARED_SECRET_SIZE],
    ) -> (MlKem1024Ciphertext, MlKemSharedSecret) {
        multiplexing::kyber_encapsulate::<
            RANK_1024,
            CPA_PKE_CIPHERTEXT_SIZE_1024,
            CPA_PKE_PUBLIC_KEY_SIZE_1024,
            T_AS_NTT_ENCODED_SIZE_1024,
            C1_SIZE_1024,
            C2_SIZE_1024,
            VECTOR_U_COMPRESSION_FACTOR_1024,
            VECTOR_V_COMPRESSION_FACTOR_1024,
            C1_BLOCK_SIZE_1024,
            ETA1,
            ETA1_RANDOMNESS_SIZE,
            ETA2,
            ETA2_RANDOMNESS_SIZE,
        >(public_key, randomness)
    }

    /// Decapsulate Kyber 1024
    ///
    /// Generates an [`MlKemSharedSecret`].
    /// The input is a reference to an [`MlKem1024PrivateKey`] and an [`MlKem1024Ciphertext`].
    #[cfg(all(not(eurydice), feature = "kyber"))]
    pub fn decapsulate(
        private_key: &MlKem1024PrivateKey,
        ciphertext: &MlKem1024Ciphertext,
    ) -> MlKemSharedSecret {
        multiplexing::kyber_decapsulate::<
            RANK_1024,
            SECRET_KEY_SIZE_1024,
            CPA_PKE_SECRET_KEY_SIZE_1024,
            CPA_PKE_PUBLIC_KEY_SIZE_1024,
            CPA_PKE_CIPHERTEXT_SIZE_1024,
            T_AS_NTT_ENCODED_SIZE_1024,
            C1_SIZE_1024,
            C2_SIZE_1024,
            VECTOR_U_COMPRESSION_FACTOR_1024,
            VECTOR_V_COMPRESSION_FACTOR_1024,
            C1_BLOCK_SIZE_1024,
            ETA1,
            ETA1_RANDOMNESS_SIZE,
            ETA2,
            ETA2_RANDOMNESS_SIZE,
            IMPLICIT_REJECTION_HASH_INPUT_SIZE,
        >(private_key, ciphertext)
    }
}
