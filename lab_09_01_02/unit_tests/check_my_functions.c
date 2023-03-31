#include "check_main.h"
#include "my_functions.h"

START_TEST(test_input_items_positive)
{
    FILE *f = fopen("unit_tests/test_input_items_positive.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    int rc = 0;
    size_t items_count = 0;
    item_t *items = malloc(sizeof(item_t) * STRUCTS_MAX);
    if (items == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    for (int i = 0; i < STRUCTS_MAX; i++)
    {
        items[i].name = malloc(sizeof(char) * NAME_MAX);
        if (items[i].name == NULL)
        {
            for (int j = 0; j < i; j++)
                free(items[j].name);
            free(items);
            ck_abort_msg("MEM_ALLOC_ERROR");
        }
    }
    
    rc = input_items(f, items, &items_count);
    
    fclose(f);
    for (int i = 0; i < STRUCTS_MAX; i++)
        free(items[i].name);
    free(items);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(test_input_items_overflow)
{
    FILE *f = fopen("unit_tests/test_input_items_overflow.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    int rc = 0;
    size_t items_count = 0;
    item_t *items = malloc(sizeof(item_t) * STRUCTS_MAX);
    if (items == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    for (int i = 0; i < STRUCTS_MAX; i++)
    {
        items[i].name = malloc(sizeof(char) * NAME_MAX);
        if (items[i].name == NULL)
        {
            for (int j = 0; j < i; j++)
                free(items[j].name);
            free(items);
            ck_abort_msg("MEM_ALLOC_ERROR");
        }
    }
    
    rc = input_items(f, items, &items_count);
    
    fclose(f);
    for (int i = 0; i < STRUCTS_MAX; i++)
        free(items[i].name);
    free(items);

    ck_assert_int_eq(rc, STRUCTS_OVERFLOW);
}

START_TEST(test_input_items_name_overflow)
{
    FILE *f = fopen("unit_tests/test_input_items_name_overflow.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    int rc = 0;
    size_t items_count = 0;
    item_t *items = malloc(sizeof(item_t) * STRUCTS_MAX);
    if (items == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    for (int i = 0; i < STRUCTS_MAX; i++)
    {
        items[i].name = malloc(sizeof(char) * NAME_MAX);
        if (items[i].name == NULL)
        {
            for (int j = 0; j < i; j++)
                free(items[j].name);
            free(items);
            ck_abort_msg("MEM_ALLOC_ERROR");
        }
    }
    
    rc = input_items(f, items, &items_count);
    
    fclose(f);
    for (int i = 0; i < STRUCTS_MAX; i++)
        free(items[i].name);
    free(items);

    ck_assert_int_eq(rc, STRING_OVERFLOW);
}

START_TEST(test_input_items_incorrect_num)
{
    FILE *f = fopen("unit_tests/test_input_items_incorrect_num.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    int rc = 0;
    size_t items_count = 0;
    item_t *items = malloc(sizeof(item_t) * STRUCTS_MAX);
    if (items == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    for (int i = 0; i < STRUCTS_MAX; i++)
    {
        items[i].name = malloc(sizeof(char) * NAME_MAX);
        if (items[i].name == NULL)
        {
            for (int j = 0; j < i; j++)
                free(items[j].name);
            free(items);
            ck_abort_msg("MEM_ALLOC_ERROR");
        }
    }
    
    rc = input_items(f, items, &items_count);
    
    fclose(f);
    for (int i = 0; i < STRUCTS_MAX; i++)
        free(items[i].name);
    free(items);

    ck_assert_int_eq(rc, INCORRECT_NUMBER);
}

START_TEST(test_input_items_num_equal_zero)
{
    FILE *f = fopen("unit_tests/test_input_items_num_equal_zero.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    int rc = 0;
    size_t items_count = 0;
    item_t *items = malloc(sizeof(item_t) * STRUCTS_MAX);
    if (items == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    for (int i = 0; i < STRUCTS_MAX; i++)
    {
        items[i].name = malloc(sizeof(char) * NAME_MAX);
        if (items[i].name == NULL)
        {
            for (int j = 0; j < i; j++)
                free(items[j].name);
            free(items);
            ck_abort_msg("MEM_ALLOC_ERROR");
        }
    }
    
    rc = input_items(f, items, &items_count);
    
    fclose(f);
    for (int i = 0; i < STRUCTS_MAX; i++)
        free(items[i].name);
    free(items);

    ck_assert_int_eq(rc, INCORRECT_VALUE);
}

Suite *input_items_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("input_items");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_input_items_overflow);
    tcase_add_test(tc_neg, test_input_items_name_overflow);
    tcase_add_test(tc_neg, test_input_items_incorrect_num);
    tcase_add_test(tc_neg, test_input_items_num_equal_zero);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_input_items_positive);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_bubble_sort_usual)
{
    size_t items_count = 5;
    item_t *items = malloc(sizeof(item_t) * STRUCTS_MAX);
    if (items == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    for (int i = 0; i < STRUCTS_MAX; i++)
    {
        items[i].name = malloc(sizeof(char) * NAME_MAX);
        if (items[i].name == NULL)
        {
            for (int j = 0; j < i; j++)
                free(items[j].name);
            free(items);
            ck_abort_msg("MEM_ALLOC_ERROR");
        }
    }

    strcpy(items[0].name, "4");
    items[0].volume = 3.75;
    items[0].weight = 15;
    strcpy(items[1].name, "2");
    items[1].volume = 2.2;
    items[1].weight = 4.4;
    strcpy(items[2].name, "5");
    items[2].volume = 4;
    items[2].weight = 20;
    strcpy(items[3].name, "1");
    items[3].volume = 2;
    items[3].weight = 2;
    strcpy(items[4].name, "3");
    items[4].volume = 1;
    items[4].weight = 3;

    bubble_sort(items, items_count);

    ck_assert_str_eq(items[0].name, "1");
    ck_assert_str_eq(items[1].name, "2");
    ck_assert_str_eq(items[2].name, "3");
    ck_assert_str_eq(items[3].name, "4");
    ck_assert_str_eq(items[4].name, "5");

    for (int i = 0; i < STRUCTS_MAX; i++)
        free(items[i].name);
    free(items);
}

START_TEST(test_bubble_sort_one_element)
{
    size_t items_count = 1;
    item_t *items = malloc(sizeof(item_t) * STRUCTS_MAX);
    if (items == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    for (int i = 0; i < STRUCTS_MAX; i++)
    {
        items[i].name = malloc(sizeof(char) * NAME_MAX);
        if (items[i].name == NULL)
        {
            for (int j = 0; j < i; j++)
                free(items[j].name);
            free(items);
            ck_abort_msg("MEM_ALLOC_ERROR");
        }
    }

    strcpy(items[0].name, "1");
    items[0].volume = 2;
    items[0].weight = 2;

    bubble_sort(items, items_count);

    ck_assert_str_eq(items[0].name, "1");
    ck_assert_double_eq(items[0].volume, 2);
    ck_assert_double_eq(items[0].weight, 2);

    for (int i = 0; i < STRUCTS_MAX; i++)
        free(items[i].name);
    free(items);
}

START_TEST(test_bubble_sort_equal_elements)
{
    size_t items_count = 2;
    item_t *items = malloc(sizeof(item_t) * STRUCTS_MAX);
    if (items == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    for (int i = 0; i < STRUCTS_MAX; i++)
    {
        items[i].name = malloc(sizeof(char) * NAME_MAX);
        if (items[i].name == NULL)
        {
            for (int j = 0; j < i; j++)
                free(items[j].name);
            free(items);
            ck_abort_msg("MEM_ALLOC_ERROR");
        }
    }

    strcpy(items[0].name, "1");
    items[0].volume = 2;
    items[0].weight = 2;
    strcpy(items[1].name, "2");
    items[1].volume = 4;
    items[1].weight = 4;

    bubble_sort(items, items_count);

    ck_assert_str_eq(items[0].name, "1");
    ck_assert_double_eq(items[0].volume, 2);
    ck_assert_double_eq(items[0].weight, 2);
    ck_assert_str_eq(items[1].name, "2");
    ck_assert_double_eq(items[1].volume, 4);
    ck_assert_double_eq(items[1].weight, 4);

    for (int i = 0; i < STRUCTS_MAX; i++)
        free(items[i].name);
    free(items);
}

Suite *bubble_sort_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("bubble_sort");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_bubble_sort_usual);
    tcase_add_test(tc_neit, test_bubble_sort_one_element);
    tcase_add_test(tc_neit, test_bubble_sort_equal_elements);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_str_to_double_no_dots)
{
    char str[] = "14";
    double num;

    int rc = str_to_double(str, &num);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_double_eq(14.0, num);
}

START_TEST(test_str_to_double_one_dot)
{
    char str[] = "14.3";
    double num;

    int rc = str_to_double(str, &num);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_double_eq(14.3, num);
}

START_TEST(test_str_to_double_two_dots)
{
    char str[] = "14.3.3";
    double num;

    int rc = str_to_double(str, &num);

    ck_assert_int_eq(rc, INCORRECT_NUMBER);
}

START_TEST(test_str_to_double_not_a_number)
{
    char str[] = "c4.a3";
    double num;

    int rc = str_to_double(str, &num);

    ck_assert_int_eq(rc, INCORRECT_NUMBER);
}

START_TEST(test_str_to_double_less_then_zero)
{
    char str[] = "-3.3";
    double num;

    int rc = str_to_double(str, &num);

    ck_assert_int_eq(rc, INCORRECT_NUMBER);
}

Suite *str_to_double_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("str_to_double");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_str_to_double_two_dots);
    tcase_add_test(tc_neg, test_str_to_double_not_a_number);
    tcase_add_test(tc_neg, test_str_to_double_less_then_zero);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_str_to_double_no_dots);
    tcase_add_test(tc_pos, test_str_to_double_one_dot);
    suite_add_tcase(s, tc_pos);

    return s;
}
