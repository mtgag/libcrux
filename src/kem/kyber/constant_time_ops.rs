use super::constants::SHARED_SECRET_SIZE;

use super::secret_integers::*;

// TODO: Examine the output that LLVM produces for this code to ensure
// operations are not being optimized away/constant-timedness is not being broken.

#[cfg_attr(hax, hax_lib_macros::ensures(|result|
    hax_lib::implies(value == 0, || result == 0) &&
    hax_lib::implies(value != 0, || result == 1)
))]
#[inline]
fn is_non_zero(value: U8) -> U8 {
    let value = U8_as_U16(value);

    let result = ((value | (!value).wrapping_add(1)) >> 8) & 1;

    U16_as_U8(result)
}

#[cfg_attr(hax, hax_lib_macros::ensures(|result|
    hax_lib::implies(lhs == rhs, || result == 0) &&
    hax_lib::implies(lhs != rhs, || result == 1)
))]
pub(crate) fn compare_ciphertexts_in_constant_time<const CIPHERTEXT_SIZE: usize>(
    lhs: &[u8],
    rhs: &[u8],
) -> U8 {
    hax_lib::debug_assert!(lhs.len() == rhs.len());
    hax_lib::debug_assert!(lhs.len() == CIPHERTEXT_SIZE);

    let mut r = U8::from(0);
    for i in 0..CIPHERTEXT_SIZE {
        r |= U8::from(lhs[i] ^ rhs[i]);
    }

    is_non_zero(r)
}

#[cfg_attr(hax, hax_lib_macros::ensures(|result|
    hax_lib::implies(selector == 0, || result == lhs) &&
    hax_lib::implies(selector != 0, || result == rhs)
))]
pub(crate) fn select_shared_secret_in_constant_time(
    lhs: &[u8],
    rhs: &[u8],
    selector: U8,
) -> [u8; SHARED_SECRET_SIZE] {
    hax_lib::debug_assert!(lhs.len() == rhs.len());
    hax_lib::debug_assert!(lhs.len() == SHARED_SECRET_SIZE);

    let mask = declassify_U8(is_non_zero(selector)).wrapping_sub(1);
    let mut out = [0u8; SHARED_SECRET_SIZE];

    for i in 0..SHARED_SECRET_SIZE {
        out[i] |= (lhs[i] & mask) | (rhs[i] & !mask);
    }

    out
}
