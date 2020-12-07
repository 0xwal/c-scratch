#include <stdio.h>
#include <string_length.h>

int main()
{
    const char sample[] = "This i a sample text to get the length";
    printf("length of %s is %zu", sample, string_length(sample));

    return 0;
}
