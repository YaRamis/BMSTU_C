#include "my_utils.h"

int count_elements(FILE *f, int *amount)
{
    int elem = 0;
    *amount = 0;
    while (!feof(f))
    {
        if (fscanf(f, "%d", &elem) != 1)
        {
            if (!feof(f))
                return ELEM_READ_ERROR;
            else
                break;
        }
        (*amount)++;
    }
    if (*amount == 0)
        return EMPTY_FILE;
    return EXIT_SUCCESS;
}
