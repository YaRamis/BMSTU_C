#ifndef _MY_UTILS_H_
#define _MY_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARG_ERROR 2
#define FILE_OPEN_ERROR 3
#define EMPTY_FILE 4
#define MEM_ALLOC_ERROR 5
#define ELEM_READ_ERROR 6
#define EQUAL_MIN_MAX 7
#define NO_ELEMENTS 8

int count_elements(FILE *f, int *amount);

#endif
