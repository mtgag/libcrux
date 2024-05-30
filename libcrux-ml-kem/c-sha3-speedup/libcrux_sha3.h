/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc --log Phase3
  F* version: 58c915a8
  KaRaMeL version: 04cb86b9
 */

#ifndef __libcrux_sha3_H
#define __libcrux_sha3_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "libcrux_core.h"
#include "eurydice_glue.h"
static const
uint64_t
libcrux_sha3_generic_keccak_ROUNDCONSTANTS[24U] =
  {
    1ULL, 32898ULL, 9223372036854808714ULL, 9223372039002292224ULL, 32907ULL, 2147483649ULL,
    9223372039002292353ULL, 9223372036854808585ULL, 138ULL, 136ULL, 2147516425ULL, 2147483658ULL,
    2147516555ULL, 9223372036854775947ULL, 9223372036854808713ULL, 9223372036854808579ULL,
    9223372036854808578ULL, 9223372036854775936ULL, 32778ULL, 9223372039002259466ULL,
    9223372039002292353ULL, 9223372036854808704ULL, 2147483649ULL, 9223372039002292232ULL
  };

  /*

extern const uint64_t libcrux_sha3_generic_keccak_ROUNDCONSTANTS[24U];

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___zero(void);

uint64_t
libcrux_sha3_portable_keccak__veor5q_u64(
  uint64_t a,
  uint64_t b,
  uint64_t c,
  uint64_t d,
  uint64_t e
);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor5(
  uint64_t a,
  uint64_t b,
  uint64_t c,
  uint64_t d,
  uint64_t e
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___1int32_t_63int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vrax1q_u64(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___rotate_left1_and_xor(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak__vbcaxq_u64(uint64_t a, uint64_t b, uint64_t c);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___and_not_xor(
  uint64_t a,
  uint64_t b,
  uint64_t c
);

uint64_t libcrux_sha3_portable_keccak__veorq_n_u64(uint64_t a, uint64_t c);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_constant(
  uint64_t a,
  uint64_t c
);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor(
  uint64_t a,
  uint64_t b
);

void
libcrux_sha3_portable_keccak_slice_1(
  Eurydice_slice a[1U],
  size_t start,
  size_t len,
  Eurydice_slice ret[1U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___slice_n(
  Eurydice_slice a[1U],
  size_t start,
  size_t len,
  Eurydice_slice ret[1U]
);

K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_
libcrux_sha3_portable_keccak_split_at_mut_1(Eurydice_slice out[1U], size_t mid);

K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___split_at_mut_n(
  Eurydice_slice a[1U],
  size_t mid
);
  */
  
typedef struct libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t_s
{ uint64_t st[5U][5U]; }
libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t;

  /*
libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t
libcrux_sha3_generic_keccak__libcrux_sha3__generic_keccak__KeccakState_T__N__TraitClause_0__1__new__uint64_t_1size_t(
  void
);

void
libcrux_sha3_portable_keccak_load_block___72size_t(
  uint64_t (*s)[5U],
  Eurydice_slice blocks[1U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___load_block___72size_t(
  uint64_t (*a)[5U],
  Eurydice_slice b[1U]
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___36int32_t_28int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___36int32_t_28int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___36int32_t_28int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___3int32_t_61int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___3int32_t_61int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___3int32_t_61int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___41int32_t_23int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___41int32_t_23int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___41int32_t_23int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___18int32_t_46int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___18int32_t_46int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___18int32_t_46int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___1int32_t_63int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___1int32_t_63int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___44int32_t_20int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___44int32_t_20int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___44int32_t_20int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___10int32_t_54int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___10int32_t_54int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___10int32_t_54int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___45int32_t_19int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___45int32_t_19int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___45int32_t_19int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___2int32_t_62int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___2int32_t_62int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___2int32_t_62int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___62int32_t_2int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___62int32_t_2int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___62int32_t_2int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___6int32_t_58int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___6int32_t_58int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___6int32_t_58int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___43int32_t_21int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___43int32_t_21int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___43int32_t_21int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___15int32_t_49int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___15int32_t_49int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___15int32_t_49int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___61int32_t_3int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___61int32_t_3int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___61int32_t_3int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___28int32_t_36int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___28int32_t_36int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___28int32_t_36int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___55int32_t_9int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___55int32_t_9int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___55int32_t_9int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___25int32_t_39int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___25int32_t_39int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___25int32_t_39int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___21int32_t_43int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___21int32_t_43int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___21int32_t_43int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___56int32_t_8int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___56int32_t_8int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___56int32_t_8int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___27int32_t_37int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___27int32_t_37int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___27int32_t_37int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___20int32_t_44int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___20int32_t_44int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___20int32_t_44int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___39int32_t_25int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___39int32_t_25int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___39int32_t_25int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___8int32_t_56int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___8int32_t_56int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___8int32_t_56int32_t(
  uint64_t a,
  uint64_t b
);

uint64_t libcrux_sha3_portable_keccak_rotate_left___14int32_t_50int32_t(uint64_t x);

uint64_t libcrux_sha3_portable_keccak__vxarq_u64___14int32_t_50int32_t(uint64_t a, uint64_t b);

uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___xor_and_rotate___14int32_t_50int32_t(
  uint64_t a,
  uint64_t b
);

void
libcrux_sha3_generic_keccak_theta_rho__uint64_t_1size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s
);

void
libcrux_sha3_generic_keccak_pi__uint64_t_1size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s
);

void
libcrux_sha3_generic_keccak_chi__uint64_t_1size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s
);

void
libcrux_sha3_generic_keccak_iota__uint64_t_1size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  size_t i
);

void
libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s
);

void
libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_72size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice blocks[1U]
);

void
libcrux_sha3_portable_keccak_load_block_full___72size_t(
  uint64_t (*s)[5U],
  uint8_t blocks[1U][200U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___load_block_full___72size_t(
  uint64_t (*a)[5U],
  uint8_t b[1U][200U]
);

void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_72size_t_6uint8_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice last[1U]
);

void
libcrux_sha3_portable_keccak_store_block___72size_t(uint64_t (*s)[5U], Eurydice_slice out[1U]);

void
libcrux_sha3_portable_keccak_store_block_full___72size_t(
  uint64_t (*s)[5U],
  uint8_t ret[1U][200U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___store_block_full___72size_t(
  uint64_t (*a)[5U],
  uint8_t ret[1U][200U]
);

void
libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_72size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___store_block___72size_t(
  uint64_t (*a)[5U],
  Eurydice_slice b[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_72size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_72size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_72size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_72size_t_6uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);

void
libcrux_sha3_portable_keccakx1___72size_t_6uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);
  */
