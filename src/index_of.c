#include "include/index_of.h"


int index_of(const char* haystack, const char* needle)
{
    if (!haystack || !needle || *haystack == '\0' || *needle == '\0')
    {
        return -1;
    }

    for (int i = 0; i < haystack[i] != '\0'; ++i)
    {
        for (int j = 0; j < needle[j] != '\0'; ++j)
        {
            char currentCharOfHaystack = haystack[i + j];
            char currentCharOfNeedle = needle[j];

            if (currentCharOfHaystack == '\0')
            {
                return -1;
            }

            if (currentCharOfHaystack != currentCharOfNeedle)
            {
                break;
            }

            if (needle[j + 1] == '\0')
            {
                return i;
            }
        }
    }
    return -1;
}
