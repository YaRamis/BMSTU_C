#include "my_functions.h"

void bubble_sort(items_t items, const size_t items_count)
{
    for (size_t i = 0; i < items_count - 1; i++)
        for (size_t j = items_count - 1; j > i; j--)
            if (items[j - 1].weight / items[j - 1].volume > items[j].weight / items[j].volume)
            {
                item_t temp = items[j - 1];
                items[j - 1] = items[j];
                items[j] = temp;
            }
}

void print_all_items(const items_t items, const size_t items_count)
{
    for (size_t i = 0; i < items_count; i++)
        print_item(items[i]);
}

void print_item(const item_t item)
{
    printf("%s\n", item.name);
    printf("%.6lf\n", item.weight);
    printf("%.6lf\n", item.volume);
}

int print_items_by_prefix(const items_t items, const size_t items_count, const char *prefix)
{
    if (strlen(prefix) == ALL_LENGTH && check_prefix_to_all(prefix) == EXIT_SUCCESS)
        print_all_items(items, items_count);
    else
    {
        int item_flag = 0;
        
        for (size_t i = 0; i < items_count; i++)
            if (strncmp(prefix, items[i].name, strlen(prefix)) == 0)
            {
                item_flag = 1;
                print_item(items[i]);
            }
        if (item_flag == 0)
            return NO_SIMILAR;
    }
    
    return EXIT_SUCCESS;
}

int input_items(FILE *f, item_t *items, size_t *items_count)
{
    int rc = 0;
    
    while (!feof(f))
    {
        if (*items_count >= STRUCTS_MAX)
            return STRUCTS_OVERFLOW;
        rc = input_item(f, &items[*items_count]);
        if (rc != EXIT_SUCCESS)
            return rc;
        (*items_count)++;
    }
    
    if (!feof(f))
        return FILE_READ_ERROR;
    
    return EXIT_SUCCESS;
}

int input_item(FILE *f, item_t *item)
{
    int rc = 0;
    
    //ввод поля с именем
    rc = input_str(f, item->name);
    if (rc != EXIT_SUCCESS)
        return rc;
    
    str_t number_s;
    
    // ввод поля с массой
    rc = input_str(f, number_s);
    if (rc != EXIT_SUCCESS)
        return rc;
    rc = str_to_double(number_s, &item->weight);
    if (rc != EXIT_SUCCESS)
        return rc;
    
    //ввод поля с объемом
    rc = input_str(f, number_s);
    if (rc != EXIT_SUCCESS)
        return rc;
    rc = str_to_double(number_s, &item->volume);
    if (rc != EXIT_SUCCESS)
        return rc;
    
    return EXIT_SUCCESS;
}

int input_str(FILE *f, str_t str)
{
    char str_temp[NAME_MAX + 1];
    
    if (fgets(str_temp, NAME_MAX + 1, f) == NULL)
        return FILE_READ_ERROR;
    // if (fscanf(f, "%s", str_temp) != 1)
        // return FILE_READ_ERROR;
    if (strchr(str_temp, '\n') != NULL)
        *(strchr(str_temp, '\n')) = '\0';
    if (strlen(str_temp) >= NAME_MAX)
        return STRING_OVERFLOW;
    if (strlen(str_temp) == 0)
        return EMPTY_STRING;
    
    strncpy(str, str_temp, NAME_MAX);
    
    return EXIT_SUCCESS;
}

int str_to_double(str_t str, double *num)
{
    int i = 0;
    int points = 0;
    
    while (str[i] != '\0')
    {
        if (str[i] == '.')
            points++;
        else if (isdigit(str[i]) == 0)
            return INCORRECT_NUMBER;
        i++;
    }
    
    if (points > 1)
        return INCORRECT_NUMBER;
    
    double num_temp = 0.0;
    num_temp = atof(str);
    
    if (num_temp - 1e-8 < 0)
        return INCORRECT_VALUE;
    
    *num = num_temp;
    
    return EXIT_SUCCESS;
}

int check_prefix_to_all(const char *prefix)
{
    if (toupper(prefix[0]) == 'A' && toupper(prefix[1]) == 'L' && toupper(prefix[2]) == 'L')
        return EXIT_SUCCESS;
    
    return EXIT_FAILURE;
}