void libcrux_sha3_portable_sha512(Eurydice_slice digest, Eurydice_slice data);
  /*
void
libcrux_sha3_portable_keccak_load_block___136size_t(
  uint64_t (*s)[5U],
  Eurydice_slice blocks[1U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___load_block___136size_t(
  uint64_t (*a)[5U],
  Eurydice_slice b[1U]
);

void
libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_136size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice blocks[1U]
);

void
libcrux_sha3_portable_keccak_load_block_full___136size_t(
  uint64_t (*s)[5U],
  uint8_t blocks[1U][200U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___load_block_full___136size_t(
  uint64_t (*a)[5U],
  uint8_t b[1U][200U]
);

void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_136size_t_6uint8_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice last[1U]
);

void
libcrux_sha3_portable_keccak_store_block___136size_t(uint64_t (*s)[5U], Eurydice_slice out[1U]);

void
libcrux_sha3_portable_keccak_store_block_full___136size_t(
  uint64_t (*s)[5U],
  uint8_t ret[1U][200U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___store_block_full___136size_t(
  uint64_t (*a)[5U],
  uint8_t ret[1U][200U]
);

void
libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_136size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___store_block___136size_t(
  uint64_t (*a)[5U],
  Eurydice_slice b[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_136size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_136size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_136size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_136size_t_6uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);

void
libcrux_sha3_portable_keccakx1___136size_t_6uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);
  */
  
void libcrux_sha3_portable_sha256(Eurydice_slice digest, Eurydice_slice data);

  /*
void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_136size_t_31uint8_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice last[1U]
);

void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_136size_t_31uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);

void
libcrux_sha3_portable_keccakx1___136size_t_31uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);
  */
  
void libcrux_sha3_portable_shake256(Eurydice_slice digest, Eurydice_slice data);
  
typedef libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t
libcrux_sha3_portable_KeccakState1;

libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t
libcrux_sha3_portable_incremental_shake128_init(void);

  /*
void
libcrux_sha3_portable_keccak_load_block___168size_t(
  uint64_t (*s)[5U],
  Eurydice_slice blocks[1U]
);

void
libcrux_sha3_portable_keccak_load_block_full___168size_t(
  uint64_t (*s)[5U],
  uint8_t blocks[1U][200U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___load_block_full___168size_t(
  uint64_t (*a)[5U],
  uint8_t b[1U][200U]
);

void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_168size_t_31uint8_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice last[1U]
);
  */
  
void
libcrux_sha3_portable_incremental_shake128_absorb_final(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice data0
);
  /*
void
libcrux_sha3_portable_keccak_store_block___168size_t(uint64_t (*s)[5U], Eurydice_slice out[1U]);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___store_block___168size_t(
  uint64_t (*a)[5U],
  Eurydice_slice b[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_168size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);
  */
void
libcrux_sha3_portable_incremental_shake128_squeeze_next_block(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out0
);
  /*
void
libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_168size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_first_three_blocks__uint64_t_1size_t_168size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);
  */
  
void
libcrux_sha3_portable_incremental_shake128_squeeze_first_three_blocks(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out0
);
  
#define libcrux_sha3_Sha224 0
#define libcrux_sha3_Sha256 1
#define libcrux_sha3_Sha384 2
#define libcrux_sha3_Sha512 3

typedef uint8_t libcrux_sha3_Algorithm;

