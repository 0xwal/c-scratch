
#include "include/rc4.h"

#define PERMUTATION_LENGTH 256

void swap(uint8_t* a, uint8_t* b)
{
    uint8_t tmpA = *a;
    *a = *b;
    *b = tmpA;
}

void identity_permutation(uint8_t* s)
{
    for (int i = 0; i < PERMUTATION_LENGTH; ++i)
    {
        s[i] = i;
    }
}

void key_scheduling_algorithm(uint8_t* s, const char* key, size_t keyLength)
{
    identity_permutation(s);

    int j = 0;
    for (int i = 0; i < PERMUTATION_LENGTH; ++i)
    {
        j = (j + s[i] + key[i % keyLength]) % PERMUTATION_LENGTH;
        swap(&s[i], &s[j]);
    }
}

void pseudo_random_generation_algorithm(uint8_t* s, const char* plain, size_t plainLength, char* result)
{
    int i = 0;
    int j = 0;

    for (int n = 0; n < plainLength; ++n)
    {
        i = (i + 1) % PERMUTATION_LENGTH;
        j = (j + s[i]) % PERMUTATION_LENGTH;

        swap(&s[i], &s[j]);

        result[n] = s[(s[i] + s[j]) % PERMUTATION_LENGTH] ^ plain[n];
    }
}

void rc4(const char* key, size_t keyLength, const char* plain, size_t plainLength, char* result)
{
    uint8_t s[PERMUTATION_LENGTH];
    key_scheduling_algorithm(s, key, keyLength);
    pseudo_random_generation_algorithm(s, plain, plainLength, result);
}

