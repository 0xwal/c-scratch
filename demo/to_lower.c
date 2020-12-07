#include <stdio.h>
#include <to_lower.h>

int main()
{
    char sample[] = "This IS A String THAT contains A CAPITAL Letters";
    printf("%s", to_lower(sample));

    return 0;
}
