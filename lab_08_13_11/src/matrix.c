#include "matrix.h"

void free_matrix(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

double **allocate_matrix(int n, int m)
{
    double **matrix = calloc(n, sizeof(double*));

    if (!matrix)
        return NULL;
    
    for (int i = 0; i < n; i++)
    {
        matrix[i] = malloc(m * sizeof(double));

        if (!matrix[i])
        {
            free_matrix(matrix, n);
            return NULL;
        }
    }

    return matrix;
}

int fread_matrix(FILE *f, double **matrix, int n, int m)
{
    double elem;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (fscanf(f, "%lf", &elem) != 1)
                return ELEM_READ_ERROR;
            
            matrix[i][j] = elem;
        }
    
    return EXIT_SUCCESS;
}

double my_pow(double a, int b)
{
    if (b == 0)
        return 1;
    else if (b < 0)
    {
        a = 1.0 / a;
        b = -b;
    }
    double res = a;
    for (int i = 1; i < b; i++)
        res *= a;
    return res;
}

void fill_minor(double **matrix, int n, double **minor, int matr_i, int matr_j)
{
    int minor_i = 0, minor_j = 0;

    for (int i = 0; i < n; i++)
    {
        if (i != matr_i)
        {
            for (int j = 0; j < n; j++)
                if (j != matr_j)
                {
                    minor[minor_i][minor_j] = matrix[i][j];
                    minor_j++;
                }
            if (minor_j == n - 1)
                minor_i++;
            minor_j = 0;
        }
    }
}

int get_matrix_determinant(double **matrix, int n, double *determinant)
{
    if (n == 1)
        (*determinant) = matrix[0][0];
    else if (n == 2)
        (*determinant) = (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
    else
    {
        for (int i = 0; i < n; i++)
        {
            double **minor = allocate_matrix(n - 1, n - 1);

            if (minor == NULL)
                return MEM_ALLOC_ERROR;
            
            double minor_determinant = 0;
            fill_minor(matrix, n, minor, i, 0);

            if (get_matrix_determinant(minor, n - 1, &minor_determinant) != EXIT_SUCCESS)
            {
                free_matrix(minor, n - 1);
                return MEM_ALLOC_ERROR;
            }

            free_matrix(minor, n - 1);

            (*determinant) += my_pow(-1, i + 2) * matrix[i][0] * minor_determinant;
        }
    }
    return EXIT_SUCCESS;
}

double **get_matrix_sum(double **matrix1, double **matrix2, int n, int m)
{
    double **sum = allocate_matrix(n, m);
    if (sum == NULL)
        return NULL;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
    
    return sum;
}

double **get_matrix_product(double **matrix1, double **matrix2, int n, int n2, int m2)
{
    double **product = allocate_matrix(n, m2);
    if (product == NULL)
        return NULL;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m2; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < n2; k++)
                product[i][j] += matrix1[i][k] * matrix2[k][j];
        }
        

    return product;
}

void fwrite_matrix(FILE *f, double **matrix, int n, int m)
{
    fprintf(f, "%d %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(f, "%.6lf ", matrix[i][j]);
        fprintf(f, "\n");
    }
}
