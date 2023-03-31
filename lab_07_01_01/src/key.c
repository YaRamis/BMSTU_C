#include "key.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int *pmin_el = (int *)pb_src, *pmax_el = (int *)pb_src;

    find_min_element(&pmin_el, pe_src);
    find_max_element(&pmax_el, pe_src);
    
    if (pmin_el == pmax_el)
        return EQUAL_MIN_MAX;
    
    if (pmin_el > pmax_el)
    {
        int *pbuf = pmax_el;
        pmax_el = pmin_el;
        pmin_el = pbuf;
    }

    if (pmin_el + 1 == pmax_el)
        return NO_ELEMENTS;

    int n = pmax_el - pmin_el - 1;
    
    *pb_dst = malloc(n * sizeof(int));
    if (*pb_dst == NULL)
        return MEM_ALLOC_ERROR;
    
    *pe_dst = *pb_dst + n;
    fill_new_arr(pb_dst, pe_dst, pmin_el);
    
    return EXIT_SUCCESS;
}

void find_min_element(int **pmin, const int *pe)
{
    for (int *i = *pmin; i < pe; i++)
        if (*i < **pmin)
            *pmin = i;
}

void find_max_element(int **pmax, const int *pe)
{
    for (int *i = *pmax; i < pe; i++)
        if (*i > **pmax)
            *pmax = i;
}

void fill_new_arr(int **pb, int **pe, int *pmin)
{
    for (int *i = *pb; i < *pe; i++)
    {
        pmin++;
        *i = *pmin;
    }
}
