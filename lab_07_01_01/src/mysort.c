#include "mysort.h"

void mysort(void *base, size_t nmemb, const size_t size, int (*compar)(const void*, const void*))
{
    for (char *i = (char *)base + size; i < (char *)base + nmemb * size; i += size)
    {
        char *ptr_lo = (char *)base, *ptr_hi = i - size;

        binary_search(&ptr_lo, &ptr_hi, size, i, compar);

        for (char *j = i; j > ptr_lo; j -= size)
            swap(j - size, j, size);
    }
}

void binary_search(char **lo, char **hi, const size_t size, const char *key, int (*compar)(const void*, const void*))
{
    while (*lo < *hi)
    {
        size_t n = (*hi - *lo) / (2 * size);
        char *mid = *lo + size * n;
        if (compar(key, mid) < 0)
            *hi = mid;
        else
            *lo = mid + size;
    }
    if (*lo == *hi && compar((void *)key, (void *)*lo) >= 0)
        *lo += size;
}

int compare_int(const void *p, const void *q)
{
    int *a = (int *)p;
    int *b = (int *)q;
    return *a - *b;
}

void swap(char *src, char *dst, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        char temp = *(dst + i);
        *(dst + i) = *(src + i);
        *(src + i) = temp;
    }
}
