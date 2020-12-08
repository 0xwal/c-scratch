#include "include/parse_int.h"

bool is_valid_number(char c)
{
    return (c >= '0' && c <= '9');
}

char get_number(char c)
{
    if (is_valid_number(c))
    {
        return (char)(c - '0');
    }
    return (char)(((c | 0x20) - 'a') + 10);
}

bool is_valid_hex_number(char c)
{
    c = (char)(c | 0x20);
    return is_valid_number(c) || (c >= 'a' && c <= 'f');
}

int calculate(int r, int number)
{
    return r * 10 + number;
}

int calculateHex(int r, int number)
{
    return (r << 4) | (number & 0xF);
}

const char* skip_spaces(const char* input)
{
    while (*input == ' ') { input++; }
    return input;
}

bool is_input_prefixed_with_0x(const char* input)
{
    return *input == '0' && *(input + 1) == 'x';
}

bool is_null_or_empty(const char* input)
{
    return input == NULL || *input == '\0';
}

int parse_int(const char* input)
{
    if (is_null_or_empty(input))
    {
        return 0;
    }

    input = skip_spaces(input);

    char c;
    int result = 0;

    bool isNegative = *input == '-';

    if (isNegative)
    {
        input++;
    }

    bool isHex = is_input_prefixed_with_0x(input);

    if (isHex)
    {
        input += 2;
    }

    while ((c = *input++) != '\0')
    {
        bool isValid = isHex
                       ? is_valid_hex_number(c)
                       : is_valid_number(c);

        if (!isValid)
        {
            return result;
        }

        char number = get_number(c);

        result = isHex
                 ? calculateHex(result, number)
                 : calculate(result, number);

    }
    return isNegative
           ? -result
           : result;
}
