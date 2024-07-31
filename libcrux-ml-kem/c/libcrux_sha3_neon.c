/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: 45b95e0f63cb830202c0b3ca00a341a3451a02ba
 * Eurydice: 58573385962a4c5d09c564f4b32549bad6c6efe9
 * Karamel: 5a2983a0e117205380661087ffa52b16da0c6321
 * F*: b2931dfbe46e839cd757220c63d48c71335bb1ae
 * Libcrux: bf6f43daf933dde5ff5bfe79598132f3433e1b77
 */

#include "libcrux_sha3_neon.h"

#include "internal/libcrux_core.h"

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t zero(void) {
  return libcrux_intrinsics_arm64__vdupq_n_u64(0ULL);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_veor5q_u64(core_core_arch_arm_shared_neon_uint64x2_t a,
            core_core_arch_arm_shared_neon_uint64x2_t b,
            core_core_arch_arm_shared_neon_uint64x2_t c,
            core_core_arch_arm_shared_neon_uint64x2_t d,
            core_core_arch_arm_shared_neon_uint64x2_t e) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  core_core_arch_arm_shared_neon_uint64x2_t cd =
      libcrux_intrinsics_arm64__veorq_u64(c, d);
  core_core_arch_arm_shared_neon_uint64x2_t abcd =
      libcrux_intrinsics_arm64__veorq_u64(ab, cd);
  return libcrux_intrinsics_arm64__veorq_u64(abcd, e);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor5(core_core_arch_arm_shared_neon_uint64x2_t a,
     core_core_arch_arm_shared_neon_uint64x2_t b,
     core_core_arch_arm_shared_neon_uint64x2_t c,
     core_core_arch_arm_shared_neon_uint64x2_t d,
     core_core_arch_arm_shared_neon_uint64x2_t e) {
  return _veor5q_u64(a, b, c, d, e);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___1int32_t_63int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)1, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)63, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vrax1q_u64(core_core_arch_arm_shared_neon_uint64x2_t a,
            core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t uu____0 = a;
  return libcrux_intrinsics_arm64__veorq_u64(
      uu____0, rotate_left___1int32_t_63int32_t(b));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left1_and_xor(core_core_arch_arm_shared_neon_uint64x2_t a,
                     core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vrax1q_u64(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vbcaxq_u64(core_core_arch_arm_shared_neon_uint64x2_t a,
            core_core_arch_arm_shared_neon_uint64x2_t b,
            core_core_arch_arm_shared_neon_uint64x2_t c) {
  return libcrux_intrinsics_arm64__veorq_u64(
      a, libcrux_intrinsics_arm64__vbicq_u64(b, c));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
and_not_xor(core_core_arch_arm_shared_neon_uint64x2_t a,
            core_core_arch_arm_shared_neon_uint64x2_t b,
            core_core_arch_arm_shared_neon_uint64x2_t c) {
  return _vbcaxq_u64(a, b, c);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_veorq_n_u64(core_core_arch_arm_shared_neon_uint64x2_t a, uint64_t c) {
  core_core_arch_arm_shared_neon_uint64x2_t c0 =
      libcrux_intrinsics_arm64__vdupq_n_u64(c);
  return libcrux_intrinsics_arm64__veorq_u64(a, c0);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_constant(core_core_arch_arm_shared_neon_uint64x2_t a, uint64_t c) {
  return _veorq_n_u64(a, c);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor0(core_core_arch_arm_shared_neon_uint64x2_t a,
     core_core_arch_arm_shared_neon_uint64x2_t b) {
  return libcrux_intrinsics_arm64__veorq_u64(a, b);
}

static KRML_MUSTINLINE void slice_2(Eurydice_slice a[2U], size_t start,
                                    size_t len, Eurydice_slice ret[2U]) {
  ret[0U] = Eurydice_slice_subslice2(a[0U], start, start + len, uint8_t,
                                     Eurydice_slice);
  ret[1U] = Eurydice_slice_subslice2(a[1U], start, start + len, uint8_t,
                                     Eurydice_slice);
}

static KRML_MUSTINLINE void slice_n(Eurydice_slice a[2U], size_t start,
                                    size_t len, Eurydice_slice ret[2U]) {
  Eurydice_slice uu____0[2U];
  memcpy(uu____0, a, (size_t)2U * sizeof(Eurydice_slice));
  Eurydice_slice ret0[2U];
  slice_2(uu____0, start, len, ret0);
  memcpy(ret, ret0, (size_t)2U * sizeof(Eurydice_slice));
}

static KRML_MUSTINLINE
    K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
    split_at_mut_2(Eurydice_slice out[2U], size_t mid) {
  Eurydice_slice out0 = out[0U];
  Eurydice_slice out1 = out[1U];
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____0 =
      core_slice___Slice_T___split_at_mut(
          out0, mid, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice out00 = uu____0.fst;
  Eurydice_slice out01 = uu____0.snd;
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at_mut(
          out1, mid, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice out10 = uu____1.fst;
  Eurydice_slice out11 = uu____1.snd;
  K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_ lit;
  lit.fst[0U] = out00;
  lit.fst[1U] = out10;
  lit.snd[0U] = out01;
  lit.snd[1U] = out11;
  return lit;
}

static KRML_MUSTINLINE
    K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
    split_at_mut_n(Eurydice_slice a[2U], size_t mid) {
  return split_at_mut_2(a, mid);
}

static KRML_MUSTINLINE
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
    new__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(void) {
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
      lit;
  lit.st[0U][0U] = zero();
  lit.st[0U][1U] = zero();
  lit.st[0U][2U] = zero();
  lit.st[0U][3U] = zero();
  lit.st[0U][4U] = zero();
  lit.st[1U][0U] = zero();
  lit.st[1U][1U] = zero();
  lit.st[1U][2U] = zero();
  lit.st[1U][3U] = zero();
  lit.st[1U][4U] = zero();
  lit.st[2U][0U] = zero();
  lit.st[2U][1U] = zero();
  lit.st[2U][2U] = zero();
  lit.st[2U][3U] = zero();
  lit.st[2U][4U] = zero();
  lit.st[3U][0U] = zero();
  lit.st[3U][1U] = zero();
  lit.st[3U][2U] = zero();
  lit.st[3U][3U] = zero();
  lit.st[3U][4U] = zero();
  lit.st[4U][0U] = zero();
  lit.st[4U][1U] = zero();
  lit.st[4U][2U] = zero();
  lit.st[4U][3U] = zero();
  lit.st[4U][4U] = zero();
  return lit;
}

static KRML_MUSTINLINE void load_block___72size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    Eurydice_slice blocks[2U]) {
  for (size_t i = (size_t)0U; i < (size_t)72U / (size_t)16U; i++) {
    size_t i0 = i;
    core_core_arch_arm_shared_neon_uint64x2_t v0 =
        libcrux_intrinsics_arm64__vld1q_bytes_u64(Eurydice_slice_subslice2(
            blocks[0U], (size_t)16U * i0, (size_t)16U * (i0 + (size_t)1U),
            uint8_t, Eurydice_slice));
    core_core_arch_arm_shared_neon_uint64x2_t v1 =
        libcrux_intrinsics_arm64__vld1q_bytes_u64(Eurydice_slice_subslice2(
            blocks[1U], (size_t)16U * i0, (size_t)16U * (i0 + (size_t)1U),
            uint8_t, Eurydice_slice));
    s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U] =
        libcrux_intrinsics_arm64__veorq_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            libcrux_intrinsics_arm64__vtrn1q_u64(v0, v1));
    s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
     [((size_t)2U * i0 + (size_t)1U) % (size_t)5U] =
         libcrux_intrinsics_arm64__veorq_u64(
             s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
              [((size_t)2U * i0 + (size_t)1U) % (size_t)5U],
             libcrux_intrinsics_arm64__vtrn2q_u64(v0, v1));
  }
  if ((size_t)72U % (size_t)16U != (size_t)0U) {
    size_t i = ((size_t)72U / (size_t)8U - (size_t)1U) / (size_t)5U;
    size_t j = ((size_t)72U / (size_t)8U - (size_t)1U) % (size_t)5U;
    uint64_t u[2U] = {0U};
    uint8_t uu____0[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst0;
    Eurydice_slice_to_array2(
        &dst0,
        Eurydice_slice_subslice2(blocks[0U], (size_t)72U - (size_t)8U,
                                 (size_t)72U, uint8_t, Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst0, uu____0);
    u[0U] = core_num__u64_9__from_le_bytes(uu____0);
    uint8_t uu____1[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst;
    Eurydice_slice_to_array2(
        &dst,
        Eurydice_slice_subslice2(blocks[1U], (size_t)72U - (size_t)8U,
                                 (size_t)72U, uint8_t, Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst, uu____1);
    u[1U] = core_num__u64_9__from_le_bytes(uu____1);
    core_core_arch_arm_shared_neon_uint64x2_t uvec =
        libcrux_intrinsics_arm64__vld1q_u64(
            Eurydice_array_to_slice((size_t)2U, u, uint64_t, Eurydice_slice));
    s[i][j] = libcrux_intrinsics_arm64__veorq_u64(s[i][j], uvec);
  }
}

static KRML_MUSTINLINE void load_block___72size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], Eurydice_slice b[2U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = a;
  Eurydice_slice uu____1[2U];
  memcpy(uu____1, b, (size_t)2U * sizeof(Eurydice_slice));
  load_block___72size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___36int32_t_28int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)36, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)28, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___36int32_t_28int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___36int32_t_28int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___36int32_t_28int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___36int32_t_28int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___3int32_t_61int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)3, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)61, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___3int32_t_61int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___3int32_t_61int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___3int32_t_61int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___3int32_t_61int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___41int32_t_23int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)41, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)23, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___41int32_t_23int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___41int32_t_23int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___41int32_t_23int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___41int32_t_23int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___18int32_t_46int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)18, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)46, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___18int32_t_46int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___18int32_t_46int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___18int32_t_46int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___18int32_t_46int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___1int32_t_63int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___1int32_t_63int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___1int32_t_63int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___1int32_t_63int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___44int32_t_20int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)44, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)20, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___44int32_t_20int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___44int32_t_20int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___44int32_t_20int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___44int32_t_20int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___10int32_t_54int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)10, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)54, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___10int32_t_54int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___10int32_t_54int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___10int32_t_54int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___10int32_t_54int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___45int32_t_19int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)45, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)19, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___45int32_t_19int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___45int32_t_19int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___45int32_t_19int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___45int32_t_19int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___2int32_t_62int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)2, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)62, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___2int32_t_62int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___2int32_t_62int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___2int32_t_62int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___2int32_t_62int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___62int32_t_2int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)62, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)2, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___62int32_t_2int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___62int32_t_2int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___62int32_t_2int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___62int32_t_2int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___6int32_t_58int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)6, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)58, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___6int32_t_58int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___6int32_t_58int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___6int32_t_58int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___6int32_t_58int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___43int32_t_21int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)43, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)21, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___43int32_t_21int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___43int32_t_21int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___43int32_t_21int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___43int32_t_21int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___15int32_t_49int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)15, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)49, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___15int32_t_49int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___15int32_t_49int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___15int32_t_49int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___15int32_t_49int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___61int32_t_3int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)61, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)3, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___61int32_t_3int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___61int32_t_3int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___61int32_t_3int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___61int32_t_3int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___28int32_t_36int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)28, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)36, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___28int32_t_36int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___28int32_t_36int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___28int32_t_36int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___28int32_t_36int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___55int32_t_9int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)55, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)9, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___55int32_t_9int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___55int32_t_9int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___55int32_t_9int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___55int32_t_9int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___25int32_t_39int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)25, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)39, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___25int32_t_39int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___25int32_t_39int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___25int32_t_39int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___25int32_t_39int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___21int32_t_43int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)21, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)43, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___21int32_t_43int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___21int32_t_43int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___21int32_t_43int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___21int32_t_43int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___56int32_t_8int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)56, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)8, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___56int32_t_8int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___56int32_t_8int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___56int32_t_8int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___56int32_t_8int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___27int32_t_37int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)27, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)37, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___27int32_t_37int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___27int32_t_37int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___27int32_t_37int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___27int32_t_37int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___20int32_t_44int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)20, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)44, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___20int32_t_44int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___20int32_t_44int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___20int32_t_44int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___20int32_t_44int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___39int32_t_25int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)39, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)25, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___39int32_t_25int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___39int32_t_25int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___39int32_t_25int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___39int32_t_25int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___8int32_t_56int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)8, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)56, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___8int32_t_56int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___8int32_t_56int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___8int32_t_56int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___8int32_t_56int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
