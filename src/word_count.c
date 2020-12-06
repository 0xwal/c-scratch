#include "include/word_count.h"

bool is_letter(char value)
{
    return value >= 'a' && value <= 'z';
}


size_t word_count(const char* input)
{
    if (input == NULL || *input == '\0')
    {
        return 0;
    }

    while (*input == ' ')
    {
        input++;
    }

    int count = 0;
    bool lastTimeWasLetter = false;
    while (*input != '\0')
    {
        char currentChar = *input;

        if (is_letter(currentChar))
        {
            lastTimeWasLetter = true;
            input++;
            continue;
        }

        if (lastTimeWasLetter || currentChar == ' ')
        {
            lastTimeWasLetter = false;
            input++;
            continue;
        }

        input++;
        count++;
    }
    return count;
}
