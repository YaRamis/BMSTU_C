#include "input.h"

int input_matrix_size(int *rows, int *columns, FILE *f)
{
    if (fscanf(f, "%d %d", rows, columns) != 2)
    {
        fclose(f);
        return MATRIX_SIZE_ERROR;
    }
    return EXIT_SUCCESS;
}

int input_matrix_elems(int **matrix, int rows, int columns, FILE *f)
{
    for (int i = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (fscanf(f, "%d", *(*matrix + sizeof(int *) * i) + sizeof(int) * j) != 1)
            {
                free_matrix(matrix, rows);
                fclose(f);
                return INCORR_ELEM;
            }
    fclose(f);
    return EXIT_SUCCESS;
}