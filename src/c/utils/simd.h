#ifndef SIMD_H__
#define SIMD_H__
#include "includes.h"
__m128i simd_left_shift(__m128i x);

void simd_print(__m128i var);

__m128i simd_xor(__m128i a, __m128i b);

int simd_getLSB(__m128i x);
#endif// SIMD_H__
