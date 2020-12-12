#include "include/factorial.h"

uint64_t factorial(uint32_t number)
{
    if (number < 1)
    {
        return 1;
    }

    return number * factorial(number - 1);
}

