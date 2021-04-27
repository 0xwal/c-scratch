#include "include/joaat.h"


uint32_t joaat(const char* input)
{
    if (input == NULL) {
        return 0;
    }

    uint32_t hash = 0;
    int i = 0;

    while (input[i] != '\0')
    {
        hash = hash + input[i];
        hash = hash + (hash << 10);
        hash = hash ^ (hash >> 6);
        i++;
    }

    hash = hash + (hash << 3);
    hash = hash ^ (hash >> 11);
    hash = hash + (hash << 15);


    return hash;
}
