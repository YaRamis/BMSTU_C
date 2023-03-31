#include "mem_actions.h"

int allocate_matrix(int rows, int columns, int **matrix, int *arr)
{
    matrix = malloc(rows * (sizeof(int *));
    if (matrix == NULL)
        return MEM_ALLOC_ERROR;
    arr = malloc(rows * columns * sizeof(int));
    if (arr == NULL)
    {
        free(matrix);
        return MEM_ALLOC_ERROR;
    }
    for (int i = 0; i < rows; i++)
        matrix[i] = arr + sizeof(int) * columns * i;
    return EXIT_SUCCESS;
}

void free_matrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}