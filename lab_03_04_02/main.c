#include <stdio.h>
#include <stdlib.h>

#define RCMAX 10

int matrix_input(int a[][RCMAX], size_t *r)
{
    for (size_t i = 0; i < *r; ++i)
        for (size_t j = 0; j < *r; ++j)
            if (scanf("%d", &a[i][j]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void matrix_output(int a[][RCMAX], size_t *r)
{
    for (size_t i = 0; i < *r; ++i)
    {
        for (size_t j = 0; j < *r; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int finding_number(int a[][RCMAX], size_t *r)
{
    int number = 0;
    for (size_t i = 1; i < *r; ++i)
        for (size_t j = *r - i; j < *r; ++j)
            if (abs(a[i][j]) % 10 == 5)
                if (a[i][j] > number || number == 0)
                    number = a[i][j];
    return number;
}

int main(void)
{
    int a[RCMAX][RCMAX];
    size_t r;
    size_t c;

    int number;

    if (scanf("%zu", &r) != 1 || r > RCMAX || r <= 1)
        return EXIT_FAILURE;

    if (scanf("%zu", &c) != 1 || c > RCMAX || c <= 1)
        return EXIT_FAILURE;

    if (r != c)
        return EXIT_FAILURE;

    if (matrix_input(a, &r) == EXIT_FAILURE)
        return EXIT_FAILURE;

    number = finding_number(a, &r);

    if (number == 0)
        return EXIT_FAILURE;

    printf("%d", number);

    return EXIT_SUCCESS;
}
