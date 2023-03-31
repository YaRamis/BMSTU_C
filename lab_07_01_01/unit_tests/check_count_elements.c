#include "check_main.h"
#include "my_utils.h"

START_TEST(test_count_elemements_empty_file)
{
    FILE *f = fopen("unit_tests/test_count_elemements_empty_file.txt", "r");
    if (f != NULL)
    {
        int n;
        int rc = count_elements(f, &n);
        ck_assert_int_eq(rc, EMPTY_FILE);
        fclose(f);
    }
    else
        ck_abort_msg("FILE OPEN ERROR");
}
END_TEST

START_TEST(test_count_elemements_incorrect_value)
{
    FILE *f = fopen("unit_tests/test_count_elemements_incorrect_value.txt", "r");
    if (f != NULL)
    {
        int n;
        int rc = count_elements(f, &n);
        ck_assert_int_eq(rc, ELEM_READ_ERROR);
        fclose(f);
    }
    else
        ck_abort_msg("FILE OPEN ERROR");
}
END_TEST

START_TEST(test_count_elemements_seven_elements)
{
    FILE *f = fopen("unit_tests/test_count_elemements_seven_elements.txt", "r");
    if (f != NULL)
    {
        int n;
        int rc = count_elements(f, &n);
        ck_assert_int_eq(rc, EXIT_SUCCESS);
        ck_assert_int_eq(n, 7);
        fclose(f);
    }
    else
        ck_abort_msg("FILE OPEN ERROR");
}
END_TEST

Suite *count_elements_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("count_elements");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_count_elemements_empty_file);
    tcase_add_test(tc_neg, test_count_elemements_incorrect_value);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_count_elemements_seven_elements);
    suite_add_tcase(s, tc_pos);

    return s;
}
