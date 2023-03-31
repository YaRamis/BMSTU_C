#include "check_main.h"
#include "matrix.h"

START_TEST(test_fread_matrix_positive)
{
    FILE *f = fopen("unit_tests/test_fread_matrix_positive.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    double **matrix = allocate_matrix(2, 2);
    if (matrix == NULL)
    {
        fclose(f);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    int rc = fread_matrix(f, matrix, 2, 2);
    fclose(f);
    free_matrix(matrix, 2);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(test_fread_matrix_negative)
{
    FILE *f = fopen("unit_tests/test_fread_matrix_negative.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    double **matrix = allocate_matrix(2, 2);
    if (matrix == NULL)
    {
        fclose(f);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    int rc = fread_matrix(f, matrix, 2, 2);
    fclose(f);
    free_matrix(matrix, 2);

    ck_assert_int_eq(rc, ELEM_READ_ERROR);
}

Suite *fread_matrix_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("fread_matrix");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_fread_matrix_negative);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_fread_matrix_positive);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_my_pow_any_to_0_power)
{
    double res = my_pow(3, 0);

    ck_assert_double_gt(EPS, fabs(res - 1));
}

START_TEST(test_my_pow_1_to_any_power)
{
    double res = my_pow(1, 5);

    ck_assert_double_gt(EPS, fabs(res - 1));
}

START_TEST(test_my_pow_0_to_any_power)
{
    double res = my_pow(0, 6);

    ck_assert_double_gt(EPS, fabs(res - 0));
}

START_TEST(test_my_pow_2_to_negative_2_power)
{
    double res = my_pow(2, -2);

    ck_assert_double_gt(EPS, fabs(res - 1.0/4.0));
}

START_TEST(test_my_pow_usual)
{
    double res = my_pow(2.2, 3);

    ck_assert_double_gt(EPS, fabs(res - 10.648));
}

Suite *my_pow_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("my_pow");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, test_my_pow_any_to_0_power);
    tcase_add_test(tc_neit, test_my_pow_1_to_any_power);
    tcase_add_test(tc_neit, test_my_pow_0_to_any_power);
    tcase_add_test(tc_neit, test_my_pow_2_to_negative_2_power);
    tcase_add_test(tc_neit, test_my_pow_usual);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(fill_minor_1st_row_1st_column_from_matrix_3x3)
{
    FILE *f = fopen("unit_tests/fill_minor_from_matrix_3x3.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    double **matrix = allocate_matrix(3, 3);
    if (matrix == NULL)
    {
        fclose(f);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    int rc = fread_matrix(f, matrix, 3, 3);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix, 3);
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    double **minor = allocate_matrix(2, 2);
    if (minor == NULL)
    {
        fclose(f);
        free_matrix(matrix, 3);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }

    fill_minor(matrix, 3, minor, 0, 0);

    fclose(f);
    free_matrix(matrix, 3);

    ck_assert_double_gt(EPS, fabs(minor[0][0] - 5));
    ck_assert_double_gt(EPS, fabs(minor[0][1] - 6));
    ck_assert_double_gt(EPS, fabs(minor[1][0] - 8));
    ck_assert_double_gt(EPS, fabs(minor[1][1] - 9));

    free_matrix(minor, 2);
}

START_TEST(fill_minor_2nd_row_2nd_column_from_matrix_3x3)
{
    FILE *f = fopen("unit_tests/fill_minor_from_matrix_3x3.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    double **matrix = allocate_matrix(3, 3);
    if (matrix == NULL)
    {
        fclose(f);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    int rc = fread_matrix(f, matrix, 3, 3);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix, 3);
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    double **minor = allocate_matrix(2, 2);
    if (minor == NULL)
    {
        fclose(f);
        free_matrix(matrix, 3);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }

    fill_minor(matrix, 3, minor, 1, 1);

    fclose(f);
    free_matrix(matrix, 3);

    ck_assert_double_gt(EPS, fabs(minor[0][0] - 1));
    ck_assert_double_gt(EPS, fabs(minor[0][1] - 3));
    ck_assert_double_gt(EPS, fabs(minor[1][0] - 7));
    ck_assert_double_gt(EPS, fabs(minor[1][1] - 9));

    free_matrix(minor, 2);
}

Suite *fill_minor_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("fill_minor");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, fill_minor_1st_row_1st_column_from_matrix_3x3);
    tcase_add_test(tc_neit, fill_minor_2nd_row_2nd_column_from_matrix_3x3);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(get_matrix_determinant_usual_1)
{
    FILE *f = fopen("unit_tests/get_matrix_determinant_usual_1.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    double **matrix = allocate_matrix(3, 3);
    if (matrix == NULL)
    {
        fclose(f);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    int rc = fread_matrix(f, matrix, 3, 3);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix, 3);
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    double determinant = 0;

    rc = get_matrix_determinant(matrix, 3, &determinant);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix, 3);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }

    fclose(f);
    free_matrix(matrix, 3);

    ck_assert_double_gt(EPS, fabs(determinant - 0));
}

START_TEST(get_matrix_determinant_usual_2)
{
    FILE *f = fopen("unit_tests/get_matrix_determinant_usual_2.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    double **matrix = allocate_matrix(4, 4);
    if (matrix == NULL)
    {
        fclose(f);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    int rc = fread_matrix(f, matrix, 4, 4);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix, 4);\
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    double determinant = 0;

    rc = get_matrix_determinant(matrix, 4, &determinant);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix, 4);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }

    fclose(f);
    free_matrix(matrix, 4);

    ck_assert_double_gt(EPS, fabs(determinant - 918.525));
}

