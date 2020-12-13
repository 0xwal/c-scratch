

#ifndef RC4_H
#define RC4_H

#include "common.h"

BEGIN_DECL

void rc4(const char* key, size_t keyLength, const char* plain, size_t plainLength, char* result);

END_DECL

#endif //RC4_H
