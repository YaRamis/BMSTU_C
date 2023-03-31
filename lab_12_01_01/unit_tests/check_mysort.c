#include "check_main.h"
#include "mysort.h"

START_TEST(test_mysort_int)
{
    int arr[] = {1, -2, 3};

    mysort(arr, 3, sizeof(int), compare_int);
    ck_assert_int_eq(arr[0], -2);
    ck_assert_int_eq(arr[1], 1);
    ck_assert_int_eq(arr[2], 3);
} END_TEST

int compare_double(const void *p, const void *q)
{
    double *a = (double *)p;
    double *b = (double *)q;
    if ((*a - *b) > EPS)
        return 1;
    else if ((*b - *a) > EPS)
        return -1;
    else
        return 0;
}

START_TEST(test_mysort_double)
{
    double arr[4] = {0.03, 0.03, -1.9, 90};

    mysort(arr, 4, sizeof(double), compare_double);
    ck_assert_double_eq_tol(arr[0], -1.9, EPS);
    ck_assert_double_eq_tol(arr[1], 0.03, EPS);
    ck_assert_double_eq_tol(arr[2], 0.03, EPS);
    ck_assert_double_eq_tol(arr[3], 90, EPS);
} END_TEST

int compare_char(const void *p, const void *q)
{
    char *a = (char *)p;
    char *b = (char *)q;
    return *a - *b;
}

START_TEST(test_mysort_char)
{
    char arr[5] = "cbaba";

    mysort(arr, 5, sizeof(char), compare_char);
    ck_assert_int_eq(arr[0], 'a');
    ck_assert_int_eq(arr[1], 'a');
    ck_assert_int_eq(arr[2], 'b');
    ck_assert_int_eq(arr[3], 'b');
    ck_assert_int_eq(arr[4], 'c');
} END_TEST

int compare_str(const void *p, const void *q)
{
    //char *a = (char *)p;
    //char *b = (char *)q;
    return strncmp((char*)p, (char*)q, strlen((char*)p));
}

START_TEST(test_mysort_string)
{
    char arr[3][3] = {"ab", "cd", "ef"};

    mysort(arr, 3, sizeof(char[3]), compare_str);
    ck_assert_str_eq(arr[0], "ab");
    ck_assert_str_eq(arr[1], "cd");
    ck_assert_str_eq(arr[2], "ef");
} END_TEST

Suite *mysort_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("mysort");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_mysort_int);
    tcase_add_test(tc_neit, test_mysort_char);
    tcase_add_test(tc_neit, test_mysort_double);
    tcase_add_test(tc_neit, test_mysort_string);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_binary_search_int)
{
    char *lo, *hi;
    int arr[] = {5, 45 ,2};
    lo = (char *)arr;
    hi = (char *)arr;
    int key = arr[1];
    char *pkey = (char *)&key;

    binary_search(&lo, &hi, sizeof(int), pkey, compare_int);
    ck_assert_ptr_eq(lo, arr + 1);
}
END_TEST

START_TEST(test_binary_search_double)
{
    char *lo, *hi;
    double arr[] = {5.5, 45, 13.14};
    lo = (char *)arr;
    hi = (char *)(arr) + sizeof(double);
    double key = arr[2];
    char *pkey = (char *)&key;
    
    binary_search(&lo, &hi, sizeof(double), pkey, compare_double);
    ck_assert_ptr_eq(lo, (char *)arr + sizeof(double));
}
END_TEST

START_TEST(test_binary_search_char)
{
    char *lo, *hi;
    char arr[] = "abbcfdk";
    lo = arr;
    hi = arr + sizeof(char) * 4;
    char key = arr[5];
    char *pkey = (char *)&key;
    
    binary_search(&lo, &hi, sizeof(char), pkey, compare_char);
    ck_assert_ptr_eq(lo, arr + sizeof(char) * 4);
}
END_TEST

Suite *binary_search_suite(void)
{
    Suite * s;
    TCase * tc_neit;

    s = suite_create("binary_search");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_binary_search_int);
    tcase_add_test(tc_neit, test_binary_search_char);
    tcase_add_test(tc_neit, test_binary_search_double);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_compare_int_equal)
{
    int p = 3;
    int q = 3;

    int rc = compare_int((void *)&p, (void *)&q);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_compare_int_first_bigger)
{
    int p = 4;
    int q = 3;

    int rc = compare_int((void *)&p, (void *)&q);
    ck_assert_int_gt(rc, 0);
}
END_TEST

START_TEST(test_compare_int_second_bigger)
{
    int p = 3;
    int q = 4;

    int rc = compare_int((void *)&p, (void *)&q);
    ck_assert_int_lt(rc, 0);
}
END_TEST

Suite *compare_int_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("compare_int");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_compare_int_equal);
    tcase_add_test(tc_neit, test_compare_int_first_bigger);
    tcase_add_test(tc_neit, test_compare_int_second_bigger);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_swap_int)
{
    int arr[] = {1, 2};

    swap((char *)arr, (char *)arr + sizeof(int), sizeof(int));
    ck_assert_int_eq(arr[0], 2);
    ck_assert_int_eq(arr[1], 1);
}
END_TEST

START_TEST(test_swap_double)
{
    double arr[] = {1.2, 2.1};

    swap((char *)arr, (char *)arr + sizeof(double), sizeof(double));
    ck_assert_double_eq(arr[0], 2.1);
    ck_assert_double_eq(arr[1], 1.2);
}
END_TEST

START_TEST(test_swap_char)
{
    char arr[] = "ab";
    char first = 'a';
    char second = 'b';

    swap((char *)arr, arr + sizeof(char), sizeof(char));
    ck_assert_int_eq(compare_char(arr, &second), 0);
    ck_assert_int_eq(compare_char(arr + 1, &first), 0);
}
END_TEST

Suite *swap_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("swap");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_swap_int);
    tcase_add_test(tc_neit, test_swap_char);
    tcase_add_test(tc_neit, test_swap_double);
    suite_add_tcase(s, tc_neit);

    return s;
}