Suite *get_matrix_determinant_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("get_matrix_determinant");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, get_matrix_determinant_usual_1);
    tcase_add_test(tc_neit, get_matrix_determinant_usual_2);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(get_matrix_product_usual_1)
{
    FILE *f = fopen("unit_tests/get_matrix_product_usual_11.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    double **matrix1 = allocate_matrix(2, 3);
    if (matrix1 == NULL)
    {
        fclose(f);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    int rc = fread_matrix(f, matrix1, 2, 3);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix1, 2);
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    fclose(f);

    f = fopen("unit_tests/get_matrix_product_usual_12.txt", "r");
    if (f == NULL)
    {
        free_matrix(matrix1, 2);
        ck_abort_msg("FILE_OPEN_ERROR");
    }
    
    double **matrix2 = allocate_matrix(3, 2);
    if (matrix2 == NULL)
    {
        fclose(f);
        free_matrix(matrix1, 2);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    rc = fread_matrix(f, matrix2, 3, 2);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix2, 3);
        free_matrix(matrix1, 2);
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    fclose(f);

    double **product = get_matrix_product(matrix1, matrix2, 2, 3, 2);
    if (product == NULL)
    {
        free_matrix(matrix2, 3);
        free_matrix(matrix1, 2);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }

    free_matrix(matrix2, 3);
    free_matrix(matrix1, 2);

    ck_assert_double_gt(EPS, fabs(product[0][0] - (-25)));
    ck_assert_double_gt(EPS, fabs(product[0][1] - (-25)));
    ck_assert_double_gt(EPS, fabs(product[1][0] - (-5)));
    ck_assert_double_gt(EPS, fabs(product[1][1] - 20));

    free_matrix(product, 2);
}

START_TEST(get_matrix_product_usual_2)
{
    FILE *f = fopen("unit_tests/get_matrix_product_usual_21.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    double **matrix1 = allocate_matrix(1, 3);
    if (matrix1 == NULL)
    {
        fclose(f);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    int rc = fread_matrix(f, matrix1, 1, 3);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix1,1);
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    fclose(f);

    f = fopen("unit_tests/get_matrix_product_usual_22.txt", "r");
    if (f == NULL)
    {
        free_matrix(matrix1, 1);
        ck_abort_msg("FILE_OPEN_ERROR");
    }
    
    double **matrix2 = allocate_matrix(3, 1);
    if (matrix2 == NULL)
    {
        fclose(f);
        free_matrix(matrix1, 1);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    rc = fread_matrix(f, matrix2, 3, 1);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix2, 3);
        free_matrix(matrix1, 1);
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    fclose(f);

    double **product = get_matrix_product(matrix1, matrix2, 1, 3, 1);
    if (product == NULL)
    {
        free_matrix(matrix2, 3);
        free_matrix(matrix1, 1);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }

    free_matrix(matrix2, 3);
    free_matrix(matrix1, 1);

    ck_assert_double_gt(EPS, fabs(product[0][0] - 14));

    free_matrix(product, 1);
}

Suite *get_matrix_product_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("get_matrix_product");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, get_matrix_product_usual_1);
    tcase_add_test(tc_neit, get_matrix_product_usual_2);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(get_matrix_sum_usual_1)
{
    FILE *f = fopen("unit_tests/get_matrix_sum_usual_11.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    double **matrix1 = allocate_matrix(2, 3);
    if (matrix1 == NULL)
    {
        fclose(f);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    int rc = fread_matrix(f, matrix1, 2, 3);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix1, 2);
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    fclose(f);

    f = fopen("unit_tests/get_matrix_sum_usual_12.txt", "r");
    if (f == NULL)
    {
        free_matrix(matrix1, 2);
        ck_abort_msg("FILE_OPEN_ERROR");
    }
    
    double **matrix2 = allocate_matrix(2, 3);
    if (matrix2 == NULL)
    {
        fclose(f);
        free_matrix(matrix1, 2);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    rc = fread_matrix(f, matrix2, 2, 3);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix2, 2);
        free_matrix(matrix1, 2);
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    fclose(f);

    double **sum = get_matrix_sum(matrix1, matrix2, 2, 3);
    if (sum == NULL)
    {
        free_matrix(matrix2, 2);
        free_matrix(matrix1, 2);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }

    free_matrix(matrix2, 2);
    free_matrix(matrix1, 2);

    ck_assert_double_gt(EPS, fabs(sum[0][0] - 3));
    ck_assert_double_gt(EPS, fabs(sum[0][1] - 3));
    ck_assert_double_gt(EPS, fabs(sum[0][2] - 3));
    ck_assert_double_gt(EPS, fabs(sum[1][0] - 4));
    ck_assert_double_gt(EPS, fabs(sum[1][1] - 4));
    ck_assert_double_gt(EPS, fabs(sum[1][2] - 4));

    free_matrix(sum, 2);
}

START_TEST(get_matrix_sum_usual_2)
{
    FILE *f = fopen("unit_tests/get_matrix_sum_usual_21.txt", "r");
    if (f == NULL)
        ck_abort_msg("FILE_OPEN_ERROR");
    
    double **matrix1 = allocate_matrix(2, 2);
    if (matrix1 == NULL)
    {
        fclose(f);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    int rc = fread_matrix(f, matrix1, 2, 2);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix1, 2);
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    fclose(f);

    f = fopen("unit_tests/get_matrix_sum_usual_22.txt", "r");
    if (f == NULL)
    {
        free_matrix(matrix1, 2);
        ck_abort_msg("FILE_OPEN_ERROR");
    }
    
    double **matrix2 = allocate_matrix(2, 2);
    if (matrix2 == NULL)
    {
        fclose(f);
        free_matrix(matrix1, 2);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }
    
    rc = fread_matrix(f, matrix2, 2, 2);
    if (rc != EXIT_SUCCESS)
    {
        fclose(f);
        free_matrix(matrix2, 2);
        free_matrix(matrix1, 2);
        ck_abort_msg("ELEMENT_READ_ERROR");
    }

    fclose(f);

    double **sum = get_matrix_sum(matrix1, matrix2, 2, 2);
    if (sum == NULL)
    {
        free_matrix(matrix2, 2);
        free_matrix(matrix1, 2);
        ck_abort_msg("MEMORY_ALLOCATE_ERROR");
    }

    free_matrix(matrix2, 2);
    free_matrix(matrix1, 2);

    ck_assert_double_gt(EPS, fabs(sum[0][0] - 3));
    ck_assert_double_gt(EPS, fabs(sum[0][1] - (-14)));
    ck_assert_double_gt(EPS, fabs(sum[1][0] - 14));
    ck_assert_double_gt(EPS, fabs(sum[1][1] - (-5)));

    free_matrix(sum, 2);
}

Suite *get_matrix_sum_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("get_matrix_sum");

    tc_neit = tcase_create("neitrals");
    tcase_add_test(tc_neit, get_matrix_sum_usual_1);
    tcase_add_test(tc_neit, get_matrix_sum_usual_2);
    suite_add_tcase(s, tc_neit);

    return s;
}
