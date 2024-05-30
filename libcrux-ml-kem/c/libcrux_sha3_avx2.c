/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /home/franziskus/eurydice//eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc
  F* version: <unknown>
  KaRaMeL version: 04cb86b9
 */

#ifndef __libcrux_sha3_avx2_H
#define __libcrux_sha3_avx2_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"
#include "libcrux_sha3_avx2.h"
#include "Hacl_Hash_SHA3_Simd256.h"
#include "libintvector.h"


extern void
libcrux_sha3_avx2_x4_shake256(
  Eurydice_slice x0,
  Eurydice_slice x1,
  Eurydice_slice x2,
  Eurydice_slice x3,
  Eurydice_slice x4,
  Eurydice_slice x5,
  Eurydice_slice x6,
  Eurydice_slice x7
){
    Hacl_Hash_SHA3_Simd256_shake256(x0.ptr, x1.ptr, x2.ptr, x3.ptr, x0.len, x4.ptr, x5.ptr, x6.ptr, x7.ptr, x4.len);
}

extern libcrux_sha3_avx2_x4_incremental_KeccakState4
libcrux_sha3_avx2_x4_incremental_shake128_init(void){
  libcrux_sha3_avx2_x4_incremental_KeccakState4 st;
  st.st = Hacl_Hash_SHA3_Simd256_state_malloc();
  return st;
}

extern void
libcrux_sha3_avx2_x4_incremental_shake128_absorb_final(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *x0,
  Eurydice_slice x1,
  Eurydice_slice x2,
  Eurydice_slice x3,
  Eurydice_slice x4
){
    Hacl_Hash_SHA3_Simd256_shake128_absorb_final(x0->st, x1.ptr, x2.ptr, x3.ptr, x4.ptr, x1.len);
}

extern void
libcrux_sha3_avx2_x4_incremental_shake128_squeeze_next_block(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *x0,
  Eurydice_slice x1,
  Eurydice_slice x2,
  Eurydice_slice x3,
  Eurydice_slice x4
){
    Hacl_Hash_SHA3_Simd256_shake128_squeeze_nblocks(x0->st, x1.ptr, x2.ptr, x3.ptr, x4.ptr, x1.len);
}

extern void
libcrux_sha3_avx2_x4_incremental_shake128_squeeze_first_three_blocks(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *x0,
  Eurydice_slice x1,
  Eurydice_slice x2,
  Eurydice_slice x3,
  Eurydice_slice x4
){
    Hacl_Hash_SHA3_Simd256_shake128_squeeze_nblocks(x0->st, x1.ptr, x2.ptr, x3.ptr, x4.ptr, x1.len);
}

#if defined(__cplusplus)
}
#endif

#define __libcrux_sha3_avx2_H_DEFINED
#endif