rotate_left___14int32_t_50int32_t(core_core_arch_arm_shared_neon_uint64x2_t x) {
  return libcrux_intrinsics_arm64__veorq_u64(
      libcrux_intrinsics_arm64__vshlq_n_u64(
          (int32_t)14, x, core_core_arch_arm_shared_neon_uint64x2_t),
      libcrux_intrinsics_arm64__vshrq_n_u64(
          (int32_t)50, x, core_core_arch_arm_shared_neon_uint64x2_t));
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
_vxarq_u64___14int32_t_50int32_t(core_core_arch_arm_shared_neon_uint64x2_t a,
                                 core_core_arch_arm_shared_neon_uint64x2_t b) {
  core_core_arch_arm_shared_neon_uint64x2_t ab =
      libcrux_intrinsics_arm64__veorq_u64(a, b);
  return rotate_left___14int32_t_50int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_arm_shared_neon_uint64x2_t
xor_and_rotate___14int32_t_50int32_t(
    core_core_arch_arm_shared_neon_uint64x2_t a,
    core_core_arch_arm_shared_neon_uint64x2_t b) {
  return _vxarq_u64___14int32_t_50int32_t(a, b);
}

static KRML_MUSTINLINE void
theta_rho__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s) {
  core_core_arch_arm_shared_neon_uint64x2_t c[5U] = {
      xor5(s->st[0U][0U], s->st[1U][0U], s->st[2U][0U], s->st[3U][0U],
           s->st[4U][0U]),
      xor5(s->st[0U][1U], s->st[1U][1U], s->st[2U][1U], s->st[3U][1U],
           s->st[4U][1U]),
      xor5(s->st[0U][2U], s->st[1U][2U], s->st[2U][2U], s->st[3U][2U],
           s->st[4U][2U]),
      xor5(s->st[0U][3U], s->st[1U][3U], s->st[2U][3U], s->st[3U][3U],
           s->st[4U][3U]),
      xor5(s->st[0U][4U], s->st[1U][4U], s->st[2U][4U], s->st[3U][4U],
           s->st[4U][4U])};
  core_core_arch_arm_shared_neon_uint64x2_t uu____0 =
      rotate_left1_and_xor(c[((size_t)0U + (size_t)4U) % (size_t)5U],
                           c[((size_t)0U + (size_t)1U) % (size_t)5U]);
  core_core_arch_arm_shared_neon_uint64x2_t uu____1 =
      rotate_left1_and_xor(c[((size_t)1U + (size_t)4U) % (size_t)5U],
                           c[((size_t)1U + (size_t)1U) % (size_t)5U]);
  core_core_arch_arm_shared_neon_uint64x2_t uu____2 =
      rotate_left1_and_xor(c[((size_t)2U + (size_t)4U) % (size_t)5U],
                           c[((size_t)2U + (size_t)1U) % (size_t)5U]);
  core_core_arch_arm_shared_neon_uint64x2_t uu____3 =
      rotate_left1_and_xor(c[((size_t)3U + (size_t)4U) % (size_t)5U],
                           c[((size_t)3U + (size_t)1U) % (size_t)5U]);
  core_core_arch_arm_shared_neon_uint64x2_t t[5U] = {
      uu____0, uu____1, uu____2, uu____3,
      rotate_left1_and_xor(c[((size_t)4U + (size_t)4U) % (size_t)5U],
                           c[((size_t)4U + (size_t)1U) % (size_t)5U])};
  s->st[0U][0U] = xor0(s->st[0U][0U], t[0U]);
  core_core_arch_arm_shared_neon_uint64x2_t uu____4 =
      xor_and_rotate___36int32_t_28int32_t(s->st[1U][0U], t[0U]);
  s->st[1U][0U] = uu____4;
  core_core_arch_arm_shared_neon_uint64x2_t uu____5 =
      xor_and_rotate___3int32_t_61int32_t(s->st[2U][0U], t[0U]);
  s->st[2U][0U] = uu____5;
  core_core_arch_arm_shared_neon_uint64x2_t uu____6 =
      xor_and_rotate___41int32_t_23int32_t(s->st[3U][0U], t[0U]);
  s->st[3U][0U] = uu____6;
  core_core_arch_arm_shared_neon_uint64x2_t uu____7 =
      xor_and_rotate___18int32_t_46int32_t(s->st[4U][0U], t[0U]);
  s->st[4U][0U] = uu____7;
  core_core_arch_arm_shared_neon_uint64x2_t uu____8 =
      xor_and_rotate___1int32_t_63int32_t(s->st[0U][1U], t[1U]);
  s->st[0U][1U] = uu____8;
  core_core_arch_arm_shared_neon_uint64x2_t uu____9 =
      xor_and_rotate___44int32_t_20int32_t(s->st[1U][1U], t[1U]);
  s->st[1U][1U] = uu____9;
  core_core_arch_arm_shared_neon_uint64x2_t uu____10 =
      xor_and_rotate___10int32_t_54int32_t(s->st[2U][1U], t[1U]);
  s->st[2U][1U] = uu____10;
  core_core_arch_arm_shared_neon_uint64x2_t uu____11 =
      xor_and_rotate___45int32_t_19int32_t(s->st[3U][1U], t[1U]);
  s->st[3U][1U] = uu____11;
  core_core_arch_arm_shared_neon_uint64x2_t uu____12 =
      xor_and_rotate___2int32_t_62int32_t(s->st[4U][1U], t[1U]);
  s->st[4U][1U] = uu____12;
  core_core_arch_arm_shared_neon_uint64x2_t uu____13 =
      xor_and_rotate___62int32_t_2int32_t(s->st[0U][2U], t[2U]);
  s->st[0U][2U] = uu____13;
  core_core_arch_arm_shared_neon_uint64x2_t uu____14 =
      xor_and_rotate___6int32_t_58int32_t(s->st[1U][2U], t[2U]);
  s->st[1U][2U] = uu____14;
  core_core_arch_arm_shared_neon_uint64x2_t uu____15 =
      xor_and_rotate___43int32_t_21int32_t(s->st[2U][2U], t[2U]);
  s->st[2U][2U] = uu____15;
  core_core_arch_arm_shared_neon_uint64x2_t uu____16 =
      xor_and_rotate___15int32_t_49int32_t(s->st[3U][2U], t[2U]);
  s->st[3U][2U] = uu____16;
  core_core_arch_arm_shared_neon_uint64x2_t uu____17 =
      xor_and_rotate___61int32_t_3int32_t(s->st[4U][2U], t[2U]);
  s->st[4U][2U] = uu____17;
  core_core_arch_arm_shared_neon_uint64x2_t uu____18 =
      xor_and_rotate___28int32_t_36int32_t(s->st[0U][3U], t[3U]);
  s->st[0U][3U] = uu____18;
  core_core_arch_arm_shared_neon_uint64x2_t uu____19 =
      xor_and_rotate___55int32_t_9int32_t(s->st[1U][3U], t[3U]);
  s->st[1U][3U] = uu____19;
  core_core_arch_arm_shared_neon_uint64x2_t uu____20 =
      xor_and_rotate___25int32_t_39int32_t(s->st[2U][3U], t[3U]);
  s->st[2U][3U] = uu____20;
  core_core_arch_arm_shared_neon_uint64x2_t uu____21 =
      xor_and_rotate___21int32_t_43int32_t(s->st[3U][3U], t[3U]);
  s->st[3U][3U] = uu____21;
  core_core_arch_arm_shared_neon_uint64x2_t uu____22 =
      xor_and_rotate___56int32_t_8int32_t(s->st[4U][3U], t[3U]);
  s->st[4U][3U] = uu____22;
  core_core_arch_arm_shared_neon_uint64x2_t uu____23 =
      xor_and_rotate___27int32_t_37int32_t(s->st[0U][4U], t[4U]);
  s->st[0U][4U] = uu____23;
  core_core_arch_arm_shared_neon_uint64x2_t uu____24 =
      xor_and_rotate___20int32_t_44int32_t(s->st[1U][4U], t[4U]);
  s->st[1U][4U] = uu____24;
  core_core_arch_arm_shared_neon_uint64x2_t uu____25 =
      xor_and_rotate___39int32_t_25int32_t(s->st[2U][4U], t[4U]);
  s->st[2U][4U] = uu____25;
  core_core_arch_arm_shared_neon_uint64x2_t uu____26 =
      xor_and_rotate___8int32_t_56int32_t(s->st[3U][4U], t[4U]);
  s->st[3U][4U] = uu____26;
  core_core_arch_arm_shared_neon_uint64x2_t uu____27 =
      xor_and_rotate___14int32_t_50int32_t(s->st[4U][4U], t[4U]);
  s->st[4U][4U] = uu____27;
}

static KRML_MUSTINLINE void
pi__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s) {
  core_core_arch_arm_shared_neon_uint64x2_t old[5U][5U];
  memcpy(old, s->st,
         (size_t)5U * sizeof(core_core_arch_arm_shared_neon_uint64x2_t[5U]));
  s->st[0U][1U] = old[1U][1U];
  s->st[0U][2U] = old[2U][2U];
  s->st[0U][3U] = old[3U][3U];
  s->st[0U][4U] = old[4U][4U];
  s->st[1U][0U] = old[0U][3U];
  s->st[1U][1U] = old[1U][4U];
  s->st[1U][2U] = old[2U][0U];
  s->st[1U][3U] = old[3U][1U];
  s->st[1U][4U] = old[4U][2U];
  s->st[2U][0U] = old[0U][1U];
  s->st[2U][1U] = old[1U][2U];
  s->st[2U][2U] = old[2U][3U];
  s->st[2U][3U] = old[3U][4U];
  s->st[2U][4U] = old[4U][0U];
  s->st[3U][0U] = old[0U][4U];
  s->st[3U][1U] = old[1U][0U];
  s->st[3U][2U] = old[2U][1U];
  s->st[3U][3U] = old[3U][2U];
  s->st[3U][4U] = old[4U][3U];
  s->st[4U][0U] = old[0U][2U];
  s->st[4U][1U] = old[1U][3U];
  s->st[4U][2U] = old[2U][4U];
  s->st[4U][3U] = old[3U][0U];
  s->st[4U][4U] = old[4U][1U];
}