size_t libcrux_sha3_digest_size(libcrux_sha3_Algorithm mode);
  /*
void
libcrux_sha3_portable_keccak_load_block___144size_t(
  uint64_t (*s)[5U],
  Eurydice_slice blocks[1U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___load_block___144size_t(
  uint64_t (*a)[5U],
  Eurydice_slice b[1U]
);

void
libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_144size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice blocks[1U]
);

void
libcrux_sha3_portable_keccak_load_block_full___144size_t(
  uint64_t (*s)[5U],
  uint8_t blocks[1U][200U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___load_block_full___144size_t(
  uint64_t (*a)[5U],
  uint8_t b[1U][200U]
);

void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_144size_t_6uint8_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice last[1U]
);

void
libcrux_sha3_portable_keccak_store_block___144size_t(uint64_t (*s)[5U], Eurydice_slice out[1U]);

void
libcrux_sha3_portable_keccak_store_block_full___144size_t(
  uint64_t (*s)[5U],
  uint8_t ret[1U][200U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___store_block_full___144size_t(
  uint64_t (*a)[5U],
  uint8_t ret[1U][200U]
);

void
libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_144size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___store_block___144size_t(
  uint64_t (*a)[5U],
  Eurydice_slice b[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_144size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_144size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_144size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_144size_t_6uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);

void
libcrux_sha3_portable_keccakx1___144size_t_6uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);

void libcrux_sha3_portable_sha224(Eurydice_slice digest, Eurydice_slice data);

void
libcrux_sha3_portable_keccak_load_block___104size_t(
  uint64_t (*s)[5U],
  Eurydice_slice blocks[1U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___load_block___104size_t(
  uint64_t (*a)[5U],
  Eurydice_slice b[1U]
);

void
libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_104size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice blocks[1U]
);

void
libcrux_sha3_portable_keccak_load_block_full___104size_t(
  uint64_t (*s)[5U],
  uint8_t blocks[1U][200U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___load_block_full___104size_t(
  uint64_t (*a)[5U],
  uint8_t b[1U][200U]
);

void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_104size_t_6uint8_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice last[1U]
);

void
libcrux_sha3_portable_keccak_store_block___104size_t(uint64_t (*s)[5U], Eurydice_slice out[1U]);

void
libcrux_sha3_portable_keccak_store_block_full___104size_t(
  uint64_t (*s)[5U],
  uint8_t ret[1U][200U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___store_block_full___104size_t(
  uint64_t (*a)[5U],
  uint8_t ret[1U][200U]
);

void
libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_104size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___store_block___104size_t(
  uint64_t (*a)[5U],
  Eurydice_slice b[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_104size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_104size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_104size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_104size_t_6uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);

void
libcrux_sha3_portable_keccakx1___104size_t_6uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);
  */
  
void libcrux_sha3_portable_sha384(Eurydice_slice digest, Eurydice_slice data);

void libcrux_sha3_sha224_ema(Eurydice_slice digest, Eurydice_slice payload);

void libcrux_sha3_sha224(Eurydice_slice data, uint8_t ret[28U]);

void libcrux_sha3_sha256_ema(Eurydice_slice digest, Eurydice_slice payload);

void libcrux_sha3_sha256(Eurydice_slice data, uint8_t ret[32U]);

void libcrux_sha3_sha384_ema(Eurydice_slice digest, Eurydice_slice payload);

void libcrux_sha3_sha384(Eurydice_slice data, uint8_t ret[48U]);

void libcrux_sha3_sha512_ema(Eurydice_slice digest, Eurydice_slice payload);

void libcrux_sha3_sha512(Eurydice_slice data, uint8_t ret[64U]);
  /*
void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___load_block___168size_t(
  uint64_t (*a)[5U],
  Eurydice_slice b[1U]
);

void
libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_168size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice blocks[1U]
);

void
libcrux_sha3_portable_keccak_store_block_full___168size_t(
  uint64_t (*s)[5U],
  uint8_t ret[1U][200U]
);

void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__KeccakItem_1__usize__for_u64___store_block_full___168size_t(
  uint64_t (*a)[5U],
  uint8_t ret[1U][200U]
);

void
libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_168size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_168size_t(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s,
  Eurydice_slice out[1U]
);

void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_168size_t_31uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);

void
libcrux_sha3_portable_keccakx1___168size_t_31uint8_t(
  Eurydice_slice data[1U],
  Eurydice_slice out[1U]
);
  */
void libcrux_sha3_portable_shake128(Eurydice_slice digest, Eurydice_slice data);
  /*
extern const size_t libcrux_sha3_generic_keccak__PI[24U];

extern const size_t libcrux_sha3_generic_keccak__ROTC[24U];

libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t
libcrux_sha3_portable___core__clone__Clone_for_libcrux_sha3__portable__KeccakState1___clone(
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *self
);

uint32_t
libcrux_sha3___core__convert__From_libcrux_sha3__Algorithm__for_u32__1__from(
  libcrux_sha3_Algorithm v
);

libcrux_sha3_Algorithm
libcrux_sha3___core__convert__From_u32__for_libcrux_sha3__Algorithm___from(uint32_t v);
  */
  
#if defined(__cplusplus)
}
#endif

#define __libcrux_sha3_H_DEFINED
#endif
