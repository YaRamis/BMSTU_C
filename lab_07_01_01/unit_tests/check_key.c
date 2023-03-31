#include "check_main.h"
#include "key.h"

START_TEST(test_key_one_element)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[] = {1};
    pb_src = a;
    pe_src = a;
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, EQUAL_MIN_MAX);
}
END_TEST

START_TEST(test_key_equal_elements)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[] = {3, 3, 3, 3, 3};
    pb_src = a;
    pe_src = a + 5;
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, EQUAL_MIN_MAX);
}
END_TEST

START_TEST(test_key_no_elements_between_min_max)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[] = {1, 2, 3, 4, -12, 44, 5, 6};
    pb_src = a;
    pe_src = a + 8;
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, NO_ELEMENTS);
}
END_TEST

START_TEST(test_key_usual)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[] = {1, -12, 2, 3, 4, 44, 5, 6};
    pb_src = a;
    pe_src = a + 8;
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_ptr_nonnull(pb_dst);
    ck_assert_int_eq(*pb_dst, 2);
    ck_assert_int_eq(*(pe_dst - 1), 4);
    ck_assert_int_eq((pe_dst - pb_dst), 3);
    free(pb_dst);
}
END_TEST

START_TEST(test_key_more_than_one_minmax)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[] = {1, -12, -12, 3, 4, 44, 44, 6};
    pb_src = a;
    pe_src = a + 8;
    int rc;
    
    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_ptr_nonnull(pb_dst);
    ck_assert_int_eq(*pb_dst, -12);
    ck_assert_int_eq(*(pe_dst - 1), 4);
    ck_assert_int_eq((pe_dst - pb_dst), 3);
    free(pb_dst);
}
END_TEST

Suite *key_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_key_one_element);
    tcase_add_test(tc_neg, test_key_equal_elements);
    tcase_add_test(tc_neg, test_key_no_elements_between_min_max);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_key_usual);
    tcase_add_test(tc_pos, test_key_more_than_one_minmax);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_fill_new_arr_usual_1)
{
    int arr[] = {1, 2, 3, 4};
    int new_arr[4];
    int *pe = new_arr + 4;
    int *pb = new_arr;

    fill_new_arr(&pb, &pe, arr - 1);
    ck_assert_int_eq(arr[0], new_arr[0]);
    ck_assert_int_eq(arr[1], new_arr[1]);
    ck_assert_int_eq(arr[2], new_arr[2]);
    ck_assert_int_eq(arr[3], new_arr[3]);
}
END_TEST

START_TEST(test_fill_new_arr_usual_2)
{
    int arr[] = {1, -2, 33, 4};
    int new_arr[4];
    int *pe = new_arr + 4;
    int *pb = new_arr;

    fill_new_arr(&pb, &pe, arr - 1);
    ck_assert_int_eq(arr[0], new_arr[0]);
    ck_assert_int_eq(arr[1], new_arr[1]);
    ck_assert_int_eq(arr[2], new_arr[2]);
    ck_assert_int_eq(arr[3], new_arr[3]);
}
END_TEST

Suite *fill_new_arr_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("fill_new_arr");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_fill_new_arr_usual_1);
    tcase_add_test(tc_neit, test_fill_new_arr_usual_2);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_find_max_element_usual)
{
    int arr[] = {2, 3, 1, 4};
    int *max = arr;
    int *pe = arr + 4;

    find_max_element(&max, pe);
    ck_assert_ptr_eq(arr + 3, max);
}
END_TEST

START_TEST(test_find_max_element_one_element)
{
    int arr[] = {2};
    int *max = arr;
    int *pe = arr + 1;

    find_max_element(&max, pe);
    ck_assert_ptr_eq(arr, max);
}
END_TEST

START_TEST(test_find_max_element_equal_elements)
{
    int arr[] = {2, 2, 2, 2};
    int *max = arr;
    int *pe = arr + 4;

    find_max_element(&max, pe);
    ck_assert_ptr_eq(arr, max);
}
END_TEST

Suite *find_max_element_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("find_max_element");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_find_max_element_usual);
    tcase_add_test(tc_neit, test_find_max_element_one_element);
    tcase_add_test(tc_neit, test_find_max_element_equal_elements);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_find_min_element_usual)
{
    int arr[] = {2, 3, 1, 4};
    int *min = arr;
    int *pe = arr + 4;

    find_min_element(&min, pe);
    ck_assert_ptr_eq(arr + 2, min);
}
END_TEST

START_TEST(test_find_min_element_one_element)
{
    int arr[] = {2};
    int *min = arr;
    int *pe = arr + 1;

    find_min_element(&min, pe);
    ck_assert_ptr_eq(arr, min);
}
END_TEST

START_TEST(test_find_min_element_equal_elements)
{
    int arr[] = {2, 2, 2, 2};
    int *min = arr;
    int *pe = arr + 4;

    find_min_element(&min, pe);
    ck_assert_ptr_eq(arr, min);
}
END_TEST

Suite *find_min_element_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("find_min_element");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_find_min_element_usual);
    tcase_add_test(tc_neit, test_find_min_element_one_element);
    tcase_add_test(tc_neit, test_find_min_element_equal_elements);
    suite_add_tcase(s, tc_neit);

    return s;
}
