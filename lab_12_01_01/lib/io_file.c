#include "io_file.h"

void input_arr(FILE *f, const int *pb, const int *pe)
{
    for (int *i = (int *)pb; i < pe; i++)
        fscanf(f, "%d", i);
}

void output_arr(FILE *f, const int *pb, const int *pe)
{
    for (int *i = (int *)pb; i < pe; i++)
        fprintf(f, "%d ", *i);
}
