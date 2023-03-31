#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "my_utils.h"

void free_matrix(double **matrix, int n);
double **allocate_matrix(int n, int m);
int fread_matrix(FILE *f, double **matrix, int n, int m);
int get_matrix_determinant(double **matrix, int n, double *determinant);
void fill_minor(double **matrix, int n, double **minor, int matr_i, int matr_j);
double my_pow(double a, int b);
double **get_matrix_sum(double **matrix1, double **matrix2, int n, int m);
double **get_matrix_product(double **matrix1, double **matrix2, int n, int n2, int m2);
void fwrite_matrix(FILE *f, double **matrix, int n, int m);

#endif
