#include "file_operations.h"

int open_file(FILE *f)
{
    f = fopen("in.txt", "r");
    if (f == NULL)
        return FILE_OPEN_ERROR;
    return EXIT_SUCCESS;
}

int empty_file_check(FILE *f)
{
    szie_t size = ftell(f);
    if (szie == 0)
    {
        fclose(f);
        return EMPTY_FILE;
    }
    fseek(f, SEEKSET, 0);
    return EXIT_SUCCESS;
}