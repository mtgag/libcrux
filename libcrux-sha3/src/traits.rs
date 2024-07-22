/// A Keccak Item
/// This holds the internal state and depends on the architecture.
pub trait KeccakStateItem<
    BufferType: internal::Buffer,
    Bl: internal::Block<BufferType>,
    const N: usize,
>: internal::KeccakItem<BufferType, Bl, N>
{
}

// Implement the public trait for all items.
impl<
        BufferType: internal::Buffer,
        Bl: internal::Block<BufferType>,
        const N: usize,
        T: internal::KeccakItem<BufferType, Bl, N>,
    > KeccakStateItem<BufferType, Bl, N> for T
{
}

pub(crate) mod internal {
    /// A trait for multiplexing implementations.
    pub trait KeccakItem<B: Buffer, Bl: Block<B>, const N: usize>: Clone + Copy {
        fn zero() -> Self;
        fn xor5(a: Self, b: Self, c: Self, d: Self, e: Self) -> Self;
        fn rotate_left1_and_xor(a: Self, b: Self) -> Self;
        fn xor_and_rotate<const LEFT: i32, const RIGHT: i32>(a: Self, b: Self) -> Self;
        fn and_not_xor(a: Self, b: Self, c: Self) -> Self;
        fn xor_constant(a: Self, c: u64) -> Self;
        fn xor(a: Self, b: Self) -> Self;
        fn load_block<const BLOCKSIZE: usize>(state: &mut [[Self; 5]; 5], buf: B);
        fn store_block<const BLOCKSIZE: usize>(a: &[[Self; 5]; 5], b: [&mut [u8]; N]);
        fn load_block_full<const BLOCKSIZE: usize>(state: &mut [[Self; 5]; 5], block: Bl);
        fn store_block_full<const BLOCKSIZE: usize>(a: &[[Self; 5]; 5]) -> [[u8; 200]; N];
        fn slice_n(a: [&[u8]; N], start: usize, len: usize) -> [&[u8]; N];
        fn split_at_mut_n(a: [&mut [u8]; N], mid: usize) -> ([&mut [u8]; N], [&mut [u8]; N]);
    }

    /// A buffer.
    /// This is depending on the implementation multiple lanes.
    pub trait Buffer: Clone + Copy {
        fn len(&self) -> usize;
        fn slice(&self, start: usize, len: usize) -> Self;
    }

    /// A full, owning block.
    /// This is used for the final absorb instead of the [`Buffer`].
    pub trait Block<B: Buffer>: Clone + Copy {
        fn init(b: B) -> Self;
        fn set_constants<const DELIM: u8, const EOB: usize>(&mut self);
    }
}
