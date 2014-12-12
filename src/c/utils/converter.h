#ifndef CONVERTOR_H_
#define CONVERTOR_H_
#include "includes.h"
int bools_to_int(bool* res, int length) {
   int res = 0;
   for(int i = 0; i < length; ++i)
   {
      res<<=1;
      if(res[i])
         res+=1;
   }
}
void int_to_bools(bool* res, int in, int length) {
   for(int i = 0; i < length; ++i)
   {
      if(in & 1 == 1)
         res[i] = true;
      res >>=1;
   }
}

#endif// CONVERTOR_H_
