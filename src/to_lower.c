#include "include/to_lower.h"

char* to_lower(char* input)
{
    if (input == NULL)
    {
        return NULL;
    }

    char* ptr = input;

    while (*ptr != '\0')
    {
        *ptr = to_lower_char(*ptr);
        ptr++;
    }

    return input;
}

char to_lower_char(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
    {
        return (char)(letter | 0x20);
    }
    return letter;
}

