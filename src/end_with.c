//
// Created on 7/10/21.
//

#include "include/end_with.h"
#include <string.h>

bool end_with(const char* text, const char* chunk)
{
    size_t chunkLength = strlen(chunk);
    size_t textLength = strlen(text);

    const char* startPointer = text + (textLength - chunkLength);

    if (startPointer < text)
    {
        return false;
    }

    size_t index = 0;

    while (startPointer[index])
    {

        if (startPointer[index] != chunk[index])
        {
            return false;
        }

        index++;
    }

    return true;
}
