#ifndef _MEM_ACTIONS_H_
#define _MEM_ACTIONS_H_

int allocate_matrix(int rows, int columns, int **matrix, int *arr);
void free_matrix(int **matrix, int rows);

#endif