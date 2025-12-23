#include "str.h"
#include <stdlib.h>
#include <string.h>
#include "defs.h"

str copy_str(const str og)
{
   unsigned long long oglen = strlen(og) + 1;
   str out = malloc(oglen);
   strcpy_s(out, oglen, og);
   return out;
}