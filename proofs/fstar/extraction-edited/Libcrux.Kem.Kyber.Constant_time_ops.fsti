module Libcrux.Kem.Kyber.Constant_time_ops
#set-options "--fuel 0 --ifuel 1 --z3rlimit 15"
open Core
open FStar.Mul

val is_non_zero (value: u8)
    : Prims.Pure u8
      Prims.l_True
      (ensures
        fun result ->
          let result:u8 = result in
          Hax_lib.implies (value =. 0uy <: bool)
            (fun temp_0_ ->
                let _:Prims.unit = temp_0_ in
                result =. 0uy <: bool) &&
          Hax_lib.implies (value <>. 0uy <: bool)
            (fun temp_0_ ->
                let _:Prims.unit = temp_0_ in
                result =. 1uy <: bool))

val compare_ciphertexts_in_constant_time (v_CIPHERTEXT_SIZE: usize) (lhs rhs: t_Slice u8)
    : Prims.Pure u8
      (requires (length lhs == v_CIPHERTEXT_SIZE /\
                 length rhs == v_CIPHERTEXT_SIZE))
      (ensures
        fun result ->
          let result:u8 = result in
          (lhs == rhs ==> v result = 0) /\
          (lhs =!= rhs ==> v result = 1))

val select_shared_secret_in_constant_time (lhs rhs: t_Slice u8) (selector: u8)
    : Prims.Pure (t_Array u8 (sz 32))
      (requires (length lhs == Libcrux.Kem.Kyber.Constants.v_SHARED_SECRET_SIZE /\
                 length rhs == Libcrux.Kem.Kyber.Constants.v_SHARED_SECRET_SIZE))
      (ensures
        fun result ->
          let result:t_Array u8 (sz 32) = result in
          (v selector == 0) ==> (result == lhs) /\
          (v selector =!= 0) ==> (result == rhs))