static KRML_MUSTINLINE void
chi__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s) {
  core_core_arch_arm_shared_neon_uint64x2_t old[5U][5U];
  memcpy(old, s->st,
         (size_t)5U * sizeof(core_core_arch_arm_shared_neon_uint64x2_t[5U]));
  KRML_MAYBE_FOR5(
      i0, (size_t)0U, (size_t)5U, (size_t)1U, size_t i1 = i0;
      KRML_MAYBE_FOR5(i, (size_t)0U, (size_t)5U, (size_t)1U, size_t j = i;
                      s->st[i1][j] = and_not_xor(
                          s->st[i1][j], old[i1][(j + (size_t)2U) % (size_t)5U],
                          old[i1][(j + (size_t)1U) % (size_t)5U]);););
}

static KRML_MUSTINLINE void
iota__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    size_t i) {
  s->st[0U][0U] = xor_constant(s->st[0U][0U],
                               libcrux_sha3_generic_keccak_ROUNDCONSTANTS[i]);
}

static KRML_MUSTINLINE void
keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s) {
  for (size_t i = (size_t)0U; i < (size_t)24U; i++) {
    size_t i0 = i;
    theta_rho__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
    pi__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
    chi__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
    iota__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s, i0);
  }
}

static KRML_MUSTINLINE void
absorb_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice blocks[2U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = s->st;
  Eurydice_slice uu____1[2U];
  memcpy(uu____1, blocks, (size_t)2U * sizeof(Eurydice_slice));
  load_block___72size_t0(uu____0, uu____1);
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
}

static KRML_MUSTINLINE void load_block_full___72size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    uint8_t blocks[2U][200U]) {
  Eurydice_slice buf[2U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice),
                            Eurydice_array_to_slice((size_t)200U, blocks[1U],
                                                    uint8_t, Eurydice_slice)};
  load_block___72size_t(s, buf);
}

static KRML_MUSTINLINE void load_block_full___72size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], uint8_t b[2U][200U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = a;
  uint8_t uu____1[2U][200U];
  memcpy(uu____1, b, (size_t)2U * sizeof(uint8_t[200U]));
  load_block_full___72size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t_6uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice last[2U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[2U][200U] = {{0U}};
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      if (last_len > (size_t)0U) {
        Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
            blocks[i0], (size_t)0U, last_len, uint8_t, Eurydice_slice);
        core_slice___Slice_T___copy_from_slice(uu____0, last[i0], uint8_t,
                                               void *);
      } blocks[i0][last_len] = 6U;
      size_t uu____1 = i0; size_t uu____2 = (size_t)72U - (size_t)1U;
      blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;);
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[2U][200U];
  memcpy(uu____4, blocks, (size_t)2U * sizeof(uint8_t[200U]));
  load_block_full___72size_t0(uu____3, uu____4);
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
}

static KRML_MUSTINLINE void store_block___72size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    Eurydice_slice out[2U]) {
  for (size_t i = (size_t)0U; i < (size_t)72U / (size_t)16U; i++) {
    size_t i0 = i;
    core_core_arch_arm_shared_neon_uint64x2_t v0 =
        libcrux_intrinsics_arm64__vtrn1q_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)2U * i0 + (size_t)1U) % (size_t)5U]);
    core_core_arch_arm_shared_neon_uint64x2_t v1 =
        libcrux_intrinsics_arm64__vtrn2q_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)2U * i0 + (size_t)1U) % (size_t)5U]);
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_slice_subslice2(out[0U], (size_t)16U * i0,
                                 (size_t)16U * (i0 + (size_t)1U), uint8_t,
                                 Eurydice_slice),
        v0);
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_slice_subslice2(out[1U], (size_t)16U * i0,
                                 (size_t)16U * (i0 + (size_t)1U), uint8_t,
                                 Eurydice_slice),
        v1);
  }
  if ((size_t)72U % (size_t)16U != (size_t)0U) {
    size_t i = ((size_t)72U / (size_t)8U - (size_t)1U) / (size_t)5U;
    size_t j = ((size_t)72U / (size_t)8U - (size_t)1U) % (size_t)5U;
    uint8_t u[16U] = {0U};
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_array_to_slice((size_t)16U, u, uint8_t, Eurydice_slice),
        s[i][j]);
    Eurydice_slice uu____0 =
        Eurydice_slice_subslice2(out[0U], (size_t)72U - (size_t)8U, (size_t)72U,
                                 uint8_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice2(u, (size_t)0U, (size_t)8U, uint8_t,
                                    Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____1 =
        Eurydice_slice_subslice2(out[1U], (size_t)72U - (size_t)8U, (size_t)72U,
                                 uint8_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____1,
        Eurydice_array_to_subslice2(u, (size_t)8U, (size_t)16U, uint8_t,
                                    Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void store_block_full___72size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U], uint8_t ret[2U][200U]) {
  uint8_t out0[200U] = {0U};
  uint8_t out1[200U] = {0U};
  Eurydice_slice buf[2U] = {
      Eurydice_array_to_slice((size_t)200U, out0, uint8_t, Eurydice_slice),
      Eurydice_array_to_slice((size_t)200U, out1, uint8_t, Eurydice_slice)};
  store_block___72size_t(s, buf);
  uint8_t uu____0[200U];
  memcpy(uu____0, out0, (size_t)200U * sizeof(uint8_t));
  uint8_t uu____1[200U];
  memcpy(uu____1, out1, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[0U], uu____0, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[1U], uu____1, (size_t)200U * sizeof(uint8_t));
}

static KRML_MUSTINLINE void store_block_full___72size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], uint8_t ret[2U][200U]) {
  store_block_full___72size_t(a, ret);
}

static KRML_MUSTINLINE void
squeeze_first_and_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  uint8_t b[2U][200U];
  store_block_full___72size_t0(s->st, b);
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      Eurydice_slice uu____0 = out[i0]; uint8_t *uu____1 = b[i0];
      core_ops_range_Range__size_t lit; lit.start = (size_t)0U;
      lit.end = core_slice___Slice_T___len(out[i0], uint8_t, size_t);
      core_slice___Slice_T___copy_from_slice(
          uu____0,
          Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                     core_ops_range_Range__size_t,
                                     Eurydice_slice),
          uint8_t, void *););
}

static KRML_MUSTINLINE void store_block___72size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], Eurydice_slice b[2U]) {
  store_block___72size_t(a, b);
}

static KRML_MUSTINLINE void
squeeze_first_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  store_block___72size_t0(s->st, out);
}

static KRML_MUSTINLINE void
squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
  store_block___72size_t0(s->st, out);
}

static KRML_MUSTINLINE void
squeeze_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        s,
    Eurydice_slice out[2U]) {
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(&s);
  uint8_t b[2U][200U];
  store_block_full___72size_t0(s.st, b);
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      Eurydice_slice uu____0 = out[i0]; uint8_t *uu____1 = b[i0];
      core_ops_range_Range__size_t lit; lit.start = (size_t)0U;
      lit.end = core_slice___Slice_T___len(out[i0], uint8_t, size_t);
      core_slice___Slice_T___copy_from_slice(
          uu____0,
          Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                     core_ops_range_Range__size_t,
                                     Eurydice_slice),
          uint8_t, void *););
}

