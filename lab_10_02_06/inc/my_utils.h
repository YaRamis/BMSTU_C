#ifndef _MY_UTILS_H_
#define _MY_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matr_list_t
{
    int row;
    int col;
    int data;
    struct matr_list_t *next;    
} matr_list_t;

// ERRORS
#define ARG_ERROR 2
#define MEM_ALLOC_ERROR 3
#define ELEM_READ_ERROR 4
#define MATRIX_SIZE_READ_ERROR 5
#define INVALID_MATRIX_SIZE 6
#define ACTION_READ_ERROR 7
#define WRONG_ACTION 8
#define EMPTY_MATRIX_LIST 9

// ACTIIONS
#define OUT "out"
#define ADD "add"
#define MUL "mul"
#define LIN "lin"

#endif
