#include "include/pow.h"

double s_pow(double base, double power)
{
    double r = 1;


    for (int i = 0; i < power; ++i)
    {
        r = r * base;
    }

    return r;
}