static KRML_MUSTINLINE void
keccak__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t_6uint8_t(
    Eurydice_slice data[2U], Eurydice_slice out[2U]) {
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
      s = new__core_core_arch_arm_shared_neon_uint64x2_t_2size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)72U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *uu____0 = &s;
    Eurydice_slice uu____1[2U];
    memcpy(uu____1, data, (size_t)2U * sizeof(Eurydice_slice));
    Eurydice_slice ret[2U];
    slice_n(uu____1, i0 * (size_t)72U, (size_t)72U, ret);
    absorb_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t(
        uu____0, ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)72U;
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
      *uu____2 = &s;
  Eurydice_slice uu____3[2U];
  memcpy(uu____3, data, (size_t)2U * sizeof(Eurydice_slice));
  Eurydice_slice ret[2U];
  slice_n(uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem,
          rem, ret);
  absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t_6uint8_t(
      uu____2, ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)72U;
  size_t last = outlen - outlen % (size_t)72U;
  if (blocks == (size_t)0U) {
    squeeze_first_and_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t(
        &s, out);
  } else {
    K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
        uu____4 = split_at_mut_n(out, (size_t)72U);
    Eurydice_slice o0[2U];
    memcpy(o0, uu____4.fst, (size_t)2U * sizeof(Eurydice_slice));
    Eurydice_slice o1[2U];
    memcpy(o1, uu____4.snd, (size_t)2U * sizeof(Eurydice_slice));
    squeeze_first_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t(
        &s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
            uu____5 = split_at_mut_n(o1, (size_t)72U);
        Eurydice_slice o[2U];
        memcpy(o, uu____5.fst, (size_t)2U * sizeof(Eurydice_slice));
        Eurydice_slice orest[2U];
        memcpy(orest, uu____5.snd, (size_t)2U * sizeof(Eurydice_slice));
        squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t(
            &s, o);
        memcpy(o1, orest, (size_t)2U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      squeeze_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t(
          s, o1);
    }
  }
}

static KRML_MUSTINLINE void keccakx2___72size_t_6uint8_t(
    Eurydice_slice data[2U], Eurydice_slice out[2U]) {
  Eurydice_slice uu____0[2U];
  memcpy(uu____0, data, (size_t)2U * sizeof(Eurydice_slice));
  keccak__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_72size_t_6uint8_t(
      uu____0, out);
}

void libcrux_sha3_neon_sha512(Eurydice_slice digest, Eurydice_slice data) {
  uint8_t dummy[64U] = {0U};
  Eurydice_slice uu____0[2U] = {data, data};
  Eurydice_slice buf[2U] = {
      digest,
      Eurydice_array_to_slice((size_t)64U, dummy, uint8_t, Eurydice_slice)};
  keccakx2___72size_t_6uint8_t(uu____0, buf);
}

static KRML_MUSTINLINE void load_block___136size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    Eurydice_slice blocks[2U]) {
  for (size_t i = (size_t)0U; i < (size_t)136U / (size_t)16U; i++) {
    size_t i0 = i;
    core_core_arch_arm_shared_neon_uint64x2_t v0 =
        libcrux_intrinsics_arm64__vld1q_bytes_u64(Eurydice_slice_subslice2(
            blocks[0U], (size_t)16U * i0, (size_t)16U * (i0 + (size_t)1U),
            uint8_t, Eurydice_slice));
    core_core_arch_arm_shared_neon_uint64x2_t v1 =
        libcrux_intrinsics_arm64__vld1q_bytes_u64(Eurydice_slice_subslice2(
            blocks[1U], (size_t)16U * i0, (size_t)16U * (i0 + (size_t)1U),
            uint8_t, Eurydice_slice));
    s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U] =
        libcrux_intrinsics_arm64__veorq_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            libcrux_intrinsics_arm64__vtrn1q_u64(v0, v1));
    s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
     [((size_t)2U * i0 + (size_t)1U) % (size_t)5U] =
         libcrux_intrinsics_arm64__veorq_u64(
             s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
              [((size_t)2U * i0 + (size_t)1U) % (size_t)5U],
             libcrux_intrinsics_arm64__vtrn2q_u64(v0, v1));
  }
  if ((size_t)136U % (size_t)16U != (size_t)0U) {
    size_t i = ((size_t)136U / (size_t)8U - (size_t)1U) / (size_t)5U;
    size_t j = ((size_t)136U / (size_t)8U - (size_t)1U) % (size_t)5U;
    uint64_t u[2U] = {0U};
    uint8_t uu____0[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst0;
    Eurydice_slice_to_array2(
        &dst0,
        Eurydice_slice_subslice2(blocks[0U], (size_t)136U - (size_t)8U,
                                 (size_t)136U, uint8_t, Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst0, uu____0);
    u[0U] = core_num__u64_9__from_le_bytes(uu____0);
    uint8_t uu____1[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst;
    Eurydice_slice_to_array2(
        &dst,
        Eurydice_slice_subslice2(blocks[1U], (size_t)136U - (size_t)8U,
                                 (size_t)136U, uint8_t, Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst, uu____1);
    u[1U] = core_num__u64_9__from_le_bytes(uu____1);
    core_core_arch_arm_shared_neon_uint64x2_t uvec =
        libcrux_intrinsics_arm64__vld1q_u64(
            Eurydice_array_to_slice((size_t)2U, u, uint64_t, Eurydice_slice));
    s[i][j] = libcrux_intrinsics_arm64__veorq_u64(s[i][j], uvec);
  }
}

static KRML_MUSTINLINE void load_block___136size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], Eurydice_slice b[2U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = a;
  Eurydice_slice uu____1[2U];
  memcpy(uu____1, b, (size_t)2U * sizeof(Eurydice_slice));
  load_block___136size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
absorb_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice blocks[2U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = s->st;
  Eurydice_slice uu____1[2U];
  memcpy(uu____1, blocks, (size_t)2U * sizeof(Eurydice_slice));
  load_block___136size_t0(uu____0, uu____1);
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
}

static KRML_MUSTINLINE void load_block_full___136size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    uint8_t blocks[2U][200U]) {
  Eurydice_slice buf[2U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice),
                            Eurydice_array_to_slice((size_t)200U, blocks[1U],
                                                    uint8_t, Eurydice_slice)};
  load_block___136size_t(s, buf);
}

static KRML_MUSTINLINE void load_block_full___136size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], uint8_t b[2U][200U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = a;
  uint8_t uu____1[2U][200U];
  memcpy(uu____1, b, (size_t)2U * sizeof(uint8_t[200U]));
  load_block_full___136size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t_6uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice last[2U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[2U][200U] = {{0U}};
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      if (last_len > (size_t)0U) {
        Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
            blocks[i0], (size_t)0U, last_len, uint8_t, Eurydice_slice);
        core_slice___Slice_T___copy_from_slice(uu____0, last[i0], uint8_t,
                                               void *);
      } blocks[i0][last_len] = 6U;
      size_t uu____1 = i0; size_t uu____2 = (size_t)136U - (size_t)1U;
      blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;);
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[2U][200U];
  memcpy(uu____4, blocks, (size_t)2U * sizeof(uint8_t[200U]));
  load_block_full___136size_t0(uu____3, uu____4);
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
}

static KRML_MUSTINLINE void store_block___136size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    Eurydice_slice out[2U]) {
  for (size_t i = (size_t)0U; i < (size_t)136U / (size_t)16U; i++) {
    size_t i0 = i;
    core_core_arch_arm_shared_neon_uint64x2_t v0 =
        libcrux_intrinsics_arm64__vtrn1q_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)2U * i0 + (size_t)1U) % (size_t)5U]);
    core_core_arch_arm_shared_neon_uint64x2_t v1 =
        libcrux_intrinsics_arm64__vtrn2q_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)2U * i0 + (size_t)1U) % (size_t)5U]);
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_slice_subslice2(out[0U], (size_t)16U * i0,
                                 (size_t)16U * (i0 + (size_t)1U), uint8_t,
                                 Eurydice_slice),
        v0);
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_slice_subslice2(out[1U], (size_t)16U * i0,
                                 (size_t)16U * (i0 + (size_t)1U), uint8_t,
                                 Eurydice_slice),
        v1);
  }
  if ((size_t)136U % (size_t)16U != (size_t)0U) {
    size_t i = ((size_t)136U / (size_t)8U - (size_t)1U) / (size_t)5U;
    size_t j = ((size_t)136U / (size_t)8U - (size_t)1U) % (size_t)5U;
    uint8_t u[16U] = {0U};
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_array_to_slice((size_t)16U, u, uint8_t, Eurydice_slice),
        s[i][j]);
    Eurydice_slice uu____0 =
        Eurydice_slice_subslice2(out[0U], (size_t)136U - (size_t)8U,
                                 (size_t)136U, uint8_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice2(u, (size_t)0U, (size_t)8U, uint8_t,
                                    Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____1 =
        Eurydice_slice_subslice2(out[1U], (size_t)136U - (size_t)8U,
                                 (size_t)136U, uint8_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____1,
        Eurydice_array_to_subslice2(u, (size_t)8U, (size_t)16U, uint8_t,
                                    Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void store_block_full___136size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U], uint8_t ret[2U][200U]) {
  uint8_t out0[200U] = {0U};
  uint8_t out1[200U] = {0U};
  Eurydice_slice buf[2U] = {
      Eurydice_array_to_slice((size_t)200U, out0, uint8_t, Eurydice_slice),
      Eurydice_array_to_slice((size_t)200U, out1, uint8_t, Eurydice_slice)};
  store_block___136size_t(s, buf);
  uint8_t uu____0[200U];
  memcpy(uu____0, out0, (size_t)200U * sizeof(uint8_t));
  uint8_t uu____1[200U];
  memcpy(uu____1, out1, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[0U], uu____0, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[1U], uu____1, (size_t)200U * sizeof(uint8_t));
}

static KRML_MUSTINLINE void store_block_full___136size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], uint8_t ret[2U][200U]) {
  store_block_full___136size_t(a, ret);
}

