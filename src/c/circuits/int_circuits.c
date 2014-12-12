#include "circuits/int_circuits.h"

void 
add(bit* out[2], bit* x, bit* y, bit* cin) {
   bit *t1 , *t2;
   new_bits(2, &t1, &t2);

  // xor(t1, x, cin);
  // xor(t2, y, cin);
   xor(out[0], x, t2);
  // and(t1, t1, t2);
   xor(out[1], cin, t1);

   delete_bits(2, &t1, &t2);
}
