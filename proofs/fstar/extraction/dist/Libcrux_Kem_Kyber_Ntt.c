/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/bhargava/Desktop/repositories/karamel/krml -tmpdir dist/ -skip-compilation obj/FStar_Pervasives_Native.krml obj/FStar_Pervasives.krml obj/FStar_Mul.krml obj/FStar_Squash.krml obj/FStar_Classical.krml obj/FStar_Preorder.krml obj/FStar_Sealed.krml obj/FStar_Range.krml obj/FStar_Calc.krml obj/FStar_StrongExcludedMiddle.krml obj/FStar_Classical_Sugar.krml obj/FStar_List_Tot_Base.krml obj/FStar_List_Tot_Properties.krml obj/FStar_List_Tot.krml obj/FStar_Seq_Base.krml obj/FStar_Seq_Properties.krml obj/FStar_Seq.krml obj/FStar_Math_Lib.krml obj/FStar_Math_Lemmas.krml obj/FStar_BitVector.krml obj/FStar_UInt.krml obj/FStar_UInt32.krml obj/FStar_Int.krml obj/FStar_Int16.krml obj/FStar_Float.krml obj/FStar_Char.krml obj/FStar_Issue.krml obj/FStar_Monotonic_Pure.krml obj/FStar_Sealed_Inhabited.krml obj/FStar_Order.krml obj/FStar_VConfig.krml obj/FStar_Ghost.krml obj/FStar_PropositionalExtensionality.krml obj/FStar_FunctionalExtensionality.krml obj/FStar_Set.krml obj/FStar_ErasedLogic.krml obj/FStar_PredicateExtensionality.krml obj/FStar_TSet.krml obj/FStar_Monotonic_Heap.krml obj/FStar_Heap.krml obj/FStar_Map.krml obj/FStar_Monotonic_Witnessed.krml obj/FStar_Monotonic_HyperHeap.krml obj/FStar_Monotonic_HyperStack.krml obj/FStar_HyperStack.krml obj/FStar_HyperStack_ST.krml obj/FStar_Universe.krml obj/FStar_GSet.krml obj/FStar_ModifiesGen.krml obj/FStar_IndefiniteDescription.krml obj/FStar_BigOps.krml obj/LowStar_Monotonic_Buffer.krml obj/LowStar_Buffer.krml obj/LowStar_BufferOps.krml obj/Spec_Loops.krml obj/FStar_UInt64.krml obj/C_Loops.krml obj/FStar_Int64.krml obj/FStar_Int32.krml obj/FStar_Int8.krml obj/FStar_UInt16.krml obj/FStar_UInt8.krml obj/FStar_Int_Cast.krml obj/FStar_Exn.krml obj/FStar_ST.krml obj/FStar_All.krml obj/FStar_List.krml obj/FStar_BV.krml obj/FStar_UInt128.krml obj/FStar_Int_Cast_Full.krml obj/FStar_Int128.krml obj/Lib_IntTypes.krml obj/Lib_Loops.krml obj/Rust_primitives_Integers.krml obj/Rust_primitives_Arrays.krml obj/Rust_primitives.krml obj/Core_Ops_Index_IndexMut.krml obj/Core_Ops_Index.krml obj/Core_Ops.krml obj/Core_Slice_Iter.krml obj/Core_Slice.krml obj/Rust_primitives_Hax.krml obj/Core_Iter_Adapters_Step_by.krml obj/Core_Iter_Adapters_Enumerate.krml obj/Core_Iter_Traits_Iterator.krml obj/Core_Ops_Range.krml obj/Core_Iter.krml obj/Core_Num_Error.krml obj/Core_Result.krml obj/Core_Num.krml obj/Core.krml obj/Core_Ops_Arith_Neg.krml obj/Libcrux_Digest.krml obj/Libcrux_Kem_Kyber_Constants.krml obj/Core_Array.krml obj/Rust_primitives_Hax_Monomorphized_update_at.krml obj/Core_Convert.krml obj/Libcrux_Kem_Kyber_Arithmetic.krml obj/Libcrux_Kem_Kyber_Ntt.krml -warn-error @4@5@18 -fparentheses -bundle LowStar.*,Prims -bundle Libcrux.Kem.Kyber.Ntt=Rust_primitives.*,Rust_primitives,Core.*,Core,Hax_lib.*,Hax_lib,Libcrux.Digest,Libcrux.Kem.Kyber.* -minimal -bundle FStar.* -add-include <stdint.h> -add-include "krml/internal/target.h" -bundle Hacl.Spec.*,Spec.*[rename=Hacl_Spec] -bundle Lib.*[rename=Hacl_Lib] -drop Lib.IntVector.Intrinsics -drop Lib.IntTypes.Intrinsics -drop Lib.IntTypes.Intrinsics_128 -fparentheses -fno-shadow -fcurly-braces -fnoreturn-else -bundle Prims,C.Failure,C,C.String,C.Loops,Spec.Loops,C.Endianness,FStar.*,LowStar.*[rename=Hacl_Krmllib] -bundle Meta.* -minimal -add-early-include <string.h> -add-early-include "krml/internal/types.h" -add-early-include "krml/lowstar_endianness.h" -dmonomorphization
  F* version: fe6dec16
  KaRaMeL version: a7be2a7c
 */

#include "Libcrux_Kem_Kyber_Ntt.h"

static uint32_t v_COEFFICIENTS_IN_RING_ELEMENT = 256U;

static int32_t v_FIELD_MODULUS = (int32_t)3329;