static KRML_MUSTINLINE void
squeeze_first_and_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  uint8_t b[2U][200U];
  store_block_full___136size_t0(s->st, b);
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      Eurydice_slice uu____0 = out[i0]; uint8_t *uu____1 = b[i0];
      core_ops_range_Range__size_t lit; lit.start = (size_t)0U;
      lit.end = core_slice___Slice_T___len(out[i0], uint8_t, size_t);
      core_slice___Slice_T___copy_from_slice(
          uu____0,
          Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                     core_ops_range_Range__size_t,
                                     Eurydice_slice),
          uint8_t, void *););
}

static KRML_MUSTINLINE void store_block___136size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], Eurydice_slice b[2U]) {
  store_block___136size_t(a, b);
}

static KRML_MUSTINLINE void
squeeze_first_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  store_block___136size_t0(s->st, out);
}

static KRML_MUSTINLINE void
squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
  store_block___136size_t0(s->st, out);
}

static KRML_MUSTINLINE void
squeeze_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        s,
    Eurydice_slice out[2U]) {
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(&s);
  uint8_t b[2U][200U];
  store_block_full___136size_t0(s.st, b);
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      Eurydice_slice uu____0 = out[i0]; uint8_t *uu____1 = b[i0];
      core_ops_range_Range__size_t lit; lit.start = (size_t)0U;
      lit.end = core_slice___Slice_T___len(out[i0], uint8_t, size_t);
      core_slice___Slice_T___copy_from_slice(
          uu____0,
          Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                     core_ops_range_Range__size_t,
                                     Eurydice_slice),
          uint8_t, void *););
}

static KRML_MUSTINLINE void
keccak__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t_6uint8_t(
    Eurydice_slice data[2U], Eurydice_slice out[2U]) {
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
      s = new__core_core_arch_arm_shared_neon_uint64x2_t_2size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)136U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *uu____0 = &s;
    Eurydice_slice uu____1[2U];
    memcpy(uu____1, data, (size_t)2U * sizeof(Eurydice_slice));
    Eurydice_slice ret[2U];
    slice_n(uu____1, i0 * (size_t)136U, (size_t)136U, ret);
    absorb_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
        uu____0, ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)136U;
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
      *uu____2 = &s;
  Eurydice_slice uu____3[2U];
  memcpy(uu____3, data, (size_t)2U * sizeof(Eurydice_slice));
  Eurydice_slice ret[2U];
  slice_n(uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem,
          rem, ret);
  absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t_6uint8_t(
      uu____2, ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)136U;
  size_t last = outlen - outlen % (size_t)136U;
  if (blocks == (size_t)0U) {
    squeeze_first_and_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
        &s, out);
  } else {
    K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
        uu____4 = split_at_mut_n(out, (size_t)136U);
    Eurydice_slice o0[2U];
    memcpy(o0, uu____4.fst, (size_t)2U * sizeof(Eurydice_slice));
    Eurydice_slice o1[2U];
    memcpy(o1, uu____4.snd, (size_t)2U * sizeof(Eurydice_slice));
    squeeze_first_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
        &s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
            uu____5 = split_at_mut_n(o1, (size_t)136U);
        Eurydice_slice o[2U];
        memcpy(o, uu____5.fst, (size_t)2U * sizeof(Eurydice_slice));
        Eurydice_slice orest[2U];
        memcpy(orest, uu____5.snd, (size_t)2U * sizeof(Eurydice_slice));
        squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
            &s, o);
        memcpy(o1, orest, (size_t)2U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      squeeze_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
          s, o1);
    }
  }
}

static KRML_MUSTINLINE void keccakx2___136size_t_6uint8_t(
    Eurydice_slice data[2U], Eurydice_slice out[2U]) {
  Eurydice_slice uu____0[2U];
  memcpy(uu____0, data, (size_t)2U * sizeof(Eurydice_slice));
  keccak__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t_6uint8_t(
      uu____0, out);
}

void libcrux_sha3_neon_sha256(Eurydice_slice digest, Eurydice_slice data) {
  uint8_t dummy[32U] = {0U};
  Eurydice_slice uu____0[2U] = {data, data};
  Eurydice_slice buf[2U] = {
      digest,
      Eurydice_array_to_slice((size_t)32U, dummy, uint8_t, Eurydice_slice)};
  keccakx2___136size_t_6uint8_t(uu____0, buf);
}

static KRML_MUSTINLINE void
absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t_31uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice last[2U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[2U][200U] = {{0U}};
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      if (last_len > (size_t)0U) {
        Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
            blocks[i0], (size_t)0U, last_len, uint8_t, Eurydice_slice);
        core_slice___Slice_T___copy_from_slice(uu____0, last[i0], uint8_t,
                                               void *);
      } blocks[i0][last_len] = 31U;
      size_t uu____1 = i0; size_t uu____2 = (size_t)136U - (size_t)1U;
      blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;);
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[2U][200U];
  memcpy(uu____4, blocks, (size_t)2U * sizeof(uint8_t[200U]));
  load_block_full___136size_t0(uu____3, uu____4);
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
}

static KRML_MUSTINLINE void
keccak__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t_31uint8_t(
    Eurydice_slice data[2U], Eurydice_slice out[2U]) {
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
      s = new__core_core_arch_arm_shared_neon_uint64x2_t_2size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)136U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *uu____0 = &s;
    Eurydice_slice uu____1[2U];
    memcpy(uu____1, data, (size_t)2U * sizeof(Eurydice_slice));
    Eurydice_slice ret[2U];
    slice_n(uu____1, i0 * (size_t)136U, (size_t)136U, ret);
    absorb_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
        uu____0, ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)136U;
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
      *uu____2 = &s;
  Eurydice_slice uu____3[2U];
  memcpy(uu____3, data, (size_t)2U * sizeof(Eurydice_slice));
  Eurydice_slice ret[2U];
  slice_n(uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem,
          rem, ret);
  absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t_31uint8_t(
      uu____2, ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)136U;
  size_t last = outlen - outlen % (size_t)136U;
  if (blocks == (size_t)0U) {
    squeeze_first_and_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
        &s, out);
  } else {
    K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
        uu____4 = split_at_mut_n(out, (size_t)136U);
    Eurydice_slice o0[2U];
    memcpy(o0, uu____4.fst, (size_t)2U * sizeof(Eurydice_slice));
    Eurydice_slice o1[2U];
    memcpy(o1, uu____4.snd, (size_t)2U * sizeof(Eurydice_slice));
    squeeze_first_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
        &s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
            uu____5 = split_at_mut_n(o1, (size_t)136U);
        Eurydice_slice o[2U];
        memcpy(o, uu____5.fst, (size_t)2U * sizeof(Eurydice_slice));
        Eurydice_slice orest[2U];
        memcpy(orest, uu____5.snd, (size_t)2U * sizeof(Eurydice_slice));
        squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
            &s, o);
        memcpy(o1, orest, (size_t)2U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      squeeze_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t(
          s, o1);
    }
  }
}

static KRML_MUSTINLINE void keccakx2___136size_t_31uint8_t(
    Eurydice_slice data[2U], Eurydice_slice out[2U]) {
  Eurydice_slice uu____0[2U];
  memcpy(uu____0, data, (size_t)2U * sizeof(Eurydice_slice));
  keccak__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_136size_t_31uint8_t(
      uu____0, out);
}

void libcrux_sha3_neon_x2_shake256(Eurydice_slice input0, Eurydice_slice input1,
                                   Eurydice_slice out0, Eurydice_slice out1) {
  Eurydice_slice buf0[2U] = {input0, input1};
  Eurydice_slice buf[2U] = {out0, out1};
  keccakx2___136size_t_31uint8_t(buf0, buf);
}

libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
libcrux_sha3_neon_x2_incremental_shake128_init(void) {
  return new__core_core_arch_arm_shared_neon_uint64x2_t_2size_t();
}

static KRML_MUSTINLINE void load_block___168size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    Eurydice_slice blocks[2U]) {
  for (size_t i = (size_t)0U; i < (size_t)168U / (size_t)16U; i++) {
    size_t i0 = i;
    core_core_arch_arm_shared_neon_uint64x2_t v0 =
        libcrux_intrinsics_arm64__vld1q_bytes_u64(Eurydice_slice_subslice2(
            blocks[0U], (size_t)16U * i0, (size_t)16U * (i0 + (size_t)1U),
            uint8_t, Eurydice_slice));
    core_core_arch_arm_shared_neon_uint64x2_t v1 =
        libcrux_intrinsics_arm64__vld1q_bytes_u64(Eurydice_slice_subslice2(
            blocks[1U], (size_t)16U * i0, (size_t)16U * (i0 + (size_t)1U),
            uint8_t, Eurydice_slice));
    s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U] =
        libcrux_intrinsics_arm64__veorq_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            libcrux_intrinsics_arm64__vtrn1q_u64(v0, v1));
    s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
     [((size_t)2U * i0 + (size_t)1U) % (size_t)5U] =
         libcrux_intrinsics_arm64__veorq_u64(
             s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
              [((size_t)2U * i0 + (size_t)1U) % (size_t)5U],
             libcrux_intrinsics_arm64__vtrn2q_u64(v0, v1));
  }
  if ((size_t)168U % (size_t)16U != (size_t)0U) {
    size_t i = ((size_t)168U / (size_t)8U - (size_t)1U) / (size_t)5U;
    size_t j = ((size_t)168U / (size_t)8U - (size_t)1U) % (size_t)5U;
    uint64_t u[2U] = {0U};
    uint8_t uu____0[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst0;
    Eurydice_slice_to_array2(
        &dst0,
        Eurydice_slice_subslice2(blocks[0U], (size_t)168U - (size_t)8U,
                                 (size_t)168U, uint8_t, Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst0, uu____0);
    u[0U] = core_num__u64_9__from_le_bytes(uu____0);
    uint8_t uu____1[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst;
    Eurydice_slice_to_array2(
        &dst,
        Eurydice_slice_subslice2(blocks[1U], (size_t)168U - (size_t)8U,
                                 (size_t)168U, uint8_t, Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst, uu____1);
    u[1U] = core_num__u64_9__from_le_bytes(uu____1);
    core_core_arch_arm_shared_neon_uint64x2_t uvec =
        libcrux_intrinsics_arm64__vld1q_u64(
            Eurydice_array_to_slice((size_t)2U, u, uint64_t, Eurydice_slice));
    s[i][j] = libcrux_intrinsics_arm64__veorq_u64(s[i][j], uvec);
  }
}

static KRML_MUSTINLINE void load_block_full___168size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    uint8_t blocks[2U][200U]) {
  Eurydice_slice buf[2U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice),
                            Eurydice_array_to_slice((size_t)200U, blocks[1U],
                                                    uint8_t, Eurydice_slice)};
  load_block___168size_t(s, buf);
}

static KRML_MUSTINLINE void load_block_full___168size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], uint8_t b[2U][200U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = a;
  uint8_t uu____1[2U][200U];
  memcpy(uu____1, b, (size_t)2U * sizeof(uint8_t[200U]));
  load_block_full___168size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_168size_t_31uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice last[2U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[2U][200U] = {{0U}};
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      if (last_len > (size_t)0U) {
        Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
            blocks[i0], (size_t)0U, last_len, uint8_t, Eurydice_slice);
        core_slice___Slice_T___copy_from_slice(uu____0, last[i0], uint8_t,
                                               void *);
      } blocks[i0][last_len] = 31U;
      size_t uu____1 = i0; size_t uu____2 = (size_t)168U - (size_t)1U;
      blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;);
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[2U][200U];
  memcpy(uu____4, blocks, (size_t)2U * sizeof(uint8_t[200U]));
  load_block_full___168size_t0(uu____3, uu____4);
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
}

