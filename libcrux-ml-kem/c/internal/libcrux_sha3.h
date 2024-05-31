/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc
  F* version: 58c915a8
  KaRaMeL version: 38d348ce
 */

#ifndef __internal_libcrux_sha3_H
#define __internal_libcrux_sha3_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "internal/libcrux_core.h"
#include "../libcrux_sha3.h"
#include "eurydice_glue.h"

extern const uint64_t libcrux_sha3_generic_keccak_ROUNDCONSTANTS[24U];

void libcrux_sha3_portable_sha512(Eurydice_slice digest, Eurydice_slice data);

void libcrux_sha3_portable_sha256(Eurydice_slice digest, Eurydice_slice data);

void libcrux_sha3_portable_shake256(Eurydice_slice digest, Eurydice_slice data);

libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t
libcrux_sha3_portable_incremental_shake128_init(void);

void
libcrux_sha3_portable_incremental_shake128_absorb_final(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice data0
);

void
libcrux_sha3_portable_incremental_shake128_squeeze_next_block(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out0
);

void
libcrux_sha3_portable_incremental_shake128_squeeze_first_three_blocks(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out0
);

#if defined(__cplusplus)
}
#endif

#define __internal_libcrux_sha3_H_DEFINED
#endif
