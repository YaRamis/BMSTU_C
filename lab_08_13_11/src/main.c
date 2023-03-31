#include "matrix.h"

#define MAX_ARGS 5
#define MIN_ARGS 4

int main(int argc, char **argv)
{
    if (argc != MIN_ARGS && argc != MAX_ARGS)
        return ARG_ERROR;
    
    if (strcmp("o", argv[1]) != 0 && strcmp("a", argv[1]) != 0 && strcmp("m", argv[1]) != 0)
        return ARG_ERROR;

    if (strcmp("o", argv[1]) == 0 && argc != MIN_ARGS)
        return ARG_ERROR;
    else if ((strcmp("a", argv[1]) == 0 || strcmp("a", argv[1]) == 0) && argc != MAX_ARGS)
        return ARG_ERROR;
    
    int n, m;

    FILE *f;
    
    f = fopen(argv[2], "r");
    if (f == NULL)
        return FILE_OPEN_ERROR;
    
    fseek(f, 0, SEEK_END);
    long pos = ftell(f);
    if (pos == 0)
    {
        fclose(f);
        return EMPTY_FILE;
    }
    rewind(f);

    if (fscanf(f, "%d", &n) != 1 || fscanf(f, "%d", &m) != 1)
    {
        fclose(f);
        return MATRIX_SIZE_READ_ERROR;
    }

    if (n <= 0 || m <= 0)
    {
        fclose(f);
        return INVALID_MATRIX_SIZE;
    }

    double **matrix1 = allocate_matrix(n, m);
        
    if (matrix1 == NULL)
    {
        fclose(f);
        return MEM_ALLOC_ERROR;
    }

    if (fread_matrix(f, matrix1, n, m) != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix1, n);
        return ELEM_READ_ERROR;
    }

    fclose(f);

    if (strcmp("o", argv[1]) == 0)
    {
        if (n != m)
        {
            free_matrix(matrix1, n);
            return INVALID_MATRIX_SIZE;
        }

        double determinant = 0;
        if (get_matrix_determinant(matrix1, n, &determinant) != EXIT_SUCCESS)
        {
            free_matrix(matrix1, n);
            return MEM_ALLOC_ERROR;
        }

        free_matrix(matrix1, n);

        f = fopen(argv[3], "w");
        if (f == NULL)
            return FILE_OPEN_ERROR;
        
        fprintf(f, "%.6lf\n", determinant);

        fclose(f);
    }
    else
    {
        f = fopen(argv[3], "r");
        if (f == NULL)
        {
            free_matrix(matrix1, n);
            return FILE_OPEN_ERROR;
        }
        
        fseek(f, 0, SEEK_END);
        long pos = ftell(f);
        if (pos == 0)
        {
            fclose(f);
            free_matrix(matrix1, n);
            return EMPTY_FILE;
        }
        rewind(f);

        int n2, m2;
        if (fscanf(f, "%d", &n2) != 1 || fscanf(f, "%d", &m2) != 1)
        {
            fclose(f);
            free_matrix(matrix1, n);
            return MATRIX_SIZE_READ_ERROR;
        }

        if (n2 <= 0 || m2 <= 0)
        {
            fclose(f);
            free_matrix(matrix1, n);
            return INVALID_MATRIX_SIZE;
        }

        double **matrix2 = allocate_matrix(n2, m2);
        
        if (matrix2 == NULL)
        {
            fclose(f);
            free_matrix(matrix1, n);
            return MEM_ALLOC_ERROR;
        }

        if (fread_matrix(f, matrix2, n2, m2) != EXIT_SUCCESS)
        {
            fclose(f);
            free_matrix(matrix1, n);
            free_matrix(matrix2, n2);
            return ELEM_READ_ERROR;
        }

        fclose(f);

        if (strcmp("a", argv[1]) == 0)
        {
            if (n2 != n || m2 != m)
            {
                free_matrix(matrix1, n);
                free_matrix(matrix2, n2);
                return INVALID_MATRIX_SIZE;
            }
            double **sum = get_matrix_sum(matrix1, matrix2, n, m);
            if (sum == NULL)
            {
                free_matrix(matrix1, n);
                free_matrix(matrix2, n2);
                return MEM_ALLOC_ERROR;
            }

            free_matrix(matrix1, n);
            free_matrix(matrix2, n2);

            f = fopen(argv[4], "w");
            if (f == NULL)
            {
                free_matrix(sum, n);
                return FILE_OPEN_ERROR;
            }

            fwrite_matrix(f, sum, n, m);

            free_matrix(sum, n);

            fclose(f);
        }
        else if (strcmp("m", argv[1]) == 0)
        {
            if (n2 != m)
            {
                free_matrix(matrix1, n);
                free_matrix(matrix2, n2);
                return INVALID_MATRIX_SIZE;
            }
            double **product = get_matrix_product(matrix1, matrix2, n, n2, m2);
            if (product == NULL)
            {
                free_matrix(matrix1, n);
                free_matrix(matrix2, n2);
                return MEM_ALLOC_ERROR;
            }

            free_matrix(matrix1, n);
            free_matrix(matrix2, n2);

            f = fopen(argv[4], "w");
            if (f == NULL)
            {
                free_matrix(product, n);
                return FILE_OPEN_ERROR;
            }

            fwrite_matrix(f, product, n, m2);
            
            free_matrix(product, n);

            fclose(f);
        }
    }

    return EXIT_SUCCESS;
}
