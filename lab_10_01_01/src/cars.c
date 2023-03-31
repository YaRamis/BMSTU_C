#include "../inc/cars.h"

void free_cars(cars_t *cars)
{
    if (cars->arr != NULL)
    {
        free(cars->arr);
        cars->arr = NULL;
    }
    cars->size = 0;
}

int fread_cars(cars_t *cars, FILE *f)
{
    int ch, pre = EOF, counter = 0;

    while ((ch = fgetc(f)) != EOF)
    {
        pre = ch;
        if (ch == '\n')
            counter++;
    }

    if (pre == EOF)
        return EMPTY_FILE;
    else if (pre != '\n')
        counter++;
    
    rewind(f);
    
    cars->size = counter;
    cars->arr = malloc(cars->size * sizeof(car_t));
    if (cars->arr == NULL)
        return MEM_ALLOC_ERROR;

    int rc;
    
    for (int i = 0; i < cars->size; i++)
    {
        rc = fscanf(f, "%s %d", cars->arr[i].brand, &(cars->arr[i].year)); 
        if (rc != 2 || cars->arr[i].year <= 0)
        {
            free_cars(cars);
            return ELEM_READ_ERROR;
        }
    }
    
    return EXIT_SUCCESS;
}

int compare_cars_by_year(const void *car_1, const void *car_2)
{
    car_t car_1_tmp = *((car_t *)car_1);
    car_t car_2_tmp = *((car_t *)car_2);
    return car_1_tmp.year - car_2_tmp.year;
}
