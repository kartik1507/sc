#include "includes.h"
#include "utils/simd.h"

int main()
{
   __m128i v = _mm_set_epi32(0xF2345678, 0x9ABCDEF0, 0xF2345678, 0x9ABCDEF0);
   simd_print(v);

   simd_print(simd_left_shift(v));
   printf("%d", simd_getLSB(v));
   return 0;
}

