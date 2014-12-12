#include "utils/converter.h"

int bools_to_int(bool* in, int length) {
   int res = 0;
   for(int i = 0; i < length; ++i)
   {
      res<<=1;
      if(in[i])
         res+=1;
   }
   return res;
}
void int_to_bools(bool* res, int in, int length) {
   for(int i = 0; i < length; ++i)
   {
      if((in & 1) == 1)
         res[i] = true;
      in >>=1;
   }
}

