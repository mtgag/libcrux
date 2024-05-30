/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /nix/store/c9m211bm84ncjmaxx27ki9dymd4qkwm2-ocaml4.14.1-eurydice-dirty/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc
  F* version: <unknown>
  KaRaMeL version: <unknown>
 */

#ifndef __libcrux_mlkem_ctops_H
#define __libcrux_mlkem_ctops_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "libcrux_mlkem_constants.h"
#include "core.h"
#include "eurydice_glue.h"

uint8_t libcrux_ml_kem_constant_time_ops_is_non_zero(uint8_t value);

void
libcrux_ml_kem_constant_time_ops_select_shared_secret_in_constant_time(
  Eurydice_slice lhs,
  Eurydice_slice rhs,
  uint8_t selector,
  uint8_t ret[32U]
);

#if defined(__cplusplus)
}
#endif

#define __libcrux_mlkem_ctops_H_DEFINED
#endif