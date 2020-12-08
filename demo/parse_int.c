#include <stdio.h>
#include <parse_int.h>

int main()
{
    const char* sample = "1238321";
    printf("%d\n", parse_int(sample));

    return 0;
}