void libcrux_sha3_neon_x2_incremental_shake128_absorb_final(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice data0, Eurydice_slice data1) {
  Eurydice_slice buf[2U] = {data0, data1};
  absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_168size_t_31uint8_t(
      s, buf);
}

static KRML_MUSTINLINE void store_block___168size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    Eurydice_slice out[2U]) {
  for (size_t i = (size_t)0U; i < (size_t)168U / (size_t)16U; i++) {
    size_t i0 = i;
    core_core_arch_arm_shared_neon_uint64x2_t v0 =
        libcrux_intrinsics_arm64__vtrn1q_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)2U * i0 + (size_t)1U) % (size_t)5U]);
    core_core_arch_arm_shared_neon_uint64x2_t v1 =
        libcrux_intrinsics_arm64__vtrn2q_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)2U * i0 + (size_t)1U) % (size_t)5U]);
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_slice_subslice2(out[0U], (size_t)16U * i0,
                                 (size_t)16U * (i0 + (size_t)1U), uint8_t,
                                 Eurydice_slice),
        v0);
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_slice_subslice2(out[1U], (size_t)16U * i0,
                                 (size_t)16U * (i0 + (size_t)1U), uint8_t,
                                 Eurydice_slice),
        v1);
  }
  if ((size_t)168U % (size_t)16U != (size_t)0U) {
    size_t i = ((size_t)168U / (size_t)8U - (size_t)1U) / (size_t)5U;
    size_t j = ((size_t)168U / (size_t)8U - (size_t)1U) % (size_t)5U;
    uint8_t u[16U] = {0U};
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_array_to_slice((size_t)16U, u, uint8_t, Eurydice_slice),
        s[i][j]);
    Eurydice_slice uu____0 =
        Eurydice_slice_subslice2(out[0U], (size_t)168U - (size_t)8U,
                                 (size_t)168U, uint8_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice2(u, (size_t)0U, (size_t)8U, uint8_t,
                                    Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____1 =
        Eurydice_slice_subslice2(out[1U], (size_t)168U - (size_t)8U,
                                 (size_t)168U, uint8_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____1,
        Eurydice_array_to_subslice2(u, (size_t)8U, (size_t)16U, uint8_t,
                                    Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void store_block___168size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], Eurydice_slice b[2U]) {
  store_block___168size_t(a, b);
}

static KRML_MUSTINLINE void
squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_168size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
  store_block___168size_t0(s->st, out);
}

void libcrux_sha3_neon_x2_incremental_shake128_squeeze_next_block(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out0, Eurydice_slice out1) {
  Eurydice_slice buf[2U] = {out0, out1};
  squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_168size_t(
      s, buf);
}

static KRML_MUSTINLINE void
squeeze_first_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_168size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  store_block___168size_t0(s->st, out);
}

static KRML_MUSTINLINE void
squeeze_first_three_blocks__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_168size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_ uu____0 =
      split_at_mut_n(out, (size_t)168U);
  Eurydice_slice o0[2U];
  memcpy(o0, uu____0.fst, (size_t)2U * sizeof(Eurydice_slice));
  Eurydice_slice o10[2U];
  memcpy(o10, uu____0.snd, (size_t)2U * sizeof(Eurydice_slice));
  squeeze_first_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_168size_t(
      s, o0);
  K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_ uu____1 =
      split_at_mut_n(o10, (size_t)168U);
  Eurydice_slice o1[2U];
  memcpy(o1, uu____1.fst, (size_t)2U * sizeof(Eurydice_slice));
  Eurydice_slice o2[2U];
  memcpy(o2, uu____1.snd, (size_t)2U * sizeof(Eurydice_slice));
  squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_168size_t(
      s, o1);
  squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_168size_t(
      s, o2);
}

void libcrux_sha3_neon_x2_incremental_shake128_squeeze_first_three_blocks(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out0, Eurydice_slice out1) {
  Eurydice_slice buf[2U] = {out0, out1};
  squeeze_first_three_blocks__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_168size_t(
      s, buf);
}

static KRML_MUSTINLINE void load_block___144size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    Eurydice_slice blocks[2U]) {
  for (size_t i = (size_t)0U; i < (size_t)144U / (size_t)16U; i++) {
    size_t i0 = i;
    core_core_arch_arm_shared_neon_uint64x2_t v0 =
        libcrux_intrinsics_arm64__vld1q_bytes_u64(Eurydice_slice_subslice2(
            blocks[0U], (size_t)16U * i0, (size_t)16U * (i0 + (size_t)1U),
            uint8_t, Eurydice_slice));
    core_core_arch_arm_shared_neon_uint64x2_t v1 =
        libcrux_intrinsics_arm64__vld1q_bytes_u64(Eurydice_slice_subslice2(
            blocks[1U], (size_t)16U * i0, (size_t)16U * (i0 + (size_t)1U),
            uint8_t, Eurydice_slice));
    s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U] =
        libcrux_intrinsics_arm64__veorq_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            libcrux_intrinsics_arm64__vtrn1q_u64(v0, v1));
    s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
     [((size_t)2U * i0 + (size_t)1U) % (size_t)5U] =
         libcrux_intrinsics_arm64__veorq_u64(
             s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
              [((size_t)2U * i0 + (size_t)1U) % (size_t)5U],
             libcrux_intrinsics_arm64__vtrn2q_u64(v0, v1));
  }
  if ((size_t)144U % (size_t)16U != (size_t)0U) {
    size_t i = ((size_t)144U / (size_t)8U - (size_t)1U) / (size_t)5U;
    size_t j = ((size_t)144U / (size_t)8U - (size_t)1U) % (size_t)5U;
    uint64_t u[2U] = {0U};
    uint8_t uu____0[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst0;
    Eurydice_slice_to_array2(
        &dst0,
        Eurydice_slice_subslice2(blocks[0U], (size_t)144U - (size_t)8U,
                                 (size_t)144U, uint8_t, Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst0, uu____0);
    u[0U] = core_num__u64_9__from_le_bytes(uu____0);
    uint8_t uu____1[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst;
    Eurydice_slice_to_array2(
        &dst,
        Eurydice_slice_subslice2(blocks[1U], (size_t)144U - (size_t)8U,
                                 (size_t)144U, uint8_t, Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst, uu____1);
    u[1U] = core_num__u64_9__from_le_bytes(uu____1);
    core_core_arch_arm_shared_neon_uint64x2_t uvec =
        libcrux_intrinsics_arm64__vld1q_u64(
            Eurydice_array_to_slice((size_t)2U, u, uint64_t, Eurydice_slice));
    s[i][j] = libcrux_intrinsics_arm64__veorq_u64(s[i][j], uvec);
  }
}

static KRML_MUSTINLINE void load_block___144size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], Eurydice_slice b[2U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = a;
  Eurydice_slice uu____1[2U];
  memcpy(uu____1, b, (size_t)2U * sizeof(Eurydice_slice));
  load_block___144size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
absorb_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice blocks[2U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = s->st;
  Eurydice_slice uu____1[2U];
  memcpy(uu____1, blocks, (size_t)2U * sizeof(Eurydice_slice));
  load_block___144size_t0(uu____0, uu____1);
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
}

static KRML_MUSTINLINE void load_block_full___144size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    uint8_t blocks[2U][200U]) {
  Eurydice_slice buf[2U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice),
                            Eurydice_array_to_slice((size_t)200U, blocks[1U],
                                                    uint8_t, Eurydice_slice)};
  load_block___144size_t(s, buf);
}

static KRML_MUSTINLINE void load_block_full___144size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], uint8_t b[2U][200U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = a;
  uint8_t uu____1[2U][200U];
  memcpy(uu____1, b, (size_t)2U * sizeof(uint8_t[200U]));
  load_block_full___144size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t_6uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice last[2U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[2U][200U] = {{0U}};
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      if (last_len > (size_t)0U) {
        Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
            blocks[i0], (size_t)0U, last_len, uint8_t, Eurydice_slice);
        core_slice___Slice_T___copy_from_slice(uu____0, last[i0], uint8_t,
                                               void *);
      } blocks[i0][last_len] = 6U;
      size_t uu____1 = i0; size_t uu____2 = (size_t)144U - (size_t)1U;
      blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;);
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[2U][200U];
  memcpy(uu____4, blocks, (size_t)2U * sizeof(uint8_t[200U]));
  load_block_full___144size_t0(uu____3, uu____4);
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
}

