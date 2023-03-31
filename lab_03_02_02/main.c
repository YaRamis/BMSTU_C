#include <stdio.h>
#include <stdlib.h>

#define RCMAX 20
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

int cheking_row(int a[RCMAX], size_t *c)
{
    int el;
    int sum;
    int j;
    int count = 0;
    for (size_t i = 0; i < *c; ++i)
    {
        sum = 0;
        el = abs(a[i]);
        j = 1;
        while (el > 0)
        {
            sum += (el % (j * 10)) / j;
            el = el - el % (j * 10);
            j *= 10;
        }
        if (sum % 2 == 1)
            ++count;
    }
    if (count < 2)
        return 1;
    return 0;
}

void inserting_row(int a[][RCMAX], size_t *r, size_t *i, size_t *c)
{
    for (size_t j = 0; j < (*r - *i); ++j)
    {
        int *p = a[*r - j];
        int *q = a[*r - j - 1];
        for (p = a[*r - j]; p < a[*r - j] + *c; ++p)
        {
            *p = *q;
            ++q;
        }
    }
    for (int *p = a[*i]; p < a[*i] + *c; ++p)
        *p = -1;
    ++*r;
    ++*i;
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
        if (cheking_row(a[i], &c) == 0)
            inserting_row(a, &r, &i, &c);

    matrix_output(a, &r, &c);

    return EXIT_SUCCESS;
}
