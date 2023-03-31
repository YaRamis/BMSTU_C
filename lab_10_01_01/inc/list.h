#ifndef _LIST_OPERATIONS_H_
#define _LIST_OPERATIONS_H_

#include "my_utils.h"

void append(node_t **head_a, node_t **head_b);
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
void *pop_back(node_t **head);
void *pop_front(node_t **head);
void free_list(node_t *head);
int fread_list(FILE *f, node_t **head);
int push_cars_to_list(cars_t *cars, node_t **head);
int push_list(node_t **head, void *data);
node_t *create_node(void *data);
void fwrite_list(node_t *head, FILE *f);

#endif
