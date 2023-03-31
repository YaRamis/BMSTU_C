#include "../inc/functions.h"

int left_cyclic_shift_by_k(int *arr, int arr_size, int k)
{
    if (arr == NULL)
        return ARR_PTR_NULL;
    
    if (arr_size < 0)
        return ARR_SIZE_ERROR;
    
    if (k < 0)
        return SHIFT_NUM_ERROR;
    
    for (int i = 0; i < k; i++)
    {
        int tmp = arr[0];
        for (int j = 1; j <= arr_size; j++)
        {
            if (j == arr_size)
                arr[0] = tmp;
            else
            {
                int buf = arr[j];
                arr[j] = tmp;
                tmp = buf;
            }
        }
    }

    return EXIT_SUCCESS;
}

int is_perfect_square(int num)
{
    for (int i = 0; i <= num; i++)
        if (i * i == num)
            return EXIT_SUCCESS;
    
    return EXIT_FAILURE;
}

int copy_perfect_squares(int *src, int *dst, int n, int *dst_n)
{
    if (src == NULL || dst == NULL)
        return ARR_PTR_NULL;
    if (n < 0)
        return ARR_SIZE_ERROR;
    
    int j = 0;
    for (int i = 0; i < n; i++)
        if (is_perfect_square(src[i]) == EXIT_SUCCESS)
            dst[j++] = src[i];
    
    for (int i = j; i < n; i++)
        dst[i] = -1;
    
    if (j == 0)
        return NO_PERFECT_SQUARES;
    
    *dst_n = j;

    return EXIT_SUCCESS;
}
