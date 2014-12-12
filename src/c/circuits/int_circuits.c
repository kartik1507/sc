#include "circuits/int_circuits.h"

void 
full_bit_adder(bit out[2], const bit* x, const bit* y, const bit* cin) 
{
   bit t1 , t2;
   xor(&t1, x, cin);
   xor(&t2, y, cin);
   xor(&out[0], x, &t2);
   and(&t1, &t1, &t2);
   xor(&out[1], cin, &t1);
}

void add(bit* out, const bit* x, const bit * y, int length) 
{
   bit t[2];
   full_bit_adder(t, &x[0], &y[0], &ZERO);
   out[0] = t[0];
   for(int i = 0; i < length-1; ++i)
   {  
      full_bit_adder(t, &x[i+1], &y[i+1], &t[1]);
      out[i+1] = t[0];
   }
   out[length-1] = t[1];
}
