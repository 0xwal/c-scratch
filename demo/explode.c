//
// Created by 0xWaleed on 11/9/2021.
//

#include <explode.h>
#include <stdio.h>

int main() {
    explode_s exp = explode_make("1,2,3,4,5,6,7,8,9", ',');

    printf("Found %zu elements\n", exp.count);

    for (int i = 0; i < exp.count; ++i)
    {
        printf("%d, %s\n", i, exp.values[i]);
    }

    explode_clean(&exp);
    return 0;
}
