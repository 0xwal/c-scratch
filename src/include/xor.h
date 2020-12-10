#ifndef XOR_H
#define XOR_H

#include "common.h"

BEGIN_DECL

char* xor_encrypt(char* input, char key);

char* xor_decrypt(char* input, char key);

END_DECL

#endif //XOR_H
