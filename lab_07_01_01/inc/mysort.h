#ifndef _MYSORT_H_
#define _MYSORT_H_

#include "my_utils.h"

void mysort(void *base, size_t nmemb, const size_t size, int (*compar)(const void*, const void*));
void binary_search(char **lo, char **hi, const size_t size, const char *key, int (*compar)(const void*, const void*));
int compare_int(const void *p, const void *q);
void swap(char *src, char *dst, const size_t size);

#endif
