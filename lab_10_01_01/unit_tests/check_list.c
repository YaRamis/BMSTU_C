#include "check_main.h"
#include "list.h"

START_TEST(test_append_both_null)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;

    append(&head_1, &head_2);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
}

START_TEST(test_append_first_null)
{
    int data = 9;
    node_t *head_1 = NULL;
    node_t *head_2 = create_node((void *)(&data));
    if (head_2 == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    node_t *tmp = head_2;

    append(&head_1, &head_2);

    ck_assert_ptr_eq(head_1, tmp);
    ck_assert_ptr_null(head_2);

    free_list(head_1);
}

START_TEST(test_append_second_null)
{
    int data = 9;
    node_t *head_2 = NULL;
    node_t *head_1 = create_node((void *)(&data));
    if (head_1 == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    node_t *tmp = head_1;

    append(&head_1, &head_2);

    ck_assert_ptr_eq(head_1, tmp);
    ck_assert_ptr_null(head_2);

    free_list(head_1);
}

START_TEST(test_append_both_not_null)
{
    int data_1 = 9;
    int data_2 = 9;
    node_t *head_2 = create_node((void *)(&data_2));
    if (head_2 == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    node_t *head_1 = create_node((void *)(&data_1));
    if (head_1 == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    node_t *tmp_1 = head_1;
    node_t *tmp_2 = head_2;

    append(&head_1, &head_2);

    ck_assert_ptr_eq(head_1, tmp_1);
    ck_assert_ptr_eq(head_1->next, tmp_2);
    ck_assert_ptr_null(head_2);

    free_list(head_1);
}

Suite *append_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("append");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_append_both_null);
    tcase_add_test(tc_neit, test_append_first_null);
    tcase_add_test(tc_neit, test_append_second_null);
    tcase_add_test(tc_neit, test_append_both_not_null);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_pop_back)
{
    int data_1 = 9;
    int data_2 = 10;
    node_t *head = create_node((void *)(&data_1));
    if (head == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    head->next = create_node((void *)(&data_2));
    if (head->next == NULL)
    {
        free_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    
    int data = *((int *)(pop_back(&head)));

    ck_assert_ptr_nonnull(head);
    ck_assert_ptr_null(head->next);
    ck_assert_int_eq(data, 10);

    free_list(head);
}

START_TEST(test_pop_front)
{
    int data_1 = 9;
    int data_2 = 10;
    node_t *head = create_node((void *)(&data_1));
    if (head == NULL)
        ck_abort_msg("MEM_ALLOC_ERROR");
    head->next = create_node((void *)(&data_2));
    if (head->next == NULL)
    {
        free_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    
    int data = *((int *)(pop_front(&head)));

    ck_assert_ptr_nonnull(head);
    ck_assert_ptr_null(head->next);
    ck_assert_int_eq(data, 9);

    free_list(head);
}

Suite *pop_back_front_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("pop_back_front");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_pop_back);
    tcase_add_test(tc_neit, test_pop_front);
    suite_add_tcase(s, tc_neit);

    return s;
}
