#include "include/string_length.h"


size_t string_length(const char* input)
{

    if (input == NULL || *input == '\0')
    {
        return 0;
    }

    const char* ptr = input;

    while (*ptr++ != '\0');

    return ptr - input - 1;

}

