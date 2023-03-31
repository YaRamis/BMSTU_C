#include "check_main.h"
#include "my_snprintf.h"


START_TEST(test_my_snprintf_1_char)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    char sym = 'R';
    const char *format = "%c";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, sym), snprintf(str_2, STRING_SIZE, format, sym));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_3_char)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    char sym_1 = 'H';
    char sym_2 = 'e';
    char sym_3 = 'y';
    const char *format = "%c%c%c";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, sym_1, sym_2, sym_3), snprintf(str_2, STRING_SIZE, format, sym_1, sym_2, sym_3));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_1_string)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    char *str_3 = "HELLO";
    const char *format = "%s";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, str_3), snprintf(str_2, STRING_SIZE, format, str_3));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_3_string)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    char *str_3 = "HELLO";
    char *str_4 = "WORLD";
    char *str_5 = "hehe";
    const char *format = "CHTO %s%s%s";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, str_3, str_4, str_5), snprintf(str_2, STRING_SIZE, format, str_3, str_4, str_5));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_1_dec)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    int num = 0;
    const char *format = "%d";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, num), snprintf(str_2, STRING_SIZE, format, num));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_3_dec)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    int num_1 = 0;
    int num_2 = -12345;
    int num_3 = 14;
    const char *format = "%d %d %d";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, num_1, num_2, num_3), snprintf(str_2, STRING_SIZE, format, num_1, num_2, num_3));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_1_long_dec)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    long num = 1;
    const char *format = "%ld";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, num), snprintf(str_2, STRING_SIZE, format, num));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_3_long_dec)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    long num_1 = 0;
    long num_2 = -12345;
    long num_3 = 567678;
    const char *format = "%ld %ld %ld";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, num_1, num_2, num_3), snprintf(str_2, STRING_SIZE, format, num_1, num_2, num_3));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_1_oct)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    unsigned int num = 9;
    const char *format = "%o";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, num), snprintf(str_2, STRING_SIZE, format, num));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_3_oct)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    unsigned int num_1 = 0;
    unsigned int num_2 = 12345;
    unsigned int num_3 = 9;
    const char *format = "%o %o %o";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, num_1, num_2, num_3), snprintf(str_2, STRING_SIZE, format, num_1, num_2, num_3));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_1_long_oct)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    unsigned long num = 1;
    const char *format = "%lo";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, num), snprintf(str_2, STRING_SIZE, format, num));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_3_long_oct)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    unsigned long num_1 = 0;
    unsigned long num_2 = 12345;
    unsigned long num_3 = 18;
    const char *format = "%lo %lo %lo";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, num_1, num_2, num_3), snprintf(str_2, STRING_SIZE, format, num_1, num_2, num_3));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_1_hex)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    unsigned int num = 1;
    const char *format = "%x";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, num), snprintf(str_2, STRING_SIZE, format, num));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_3_hex)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    unsigned int num_1 = 0;
    unsigned int num_2 = 12345;
    unsigned int num_3 = 17;
    const char *format = "%x %x %x";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, num_1, num_2, num_3), snprintf(str_2, STRING_SIZE, format, num_1, num_2, num_3));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_1_long_hex)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    unsigned long x = 1;
    const char *format = "%lx";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, x), snprintf(str_2, STRING_SIZE, format, x));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_3_long_hex)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    unsigned long num_1 = 0;
    unsigned long num_2 = 12345;
    unsigned long num_3 = 17;
    const char *format = "%lx %lx %lx";

    ck_assert_int_eq(my_snprintf(str_1, STRING_SIZE, format, num_1, num_2, num_3), snprintf(str_2, STRING_SIZE, format, num_1, num_2, num_3));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_format_len_equal_n)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    int num = 1;
    const char *format = "halo%d";

    ck_assert_int_eq(my_snprintf(str_1, 6, format, num), snprintf(str_2, 6, format, num));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_not_enough_n)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    int num = 1;
    const char *format = "halo %d time";

    ck_assert_int_eq(my_snprintf(str_1, 5, format, num), snprintf(str_2, 5, format, num));
    ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_my_snprintf_null_n)
{
    char str_1[STRING_SIZE];
    char str_2[STRING_SIZE];

    int num = 3;
    const char *format = "halo %d times";

    ck_assert_int_eq(my_snprintf(str_1, 0, format, num), snprintf(str_2, 0, format, num));
}
END_TEST

// START_TEST(test_my_snprintf_null_str_and_n)
// {
//     int num = 5;
//     const char *format = "halo %d times";

//     ck_assert_int_eq(my_snprintf(NULL, 0, format, num), snprintf(NULL, 0, format, num));
// }
// END_TEST

Suite *my_snprintf_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("my_snprintf");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_my_snprintf_not_enough_n);
    tcase_add_test(tc_neg, test_my_snprintf_null_n);
    //tcase_add_test(tc_neg, test_my_snprintf_null_str_and_n);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_my_snprintf_1_char);
    tcase_add_test(tc_pos, test_my_snprintf_3_char);
    tcase_add_test(tc_pos, test_my_snprintf_1_string);
    tcase_add_test(tc_pos, test_my_snprintf_3_string);
    tcase_add_test(tc_pos, test_my_snprintf_1_dec);
    tcase_add_test(tc_pos, test_my_snprintf_3_dec);
    tcase_add_test(tc_pos, test_my_snprintf_1_long_dec);
    tcase_add_test(tc_pos, test_my_snprintf_3_long_dec);
    tcase_add_test(tc_pos, test_my_snprintf_1_oct);
    tcase_add_test(tc_pos, test_my_snprintf_3_oct);
    tcase_add_test(tc_pos, test_my_snprintf_1_long_oct);
    tcase_add_test(tc_pos, test_my_snprintf_3_long_oct);
    tcase_add_test(tc_pos, test_my_snprintf_1_hex);
    tcase_add_test(tc_pos, test_my_snprintf_3_hex);
    tcase_add_test(tc_pos, test_my_snprintf_1_long_hex);
    tcase_add_test(tc_pos, test_my_snprintf_3_long_hex);
    tcase_add_test(tc_pos, test_my_snprintf_format_len_equal_n);
    suite_add_tcase(s, tc_pos);

    return s;
}
