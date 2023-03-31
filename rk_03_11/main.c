#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"

int main(void)
{
    FILE *f;
    int rc = EXIT_SUCCESS;
    
    rc = file_open(f);
    if (rc == EXIT_SUCCESS)
        rc = empty_file_check(f);
        if (rc == EXIT_SUCCESS)
        {
            int rows, columns;
            rc =  input_matrix_size(&rows, &columns, f);
            if (rc == EXIT_SUCCESS)
            {
                int **matrix;
                int *arr;
                rc = allocate_matrix(rows, columns, matrix, arr);
                if (rc == EXIT_SUCCESS)
                {
                    rc = input_matrix_elems(matrix, rows, columns, f);
                    if (rc = EXIT_SUCCESS)
                    {
                        int rows_null_matr, columns_null_matr;
                        int **null_matr;
                        rc = find_min_null_matrix(matrix, rows, columns, null_matr, &rows_null_matr, &columns_null_matr);
                        if (rc == EXIT_SUCCESS)
                        {
                            rc = delete_columns(matrix, matrix, rows, columns, null_matr, rows_null_matr, columns_null_matr);
                            if (rc == EXIT_SUCCESS)
                            {
                                rc = output_matrix(matrix);
                            }
                        }
                    }
                }
                else
                    fclose(f);
            }
        }
        
    return rc;
}