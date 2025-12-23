#pragma once

#include <stdio.h>
#include "defs.h"

struc_t
{
   FILE ptr f;
   int c;
}
fstream_t;

str dump_file(const str in_path);

void fetch_token(fstream_t ptr fs, str tk);

#define fsgetc(fs) (fs).c = fgetc((fs).f);

#define fsopen(fs, path, mode)                                                                     \
   fopen_s(addr(fs).f, path, mode);                                                                \
   fsgetc(fs);

#define fsclose(fs) fclose((fs).f);

#define fseof(fs) ((fs).c == EOF)
