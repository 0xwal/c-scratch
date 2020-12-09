#include <stdio.h>
#include <index_of.h>

int main()
{
    const char* sample = "Hello World";

    int index = index_of(sample, "World");
    printf("index of '%s' is %d\n", &sample[index], index);
    
    return 0;
}