static uint32_t v_INVERSE_OF_MODULUS_MOD_R = 62209U;

static uint8_t v_MONTGOMERY_SHIFT = 16U;

static uint32_t get_montgomery_r_least_significant_bits(uint32_t value)
{
  return value & ((1U << (uint32_t)v_MONTGOMERY_SHIFT) - 1U);
}

static int32_t montgomery_reduce(int32_t value)
{
  uint32_t
  t = get_montgomery_r_least_significant_bits((uint32_t)value) * v_INVERSE_OF_MODULUS_MOD_R;
  uint32_t m = 16U;
  uint32_t pow2_bits = 65536U;
  uint32_t pow2_bits_minus_one = 32768U;
  uint32_t
  a2 = (get_montgomery_r_least_significant_bits(t) & ((1U << m) - 1U)) - pow2_bits_minus_one;
  uint32_t mask = a2 >> 31U;
  uint32_t a3 = (get_montgomery_r_least_significant_bits(t) & ((1U << m) - 1U)) - pow2_bits;
  uint32_t b = a3 + (mask & pow2_bits);
  int16_t k = (int16_t)b;
  int32_t k_times_modulus = (int32_t)k * v_FIELD_MODULUS;
  int32_t c = FStar_Int32_shift_arithmetic_right(k_times_modulus, (uint32_t)v_MONTGOMERY_SHIFT);
  int32_t value_high = FStar_Int32_shift_arithmetic_right(value, (uint32_t)v_MONTGOMERY_SHIFT);
  return value_high - c;
}

typedef int32_t *t_PolynomialRingElement;

static int32_t impl__PolynomialRingElement__ZERO[256U];

int32_t *Libcrux_Kem_Kyber_Ntt_v_ZETAS_TIMES_MONTGOMERY_R;

K___int32_t_int32_t
Libcrux_Kem_Kyber_Ntt_ntt_multiply_binomials(
  K___int32_t_int32_t a,
  K___int32_t_int32_t b,
  int32_t zeta
)
{
  return
    (
      (K___int32_t_int32_t){
        .fst = montgomery_reduce(a.fst * b.fst + montgomery_reduce(a.snd * b.snd) * zeta),
        .snd = montgomery_reduce(a.fst * b.snd + a.snd * b.fst)
      }
    );
}

void Libcrux_Kem_Kyber_Ntt_invert_ntt_montgomery(uint32_t v_K, int32_t *re)
{
  KRML_MAYBE_UNUSED_VAR(v_K);
  KRML_MAYBE_UNUSED_VAR(re);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n",
    __FILE__,
    __LINE__,
    "This function was not extracted:\nFailure(\"Argument of FStar.Buffer.createL is not a list literal!\")");
  KRML_HOST_EXIT(255U);
}

int32_t *Libcrux_Kem_Kyber_Ntt_ntt_binomially_sampled_ring_element(int32_t *re)
{
  KRML_MAYBE_UNUSED_VAR(re);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n",
    __FILE__,
    __LINE__,
    "This function was not extracted:\nFailure(\"Argument of FStar.Buffer.createL is not a list literal!\")");
  KRML_HOST_EXIT(255U);
}

int32_t *Libcrux_Kem_Kyber_Ntt_ntt_multiply(int32_t *left, int32_t *right)
{
  int32_t *out = impl__PolynomialRingElement__ZERO;
  uint32_t start = 0U;
  uint32_t finish = v_COEFFICIENTS_IN_RING_ELEMENT / 4U;
  for (uint32_t i = start; i < finish; i++)
  {
    uint32_t i1 = i;
    K___int32_t_int32_t
    product =
      Libcrux_Kem_Kyber_Ntt_ntt_multiply_binomials((
          (K___int32_t_int32_t){ .fst = left[4U * i1], .snd = left[4U * i1 + 1U] }
        ),
        ((K___int32_t_int32_t){ .fst = right[4U * i1], .snd = right[4U * i1 + 1U] }),
        Libcrux_Kem_Kyber_Ntt_v_ZETAS_TIMES_MONTGOMERY_R[64U + i1]);
    out[4U * i1] = product.fst;
    out[4U * i1 + 1U] = product.snd;
    K___int32_t_int32_t
    product1 =
      Libcrux_Kem_Kyber_Ntt_ntt_multiply_binomials((
          (K___int32_t_int32_t){ .fst = left[4U * i1 + 2U], .snd = left[4U * i1 + 3U] }
        ),
        ((K___int32_t_int32_t){ .fst = right[4U * i1 + 2U], .snd = right[4U * i1 + 3U] }),
        KRML_EABORT(int32_t, "") - Libcrux_Kem_Kyber_Ntt_v_ZETAS_TIMES_MONTGOMERY_R[64U + i1]);
    out[4U * i1 + 2U] = product1.fst;
    out[4U * i1 + 3U] = product1.snd;
  }
  return out;
}

int32_t
*Libcrux_Kem_Kyber_Ntt_ntt_vector_u(uint32_t v_VECTOR_U_COMPRESSION_FACTOR, int32_t *re)
{
  KRML_MAYBE_UNUSED_VAR(v_VECTOR_U_COMPRESSION_FACTOR);
  KRML_MAYBE_UNUSED_VAR(re);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n",
    __FILE__,
    __LINE__,
    "This function was not extracted:\nFailure(\"Argument of FStar.Buffer.createL is not a list literal!\")");
  KRML_HOST_EXIT(255U);
}

