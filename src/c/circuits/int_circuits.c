#include "../config.h"
#include "../validator/validator.c"

static bit* add(bit x, bit y, bit cin) {
   bit *out = (bit*)malloc(2*sizeof(bit));

   bit t1 = xor(x, cin);
   bit t2 = xor(y, cin);
   out[0] = xor(x, t2);
   t1 = and(t1, t2);
   out[1] = xor(cin, t1);
return out;
}
