#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include <check.h>
#include "my_utils.h"

#define EPS 1e-7

Suite *compare_cars_by_year_suite(void);
Suite *fread_cars_suite(void);
Suite *pop_back_front_suite(void);
Suite *append_suite(void);

#endif
