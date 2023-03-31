#include <stdio.h>
#include <stdlib.h>

#define R 10
#define C 10

int matrix_input(int a[][C], size_t *r, size_t *c)
{
    for (size_t i = 0; i < *r; ++i)
        for (size_t j = 0; j < *c; ++j)
            if (scanf("%d", &a[j][i]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int cheking_column(int a[C], size_t *r)
{
    if (*r > 1)
    {
        for (size_t i = 1; i < *r; ++i)
            if (a[i - 1] * a[i] > 0 || a[i - 1] * a[i] == 0)
                return 0;
        return 1;
    }
    return 0;
}

void arr_output(int *a, size_t *size)
{
    for (size_t i = 0; i < *size; ++i)
    {
        printf("%d ", *a);
        ++a;
    }
}

int main(void)
{
    int a[R][C];
    int b[C];
    size_t r, c;

    if (scanf("%zu", &r) != 1 || r > R || r == 0)
    {
        printf("invalid input (row)");
        return EXIT_FAILURE;
    }

    if (scanf("%zu", &c) != 1 || c > C || c == 0)
    {
        printf("invalid input (column)");
        return EXIT_FAILURE;
    }

    if (matrix_input(a, &r, &c) == EXIT_FAILURE)
    {
        printf("invalid input (matrix elements)");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < c; ++i)
        b[i] = cheking_column(a[i], &r);

    arr_output(b, &c);

    return EXIT_SUCCESS;
}
