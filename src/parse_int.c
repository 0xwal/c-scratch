#include "include/parse_int.h"

char get_number(char c)
{
    if (c >= '0' && c <= '9')
    {
        return (char)(c - '0');
    }
    return (char)(((c | 0x20) - 'a') + 10);
}

bool is_valid_number(char c)
{
    return (c >= '0' && c <= '9');
}

bool is_valid_hex_number(char c)
{
    c = (char)(c | 0x20);
    return is_valid_number(c) || (c >= 'a' && c <= 'f');
}

int calculate(int result, int number)
{
    return result * 10 + number;
}

int calculateHex(int result, int number)
{
    return (result << 4) | (number & 0xF);
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

int parse_int(const char* input)
{
    if (input == NULL || *input == '\0')
    {
        return 0;
    }


    input = skip_spaces(input);

    char c;
    int result = 0;
    bool isNegative = false;

    bool isHex = is_input_prefixed_with_0x(input);

    if (isHex)
    {
        input += 2;
    }

    while ((c = *input) != '\0')
    {
        input++;

        if (c == '-')
        {
            isNegative = true;
            continue;
        }

        bool isValid = isHex ? is_valid_hex_number(c) : is_valid_number(c);

        if (!isValid)
        {
            return result;
        }

        int number = get_number(c);

        result = isHex
                 ? calculateHex(result, number)
                 : calculate(result, number);

    }
    return isNegative ? -result : result;
}
