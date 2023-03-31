#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int plus_i(int iteration)
{
    return iteration + 1;
}
int main(void)
{
    int n;
    int i = 1;
    int fibi = 0, fibj = 1;
    int fibn = 0;

    if (scanf("%d", &n) != 1 || n < 0)
        return EXIT_FAILURE;

    while (i < n)
    {
        if ((INT_MAX - fibi) < fibj)
            return EXIT_FAILURE;
        fibi = fibi + fibj;
        i = plus_i(i);
        if ((INT_MAX - fibi) < fibj)
            return EXIT_FAILURE;
        fibj = fibi + fibj;
        i = plus_i(i);
    }

    if (i == n)
        fibn = fibj;

    if (i > n)
        fibn = fibi;

    printf("%d", fibn);

    return EXIT_SUCCESS;
}