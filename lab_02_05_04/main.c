#include <stdio.h>
#include <stdlib.h>

#define NMAX 10

int input_arr(int *m, size_t *size)
{
    if (scanf("%zu", size) != 1 || *size == 0 || *size > NMAX)
        return EXIT_FAILURE;
    size_t i;
    for (i = 0; i < *size; ++i)
    {
        if (scanf("%d", m) != 1)
            return EXIT_FAILURE;
        m++;
    }
    return EXIT_SUCCESS;
}

int amount_of_unique_nums(int *m, size_t *size)
{
    int amount = 0;
    int *pb;

    for (size_t i = 0; i < *size; ++i)
    {
        pb = m;
        for (size_t j = i + 1; j < *size; ++j)
        {
            pb++;
            if (*m == *pb)
            {
                amount++;
                break;
            }
        }
        m++;
    }
    return *size - amount;
}

int main(void)
{
    int a[NMAX];
    int *pa = a;
    size_t n;
    
    int exit_code = input_arr(pa, &n);
    if (exit_code == EXIT_FAILURE)
        return EXIT_FAILURE;
    pa = a;
    int am = amount_of_unique_nums(pa, &n);
    printf("%d", am);
    return EXIT_SUCCESS;
}
