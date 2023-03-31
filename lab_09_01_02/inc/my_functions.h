#ifndef _MY_FUNCTIONS_H
#define _MY_FUNCTIONS_H

#define ALL_LENGTH 3

#include "my_utils.h"

void bubble_sort(item_t *items, const size_t items_count);
void print_all_items(const item_t *items, const size_t items_count);
void print_item(const item_t item);
int print_items_by_prefix(const item_t *items, const size_t items_count, const char *prefix);
int input_items(FILE *f, item_t *items, size_t *items_count);
int input_item(FILE *f, item_t *item);
int input_str(FILE *f, char *str);
int str_to_double(char *str, double *num);
int check_prefix_to_all(const char *prefix);

#endif