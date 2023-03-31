#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include <check.h>
#include "my_utils.h"

#define EPS 1e-7

Suite *count_elements_suite(void);
Suite *key_suite(void);
Suite *mysort_suite(void);
Suite *binary_search_suite(void);
Suite *compare_int_suite(void);
Suite *fill_new_arr_suite(void);
Suite *find_min_element_suite(void);
Suite *find_max_element_suite(void);
Suite *swap_suite(void);

#endif
