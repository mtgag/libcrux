module Libcrux.Kem.Kyber.Matrix
#set-options "--fuel 0 --ifuel 1 --z3rlimit 15"
open Core
open FStar.Mul

let op_Array_Access (x:Libcrux.Kem.Kyber.Arithmetic.t_PolynomialRingElement) (i:usize{v i < 256}): i32  =
    x.f_coefficients.[i]
    

let compute_As_plus_e v_K matrix_A s_as_ntt error_as_ntt =
  let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
    Rust_primitives.Hax.repeat (Libcrux.Kem.Kyber.Arithmetic.cast_poly_b #1 #3328 Libcrux.Kem.Kyber.Arithmetic.impl__PolynomialRingElement__ZERO) v_K
  in
  admit();
  let acc_t = t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K in
  [@ inline_let]
  let inv = fun (acc:acc_t) (i:usize) -> True in
  let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
    Rust_primitives.Iterators.foldi_slice #(t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) #acc_t #inv
      matrix_A
      result
      (fun result temp_1_ ->
          let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K = result in
          let i, row:(usize & t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) =
            temp_1_
          in
          [@ inline_let]
          let inv = fun (acc:acc_t) (i:usize) -> True in
          let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
            Rust_primitives.Iterators.foldi_slice #Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement #acc_t #inv
              row
              result
              (fun result temp_1_ ->
                  let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
                    result
                  in
                  let j, matrix_element:(usize &
                    Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement) =
                    temp_1_
                  in
                  let product:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
                    Libcrux.Kem.Kyber.Ntt.ntt_multiply matrix_element
                      (s_as_ntt.[ j ] <: Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                  in
                  admit(); // needs bounds for add_to_ring_element
                  let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
                    Rust_primitives.Hax.Monomorphized_update_at.update_at_usize result
                      i
                      (Libcrux.Kem.Kyber.Arithmetic.add_to_ring_element v_K
                          (result.[ i ] <: Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                          product
                        <:
                        Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                  in
                  result)
          in
          let acc_t = t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K in
          [@ inline_let]
          let inv = fun (acc:acc_t) (i:usize) -> True in
            Rust_primitives.Iterators.foldi_range #_ #acc_t #inv {
              Core.Ops.Range.f_start = sz 0;
              Core.Ops.Range.f_end = Libcrux.Kem.Kyber.Constants.v_COEFFICIENTS_IN_RING_ELEMENT
            }
            result
            (fun result j ->
                let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
                  result
                in
                let j:usize = j in
                assume (range (v (result.[i]).(j) * 1353) i32_inttype);
                let coefficient_normal_form =
                  Libcrux.Kem.Kyber.Arithmetic.to_standard_domain #3328 ((result.[ i ]
                        <:
                        Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                        .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ j ])
                in
                let x1: Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement = error_as_ntt.[i] in
                let x2 : i32 = x1.f_coefficients.[j] in
                assume (range (v coefficient_normal_form + v x2) i32_inttype);
                Rust_primitives.Hax.Monomorphized_update_at.update_at_usize result
                  i
                  ({
                      (result.[ i ] <: Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement) with
                      Libcrux.Kem.Kyber.Arithmetic.f_coefficients
                      =
                      Rust_primitives.Hax.Monomorphized_update_at.update_at_usize (result.[ i ]
                          <:
                          Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
                        j
                        (Libcrux.Kem.Kyber.Arithmetic.barrett_reduce (coefficient_normal_form +!
                              ((error_as_ntt.[ i ]
                                  <:
                                  Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                                  .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ j ]
                                <:
                                i32)
                              <:
                              i32)
                          <:
                          i32)
                      <:
                      t_Array i32 (sz 256)
                    }
                    <:
                    Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)))
  in
  admit(); //P-F
  result 

let compute_message #p v_K m_v secret_as_ntt u_as_ntt = 
  let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
    Libcrux.Kem.Kyber.Arithmetic.cast_poly_b Libcrux.Kem.Kyber.Arithmetic.impl__PolynomialRingElement__ZERO
  in
  let acc_t = Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement in
  [@ inline_let]
  let inv = fun (acc:acc_t) (i:usize) -> True in
  let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
    Rust_primitives.Iterators.foldi_range #_ #acc_t #inv {
              Core.Ops.Range.f_start = sz 0;
              Core.Ops.Range.f_end = v_K
            }
      result 
      (fun result i ->
          let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement = result in
          let i:usize = i in
          admit();
          let product:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
            Libcrux.Kem.Kyber.Ntt.ntt_multiply (secret_as_ntt.[ i ]
                <:
                Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
              (u_as_ntt.[ i ] <: Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
          in
          admit(); //pre for add_to_ring
          let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
            Libcrux.Kem.Kyber.Arithmetic.add_to_ring_element v_K result product
          in
          result)
  in
  admit();
  let result:Libcrux.Kem.Kyber.Arithmetic.t_PolynomialRingElement_b (128*v v_K*3328) =
    Libcrux.Kem.Kyber.Ntt.invert_ntt_montgomery v_K result
  in
  let acc_t = Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement in
  [@ inline_let]
  let inv = fun (acc:acc_t) (i:usize) -> True in
  let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
    Rust_primitives.Iterators.foldi_range #_ #acc_t #inv {
              Core.Ops.Range.f_start = sz 0;
              Core.Ops.Range.f_end = Libcrux.Kem.Kyber.Constants.v_COEFFICIENTS_IN_RING_ELEMENT
            }
      result 
      (fun result i ->
          let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement = result in
          let i:usize = i in
          assume (range (v #i32_inttype result.Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[i] *  1441) i32_inttype);
          let coefficient_normal_form = 
              Libcrux.Kem.Kyber.Arithmetic.montgomery_reduce 
                           (Libcrux.Kem.Kyber.Arithmetic.mul_i32_b #3328 #1441
                           result.Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ i ] 
                           (1441l <: Libcrux.Kem.Kyber.Arithmetic.i32_b 1441)) in
          assume (range (v #i32_inttype m_v.Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[i] - v coefficient_normal_form) i32_inttype);
//          assume (Libcrux.Kem.Kyber.Arithmetic.barrett_pre (m_v.(i) -! coefficient_normal_form));

          let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
            {
              result with
              Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              =
              Rust_primitives.Hax.Monomorphized_update_at.update_at_usize result
                  .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
                i
                (Libcrux.Kem.Kyber.Arithmetic.barrett_reduce ((m_v
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ i ]
                        <:
                        i32) -!
                      coefficient_normal_form
                      <:
                      i32)
                  <:
                  i32)
            }
            <:
            Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement
          in
          result)
  in
  admit(); //P-F
  result


let compute_ring_element_v v_K tt_as_ntt r_as_ntt error_2_ message =
  let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
    Libcrux.Kem.Kyber.Arithmetic.cast_poly_b Libcrux.Kem.Kyber.Arithmetic.impl__PolynomialRingElement__ZERO
  in
  let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
    Core.Iter.Traits.Iterator.f_fold (Core.Iter.Traits.Collect.f_into_iter ({
              Core.Ops.Range.f_start = sz 0;
              Core.Ops.Range.f_end = v_K
            }
            <:
            Core.Ops.Range.t_Range usize)
        <:
        Core.Ops.Range.t_Range usize)
      result
      (fun result i ->
          let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement = result in
          let i:usize = i in
          admit();
          let product:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
            Libcrux.Kem.Kyber.Ntt.ntt_multiply (tt_as_ntt.[ i ]
                <:
                Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
              (r_as_ntt.[ i ] <: Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
          in
          admit(); //pre for add_to_ring_element
          let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
            Libcrux.Kem.Kyber.Arithmetic.add_to_ring_element v_K result product
          in
          result)
  in
  admit();
  let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
    Libcrux.Kem.Kyber.Ntt.invert_ntt_montgomery v_K result
  in
  let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
    Core.Iter.Traits.Iterator.f_fold (Core.Iter.Traits.Collect.f_into_iter ({
              Core.Ops.Range.f_start = sz 0;
              Core.Ops.Range.f_end = Libcrux.Kem.Kyber.Constants.v_COEFFICIENTS_IN_RING_ELEMENT
            }
            <:
            Core.Ops.Range.t_Range usize)
        <:
        Core.Ops.Range.t_Range usize)
      result
      (fun result i ->
          let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement = result in
          let i:usize = i in
          assume (range (v #i32_inttype result.Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[i] * 1441) i32_inttype);
          let coefficient_normal_form =
            Libcrux.Kem.Kyber.Arithmetic.montgomery_reduce 
                    (Libcrux.Kem.Kyber.Arithmetic.mul_i32_b #3328 #1441
                    (result.Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ i ])
                    (1441l <: Libcrux.Kem.Kyber.Arithmetic.i32_b 1441))
          in
          assume (range (v coefficient_normal_form +
                        v #i32_inttype error_2_.f_coefficients.[ i ]) i32_inttype);
          assume (range (v coefficient_normal_form +
                        v #i32_inttype error_2_.f_coefficients.[ i ] +
                        v #i32_inttype message.f_coefficients.[ i ]) i32_inttype);
//          assume (Libcrux.Kem.Kyber.Arithmetic.barrett_pre (coefficient_normal_form +! error_2_.f_coefficients.[ i ] +! message.f_coefficients.[ i ]));
          let result:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
            {
              result with
              Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              =
              Rust_primitives.Hax.Monomorphized_update_at.update_at_usize result
                  .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
                i
                (Libcrux.Kem.Kyber.Arithmetic.barrett_reduce ((coefficient_normal_form +!
                        (error_2_.Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ i ] <: i32)
                        <:
                        i32) +!
                      (message.Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ i ] <: i32)
                      <:
                      i32)
                  <:
                  i32)
            }
            <:
            Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement
          in
          result)
  in
  admit(); //P-F
  result

let compute_vector_u
      (v_K: usize)
      (a_as_ntt: t_Array (t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) v_K)
      (r_as_ntt error_1_: t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) =
  let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
    Rust_primitives.Hax.repeat (Libcrux.Kem.Kyber.Arithmetic.cast_poly_b #1 #3328 Libcrux.Kem.Kyber.Arithmetic.impl__PolynomialRingElement__ZERO) v_K
  in
  let acc_t = t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K in
  [@ inline_let]
  let inv = fun (acc:acc_t) (i:usize) -> True in
  let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
    Rust_primitives.Iterators.foldi_slice #(t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) #acc_t #inv
      a_as_ntt
      result
      (fun result temp_1_ ->
          let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K = result in
          let i, row:(usize & t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) =
            temp_1_
          in
          [@ inline_let]
          let inv = fun (acc:acc_t) (i:usize) -> True in
          let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
            Rust_primitives.Iterators.foldi_slice #Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement #acc_t #inv
              row
              result
              (fun result temp_1_ ->
                  let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
                    result
                  in
                  let j, a_element:(usize & Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement) =
                    temp_1_
                  in
                  admit();
                  let product:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
                    Libcrux.Kem.Kyber.Ntt.ntt_multiply a_element
                      (r_as_ntt.[ j ] <: Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                  in
                  admit(); //pre for add_to_ring
                  let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
                    Rust_primitives.Hax.Monomorphized_update_at.update_at_usize result
                      i
                      (Libcrux.Kem.Kyber.Arithmetic.add_to_ring_element v_K
                          (result.[ i ] <: Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                          product
                        <:
                        Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                  in
                  result)
          in
          admit();
          let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
            Rust_primitives.Hax.Monomorphized_update_at.update_at_usize result
              i
              (Libcrux.Kem.Kyber.Ntt.invert_ntt_montgomery v_K
                  (result.[ i ] <: Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                <:
                Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
          in
          Core.Iter.Traits.Iterator.f_fold (Core.Iter.Traits.Collect.f_into_iter ({
                    Core.Ops.Range.f_start = sz 0;
                    Core.Ops.Range.f_end
                    =
                    Libcrux.Kem.Kyber.Constants.v_COEFFICIENTS_IN_RING_ELEMENT
                  }
                  <:
                  Core.Ops.Range.t_Range usize)
              <:
              Core.Ops.Range.t_Range usize)
            result
            (fun result j ->
                let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
                  result
                in
                assume (range (v (result.[i]).(j) * 1441) i32_inttype);

                let j:usize = j in
                let coefficient_normal_form =
                  Libcrux.Kem.Kyber.Arithmetic.montgomery_reduce (
                  Libcrux.Kem.Kyber.Arithmetic.mul_i32_b
                  ((result.[ i ]
                          <:
                          Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ j ]
                        <:
                        Libcrux.Kem.Kyber.Arithmetic.i32_b 3328)
                   (1441l <: Libcrux.Kem.Kyber.Arithmetic.i32_b 1441)) 
                in
                assume (range (v coefficient_normal_form + v (error_1_.[i]).( j )) i32_inttype);
//                assume (Libcrux.Kem.Kyber.Arithmetic.barrett_pre (coefficient_normal_form +! (error_1_.[i]).( j ))); 
                let result:t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K =
                  Rust_primitives.Hax.Monomorphized_update_at.update_at_usize result
                    i
                    ({
                        (result.[ i ] <: Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement) with
                        Libcrux.Kem.Kyber.Arithmetic.f_coefficients
                        =
                        Rust_primitives.Hax.Monomorphized_update_at.update_at_usize (result.[ i ]
                            <:
                            Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                            .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
                          j
                          (Libcrux.Kem.Kyber.Arithmetic.barrett_reduce (coefficient_normal_form +!
                                ((error_1_.[ i ]
                                    <:
                                    Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                                    .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ j ]
                                  <:
                                  i32)
                                <:
                                i32)
                            <:
                            i32)
                        <:
                        t_Array i32 (sz 256)
                      }
                      <:
                      Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement)
                in
                result))
  in
  admit(); //P-F
  result

let sample_matrix_A (v_K: usize) (seed: t_Array u8 (sz 34)) (transpose: bool) =
  let v_A_transpose:t_Array (t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) v_K =
    Rust_primitives.Hax.repeat (Rust_primitives.Hax.repeat (Libcrux.Kem.Kyber.Arithmetic.cast_poly_b #1 #3328 Libcrux.Kem.Kyber.Arithmetic.impl__PolynomialRingElement__ZERO)
          v_K
        <:
        t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K)
      v_K
  in
  let v_A_transpose:t_Array (t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) v_K =
    Core.Iter.Traits.Iterator.f_fold (Core.Iter.Traits.Collect.f_into_iter ({
              Core.Ops.Range.f_start = sz 0;
              Core.Ops.Range.f_end = v_K
            }
            <:
            Core.Ops.Range.t_Range usize)
        <:
        Core.Ops.Range.t_Range usize)
      v_A_transpose
      (fun v_A_transpose i ->
          let v_A_transpose:t_Array
            (t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) v_K =
            v_A_transpose
          in
          let i:usize = i in
          let seeds:t_Array (t_Array u8 (sz 34)) v_K = Rust_primitives.Hax.repeat seed v_K in
          let seeds:t_Array (t_Array u8 (sz 34)) v_K =
            Core.Iter.Traits.Iterator.f_fold (Core.Iter.Traits.Collect.f_into_iter ({
                      Core.Ops.Range.f_start = sz 0;
                      Core.Ops.Range.f_end = v_K
                    }
                    <:
                    Core.Ops.Range.t_Range usize)
                <:
                Core.Ops.Range.t_Range usize)
              seeds
              (fun seeds j ->
                  let seeds:t_Array (t_Array u8 (sz 34)) v_K = seeds in
                  let j:usize = j in
                  let seeds:t_Array (t_Array u8 (sz 34)) v_K =
                    Rust_primitives.Hax.Monomorphized_update_at.update_at_usize seeds
                      j
                      (Rust_primitives.Hax.Monomorphized_update_at.update_at_usize (seeds.[ j ]
                            <:
                            t_Array u8 (sz 34))
                          (sz 32)
                          (cast (i <: usize) <: u8)
                        <:
                        t_Array u8 (sz 34))
                  in
                  let seeds:t_Array (t_Array u8 (sz 34)) v_K =
                    Rust_primitives.Hax.Monomorphized_update_at.update_at_usize seeds
                      j
                      (Rust_primitives.Hax.Monomorphized_update_at.update_at_usize (seeds.[ j ]
                            <:
                            t_Array u8 (sz 34))
                          (sz 33)
                          (cast (j <: usize) <: u8)
                        <:
                        t_Array u8 (sz 34))
                  in
                  seeds)
          in
          let xof_bytes:t_Array (t_Array u8 (sz 840)) v_K =
            Libcrux.Kem.Kyber.Hash_functions.v_XOFx4 v_K seeds
          in
          Core.Iter.Traits.Iterator.f_fold (Core.Iter.Traits.Collect.f_into_iter ({
                    Core.Ops.Range.f_start = sz 0;
                    Core.Ops.Range.f_end = v_K
                  }
                  <:
                  Core.Ops.Range.t_Range usize)
              <:
              Core.Ops.Range.t_Range usize)
            v_A_transpose
            (fun v_A_transpose j ->
                let v_A_transpose:t_Array
                  (t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) v_K =
                  v_A_transpose
                in
                let j:usize = j in
                let sampled:Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement =
                  Libcrux.Kem.Kyber.Sampling.sample_from_uniform_distribution (xof_bytes.[ j ]
                      <:
                      t_Array u8 (sz 840))
                in
                if transpose
                then
                  let v_A_transpose:t_Array
                    (t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) v_K =
                    Rust_primitives.Hax.Monomorphized_update_at.update_at_usize v_A_transpose
                      j
                      (Rust_primitives.Hax.Monomorphized_update_at.update_at_usize (v_A_transpose.[ j
                            ]
                            <:
                            t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K)
                          i
                          sampled
                        <:
                        t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K)
                  in
                  v_A_transpose
                else
                  let v_A_transpose:t_Array
                    (t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K) v_K =
                    Rust_primitives.Hax.Monomorphized_update_at.update_at_usize v_A_transpose
                      i
                      (Rust_primitives.Hax.Monomorphized_update_at.update_at_usize (v_A_transpose.[ i
                            ]
                            <:
                            t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K)
                          j
                          sampled
                        <:
                        t_Array Libcrux.Kem.Kyber.Arithmetic.wfPolynomialRingElement v_K)
                  in
                  v_A_transpose))
  in
  admit(); //P-F
  v_A_transpose