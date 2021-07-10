//
// Created on 7/10/21.
//

#include "include/start_with.h"

bool start_with(const char* text, const char* chunk)
{
    size_t i = 0;
    bool flag = true;

    while (chunk[i] != '\0')
    {
        if (text[i] == '\0') {
            flag = false;
            break;
        }

        if (text[i] != chunk[i]) {
            flag = false;
            break;
        }

        i++;
    }

    return flag;
}
