module Libcrux_ml_kem.Ntt
#set-options "--fuel 0 --ifuel 1 --z3rlimit 15"
open Core
open FStar.Mul

/// Use the Gentleman-Sande butterfly to invert, in-place, the NTT representation
/// of a `KyberPolynomialRingElement`. The coefficients of the output
/// ring element are in the Montgomery domain.
val impl__invert_ntt_montgomery
      (#v_Vector: Type)
      (v_K: usize)
      {| i2: Libcrux_ml_kem.Simd.Simd_trait.t_Operations v_Vector |}
      (self: Libcrux_ml_kem.Polynomial.t_PolynomialRingElement v_Vector)
    : Prims.Pure (Libcrux_ml_kem.Polynomial.t_PolynomialRingElement v_Vector)
      Prims.l_True
      (fun _ -> Prims.l_True)

/// Use the Cooley–Tukey butterfly to compute an in-place NTT representation
/// of a `KyberPolynomialRingElement`.
/// This function operates on the ring element that partly constitutes
/// the ciphertext.
val impl__ntt_vector_u
      (#v_Vector: Type)
      (v_VECTOR_U_COMPRESSION_FACTOR: usize)
      {| i2: Libcrux_ml_kem.Simd.Simd_trait.t_Operations v_Vector |}
      (self: Libcrux_ml_kem.Polynomial.t_PolynomialRingElement v_Vector)
    : Prims.Pure (Libcrux_ml_kem.Polynomial.t_PolynomialRingElement v_Vector)
      Prims.l_True
      (fun _ -> Prims.l_True)

/// Use the Cooley–Tukey butterfly to compute an in-place NTT representation
/// of a `KyberPolynomialRingElement`.
/// This function operates only on those which were produced by binomial
/// sampling, and thus those which have small coefficients. The small
/// coefficients let us skip the first round of Montgomery reductions.
val impl__ntt_binomially_sampled_ring_element
      (#v_Vector: Type)
      {| i1: Libcrux_ml_kem.Simd.Simd_trait.t_Operations v_Vector |}
      (self: Libcrux_ml_kem.Polynomial.t_PolynomialRingElement v_Vector)
    : Prims.Pure (Libcrux_ml_kem.Polynomial.t_PolynomialRingElement v_Vector)
      Prims.l_True
      (fun _ -> Prims.l_True)
