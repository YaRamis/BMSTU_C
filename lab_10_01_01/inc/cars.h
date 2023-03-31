#ifndef _CARS_H_
#define _CARS_H_

#include "my_utils.h"

void free_cars(cars_t *cars);
int fread_cars(cars_t *cars, FILE *f);
int compare_cars_by_year(const void *car_1, const void *car_2);

#endif
