#include "utils/simd.h"

// http://stackoverflow.com/questions/17610696/shift-a-m128i-of-n-bits
__m128i simd_left_shift(__m128i v)
{
   __m128i v1, v2;
   v1 = _mm_slli_epi64(v, 1);
   v2 = _mm_slli_si128(v, 8);
   v2 = _mm_srli_epi64(v2, 64 - (1));
   return _mm_or_si128(v1, v2);
}

__m128i simd_xor(__m128i a, __m128i b)
{
   return _mm_xor_si128(a, b);
}
void simd_print(__m128i var)
{
   uint32_t *val = (uint32_t*) &var;
   printf("Numerical: %0x %0x %0x %0x \n", 
         val[3], val[2], val[1], val[0]);
}

int simd_getLSB(__m128i x)
{
   return  (
         ( (int*)(&x) )[0] & 1
         )  == 1;
} 
