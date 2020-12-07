#include <stdio.h>
#include <words_count.h>


int main()
{
    const char sample[] = "This is a sample text";
    printf("words count: %zu\n", words_count(sample));

    return 0;
}
