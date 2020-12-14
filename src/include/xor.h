#ifndef XOR_H
#define XOR_H

#include "common.h"

BEGIN_DECL

char* xor_encrypt(char* input, const char* key);

char* xor_decrypt(char* input, const char* key);

END_DECL

#endif //XOR_H