static KRML_MUSTINLINE void store_block___144size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    Eurydice_slice out[2U]) {
  for (size_t i = (size_t)0U; i < (size_t)144U / (size_t)16U; i++) {
    size_t i0 = i;
    core_core_arch_arm_shared_neon_uint64x2_t v0 =
        libcrux_intrinsics_arm64__vtrn1q_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)2U * i0 + (size_t)1U) % (size_t)5U]);
    core_core_arch_arm_shared_neon_uint64x2_t v1 =
        libcrux_intrinsics_arm64__vtrn2q_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)2U * i0 + (size_t)1U) % (size_t)5U]);
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_slice_subslice2(out[0U], (size_t)16U * i0,
                                 (size_t)16U * (i0 + (size_t)1U), uint8_t,
                                 Eurydice_slice),
        v0);
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_slice_subslice2(out[1U], (size_t)16U * i0,
                                 (size_t)16U * (i0 + (size_t)1U), uint8_t,
                                 Eurydice_slice),
        v1);
  }
  if ((size_t)144U % (size_t)16U != (size_t)0U) {
    size_t i = ((size_t)144U / (size_t)8U - (size_t)1U) / (size_t)5U;
    size_t j = ((size_t)144U / (size_t)8U - (size_t)1U) % (size_t)5U;
    uint8_t u[16U] = {0U};
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_array_to_slice((size_t)16U, u, uint8_t, Eurydice_slice),
        s[i][j]);
    Eurydice_slice uu____0 =
        Eurydice_slice_subslice2(out[0U], (size_t)144U - (size_t)8U,
                                 (size_t)144U, uint8_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice2(u, (size_t)0U, (size_t)8U, uint8_t,
                                    Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____1 =
        Eurydice_slice_subslice2(out[1U], (size_t)144U - (size_t)8U,
                                 (size_t)144U, uint8_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____1,
        Eurydice_array_to_subslice2(u, (size_t)8U, (size_t)16U, uint8_t,
                                    Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void store_block_full___144size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U], uint8_t ret[2U][200U]) {
  uint8_t out0[200U] = {0U};
  uint8_t out1[200U] = {0U};
  Eurydice_slice buf[2U] = {
      Eurydice_array_to_slice((size_t)200U, out0, uint8_t, Eurydice_slice),
      Eurydice_array_to_slice((size_t)200U, out1, uint8_t, Eurydice_slice)};
  store_block___144size_t(s, buf);
  uint8_t uu____0[200U];
  memcpy(uu____0, out0, (size_t)200U * sizeof(uint8_t));
  uint8_t uu____1[200U];
  memcpy(uu____1, out1, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[0U], uu____0, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[1U], uu____1, (size_t)200U * sizeof(uint8_t));
}

static KRML_MUSTINLINE void store_block_full___144size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], uint8_t ret[2U][200U]) {
  store_block_full___144size_t(a, ret);
}

static KRML_MUSTINLINE void
squeeze_first_and_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  uint8_t b[2U][200U];
  store_block_full___144size_t0(s->st, b);
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      Eurydice_slice uu____0 = out[i0]; uint8_t *uu____1 = b[i0];
      core_ops_range_Range__size_t lit; lit.start = (size_t)0U;
      lit.end = core_slice___Slice_T___len(out[i0], uint8_t, size_t);
      core_slice___Slice_T___copy_from_slice(
          uu____0,
          Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                     core_ops_range_Range__size_t,
                                     Eurydice_slice),
          uint8_t, void *););
}

static KRML_MUSTINLINE void store_block___144size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], Eurydice_slice b[2U]) {
  store_block___144size_t(a, b);
}

static KRML_MUSTINLINE void
squeeze_first_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  store_block___144size_t0(s->st, out);
}

static KRML_MUSTINLINE void
squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
  store_block___144size_t0(s->st, out);
}

static KRML_MUSTINLINE void
squeeze_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        s,
    Eurydice_slice out[2U]) {
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(&s);
  uint8_t b[2U][200U];
  store_block_full___144size_t0(s.st, b);
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      Eurydice_slice uu____0 = out[i0]; uint8_t *uu____1 = b[i0];
      core_ops_range_Range__size_t lit; lit.start = (size_t)0U;
      lit.end = core_slice___Slice_T___len(out[i0], uint8_t, size_t);
      core_slice___Slice_T___copy_from_slice(
          uu____0,
          Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                     core_ops_range_Range__size_t,
                                     Eurydice_slice),
          uint8_t, void *););
}

static KRML_MUSTINLINE void
keccak__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t_6uint8_t(
    Eurydice_slice data[2U], Eurydice_slice out[2U]) {
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
      s = new__core_core_arch_arm_shared_neon_uint64x2_t_2size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)144U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *uu____0 = &s;
    Eurydice_slice uu____1[2U];
    memcpy(uu____1, data, (size_t)2U * sizeof(Eurydice_slice));
    Eurydice_slice ret[2U];
    slice_n(uu____1, i0 * (size_t)144U, (size_t)144U, ret);
    absorb_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t(
        uu____0, ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)144U;
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
      *uu____2 = &s;
  Eurydice_slice uu____3[2U];
  memcpy(uu____3, data, (size_t)2U * sizeof(Eurydice_slice));
  Eurydice_slice ret[2U];
  slice_n(uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem,
          rem, ret);
  absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t_6uint8_t(
      uu____2, ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)144U;
  size_t last = outlen - outlen % (size_t)144U;
  if (blocks == (size_t)0U) {
    squeeze_first_and_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t(
        &s, out);
  } else {
    K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
        uu____4 = split_at_mut_n(out, (size_t)144U);
    Eurydice_slice o0[2U];
    memcpy(o0, uu____4.fst, (size_t)2U * sizeof(Eurydice_slice));
    Eurydice_slice o1[2U];
    memcpy(o1, uu____4.snd, (size_t)2U * sizeof(Eurydice_slice));
    squeeze_first_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t(
        &s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
            uu____5 = split_at_mut_n(o1, (size_t)144U);
        Eurydice_slice o[2U];
        memcpy(o, uu____5.fst, (size_t)2U * sizeof(Eurydice_slice));
        Eurydice_slice orest[2U];
        memcpy(orest, uu____5.snd, (size_t)2U * sizeof(Eurydice_slice));
        squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t(
            &s, o);
        memcpy(o1, orest, (size_t)2U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      squeeze_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t(
          s, o1);
    }
  }
}

static KRML_MUSTINLINE void keccakx2___144size_t_6uint8_t(
    Eurydice_slice data[2U], Eurydice_slice out[2U]) {
  Eurydice_slice uu____0[2U];
  memcpy(uu____0, data, (size_t)2U * sizeof(Eurydice_slice));
  keccak__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_144size_t_6uint8_t(
      uu____0, out);
}

KRML_MUSTINLINE void libcrux_sha3_neon_sha224(Eurydice_slice digest,
                                              Eurydice_slice data) {
  uint8_t dummy[28U] = {0U};
  Eurydice_slice uu____0[2U] = {data, data};
  Eurydice_slice buf[2U] = {
      digest,
      Eurydice_array_to_slice((size_t)28U, dummy, uint8_t, Eurydice_slice)};
  keccakx2___144size_t_6uint8_t(uu____0, buf);
}

static KRML_MUSTINLINE void load_block___104size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    Eurydice_slice blocks[2U]) {
  for (size_t i = (size_t)0U; i < (size_t)104U / (size_t)16U; i++) {
    size_t i0 = i;
    core_core_arch_arm_shared_neon_uint64x2_t v0 =
        libcrux_intrinsics_arm64__vld1q_bytes_u64(Eurydice_slice_subslice2(
            blocks[0U], (size_t)16U * i0, (size_t)16U * (i0 + (size_t)1U),
            uint8_t, Eurydice_slice));
    core_core_arch_arm_shared_neon_uint64x2_t v1 =
        libcrux_intrinsics_arm64__vld1q_bytes_u64(Eurydice_slice_subslice2(
            blocks[1U], (size_t)16U * i0, (size_t)16U * (i0 + (size_t)1U),
            uint8_t, Eurydice_slice));
    s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U] =
        libcrux_intrinsics_arm64__veorq_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            libcrux_intrinsics_arm64__vtrn1q_u64(v0, v1));
    s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
     [((size_t)2U * i0 + (size_t)1U) % (size_t)5U] =
         libcrux_intrinsics_arm64__veorq_u64(
             s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
              [((size_t)2U * i0 + (size_t)1U) % (size_t)5U],
             libcrux_intrinsics_arm64__vtrn2q_u64(v0, v1));
  }
  if ((size_t)104U % (size_t)16U != (size_t)0U) {
    size_t i = ((size_t)104U / (size_t)8U - (size_t)1U) / (size_t)5U;
    size_t j = ((size_t)104U / (size_t)8U - (size_t)1U) % (size_t)5U;
    uint64_t u[2U] = {0U};
    uint8_t uu____0[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst0;
    Eurydice_slice_to_array2(
        &dst0,
        Eurydice_slice_subslice2(blocks[0U], (size_t)104U - (size_t)8U,
                                 (size_t)104U, uint8_t, Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst0, uu____0);
    u[0U] = core_num__u64_9__from_le_bytes(uu____0);
    uint8_t uu____1[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst;
    Eurydice_slice_to_array2(
        &dst,
        Eurydice_slice_subslice2(blocks[1U], (size_t)104U - (size_t)8U,
                                 (size_t)104U, uint8_t, Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst, uu____1);
    u[1U] = core_num__u64_9__from_le_bytes(uu____1);
    core_core_arch_arm_shared_neon_uint64x2_t uvec =
        libcrux_intrinsics_arm64__vld1q_u64(
            Eurydice_array_to_slice((size_t)2U, u, uint64_t, Eurydice_slice));
    s[i][j] = libcrux_intrinsics_arm64__veorq_u64(s[i][j], uvec);
  }
}

static KRML_MUSTINLINE void load_block___104size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], Eurydice_slice b[2U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = a;
  Eurydice_slice uu____1[2U];
  memcpy(uu____1, b, (size_t)2U * sizeof(Eurydice_slice));
  load_block___104size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
absorb_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice blocks[2U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = s->st;
  Eurydice_slice uu____1[2U];
  memcpy(uu____1, blocks, (size_t)2U * sizeof(Eurydice_slice));
  load_block___104size_t0(uu____0, uu____1);
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
}

static KRML_MUSTINLINE void load_block_full___104size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    uint8_t blocks[2U][200U]) {
  Eurydice_slice buf[2U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice),
                            Eurydice_array_to_slice((size_t)200U, blocks[1U],
                                                    uint8_t, Eurydice_slice)};
  load_block___104size_t(s, buf);
}

static KRML_MUSTINLINE void load_block_full___104size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], uint8_t b[2U][200U]) {
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____0)[5U] = a;
  uint8_t uu____1[2U][200U];
  memcpy(uu____1, b, (size_t)2U * sizeof(uint8_t[200U]));
  load_block_full___104size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t_6uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice last[2U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[2U][200U] = {{0U}};
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      if (last_len > (size_t)0U) {
        Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
            blocks[i0], (size_t)0U, last_len, uint8_t, Eurydice_slice);
        core_slice___Slice_T___copy_from_slice(uu____0, last[i0], uint8_t,
                                               void *);
      } blocks[i0][last_len] = 6U;
      size_t uu____1 = i0; size_t uu____2 = (size_t)104U - (size_t)1U;
      blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;);
  core_core_arch_arm_shared_neon_uint64x2_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[2U][200U];
  memcpy(uu____4, blocks, (size_t)2U * sizeof(uint8_t[200U]));
  load_block_full___104size_t0(uu____3, uu____4);
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
}

