#include "check_main.h"
#include "cars.h"

START_TEST(test_fread_cars_empty_file)
{
    FILE *f = fopen("unit_tests/test_fread_cars_empty_file.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    cars_t cars = {NULL, 0};

    int rc = fread_cars(&cars, f);

    ck_assert_int_eq(rc, EMPTY_FILE);
}

START_TEST(test_fread_cars_sym_year)
{
    FILE *f = fopen("unit_tests/test_fread_cars_sym_year.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    cars_t cars = {NULL, 0};

    int rc = fread_cars(&cars, f);

    if (rc == EMPTY_FILE)
        ck_abort_msg("EMPTY_FILE");
    else if (rc == MEM_ALLOC_ERROR)
        ck_abort_msg("MEM_ALLOC_ERROR");
    else if (rc == EXIT_SUCCESS)
    {
        free_cars(&cars);
        ck_abort_msg("EXIT_SUCCESS");
    }

    ck_assert_int_eq(rc, ELEM_READ_ERROR);
}

START_TEST(test_fread_cars_year_null)
{
    FILE *f = fopen("unit_tests/test_fread_cars_year_null.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    cars_t cars = {NULL, 0};

    int rc = fread_cars(&cars, f);

    if (rc == EMPTY_FILE)
        ck_abort_msg("EMPTY_FILE");
    else if (rc == MEM_ALLOC_ERROR)
        ck_abort_msg("MEM_ALLOC_ERROR");
    else if (rc == EXIT_SUCCESS)
    {
        free_cars(&cars);
        ck_abort_msg("EXIT_SUCCESS");
    }

    ck_assert_int_eq(rc, ELEM_READ_ERROR);
}

START_TEST(test_fread_cars_year_neg)
{
    FILE *f = fopen("unit_tests/test_fread_cars_year_neg.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    cars_t cars = {NULL, 0};

    int rc = fread_cars(&cars, f);

    if (rc == EMPTY_FILE)
        ck_abort_msg("EMPTY_FILE");
    else if (rc == MEM_ALLOC_ERROR)
        ck_abort_msg("MEM_ALLOC_ERROR");
    else if (rc == EXIT_SUCCESS)
    {
        free_cars(&cars);
        ck_abort_msg("EXIT_SUCCESS");
    }

    ck_assert_int_eq(rc, ELEM_READ_ERROR);
}

START_TEST(test_fread_cars_1_car)
{
    FILE *f = fopen("unit_tests/test_fread_cars_1_car.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    cars_t cars = {NULL, 0};

    int rc = fread_cars(&cars, f);

    if (rc == EMPTY_FILE)
        ck_abort_msg("EMPTY_FILE");
    else if (rc == MEM_ALLOC_ERROR)
        ck_abort_msg("MEM_ALLOC_ERROR");
    else if (rc == ELEM_READ_ERROR)
        ck_abort_msg("ELEM_READ_ERROR");

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(cars.size, 1);
    ck_assert_str_eq(cars.arr[0].brand, "mers");
    ck_assert_int_eq(cars.arr[0].year, 2);

    free_cars(&cars);
}

START_TEST(test_fread_cars_usual_pos)
{
    FILE *f = fopen("unit_tests/test_fread_cars_usual_pos.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    cars_t cars = {NULL, 0};

    int rc = fread_cars(&cars, f);

    if (rc == EMPTY_FILE)
        ck_abort_msg("EMPTY_FILE");
    else if (rc == MEM_ALLOC_ERROR)
        ck_abort_msg("MEM_ALLOC_ERROR");
    else if (rc == ELEM_READ_ERROR)
        ck_abort_msg("ELEM_READ_ERROR");

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(cars.size, 3);
    ck_assert_str_eq(cars.arr[0].brand, "mers");
    ck_assert_int_eq(cars.arr[0].year, 2);
    ck_assert_str_eq(cars.arr[1].brand, "bmw");
    ck_assert_int_eq(cars.arr[1].year, 2002);
    ck_assert_str_eq(cars.arr[2].brand, "tesla");
    ck_assert_int_eq(cars.arr[2].year, 2020);

    free_cars(&cars);
}

Suite *fread_cars_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("fread_cars");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_fread_cars_empty_file);
    tcase_add_test(tc_neg, test_fread_cars_sym_year);
    tcase_add_test(tc_neg, test_fread_cars_year_null);
    tcase_add_test(tc_neg, test_fread_cars_year_neg);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_fread_cars_1_car);
    tcase_add_test(tc_pos, test_fread_cars_usual_pos);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_compare_cars_by_year_eq)
{
    car_t car1 = {"mers", 2000};
    car_t car2 = {"bmw", 2000};

    ck_assert_int_eq(0, compare_cars_by_year((void *)(&car1), (void *)(&car2)));
}

START_TEST(test_compare_cars_by_year_gt)
{
    car_t car1 = {"mers", 2000};
    car_t car2 = {"bmw", 2002};

    ck_assert_int_gt(0, compare_cars_by_year((void *)(&car1), (void *)(&car2)));
}

START_TEST(test_compare_cars_by_year_lt)
{
    car_t car1 = {"mers", 2002};
    car_t car2 = {"bmw", 2000};

    ck_assert_int_lt(0, compare_cars_by_year((void *)(&car1), (void *)(&car2)));
}

Suite *compare_cars_by_year_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("compare_cars_by_year");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_compare_cars_by_year_eq);
    tcase_add_test(tc_neit, test_compare_cars_by_year_gt);
    tcase_add_test(tc_neit, test_compare_cars_by_year_lt);
    suite_add_tcase(s, tc_neit);

    return s;
}
