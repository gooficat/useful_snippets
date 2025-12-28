#pragma once

#include <stdio.h>
#include "better.h"

CLASS(FStream)
{
    FILE ptr f;
    int c;
};

STRING dump_file(const STRING in_path);

void fetch_token(FStream ptr fs, STRING tk);

#define fsgetc(fs) (fs).c = fgetc((fs).f);

#define fsopen(fs, path, mode)                                                                     \
    fopen_s(addr(fs).f, path, mode);                                                               \
    fsgetc(fs);

#define fsclose(fs) fclose((fs).f);

#define fseof(fs) ((fs).c == EOF)
