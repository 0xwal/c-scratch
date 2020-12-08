#include "include/parse_int.h"

int parse_int(const char* input)
{
    if (input == NULL || *input == '\0')
    {
        return 0;
    }
    char c;
    int result = 0;
    bool isNegative = false;

    while (*input == ' ')
    {
        input++;
    }

    while ((c = *input) != '\0')
    {
        input++;
        if (c == ' ')
        {
            break;
        }
        if (c == '-')
        {
            isNegative = true;
            continue;
        }

        if (!(c >= '0' && c <= '9'))
        {
            break;
        }

        result = result * 10 + (c - '0');
    }
    return isNegative ? -result : result;
}
