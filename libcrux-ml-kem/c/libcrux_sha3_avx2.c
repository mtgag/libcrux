/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc
  F* version: b5cb71b8
  KaRaMeL version: 04cb86b9
 */

#include "intrinsics/libcrux_intrinsics_avx2.h"

#include "libcrux_sha3_avx2.h"

#include "internal/libcrux_core.h"

inline void
libcrux_sha3_avx2_x4_shake256(
  Eurydice_slice input0,
  Eurydice_slice input1,
  Eurydice_slice input2,
  Eurydice_slice input3,
  Eurydice_slice out0,
  Eurydice_slice out1,
  Eurydice_slice out2,
  Eurydice_slice out3
)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline libcrux_sha3_avx2_x4_incremental_KeccakState4
libcrux_sha3_avx2_x4_incremental_shake128_init(void)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline void
libcrux_sha3_avx2_x4_incremental_shake128_absorb_final(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *s,
  Eurydice_slice data0,
  Eurydice_slice data1,
  Eurydice_slice data2,
  Eurydice_slice data3
)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline void
libcrux_sha3_avx2_x4_incremental_shake128_squeeze_next_block(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *s,
  Eurydice_slice out0,
  Eurydice_slice out1,
  Eurydice_slice out2,
  Eurydice_slice out3
)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline void
libcrux_sha3_avx2_x4_incremental_shake128_squeeze_first_three_blocks(
  libcrux_sha3_avx2_x4_incremental_KeccakState4 *s,
  Eurydice_slice out0,
  Eurydice_slice out1,
  Eurydice_slice out2,
  Eurydice_slice out3
)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}
