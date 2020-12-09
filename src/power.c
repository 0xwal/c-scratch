double power(double base, double exponent)
{
    if (!base)
    {
        return 0;
    }

    double r = 1;

    for (int i = 0; i < exponent; ++i)
    {
        r *= base;
    }
    return r;
}

