//
// Created by 0xWaleed on 11/8/2021.
//

#ifndef EXPLODE_H
#define EXPLODE_H

#include "common.h"

typedef struct
{
    char** values;
    size_t count;
} explode_s;


BEGIN_DECL

explode_s explode_make(const char* text, char character);
void explode_clean(explode_s* exp);

END_DECL

#endif //EXPLODE_H