static KRML_MUSTINLINE void store_block___104size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U],
    Eurydice_slice out[2U]) {
  for (size_t i = (size_t)0U; i < (size_t)104U / (size_t)16U; i++) {
    size_t i0 = i;
    core_core_arch_arm_shared_neon_uint64x2_t v0 =
        libcrux_intrinsics_arm64__vtrn1q_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)2U * i0 + (size_t)1U) % (size_t)5U]);
    core_core_arch_arm_shared_neon_uint64x2_t v1 =
        libcrux_intrinsics_arm64__vtrn2q_u64(
            s[(size_t)2U * i0 / (size_t)5U][(size_t)2U * i0 % (size_t)5U],
            s[((size_t)2U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)2U * i0 + (size_t)1U) % (size_t)5U]);
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_slice_subslice2(out[0U], (size_t)16U * i0,
                                 (size_t)16U * (i0 + (size_t)1U), uint8_t,
                                 Eurydice_slice),
        v0);
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_slice_subslice2(out[1U], (size_t)16U * i0,
                                 (size_t)16U * (i0 + (size_t)1U), uint8_t,
                                 Eurydice_slice),
        v1);
  }
  if ((size_t)104U % (size_t)16U != (size_t)0U) {
    size_t i = ((size_t)104U / (size_t)8U - (size_t)1U) / (size_t)5U;
    size_t j = ((size_t)104U / (size_t)8U - (size_t)1U) % (size_t)5U;
    uint8_t u[16U] = {0U};
    libcrux_intrinsics_arm64__vst1q_bytes_u64(
        Eurydice_array_to_slice((size_t)16U, u, uint8_t, Eurydice_slice),
        s[i][j]);
    Eurydice_slice uu____0 =
        Eurydice_slice_subslice2(out[0U], (size_t)104U - (size_t)8U,
                                 (size_t)104U, uint8_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice2(u, (size_t)0U, (size_t)8U, uint8_t,
                                    Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____1 =
        Eurydice_slice_subslice2(out[1U], (size_t)104U - (size_t)8U,
                                 (size_t)104U, uint8_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____1,
        Eurydice_array_to_subslice2(u, (size_t)8U, (size_t)16U, uint8_t,
                                    Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void store_block_full___104size_t(
    core_core_arch_arm_shared_neon_uint64x2_t (*s)[5U], uint8_t ret[2U][200U]) {
  uint8_t out0[200U] = {0U};
  uint8_t out1[200U] = {0U};
  Eurydice_slice buf[2U] = {
      Eurydice_array_to_slice((size_t)200U, out0, uint8_t, Eurydice_slice),
      Eurydice_array_to_slice((size_t)200U, out1, uint8_t, Eurydice_slice)};
  store_block___104size_t(s, buf);
  uint8_t uu____0[200U];
  memcpy(uu____0, out0, (size_t)200U * sizeof(uint8_t));
  uint8_t uu____1[200U];
  memcpy(uu____1, out1, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[0U], uu____0, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[1U], uu____1, (size_t)200U * sizeof(uint8_t));
}

static KRML_MUSTINLINE void store_block_full___104size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], uint8_t ret[2U][200U]) {
  store_block_full___104size_t(a, ret);
}

static KRML_MUSTINLINE void
squeeze_first_and_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  uint8_t b[2U][200U];
  store_block_full___104size_t0(s->st, b);
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      Eurydice_slice uu____0 = out[i0]; uint8_t *uu____1 = b[i0];
      core_ops_range_Range__size_t lit; lit.start = (size_t)0U;
      lit.end = core_slice___Slice_T___len(out[i0], uint8_t, size_t);
      core_slice___Slice_T___copy_from_slice(
          uu____0,
          Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                     core_ops_range_Range__size_t,
                                     Eurydice_slice),
          uint8_t, void *););
}

static KRML_MUSTINLINE void store_block___104size_t0(
    core_core_arch_arm_shared_neon_uint64x2_t (*a)[5U], Eurydice_slice b[2U]) {
  store_block___104size_t(a, b);
}

static KRML_MUSTINLINE void
squeeze_first_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  store_block___104size_t0(s->st, out);
}

static KRML_MUSTINLINE void
squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *s,
    Eurydice_slice out[2U]) {
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(s);
  store_block___104size_t0(s->st, out);
}

static KRML_MUSTINLINE void
squeeze_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        s,
    Eurydice_slice out[2U]) {
  keccakf1600__core_core_arch_arm_shared_neon_uint64x2_t_2size_t(&s);
  uint8_t b[2U][200U];
  store_block_full___104size_t0(s.st, b);
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      Eurydice_slice uu____0 = out[i0]; uint8_t *uu____1 = b[i0];
      core_ops_range_Range__size_t lit; lit.start = (size_t)0U;
      lit.end = core_slice___Slice_T___len(out[i0], uint8_t, size_t);
      core_slice___Slice_T___copy_from_slice(
          uu____0,
          Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                     core_ops_range_Range__size_t,
                                     Eurydice_slice),
          uint8_t, void *););
}

static KRML_MUSTINLINE void
keccak__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t_6uint8_t(
    Eurydice_slice data[2U], Eurydice_slice out[2U]) {
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
      s = new__core_core_arch_arm_shared_neon_uint64x2_t_2size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)104U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
        *uu____0 = &s;
    Eurydice_slice uu____1[2U];
    memcpy(uu____1, data, (size_t)2U * sizeof(Eurydice_slice));
    Eurydice_slice ret[2U];
    slice_n(uu____1, i0 * (size_t)104U, (size_t)104U, ret);
    absorb_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t(
        uu____0, ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)104U;
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_arm_shared_neon_uint64x2_t__2size_t
      *uu____2 = &s;
  Eurydice_slice uu____3[2U];
  memcpy(uu____3, data, (size_t)2U * sizeof(Eurydice_slice));
  Eurydice_slice ret[2U];
  slice_n(uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem,
          rem, ret);
  absorb_final__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t_6uint8_t(
      uu____2, ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)104U;
  size_t last = outlen - outlen % (size_t)104U;
  if (blocks == (size_t)0U) {
    squeeze_first_and_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t(
        &s, out);
  } else {
    K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
        uu____4 = split_at_mut_n(out, (size_t)104U);
    Eurydice_slice o0[2U];
    memcpy(o0, uu____4.fst, (size_t)2U * sizeof(Eurydice_slice));
    Eurydice_slice o1[2U];
    memcpy(o1, uu____4.snd, (size_t)2U * sizeof(Eurydice_slice));
    squeeze_first_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t(
        &s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_
            uu____5 = split_at_mut_n(o1, (size_t)104U);
        Eurydice_slice o[2U];
        memcpy(o, uu____5.fst, (size_t)2U * sizeof(Eurydice_slice));
        Eurydice_slice orest[2U];
        memcpy(orest, uu____5.snd, (size_t)2U * sizeof(Eurydice_slice));
        squeeze_next_block__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t(
            &s, o);
        memcpy(o1, orest, (size_t)2U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      squeeze_last__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t(
          s, o1);
    }
  }
}

static KRML_MUSTINLINE void keccakx2___104size_t_6uint8_t(
    Eurydice_slice data[2U], Eurydice_slice out[2U]) {
  Eurydice_slice uu____0[2U];
  memcpy(uu____0, data, (size_t)2U * sizeof(Eurydice_slice));
  keccak__core_core_arch_arm_shared_neon_uint64x2_t_2size_t_104size_t_6uint8_t(
      uu____0, out);
}

KRML_MUSTINLINE void libcrux_sha3_neon_sha384(Eurydice_slice digest,
                                              Eurydice_slice data) {
  uint8_t dummy[48U] = {0U};
  Eurydice_slice uu____0[2U] = {data, data};
  Eurydice_slice buf[2U] = {
      digest,
      Eurydice_array_to_slice((size_t)48U, dummy, uint8_t, Eurydice_slice)};
  keccakx2___104size_t_6uint8_t(uu____0, buf);
}
