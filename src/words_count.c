#include "include/words_count.h"

#define SMALL_LETTER_BITMASK 0b00100000

bool is_letter(char value)
{
    int smallLetter = value | SMALL_LETTER_BITMASK;
    return smallLetter >= 'a' && smallLetter <= 'z';
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
        char currentChar = *input++;

        if (is_letter(currentChar) && !calculated)
        {
            count++;
            calculated = true;
            continue;
        }


        if (currentChar == ' ')
        {
            calculated = false;
        }

    }

    return count;

}

// Another solution suggested by Fabreaz#2247
//This solutions not aware of symbol and other stuff
/*
    while (*input == ' ') input++; //This ignores all leading whitespaces

    for (int i = 0; input[i] != '\0'; ++i)
    {
        if (i == 0) //consider this a non-space and we should count one because there is no previous space that we count on.
        {
            count++;
            continue;
        }

        if (input[i - 1] == ' ' && is_letter(input[i])) // make sense, each word should be preceded by a space unless if its the start word
        {
            count++;
        }
    }
 */
