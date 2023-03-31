#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include <check.h>
#include "my_utils.h"

#define EPS 1e-7

Suite *fread_matrix_suite(void);
Suite *my_pow_suite(void);
Suite *fill_minor_suite(void);
Suite *get_matrix_determinant_suite(void);
Suite *get_matrix_product_suite(void);
Suite *get_matrix_sum_suite(void);

#endif
