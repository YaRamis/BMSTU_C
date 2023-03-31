#include "my_utils.h"
#include "mysort.h"
#include "key.h"
#include "io_file.h"

#define MAX_ARGS 4
#define MIN_ARGS 3

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    if ((argc != MAX_ARGS && argc != MIN_ARGS) || (argc == MAX_ARGS && strcmp(argv[3], "f")))
        return ARG_ERROR;

    FILE *f;
    
    f = fopen(argv[1], "r");
    if (f == NULL)
        return FILE_OPEN_ERROR;
    
    fseek(f, 0, SEEK_END);
    long pos = ftell(f);
    if (pos == 0)
    {
        fclose(f);
        return EMPTY_FILE;
    }
    rewind(f);

    int rc = EXIT_SUCCESS;
    int elements_amount = 0;

    rc = count_elements(f, &elements_amount);
    rewind(f);

    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        return rc;
    }

    int *pb_in = calloc(elements_amount, sizeof(int));

    if (pb_in == NULL)
    {
        fclose(f);
        return MEM_ALLOC_ERROR;
    }

    int *pe_in = pb_in + elements_amount;
    int second_alloc = 0;

    input_arr(f, pb_in, pe_in);
    fclose(f);

    int *pb_out, *pe_out;
    
    if (argc == MAX_ARGS)
    {
        rc = key(pb_in, pe_in, &pb_out, &pe_out);
        second_alloc = rc;
    }
    else
    {
        pb_out = pb_in;
        pe_out = pe_in;
    }

    if (rc != EXIT_SUCCESS)
    {
        free(pb_in);
        if (argc == MAX_ARGS && second_alloc == 0)
            free(pb_out);
        return rc;
    }

    mysort(pb_out, pe_out - pb_out, sizeof(int), compare_int);
    f = fopen(argv[2], "w");
    if (f == NULL)
    {
        free(pb_in);
        if (argc == MAX_ARGS && second_alloc == 0)
            free(pb_out);
        return FILE_OPEN_ERROR;
    }

    output_arr(f, pb_out, pe_out);
    fclose(f);

    free(pb_in);
    if (argc == MAX_ARGS && second_alloc == 0)
        free(pb_out);

    return EXIT_SUCCESS;
}
