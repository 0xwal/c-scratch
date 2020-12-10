#include "include/power.h"

double power(double base, int64_t exponent)
{
    if (exponent == 0)
    {
        return 1;
    }

    if (exponent == 1)
    {
        return base;
    }

    if (exponent < 0)
    {
        exponent *= -1;
        base = 1 / base;
    }

    if (exponent >= 2)
    {
        double half = power(base, exponent / 2);
        return exponent % 2 != 0 ? ((half * half) * base) : (half * half);
    }

    return 0;
}

