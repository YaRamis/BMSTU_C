#ifndef _MY_UTILS_H
#define _MY_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_MAX 26
#define STRUCTS_MAX 15

#define ARG_ERROR 2
#define FILE_OPEN_ERROR 3
#define FILE_READ_ERROR 4
#define STRING_OVERFLOW 5
#define PREFIX_OVERFLOW 6
#define NO_SIMILAR 7
#define STRUCTS_OVERFLOW 8
#define EMPTY_FILE 9
#define EMPTY_STRING 10
#define INCORRECT_NUMBER 11
#define INCORRECT_VALUE 12

typedef double weight_t;
typedef double volume_t;

typedef struct
{
    char *name;
    weight_t weight;
    volume_t volume;
} item_t;

#endif