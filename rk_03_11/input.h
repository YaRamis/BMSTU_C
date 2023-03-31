#ifndef _INPUT_H_
#define _INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "mem_actions.h"

int input_matrix_size(int *rows, int *columns, FILE *f);
int input_matrix_elems(int **matrix, int rows, int columns, FILE *f);

#endif