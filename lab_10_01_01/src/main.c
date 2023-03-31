#include "../inc/list.h"
#include "../inc/cars.h"

#define MIN_MAX_ARGS 4

int main(int argc, char **argv)
{
    if (argc != MIN_MAX_ARGS)
        return ARG_ERROR;
    
    FILE *f1;
    FILE *f2;

    f1 = fopen(argv[1], "r");
    if (f1 == NULL)
        return FILE_OPEN_ERROR;
    
    fseek(f1, 0, SEEK_END);
    long pos = ftell(f1);
    if (pos == 0)
    {
        fclose(f1);
        return EMPTY_FILE;
    }
    rewind(f1);

    f2 = fopen(argv[2], "r");
    if (f2 == NULL)
    {
        fclose(f1);
        return FILE_OPEN_ERROR;
    }
    
    fseek(f2, 0, SEEK_END);
    pos = ftell(f2);
    if (pos == 0)
    {
        fclose(f2);
        fclose(f1);
        return EMPTY_FILE;
    }
    rewind(f2);

    cars_t cars_1 = { NULL, 0 };
    cars_t cars_2 = { NULL, 0 };
    
    int rc = fread_cars(&cars_1, f1);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f2);
        fclose(f1);
        return rc;
    }

    rc = fread_cars(&cars_2, f2);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f2);
        fclose(f1);
        free_cars(&cars_1);
        return rc;
    }

    fclose(f1);
    fclose(f2);

    node_t *head_1 = NULL;

    rc = push_cars_to_list(&cars_1, &head_1);
    if (rc != EXIT_SUCCESS)
    {
        free_cars(&cars_1);
        free_cars(&cars_2);
        return rc;
    }

    node_t *head_2 = NULL;

    rc = push_cars_to_list(&cars_2, &head_2);
    if (rc != EXIT_SUCCESS)
    {
        free_cars(&cars_1);
        free_cars(&cars_2);
        free_list(head_1);
        return rc;
    }

    head_1 = sort(head_1, compare_cars_by_year);
    head_2 = sort(head_2, compare_cars_by_year);

    pop_back(&head_1);
    pop_back(&head_2);

    pop_front(&head_1);
    pop_front(&head_2);

    if (head_1 == NULL && head_2 == NULL)
    {
        free_cars(&cars_1);
        free_cars(&cars_2);
        free_list(head_1);
        free_list(head_2);
        return BOTH_LISTS_EMPTY;
    }

    append(&head_1, &head_2);

    head_1 = sort(head_1, compare_cars_by_year);

    FILE *f_out = fopen(argv[3], "w");
    if (f_out == NULL)
    {
        free_cars(&cars_1);
        free_cars(&cars_2);
        free_list(head_1);
        free_list(head_2);
        return FILE_OPEN_ERROR;
    }

    fwrite_list(head_1, f_out);

    free_cars(&cars_1);
    free_cars(&cars_2);
    free_list(head_1);
    free_list(head_2);
    fclose(f_out);

    return EXIT_SUCCESS;
}
