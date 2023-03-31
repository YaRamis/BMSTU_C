#ifndef _KEY_H_
#define _KEY_H_

#include "my_utils.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void find_min_element(int **pmin, const int *pe);
void find_max_element(int **pmax, const int *pe);
void fill_new_arr(int **pb, int **pe, int *pmin);

#endif
