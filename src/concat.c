//
// Created by WA on 25/02/2022.
//

#include <stdlib.h>
#include "include/concat.h"

#define CONCAT_OUT_CHUNK_SIZE 64

void resize_if_needed(size_t currentSize, char** pointer, size_t newSize)
{
    if (currentSize == 0 || currentSize % CONCAT_OUT_CHUNK_SIZE != 0)
    {
        return;
    }

    char* p = realloc(*pointer, newSize);
    if (p == *pointer)
    {
        return;
    }
    *pointer = p;
}

size_t append(char** dest, const char* src, size_t* start)
{
    const char* sepCursor = src;
    size_t totalSize = 0;
    while (*sepCursor != '\0')
    {
        size_t startSize = *start;
        resize_if_needed(startSize, &*dest, startSize + CONCAT_OUT_CHUNK_SIZE);
        *(*dest + startSize) = *sepCursor;
        sepCursor++;
        (*start)++;
        totalSize++;
    }
    return totalSize;
}

char* concat(const char** input, const char* separator)
{
    if (input == NULL)
    {
        return NULL;
    }

    char* out = calloc(CONCAT_OUT_CHUNK_SIZE, 1);

    char* cur = input[0];
    size_t i = 1;
    size_t outCursor = 0;
    size_t separatorSize = 0;
    while (cur)
    {
        char* chunk = cur;

        append(&out, chunk, &outCursor);

        if (separator != NULL)
        {
            separatorSize = append(&out, separator, &outCursor);
        }

        cur = input[i++];
    }

    if (separator)
    {
        out[outCursor - separatorSize] = 0;
    }

    return out;
}
