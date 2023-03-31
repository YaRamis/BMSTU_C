#include <stdio.h>
#include <stdlib.h>

#define RCMAX 100
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

int is_prime(int number)
{
    if (number > 1)
    {
        for (int i = 2; i < number; ++i)
            if (number % i == 0)
                return 1;
    }
    else
        return 1;
    return 0;
}

size_t filling_arr(int b[RCMAX], int a[][RCMAX], size_t *r, size_t *c)
{
    size_t i = 0;
    for (size_t j = 0; j < *r; ++j)
        for (size_t k = 0; k < *c; ++k)
            if (is_prime(a[j][k]) == 0)
            {
                b[i] = a[j][k];
                ++i;
            }
    return i;
}

void reverse_arr(int b[RCMAX], size_t *n)
{
    for (size_t i = 0; i < *n / 2; ++i)
    {
        int tmp = b[i];
        b[i] = b[*n - i - 1];
        b[*n - i - 1] = tmp;
    }
}

void from_arr_to_matrix(int b[RCMAX], int a[][RCMAX], size_t *r, size_t *c)
{
    size_t i = 0;
    for (size_t j = 0; j < *r; ++j)
        for (size_t k = 0; k < *c; ++k)
            if (is_prime(a[j][k]) == 0)
            {
                a[j][k] = b[i];
                ++i;
            }
}

int main(void)
{
    int a[RCMAX][RCMAX];
    size_t r, c;

    int b[RCMAX];
    size_t len_b;

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

    len_b = filling_arr(b, a, &r, &c);
    if (len_b == 0)
    {
        printf("there are no prime numbers in matrix");
        return EXIT_FAILURE;
    }

    reverse_arr(b, &len_b);

    from_arr_to_matrix(b, a, &r, &c);

    matrix_output(a, &r, &c);

    return EXIT_SUCCESS;
}
