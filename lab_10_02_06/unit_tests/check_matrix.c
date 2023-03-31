#include "check_main.h"
#include "matrix.h"

START_TEST(test_add_matrix_lists_2x2_2x2_full)
{
    matr_list_t *head_1 = NULL;
    matr_list_t *head_2 = NULL;

    if (push_matrix_list(&head_1, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    matr_list_t *res = add_matrix_lists(head_1, head_2);
    if (res == NULL)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        free_matrix_list(res);
        ck_abort_msg("MATRIX ADD ERROR");
    }

    matr_list_t *tmp = res;
    ck_assert_int_eq(tmp->data, 2);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 2);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 2);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 2);
    
    free_matrix_list(head_1);
    free_matrix_list(head_2);
    free_matrix_list(res);
}

START_TEST(test_add_matrix_lists_2x2_2x2_not_full)
{
    matr_list_t *head_1 = NULL;
    matr_list_t *head_2 = NULL;

    if (push_matrix_list(&head_1, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    matr_list_t *res = add_matrix_lists(head_1, head_2);
    if (res == NULL)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        free_matrix_list(res);
        ck_abort_msg("MATRIX ADD ERROR");
    }

    matr_list_t *tmp = res;
    ck_assert_int_eq(tmp->data, 2);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 2);
    
    free_matrix_list(head_1);
    free_matrix_list(head_2);
    free_matrix_list(res);
}

START_TEST(test_add_matrix_lists_1x1_2x2_full)
{
    matr_list_t *head_1 = NULL;
    matr_list_t *head_2 = NULL;

    if (push_matrix_list(&head_1, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    if (push_matrix_list(&head_2, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    matr_list_t *res = add_matrix_lists(head_1, head_2);
    if (res == NULL)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        free_matrix_list(res);
        ck_abort_msg("MATRIX ADD ERROR");
    }

    matr_list_t *tmp = res;
    ck_assert_int_eq(tmp->data, 2);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 1);
    
    free_matrix_list(head_1);
    free_matrix_list(head_2);
    free_matrix_list(res);
}

START_TEST(test_add_matrix_lists_2x2_2x2_zero_res)
{
    matr_list_t *head_1 = NULL;
    matr_list_t *head_2 = NULL;

    if (push_matrix_list(&head_1, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, -1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, -1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, -1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, -1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    matr_list_t *res = add_matrix_lists(head_1, head_2);
    
    ck_assert_ptr_null(res);
    
    free_matrix_list(head_1);
    free_matrix_list(head_2);
    free_matrix_list(res);
}

Suite *add_matrix_lists_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("add_matrix_lists");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_add_matrix_lists_2x2_2x2_zero_res);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_add_matrix_lists_2x2_2x2_full);
    tcase_add_test(tc_pos, test_add_matrix_lists_2x2_2x2_not_full);
    tcase_add_test(tc_pos, test_add_matrix_lists_1x1_2x2_full);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_mul_matrix_lists_2x2_2x2_full)
{
    matr_list_t *head_1 = NULL;
    matr_list_t *head_2 = NULL;

    if (push_matrix_list(&head_1, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    matr_list_t *res = mul_matrix_lists(head_1, head_2, 2, 2);
    if (res == NULL)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        free_matrix_list(res);
        ck_abort_msg("MATRIX MUL ERROR");
    }

    matr_list_t *tmp = res;
    ck_assert_int_eq(tmp->data, 2);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 2);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 2);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 2);
    
    free_matrix_list(head_1);
    free_matrix_list(head_2);
    free_matrix_list(res);
}

START_TEST(test_mul_matrix_lists_2x2_2x2_not_full)
{
    matr_list_t *head_1 = NULL;
    matr_list_t *head_2 = NULL;

    if (push_matrix_list(&head_1, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_1, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    matr_list_t *res = mul_matrix_lists(head_1, head_2, 2, 2);
    if (res == NULL)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        free_matrix_list(res);
        ck_abort_msg("MATRIX ADD ERROR");
    }

    matr_list_t *tmp = res;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 2);
    
    free_matrix_list(head_1);
    free_matrix_list(head_2);
    free_matrix_list(res);
}

