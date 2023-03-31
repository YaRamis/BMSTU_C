#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

typedef struct node
{
    void *data;
    struct node *next;
} node_t;

typedef struct
{
    char brand[100];
    int year;
} car_t;

typedef struct
{
    car_t *arr;
    int size;
} cars_t;


#endif
