#include "include/parse_int.h"

typedef int (* base_operation_t)(int, int);

typedef bool(* base_char_verifier_t)(char);

typedef struct
{
    char prefix[2];
    base_operation_t calculate;
    base_char_verifier_t verifier;

} base_operation_s;

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

bool has_base(const char* input)
{
    return *input == '0' && *(input + 1) == 'x';
}

bool is_null_or_empty(const char* input)
{
    return input == NULL || *input == '\0';
}

static bool is_equals(const char* first, const char* second)
{
    while (*first != '\0' && *second != '\0')
    {
        if (*first != *second)
        {
            return false;
        }
        first++;
        second++;
    }
    return true;
}

static base_operation_s g_operations[] = {
        {
                "0x",
                calculateHex,
                is_valid_hex_number
        }
};

base_operation_s* get_operation(const char* input)
{
    size_t s = sizeof(g_operations) / sizeof(base_operation_s);
    for (int i = 0; i < s; ++i)
    {
        if (is_equals(g_operations[i].prefix, input))
        {
            return &g_operations[i];
        }
    }
    return NULL;
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

    bool hasBase = has_base(input);

    base_operation_t operation = calculate;
    base_char_verifier_t verifier = is_valid_number;

    if (hasBase)
    {
        base_operation_s* base = get_operation(input);
        if (base)
        {
            operation = base->calculate;
            verifier = base->verifier;
        }
        input += 2;
    }

    while ((c = *input++) != '\0')
    {
        if (!verifier(c))
        {
            return result;
        }

        char number = get_number(c);

        result = operation(result, number);
    }

    return isNegative
           ? -result
           : result;
}
