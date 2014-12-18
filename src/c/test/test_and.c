#include "config.h"
#include "includes.h"
#include "circuits/int_circuits.h"

void testcase(bool in1, bool in2){
   bit a, b, c;
   bool rc;
   input_wire(a, in1, Alice);
   input_wire(b, in2, Bob);
   and(c, a, b);
   output_wire(&rc, c, Alice);
   printf("%d %d %d\n", in1, in2, rc);
   assert(rc == (in1 && in2));
}

void testcase_array(bool * in1, bool * in2, int length)
{
   bit a[length], b[length], c[length];
   input_wire_array(a, in1, length, Alice);
   input_wire_array(b, in2, length, Alice);
   bool res[length];
   and_array(c, a, b, length);
   output_wire_array(res, c, length, Alice);
   for(int i = 0; i < length; ++i) 
      printf("%d ", res[i]);
}
int main()
{
   testcase(true, false);
   testcase(false, true);
   testcase(true, true);
   testcase(false, false);
   bool in1[] = {true, false, true, false};
   bool in2[] = {true, true, false, false};
   testcase_array(in1, in2, 4);
}
