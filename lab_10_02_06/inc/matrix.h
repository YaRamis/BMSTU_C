#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "my_utils.h"

int input_matrix_to_list(matr_list_t **head, int *n, int *m);
void free_matrix_list(matr_list_t *head);
matr_list_t *create_matr_list_node(int data, int row, int col);
int push_matrix_list(matr_list_t **head, int data, int row, int col);
int output_matrix_list(matr_list_t *head);
matr_list_t *add_matrix_lists(matr_list_t *head_1, matr_list_t *head_2);
matr_list_t *mul_matrix_lists(matr_list_t *head_1, matr_list_t *head_2, int n, int m);
int delete_max_element_matrix_list(matr_list_t **head);

#endif
