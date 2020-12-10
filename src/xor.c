#include "include/xor.h"

char* xor_encrypt(char* input, char key)
{
    if (!input)
    {
        return NULL;
    }

    char* ptr = input;

    while (*ptr != '\0')
    {
        *ptr = (char)(*ptr ^ key);
        ptr++;
    }

    return input;
}
