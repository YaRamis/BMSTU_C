#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMAX 10
#define ARR_FULL 100

int input_arr(int *m, size_t max_size, size_t *size)
{
    while (scanf("%d", &m[*size]) == 1)
    {
        (*size)++;
        if (*size > max_size)
        {
            *size = 10;
            return ARR_FULL;
        }
    }
    if (*size == 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void output_arr(int *m, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        printf("%d ", m[i]);
}

void selection_sort(int *m, size_t size)
{
    int temp;
    size_t min;
    for (size_t i = 0; i < size - 1; i++) 
    {
        min = i;

        for (size_t j = i + 1; j < size; j++)
            if (m[j] < m[min])
                min = j;

        temp = m[i];
        m[i] = m[min];
        m[min] = temp;
    }
}

int main(void)
{
    int a[NMAX];
    size_t i = 0;

    int exit_code = input_arr(a, NMAX, &i);
    if (exit_code == EXIT_FAILURE)
        return EXIT_FAILURE;
    selection_sort(a, i);
    output_arr(a, i);
    return exit_code;
}