#include "my_utils.h"
#include "my_functions.h"

#define MAX_ARGS 3
#define MIN_ARGS 2

int main(int argc, char **argv)
{
    if (argc != MAX_ARGS && argc != MIN_ARGS)
        return ARG_ERROR;
    
    if (argc == MAX_ARGS && strlen(argv[2]) >= NAME_MAX)
        return PREFIX_OVERFLOW;
    
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
    
    int rc = 0;
    size_t items_count = 0;
    item_t *items = malloc(sizeof(item_t) * STRUCTS_MAX);
    for (int i = 0; i < STRUCTS_MAX; i++)
        items[i].name = malloc(sizeof(char) * NAME_MAX);
    
    rc = input_items(f, items, &items_count);
    
    fclose(f);
    
    if (rc == EXIT_SUCCESS)
    {
        if (argc == MIN_ARGS)
        {
            bubble_sort(items, items_count);
            print_all_items(items, items_count);
        }
        else
            rc = print_items_by_prefix(items, items_count, argv[2]);
    }
    
    for (int i = 0; i < STRUCTS_MAX; i++)
        free(items[i].name);
    free(items);

    return rc;
}