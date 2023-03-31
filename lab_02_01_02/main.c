#include <stdio.h>
#include <stdlib.h>

#define NMAX 10

int input_arr(int *m, size_t size)
{
    size_t i;
    for (i = 0; i < size; ++i) 
        if (scanf("%d", &m[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

double finding_average(int *m, size_t n)
{
    size_t i;
    int j = 0;
    double sum = 0;
    for (i = 0; i < n; ++i)
        if (m[i] < 0)
        {
            sum += m[i];
            j++;
        }

    if (j == 0)
        return 1.0;
    return sum / j;
}

int main(void)
{
    int a[NMAX];
    size_t n;
    double average;
    
    if (scanf("%zu", &n) != 1 || n > NMAX || n == 0)
        return EXIT_FAILURE;
    
    if (input_arr(a, n) == EXIT_FAILURE)
        return EXIT_FAILURE;
    
    average = finding_average(a, n);
    if (average > 0)
        return EXIT_FAILURE;

    printf("%lf", average);

    return EXIT_SUCCESS;
}