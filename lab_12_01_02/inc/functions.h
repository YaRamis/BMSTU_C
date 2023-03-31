#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>

#define ARR_PTR_NULL 1
#define ARR_SIZE_ERROR 2
#define SHIFT_NUM_ERROR 3
#define NO_PERFECT_SQUARES 4

int left_cyclic_shift_by_k(int *arr, int arr_size, int k);
int is_perfect_square(int num);
int copy_perfect_squares(int *src, int *dst, int n, int *dst_n);

#endif
