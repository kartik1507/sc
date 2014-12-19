#include "gc/gc.h"
#include "includes.h"
#include "utils/simd.h"
int64_t gid;
void init(int _sock) {
   sock = _sock;
   gid = 0;
}

void assign(bit a, bit b)
{
   * a = * b;
}
bit* new_bit_array(int length){
return NULL;}
void delete_bit_array(bit** bits, int length){}

void and(bit out, const bit a, const bit b)
{
   
}
void xor(bit out, const bit a, const bit b)
{
}

void input_wire(bit out, bool input, enum Party party){}
void input_wire_array(bit* out, bool* input, int length, enum Party party){}
void output_wire(bool* res, bit b, enum Party party){}
void output_wire_array(bool* out, bit* b, int length, enum Party party){}

void hash(bit res, bit b1, int64_t gid)
{
/*   __m128i mmi_i =  _mm_set_epi64((__m64)0, gid);
   __m128i mmi_2x = simd_left_shift(*b1);
   __m128i mmi_K = simd_xor(mmi_i, mmi_2x);
   __m128i mmi_PiK = simd_Enc(mmi_K);
   *res  = simd_xor(mmi_K, mmi_PiK);
*/}