START_TEST(test_mul_matrix_lists_1x1_2x2_full)
{
    matr_list_t *head_1 = NULL;
    matr_list_t *head_2 = NULL;

    if (push_matrix_list(&head_1, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    if (push_matrix_list(&head_2, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    matr_list_t *res = mul_matrix_lists(head_1, head_2, 1, 2);
    if (res == NULL)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        free_matrix_list(res);
        ck_abort_msg("MATRIX ADD ERROR");
    }

    matr_list_t *tmp = res;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    
    free_matrix_list(head_1);
    free_matrix_list(head_2);
    free_matrix_list(res);
}

START_TEST(test_mul_matrix_lists_2x2_2x2_zero_res)
{
    matr_list_t *head_1 = NULL;
    matr_list_t *head_2 = NULL;

    if (push_matrix_list(&head_1, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, -1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    if (push_matrix_list(&head_1, -1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, -1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    if (push_matrix_list(&head_1, -1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, -1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    if (push_matrix_list(&head_1, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head_2, -1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head_1);
        free_matrix_list(head_2);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    matr_list_t *res = mul_matrix_lists(head_1, head_2, 2, 2);
    
    ck_assert_ptr_null(res);
    
    free_matrix_list(head_1);
    free_matrix_list(head_2);
    free_matrix_list(res);
}

Suite *mul_matrix_lists_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("mul_matrix_lists");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_mul_matrix_lists_2x2_2x2_zero_res);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_mul_matrix_lists_2x2_2x2_full);
    tcase_add_test(tc_pos, test_mul_matrix_lists_2x2_2x2_not_full);
    tcase_add_test(tc_pos, test_mul_matrix_lists_1x1_2x2_full);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_delete_max_element_matrix_list_2x2_all_eq)
{
    matr_list_t *head = NULL;

    if (push_matrix_list(&head, 1, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    int rc = delete_max_element_matrix_list(&head);

    if (rc == EMPTY_MATRIX_LIST)
    {
        free_matrix_list(head);
        ck_abort_msg("EMPTY_MATRIX_LIST");
    }

    matr_list_t *tmp = head;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_ptr_null(tmp);
    
    free_matrix_list(head);
}

START_TEST(test_delete_max_element_matrix_list_2x2_first_row)
{
    matr_list_t *head = NULL;

    if (push_matrix_list(&head, 2, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head, 1, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    int rc = delete_max_element_matrix_list(&head);

    if (rc == EMPTY_MATRIX_LIST)
    {
        free_matrix_list(head);
        ck_abort_msg("EMPTY_MATRIX_LIST");
    }

    matr_list_t *tmp = head;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_ptr_null(tmp);
    
    free_matrix_list(head);
}

START_TEST(test_delete_max_element_matrix_list_2x2_last_row)
{
    matr_list_t *head = NULL;

    if (push_matrix_list(&head, 2, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head, 1, 1, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head, 3, 1, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    int rc = delete_max_element_matrix_list(&head);

    if (rc == EMPTY_MATRIX_LIST)
    {
        free_matrix_list(head);
        ck_abort_msg("EMPTY_MATRIX_LIST");
    }

    matr_list_t *tmp = head;
    ck_assert_int_eq(tmp->data, 2);
    tmp = tmp->next;
    ck_assert_int_eq(tmp->data, 1);
    tmp = tmp->next;
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_ptr_null(tmp);
    
    free_matrix_list(head);
}

START_TEST(test_delete_max_element_matrix_list_1x2)
{
    matr_list_t *head = NULL;

    if (push_matrix_list(&head, 2, 0, 0) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }
    if (push_matrix_list(&head, 1, 0, 1) != EXIT_SUCCESS)
    {
        free_matrix_list(head);
        ck_abort_msg("MEM_ALLOC_ERROR");
    }

    int rc = delete_max_element_matrix_list(&head);

    ck_assert_int_eq(rc, EMPTY_MATRIX_LIST);
    
    free_matrix_list(head);
}

Suite *delete_max_element_matrix_list_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("delete_max_element_matrix_list");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_delete_max_element_matrix_list_1x2);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_delete_max_element_matrix_list_2x2_all_eq);
    tcase_add_test(tc_pos, test_delete_max_element_matrix_list_2x2_first_row);
    tcase_add_test(tc_pos, test_delete_max_element_matrix_list_2x2_last_row);
    suite_add_tcase(s, tc_pos);

    return s;
}
