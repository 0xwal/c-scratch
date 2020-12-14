#include "include/xor.h"

size_t length(const char* input)
{
    size_t length = 0;
    while (input[length] != '\0') length++;
    return length;
}

char* xor_encrypt(char* input, const char* key)
{
    if (!input)
    {
        return NULL;
    }

    size_t keyLength = length(key);
    size_t inputLength = length(input);

    for (size_t i = 0; i < inputLength; ++i)
    {
        char ored = (char)(input[i] ^key[i % keyLength]);
        if (!ored)
            ored = input[i];
        input[i] = ored;
    }

    return input;
}


char* xor_decrypt(char* input, const char* key)
{
    return xor_encrypt(input, key);
}
