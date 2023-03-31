#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#define DIGITS (CHAR_BIT * sizeof(uint32_t))

void print_bin(uint32_t a2)
{
    for (int i = DIGITS - 1; i >= 0; i--)
    {
        if (((a2 >> i) & 1) == 1)
            printf("1");
        else
            printf("0");
    }
}

int shl(uint32_t a1, int n1)
{
    return (a1 << n1) | (a1 >> (DIGITS - n1));
}

int main(void)
{
    uint32_t a;
    int n;

    if (scanf("%u %d", &a, &n) != 2)
    {
        printf("Error: unsuccessful read and assign");

        return EXIT_FAILURE;
    }

    if (n < 0)
    {
        printf("Error: negative value");

        return EXIT_FAILURE;
    }

    printf("Result: ");

    print_bin(shl(a, n));

    return EXIT_SUCCESS;
}