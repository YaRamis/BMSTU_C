#include "check_main.h"

int main(void)
{
    int no_failed = 0;
    SRunner * sr;
    sr = srunner_create(fread_matrix_suite());
    srunner_add_suite(sr, my_pow_suite());
    srunner_add_suite(sr, fill_minor_suite());
    srunner_add_suite(sr, get_matrix_determinant_suite());
    srunner_add_suite(sr, get_matrix_product_suite());
    srunner_add_suite(sr, get_matrix_sum_suite());
    srunner_run_all(sr, CK_VERBOSE);
    no_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
