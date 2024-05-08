use core::arch::aarch64::*;

/// This table is taken from PQClean. It is used in rej_sample
// It implements the following logic:
// let mut index : [u8;16] = [0u8; 16];
// let mut idx = 0;
// for i in 0..8 {
//     if used > 0 {
//         let next = used.trailing_zeros();
//         idx = idx + next;
//         index[i*2] = (idx*2) as u8;
//         index[i*2+1] = (idx*2 + 1) as u8;
//         idx = idx + 1;
//         used = used >> (next+1);
//     }
// }
// let index_vec = unsafe { vld1q_u8(index.as_ptr() as *const u8) };
// End of index table lookup calculation

const IDX_TABLE: [[u8; 16]; 256] = [
    [
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff,
    ], // 0
    [
        0, 1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 1
    [
        2, 3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 2
    [
        0, 1, 2, 3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 3
    [
        4, 5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 4
    [
        0, 1, 4, 5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 5
    [
        2, 3, 4, 5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 6
    [
        0, 1, 2, 3, 4, 5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 7
    [
        6, 7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 8
    [
        0, 1, 6, 7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 9
    [
        2, 3, 6, 7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 10
    [
        0, 1, 2, 3, 6, 7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 11
    [
        4, 5, 6, 7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 12
    [
        0, 1, 4, 5, 6, 7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 13
    [
        2, 3, 4, 5, 6, 7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 14
    [
        0, 1, 2, 3, 4, 5, 6, 7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 15
    [
        8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 16
    [
        0, 1, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 17
    [
        2, 3, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 18
    [
        0, 1, 2, 3, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 19
    [
        4, 5, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 20
    [
        0, 1, 4, 5, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 21
    [
        2, 3, 4, 5, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 22
    [
        0, 1, 2, 3, 4, 5, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 23
    [
        6, 7, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 24
    [
        0, 1, 6, 7, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 25
    [
        2, 3, 6, 7, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 26
    [
        0, 1, 2, 3, 6, 7, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 27
    [
        4, 5, 6, 7, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 28
    [
        0, 1, 4, 5, 6, 7, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 29
    [
        2, 3, 4, 5, 6, 7, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 30
    [
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 31
    [
        10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 32
    [
        0, 1, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 33
    [
        2, 3, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 34
    [
        0, 1, 2, 3, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 35
    [
        4, 5, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 36
    [
        0, 1, 4, 5, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 37
    [
        2, 3, 4, 5, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 38
    [
        0, 1, 2, 3, 4, 5, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 39
    [
        6, 7, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 40
    [
        0, 1, 6, 7, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 41
    [
        2, 3, 6, 7, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 42
    [
        0, 1, 2, 3, 6, 7, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 43
    [
        4, 5, 6, 7, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 44
    [
        0, 1, 4, 5, 6, 7, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 45
    [
        2, 3, 4, 5, 6, 7, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 46
    [
        0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 47
    [
        8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 48
    [
        0, 1, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 49
    [
        2, 3, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 50
    [
        0, 1, 2, 3, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 51
    [
        4, 5, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 52
    [
        0, 1, 4, 5, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 53
    [
        2, 3, 4, 5, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 54
    [
        0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 55
    [
        6, 7, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 56
    [
        0, 1, 6, 7, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 57
    [
        2, 3, 6, 7, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 58
    [
        0, 1, 2, 3, 6, 7, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 59
    [
        4, 5, 6, 7, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 60
    [
        0, 1, 4, 5, 6, 7, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 61
    [
        2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 62
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0xff, 0xff, 0xff, 0xff], // 63
    [
        12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 64
    [
        0, 1, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 65
    [
        2, 3, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 66
    [
        0, 1, 2, 3, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 67
    [
        4, 5, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 68
    [
        0, 1, 4, 5, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 69
    [
        2, 3, 4, 5, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 70
    [
        0, 1, 2, 3, 4, 5, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 71
    [
        6, 7, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 72
    [
        0, 1, 6, 7, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 73
    [
        2, 3, 6, 7, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 74
    [
        0, 1, 2, 3, 6, 7, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 75
    [
        4, 5, 6, 7, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 76
    [
        0, 1, 4, 5, 6, 7, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 77
    [
        2, 3, 4, 5, 6, 7, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 78
    [
        0, 1, 2, 3, 4, 5, 6, 7, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 79
    [
        8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 80
    [
        0, 1, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 81
    [
        2, 3, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 82
    [
        0, 1, 2, 3, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 83
    [
        4, 5, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 84
    [
        0, 1, 4, 5, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 85
    [
        2, 3, 4, 5, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 86
    [
        0, 1, 2, 3, 4, 5, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 87
    [
        6, 7, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 88
    [
        0, 1, 6, 7, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 89
    [
        2, 3, 6, 7, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 90
    [
        0, 1, 2, 3, 6, 7, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 91
    [
        4, 5, 6, 7, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 92
    [
        0, 1, 4, 5, 6, 7, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 93
    [
        2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 94
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 0xff, 0xff, 0xff, 0xff], // 95
    [
        10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 96
    [
        0, 1, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 97
    [
        2, 3, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 98
    [
        0, 1, 2, 3, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 99
    [
        4, 5, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 100
    [
        0, 1, 4, 5, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 101
    [
        2, 3, 4, 5, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 102
    [
        0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 103
    [
        6, 7, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 104
    [
        0, 1, 6, 7, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 105
    [
        2, 3, 6, 7, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 106
    [
        0, 1, 2, 3, 6, 7, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 107
    [
        4, 5, 6, 7, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 108
    [
        0, 1, 4, 5, 6, 7, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 109
    [
        2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 110
    [
        0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff,
    ], // 111
    [
        8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 112
    [
        0, 1, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 113
    [
        2, 3, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 114
    [
        0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 115
    [
        4, 5, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 116
    [
        0, 1, 4, 5, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 117
    [
        2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 118
    [
        0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff,
    ], // 119
    [
        6, 7, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 120
    [
        0, 1, 6, 7, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 121
    [
        2, 3, 6, 7, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 122
    [
        0, 1, 2, 3, 6, 7, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff,
    ], // 123
    [
        4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 124
    [
        0, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff,
    ], // 125
    [
        2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0xff, 0xff, 0xff, 0xff,
    ], // 126
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0xff, 0xff],     // 127
    [
        14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff,
    ], // 128
    [
        0, 1, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 129
    [
        2, 3, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 130
    [
        0, 1, 2, 3, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 131
    [
        4, 5, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 132
    [
        0, 1, 4, 5, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 133
    [
        2, 3, 4, 5, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 134
    [
        0, 1, 2, 3, 4, 5, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 135
    [
        6, 7, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 136
    [
        0, 1, 6, 7, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 137
    [
        2, 3, 6, 7, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 138
    [
        0, 1, 2, 3, 6, 7, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 139
    [
        4, 5, 6, 7, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 140
    [
        0, 1, 4, 5, 6, 7, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 141
    [
        2, 3, 4, 5, 6, 7, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 142
    [
        0, 1, 2, 3, 4, 5, 6, 7, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 143
    [
        8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 144
    [
        0, 1, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 145
    [
        2, 3, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 146
    [
        0, 1, 2, 3, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 147
    [
        4, 5, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 148
    [
        0, 1, 4, 5, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 149
    [
        2, 3, 4, 5, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 150
    [
        0, 1, 2, 3, 4, 5, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 151
    [
        6, 7, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 152
    [
        0, 1, 6, 7, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 153
    [
        2, 3, 6, 7, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 154
    [
        0, 1, 2, 3, 6, 7, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 155
    [
        4, 5, 6, 7, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 156
    [
        0, 1, 4, 5, 6, 7, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 157
    [
        2, 3, 4, 5, 6, 7, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 158
    [
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 159
    [
        10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 160
    [
        0, 1, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 161
    [
        2, 3, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 162
    [
        0, 1, 2, 3, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 163
    [
        4, 5, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 164
    [
        0, 1, 4, 5, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 165
    [
        2, 3, 4, 5, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 166
    [
        0, 1, 2, 3, 4, 5, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 167
    [
        6, 7, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 168
    [
        0, 1, 6, 7, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 169
    [
        2, 3, 6, 7, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 170
    [
        0, 1, 2, 3, 6, 7, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 171
    [
        4, 5, 6, 7, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 172
    [
        0, 1, 4, 5, 6, 7, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 173
    [
        2, 3, 4, 5, 6, 7, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 174
    [
        0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 175
    [
        8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 176
    [
        0, 1, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 177
    [
        2, 3, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 178
    [
        0, 1, 2, 3, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 179
    [
        4, 5, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 180
    [
        0, 1, 4, 5, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 181
    [
        2, 3, 4, 5, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 182
    [
        0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 183
    [
        6, 7, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 184
    [
        0, 1, 6, 7, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 185
    [
        2, 3, 6, 7, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 186
    [
        0, 1, 2, 3, 6, 7, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 187
    [
        4, 5, 6, 7, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 188
    [
        0, 1, 4, 5, 6, 7, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 189
    [
        2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 190
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 14, 0xff, 0xff, 0xff],   // 191
    [
        12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 192
    [
        0, 1, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 193
    [
        2, 3, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 194
    [
        0, 1, 2, 3, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 195
    [
        4, 5, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 196
    [
        0, 1, 4, 5, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 197
    [
        2, 3, 4, 5, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 198
    [
        0, 1, 2, 3, 4, 5, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 199
    [
        6, 7, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 200
    [
        0, 1, 6, 7, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 201
    [
        2, 3, 6, 7, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 202
    [
        0, 1, 2, 3, 6, 7, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 203
    [
        4, 5, 6, 7, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 204
    [
        0, 1, 4, 5, 6, 7, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 205
    [
        2, 3, 4, 5, 6, 7, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 206
    [
        0, 1, 2, 3, 4, 5, 6, 7, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 207
    [
        8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 208
    [
        0, 1, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 209
    [
        2, 3, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 210
    [
        0, 1, 2, 3, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 211
    [
        4, 5, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 212
    [
        0, 1, 4, 5, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 213
    [
        2, 3, 4, 5, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 214
    [
        0, 1, 2, 3, 4, 5, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 215
    [
        6, 7, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 216
    [
        0, 1, 6, 7, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 217
    [
        2, 3, 6, 7, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 218
    [
        0, 1, 2, 3, 6, 7, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 219
    [
        4, 5, 6, 7, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 220
    [
        0, 1, 4, 5, 6, 7, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 221
    [
        2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 222
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 14, 0xff, 0xff, 0xff],   // 223
    [
        10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 224
    [
        0, 1, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 225
    [
        2, 3, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 226
    [
        0, 1, 2, 3, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 227
    [
        4, 5, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 228
    [
        0, 1, 4, 5, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 229
    [
        2, 3, 4, 5, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 230
    [
        0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 231
    [
        6, 7, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 232
    [
        0, 1, 6, 7, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 233
    [
        2, 3, 6, 7, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 234
    [
        0, 1, 2, 3, 6, 7, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 235
    [
        4, 5, 6, 7, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 236
    [
        0, 1, 4, 5, 6, 7, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 237
    [
        2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 238
    [0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff], // 239
    [
        8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 240
    [
        0, 1, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 241
    [
        2, 3, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 242
    [
        0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 243
    [
        4, 5, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 244
    [
        0, 1, 4, 5, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 245
    [
        2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 246
    [0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff], // 247
    [
        6, 7, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 248
    [
        0, 1, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 249
    [
        2, 3, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 250
    [0, 1, 2, 3, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff], // 251
    [
        4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff, 0xff, 0xff,
    ], // 252
    [0, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff], // 253
    [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0xff, 0xff, 0xff], // 254
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0xff],       // 255
];

#[inline(always)]
pub(crate) fn rej_sample(a: &[u8]) -> (usize, [i16; 16]) {
    let neon_bits: [u16; 8] = [0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80];
    let bits = unsafe { vld1q_u16(neon_bits.as_ptr() as *const u16) };
    let fm = unsafe { vdupq_n_s16(3328) };

    let input = super::simd128ops::deserialize_12(a);
    let mask0 = unsafe { vcleq_s16(input.low, fm) };
    let mask1 = unsafe { vcleq_s16(input.high, fm) };
    let used0 = unsafe { vaddvq_u16(vandq_u16(mask0, bits)) };
    let used1 = unsafe { vaddvq_u16(vandq_u16(mask1, bits)) };
    let pick0 = used0.count_ones();
    let pick1 = used1.count_ones();

    let index_vec0 = unsafe { vld1q_u8(IDX_TABLE[used0 as usize].as_ptr() as *const u8) };
    let shifted0 = unsafe { vqtbl1q_u8(vreinterpretq_u8_s16(input.low), index_vec0) };
    let index_vec1 = unsafe { vld1q_u8(IDX_TABLE[used1 as usize].as_ptr() as *const u8) };
    let shifted1 = unsafe { vqtbl1q_u8(vreinterpretq_u8_s16(input.high), index_vec1) };

    let mut out: [i16; 16] = [0i16; 16];
    let idx0 = pick0 as usize;
    unsafe {
        vst1q_s16(
            out[0..8].as_mut_ptr() as *mut i16,
            vreinterpretq_s16_u8(shifted0),
        )
    };
    unsafe {
        vst1q_s16(
            out[idx0..idx0 + 8].as_mut_ptr() as *mut i16,
            vreinterpretq_s16_u8(shifted1),
        )
    };
    ((pick0 + pick1) as usize, out)
}
