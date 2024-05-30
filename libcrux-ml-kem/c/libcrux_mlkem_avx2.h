/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /home/franziskus/eurydice//eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc
  F* version: <unknown>
  KaRaMeL version: 04cb86b9
 */

#ifndef __libcrux_mlkem_avx2_H
#define __libcrux_mlkem_avx2_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "libcrux_sha3_avx2.h"
#include "libcrux_sha3.h"
#include "libcrux_core.h"
#include "eurydice_glue.h"

typedef core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_SIMD256Vector;

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_zero(void);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___ZERO(
  void
);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_from_i16_array(Eurydice_slice array);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___from_i16_array(
  Eurydice_slice array
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_add(
  core_core_arch_x86___m256i lhs,
  core_core_arch_x86___m256i rhs
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___add(
  core_core_arch_x86___m256i lhs,
  core_core_arch_x86___m256i *rhs
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_sub(
  core_core_arch_x86___m256i lhs,
  core_core_arch_x86___m256i rhs
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___sub(
  core_core_arch_x86___m256i lhs,
  core_core_arch_x86___m256i *rhs
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_multiply_by_constant(
  core_core_arch_x86___m256i vector,
  int16_t constant
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___multiply_by_constant(
  core_core_arch_x86___m256i v,
  int16_t c
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_bitwise_and_with_constant(
  core_core_arch_x86___m256i vector,
  int16_t constant
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___bitwise_and_with_constant(
  core_core_arch_x86___m256i vector,
  int16_t constant
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_cond_subtract_3329(core_core_arch_x86___m256i vector);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___cond_subtract_3329(
  core_core_arch_x86___m256i vector
);

#define LIBCRUX_ML_KEM_VECTOR_AVX2_ARITHMETIC_BARRETT_MULTIPLIER ((int16_t)20159)

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_barrett_reduce(core_core_arch_x86___m256i vector);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___barrett_reduce(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_montgomery_multiply_by_constant(
  core_core_arch_x86___m256i vector,
  int16_t constant
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___montgomery_multiply_by_constant(
  core_core_arch_x86___m256i vector,
  int16_t constant
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_compress_message_coefficient(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___compress_1(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_mulhi_mm256_epi32(
  core_core_arch_x86___m256i lhs,
  core_core_arch_x86___m256i rhs
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_montgomery_multiply_by_constants(
  core_core_arch_x86___m256i v,
  core_core_arch_x86___m256i c
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_ntt_ntt_layer_1_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta0,
  int16_t zeta1,
  int16_t zeta2,
  int16_t zeta3
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___ntt_layer_1_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta0,
  int16_t zeta1,
  int16_t zeta2,
  int16_t zeta3
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_ntt_ntt_layer_2_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta0,
  int16_t zeta1
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___ntt_layer_2_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta0,
  int16_t zeta1
);

core_core_arch_x86___m128i
libcrux_ml_kem_vector_avx2_arithmetic_montgomery_multiply_m128i_by_constants(
  core_core_arch_x86___m128i v,
  core_core_arch_x86___m128i c
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_ntt_ntt_layer_3_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___ntt_layer_3_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_ntt_inv_ntt_layer_1_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta0,
  int16_t zeta1,
  int16_t zeta2,
  int16_t zeta3
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___inv_ntt_layer_1_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta0,
  int16_t zeta1,
  int16_t zeta2,
  int16_t zeta3
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_ntt_inv_ntt_layer_2_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta0,
  int16_t zeta1
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___inv_ntt_layer_2_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta0,
  int16_t zeta1
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_ntt_inv_ntt_layer_3_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___inv_ntt_layer_3_step(
  core_core_arch_x86___m256i vector,
  int16_t zeta
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_montgomery_reduce_i32s(core_core_arch_x86___m256i v);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_ntt_ntt_multiply(
  core_core_arch_x86___m256i lhs,
  core_core_arch_x86___m256i rhs,
  int16_t zeta0,
  int16_t zeta1,
  int16_t zeta2,
  int16_t zeta3
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___ntt_multiply(
  core_core_arch_x86___m256i *lhs,
  core_core_arch_x86___m256i *rhs,
  int16_t zeta0,
  int16_t zeta1,
  int16_t zeta2,
  int16_t zeta3
);

void
libcrux_ml_kem_vector_avx2_serialize_serialize_1(
  core_core_arch_x86___m256i vector,
  uint8_t ret[2U]
);

void
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_1(
  core_core_arch_x86___m256i vector,
  uint8_t ret[2U]
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_serialize_deserialize_1(Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_1(
  Eurydice_slice bytes
);

void
libcrux_ml_kem_vector_avx2_serialize_serialize_4(
  core_core_arch_x86___m256i vector,
  uint8_t ret[8U]
);

void
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_4(
  core_core_arch_x86___m256i vector,
  uint8_t ret[8U]
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_serialize_deserialize_4(Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_4(
  Eurydice_slice bytes
);

void
libcrux_ml_kem_vector_avx2_serialize_serialize_5(
  core_core_arch_x86___m256i vector,
  uint8_t ret[10U]
);

void
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_5(
  core_core_arch_x86___m256i vector,
  uint8_t ret[10U]
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_serialize_deserialize_5(Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_5(
  Eurydice_slice bytes
);

void
libcrux_ml_kem_vector_avx2_serialize_serialize_10(
  core_core_arch_x86___m256i vector,
  uint8_t ret[20U]
);

void
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_10(
  core_core_arch_x86___m256i vector,
  uint8_t ret[20U]
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_serialize_deserialize_10(Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_10(
  Eurydice_slice bytes
);

void libcrux_ml_kem_vector_avx2_to_i16_array(core_core_arch_x86___m256i v, int16_t ret[16U]);

typedef struct libcrux_ml_kem_vector_avx2_portable_PortableVector_s { int16_t elements[16U]; }
libcrux_ml_kem_vector_avx2_portable_PortableVector;

libcrux_ml_kem_vector_avx2_portable_PortableVector
libcrux_ml_kem_vector_avx2_portable_from_i16_array(int16_t array[16U]);

void
libcrux_ml_kem_vector_avx2_portable_serialize_11(
  libcrux_ml_kem_vector_avx2_portable_PortableVector v,
  uint8_t ret[22U]
);

void
libcrux_ml_kem_vector_avx2_serialize_serialize_11(
  core_core_arch_x86___m256i vector,
  uint8_t ret[22U]
);

void
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_11(
  core_core_arch_x86___m256i vector,
  uint8_t ret[22U]
);

libcrux_ml_kem_vector_avx2_portable_PortableVector
libcrux_ml_kem_vector_avx2_portable_zero(void);

libcrux_ml_kem_vector_avx2_portable_PortableVector
libcrux_ml_kem_vector_avx2_portable_deserialize_11(Eurydice_slice bytes);

void
libcrux_ml_kem_vector_avx2_portable_to_i16_array(
  libcrux_ml_kem_vector_avx2_portable_PortableVector v,
  int16_t ret[16U]
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_serialize_deserialize_11(Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_11(
  Eurydice_slice bytes
);

void
libcrux_ml_kem_vector_avx2_serialize_serialize_12(
  core_core_arch_x86___m256i vector,
  uint8_t ret[24U]
);

void
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_12(
  core_core_arch_x86___m256i vector,
  uint8_t ret[24U]
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_serialize_deserialize_12(Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_12(
  Eurydice_slice bytes
);

size_t
libcrux_ml_kem_vector_avx2_sampling_rejection_sample(
  Eurydice_slice input,
  Eurydice_slice output
);

size_t
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___rej_sample(
  Eurydice_slice input,
  Eurydice_slice output
);

libcrux_ml_kem_vector_avx2_portable_PortableVector
libcrux_ml_kem_vector_avx2_portable___core__clone__Clone_for_libcrux_ml_kem__vector__avx2__portable__PortableVector___clone(
  libcrux_ml_kem_vector_avx2_portable_PortableVector *self
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___core__clone__Clone_for_libcrux_ml_kem__vector__avx2__SIMD256Vector__1__clone(
  core_core_arch_x86___m256i *self
);

typedef struct
libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector_s
{ core_core_arch_x86___m256i coefficients[16U]; }
libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector;

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_shift_right___15int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___shift_right___15int32_t(
  core_core_arch_x86___m256i vector
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___G___2size_t(
  Eurydice_slice input,
  uint8_t ret[64U]
);

typedef libcrux_sha3_avx2_x4_incremental_KeccakState4
libcrux_ml_kem_hash_functions_avx2_Simd256Hash;

libcrux_sha3_avx2_x4_incremental_KeccakState4
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___shake128_init_absorb___2size_t(
  uint8_t input[2U][34U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___shake128_squeeze_three_blocks___2size_t(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *self,
  uint8_t ret[2U][504U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___shake128_squeeze_block___2size_t(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *self,
  uint8_t ret[2U][168U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___PRFxN___2size_t_192size_t(
  uint8_t (*input)[33U],
  uint8_t ret[2U][192U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___H___2size_t(
  Eurydice_slice input,
  uint8_t ret[32U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___PRFxN___2size_t_128size_t(
  uint8_t (*input)[33U],
  uint8_t ret[2U][128U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___PRF___2size_t_128size_t(
  Eurydice_slice input,
  uint8_t ret[128U]
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_compress_ciphertext_coefficient___10int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___compress___10int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_compress_ciphertext_coefficient___11int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___compress___11int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_compress_ciphertext_coefficient___4int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___compress___4int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_compress_ciphertext_coefficient___5int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___compress___5int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_decompress_ciphertext_coefficient___10int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___decompress_ciphertext_coefficient___10int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_decompress_ciphertext_coefficient___11int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___decompress_ciphertext_coefficient___11int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_decompress_ciphertext_coefficient___4int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___decompress_ciphertext_coefficient___4int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_decompress_ciphertext_coefficient___5int32_t(
  core_core_arch_x86___m256i vector
);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___decompress_ciphertext_coefficient___5int32_t(
  core_core_arch_x86___m256i vector
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___PRF___2size_t_32size_t(
  Eurydice_slice input,
  uint8_t ret[32U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___G___4size_t(
  Eurydice_slice input,
  uint8_t ret[64U]
);

libcrux_sha3_avx2_x4_incremental_KeccakState4
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___shake128_init_absorb___4size_t(
  uint8_t input[4U][34U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___shake128_squeeze_three_blocks___4size_t(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *self,
  uint8_t ret[4U][504U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___shake128_squeeze_block___4size_t(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *self,
  uint8_t ret[4U][168U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___PRFxN___4size_t_128size_t(
  uint8_t (*input)[33U],
  uint8_t ret[4U][128U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___H___4size_t(
  Eurydice_slice input,
  uint8_t ret[32U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___PRF___4size_t_128size_t(
  Eurydice_slice input,
  uint8_t ret[128U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___PRF___4size_t_32size_t(
  Eurydice_slice input,
  uint8_t ret[32U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___G___3size_t(
  Eurydice_slice input,
  uint8_t ret[64U]
);

libcrux_sha3_avx2_x4_incremental_KeccakState4
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___shake128_init_absorb___3size_t(
  uint8_t input[3U][34U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___shake128_squeeze_three_blocks___3size_t(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *self,
  uint8_t ret[3U][504U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___shake128_squeeze_block___3size_t(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *self,
  uint8_t ret[3U][168U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___PRFxN___3size_t_128size_t(
  uint8_t (*input)[33U],
  uint8_t ret[3U][128U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___H___3size_t(
  Eurydice_slice input,
  uint8_t ret[32U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___PRF___3size_t_128size_t(
  Eurydice_slice input,
  uint8_t ret[128U]
);

void
libcrux_ml_kem_hash_functions_avx2___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__avx2__Simd256Hash___PRF___3size_t_32size_t(
  Eurydice_slice input,
  uint8_t ret[32U]
);

#if defined(__cplusplus)
}
#endif

#define __libcrux_mlkem_avx2_H_DEFINED
#endif
