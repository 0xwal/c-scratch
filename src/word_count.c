#include "include/word_count.h"

bool is_letter(char value)
{

    return ((value | 0x20) >= 'a' && (value | 0x20) <= 'z');
}

bool is_null_or_empty_string(const char* input)
{
    return input == NULL || *input == '\0';
}

size_t words_count(const char* input)
{

    if (is_null_or_empty_string(input))
    {
        return 0;
    }

    int count = 0;
    bool calculated = false;

    while (*input != '\0')
    {
        char currentChar = *input;
        input++;

        if (is_letter(currentChar) && !calculated)
        {
            count++;
            calculated = true;
            continue;
        }


        if (currentChar == ' ')
        {
            calculated = false;
            continue;
        }

    }

    return count;

}
