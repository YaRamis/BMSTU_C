#include <stdio.h>
#include <stdlib.h>

#define RCMAX 11
#define R 10
#define C 10

int matrix_input(int a[][RCMAX], size_t *r, size_t *c)
{
    for (size_t i = 0; i < *r; ++i)
        for (size_t j = 0; j < *c; ++j)
            if (scanf("%d", &a[i][j]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void matrix_output(int a[][RCMAX], size_t *r, size_t *c)
{
    for (size_t i = 0; i < *r; ++i)
    {
        for (size_t j = 0; j < *c; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int product_of_row_elements(int a[RCMAX], size_t *c)
{
    int product = 1;
    for (size_t i = 0; i < *c; ++i)
        product *= a[i];
    return product;
}

void matrix_sorting(int a[][RCMAX], size_t *r, size_t *c)
{
    for (size_t i = 0; i < *r - 1; ++i)
        for (size_t j = 0; j < *r - i - 1; ++j)
            if (a[j][*c] > a[j + 1][*c])
            {
                int tmp[RCMAX];
                for (size_t k = 0; k < *c + 1; ++k)
                    tmp[k] = a[j][k];
                for (size_t k = 0; k < *c + 1; ++k)
                    a[j][k] = a[j + 1][k];
                for (size_t k = 0; k < *c + 1; ++k)
                    a[j + 1][k] = tmp[k];
            }
}

int main(void)
{
    int a[RCMAX][RCMAX];
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

    for (size_t i = 0; i < r; ++i)
        a[i][c] = product_of_row_elements(a[i], &c);

    matrix_sorting(a, &r, &c);

    matrix_output(a, &r, &c);

    return EXIT_SUCCESS;
}
