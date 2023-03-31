#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMAX 10
#define EPS 1e-8

int input_arr(int *m, size_t size)
{
    size_t i;
    for (i = 0; i < size; ++i) 
        if (scanf("%d", &m[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void output_arr(int *m, size_t size)
{
    size_t i;
    for (i = 0; i < size; ++i)
        printf("%d ", m[i]);
}

int full_square_check(int number)
{
    if (number == 0)
        return 1;
    double el;
    el = floor(exp((1.0 / 2.0) * log(number)) + EPS);
    el = exp((2.0) * log(el));
    if (el <= number + EPS && el >= number - EPS)
        return 1;
    return 0;
}

int main(void)
{
    int a[NMAX];
    size_t n, i, j;
    int k;
    
    if (scanf("%zu", &n) != 1 || n > NMAX || n == 0)
        return EXIT_FAILURE;
    
    if (input_arr(a, n) == EXIT_FAILURE)
        return EXIT_FAILURE;
    
    for (i = 0; i < n; ++i)
    {
        k = full_square_check(a[i]);
        if (k == 1)
        {
            for (j = i; j < n - 1; j++)
                a[j] = a[j + 1];
            i--;
            n--;
            continue;
        }
    }
    if (n == 0)
        return EXIT_FAILURE;

    output_arr(a, n);

    return EXIT_SUCCESS;
}