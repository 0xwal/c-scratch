

#include "include/to_upper.h"

char* to_upper(char* input)
{
    if (input == NULL)
    {
        return NULL;
    }

    char* ptr = input;
    while (*ptr != '\0')
    {
        *ptr = to_upper_char(*ptr);
        ptr++;
    }

    return input;
}


char to_upper_char(char letter)
{
    if (letter >= 'a' && letter <= 'z')
    {
        return (char)(letter & 0xDF);
    }

    return letter;
}
