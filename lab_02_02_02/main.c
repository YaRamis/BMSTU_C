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

void output_arr(int *m, size_t size)
{
    size_t i;
    for (i = 0; i < size; ++i)
        printf("%d ", m[i]);
}

int checking_number(int number)
{
    //if (number / 10 == 0)
    //    return EXIT_FAILURE;
    int first, last;
    last = number % 10;
    first = number;
    while (first >= 10)
        first = first / 10;
    if (first == last)
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

int making_new_arr(int *m1, int *m2, size_t size1, size_t size2)
{
    size_t i;
    for (i = 0; i < size1; ++i)
        if (checking_number(abs(m1[i])) == EXIT_SUCCESS)
        {
            m2[size2] = m1[i];
            size2++;
        }
    return size2;
}

int main(void)
{
    size_t n, j = 0;
    int a[NMAX];
    int b[NMAX];
    
    if (scanf("%zu", &n) != 1 || n > NMAX || n == 0)
        return EXIT_FAILURE;
    if (input_arr(a, n) == EXIT_FAILURE)
        return EXIT_FAILURE;
    j = making_new_arr(a, b, n, j);
    if (j == 0)
        return EXIT_FAILURE;
    
    output_arr(b, j);
    
    return EXIT_SUCCESS;
}