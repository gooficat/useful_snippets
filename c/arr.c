#include <malloc.h>
#include "fancc.h"
#include <math.h>
#include "arr.h"
#include "defs.h"

void rsz_arr_f(struct generic_arr ptr arr, u8 sz)
{
   u64 spowmul = pow(2, arr->powmul);
   if (spowmul < arr->len)
   {
      while ((spowmul = pow(2, ++arr->powmul)) < arr->len)
         ;
   retry:;
      void* inb = realloc(arr->get, sz * spowmul);
      if (inb)
      {
         arr->get = inb;
      }
      else
      {
         fancc(RED, "Failed to resize array! Retrying. This may cause a loop.");
         goto retry;
      }
   }
}
