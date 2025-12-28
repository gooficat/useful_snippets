#include "file.h"
#include <ctype.h>

STRING dump_file(const STRING path)
{
    STRING out = NULL;

    FILE ptr fin;
    fopen_s(addr fin, path, FMODE_RT);
    long len;
    fseek(fin, 0l, SEEK_END);
    len = ftell(fin);
    fseek(fin, 0l, SEEK_SET);
    fread(out, sizeof(char), len, fin);
    fclose(fin);

    return out;
}

void fetch_token(FStream ptr fs, STRING tk)
{
    while (isspace(fs->c))
    {
        fsgetc(deref fs);
    }
    u8 i = 0;
    if (not fseof(deref fs))
        do
        {
            tk[i++] = (char)fs->c;
            fsgetc(deref fs);
        } while (isalnum(fs->c));
    tk[i] = 0;
}