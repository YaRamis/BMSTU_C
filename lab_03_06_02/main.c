#include <stdio.h>
#include <stdlib.h>

#define R 10
#define C 10

void matrix_output(int a[][C], size_t *r, size_t *c)
{
    for (size_t i = 0; i < *r; ++i)
    {
        for (size_t j = 0; j < *c; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void filling_matrix(int a[][C], size_t *r, size_t *c)
{
    int el = *r * *c;
    int flag = 0;
    for (size_t i = 0; i < *c; ++i)
    {
        if (flag == 0)
        {
            for (size_t j = 0; j < *r; ++j)
            {
                a[*r - j - 1][i] = el;
                el--;
            }
            flag = 1;
            continue;
        }
        for (size_t j = 0; j < *r; ++j)
        {
            a[j][i] = el;
            el--;
        }
        flag = 0;
    }
}

int main(void)
{
    int a[R][C];
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

    filling_matrix(a, &r, &c);

    matrix_output(a, &r, &c);

    return EXIT_SUCCESS;
}
