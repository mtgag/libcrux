/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /nix/store/c9m211bm84ncjmaxx27ki9dymd4qkwm2-ocaml4.14.1-eurydice-dirty/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc
  F* version: <unknown>
  KaRaMeL version: <unknown>
 */

#ifndef __libcrux_platform_H
#define __libcrux_platform_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"

extern bool libcrux_platform_platform_simd256_support(void);

extern bool libcrux_platform_platform_simd128_support(void);

#if defined(__cplusplus)
}
#endif

#define __libcrux_platform_H_DEFINED
#endif