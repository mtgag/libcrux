/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc
  F* version: 58c915a8
  KaRaMeL version: 38d348ce
 */

#ifndef __internal_libcrux_mlkem_avx2_H
#define __internal_libcrux_mlkem_avx2_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "internal/libcrux_sha3_avx2.h"
#include "internal/libcrux_polynomial.h"
#include "internal/libcrux_core.h"
#include "../libcrux_mlkem_avx2.h"
#include "eurydice_glue.h"

bool
libcrux_ml_kem_ind_cca_validate_public_key_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_2size_t_768size_t_800size_t(
  uint8_t *public_key
);

libcrux_ml_kem_types_MlKemKeyPair____1632size_t__800size_t
libcrux_ml_kem_ind_cca_generate_keypair_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_libcrux_ml_kem_hash_functions_avx2_Simd256Hash_2size_t_768size_t_1632size_t_800size_t_768size_t_3size_t_192size_t(
  Eurydice_slice ind_cpa_keypair_randomness,
  Eurydice_slice implicit_rejection_value
);

K___libcrux_ml_kem_types_MlKemCiphertext___768size_t___uint8_t_32size_t_
libcrux_ml_kem_ind_cca_encapsulate_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_libcrux_ml_kem_hash_functions_avx2_Simd256Hash_2size_t_768size_t_800size_t_768size_t_640size_t_128size_t_10size_t_4size_t_320size_t_3size_t_192size_t_2size_t_128size_t(
  libcrux_ml_kem_types_MlKemPublicKey____800size_t *public_key,
  uint8_t randomness[32U]
);

void
libcrux_ml_kem_ind_cca_decapsulate_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_libcrux_ml_kem_hash_functions_avx2_Simd256Hash_2size_t_1632size_t_768size_t_800size_t_768size_t_768size_t_640size_t_128size_t_10size_t_4size_t_320size_t_3size_t_192size_t_2size_t_128size_t_800size_t(
  libcrux_ml_kem_types_MlKemPrivateKey____1632size_t *private_key,
  libcrux_ml_kem_types_MlKemCiphertext____768size_t *ciphertext,
  uint8_t ret[32U]
);

bool
libcrux_ml_kem_ind_cca_validate_public_key_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_4size_t_1536size_t_1568size_t(
  uint8_t *public_key
);

libcrux_ml_kem_types_MlKemKeyPair____3168size_t__1568size_t
libcrux_ml_kem_ind_cca_generate_keypair_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_libcrux_ml_kem_hash_functions_avx2_Simd256Hash_4size_t_1536size_t_3168size_t_1568size_t_1536size_t_2size_t_128size_t(
  Eurydice_slice ind_cpa_keypair_randomness,
  Eurydice_slice implicit_rejection_value
);

K___libcrux_ml_kem_types_MlKemCiphertext___1568size_t___uint8_t_32size_t_
libcrux_ml_kem_ind_cca_encapsulate_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_libcrux_ml_kem_hash_functions_avx2_Simd256Hash_4size_t_1568size_t_1568size_t_1536size_t_1408size_t_160size_t_11size_t_5size_t_352size_t_2size_t_128size_t_2size_t_128size_t(
  libcrux_ml_kem_types_MlKemPublicKey____1568size_t *public_key,
  uint8_t randomness[32U]
);

void
libcrux_ml_kem_ind_cca_decapsulate_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_libcrux_ml_kem_hash_functions_avx2_Simd256Hash_4size_t_3168size_t_1536size_t_1568size_t_1568size_t_1536size_t_1408size_t_160size_t_11size_t_5size_t_352size_t_2size_t_128size_t_2size_t_128size_t_1600size_t(
  libcrux_ml_kem_types_MlKemPrivateKey____3168size_t *private_key,
  libcrux_ml_kem_types_MlKemCiphertext____1568size_t *ciphertext,
  uint8_t ret[32U]
);

bool
libcrux_ml_kem_ind_cca_validate_public_key_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_3size_t_1152size_t_1184size_t(
  uint8_t *public_key
);

libcrux_ml_kem_types_MlKemKeyPair____2400size_t__1184size_t
libcrux_ml_kem_ind_cca_generate_keypair_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_libcrux_ml_kem_hash_functions_avx2_Simd256Hash_3size_t_1152size_t_2400size_t_1184size_t_1152size_t_2size_t_128size_t(
  Eurydice_slice ind_cpa_keypair_randomness,
  Eurydice_slice implicit_rejection_value
);

K___libcrux_ml_kem_types_MlKemCiphertext___1088size_t___uint8_t_32size_t_
libcrux_ml_kem_ind_cca_encapsulate_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_libcrux_ml_kem_hash_functions_avx2_Simd256Hash_3size_t_1088size_t_1184size_t_1152size_t_960size_t_128size_t_10size_t_4size_t_320size_t_2size_t_128size_t_2size_t_128size_t(
  libcrux_ml_kem_types_MlKemPublicKey____1184size_t *public_key,
  uint8_t randomness[32U]
);

void
libcrux_ml_kem_ind_cca_decapsulate_generic__libcrux_ml_kem_vector_avx2_SIMD256Vector_libcrux_ml_kem_hash_functions_avx2_Simd256Hash_3size_t_2400size_t_1152size_t_1184size_t_1088size_t_1152size_t_960size_t_128size_t_10size_t_4size_t_320size_t_2size_t_128size_t_2size_t_128size_t_1120size_t(
  libcrux_ml_kem_types_MlKemPrivateKey____2400size_t *private_key,
  libcrux_ml_kem_types_MlKemCiphertext____1088size_t *ciphertext,
  uint8_t ret[32U]
);

#if defined(__cplusplus)
}
#endif

#define __internal_libcrux_mlkem_avx2_H_DEFINED
#endif
