#include "check_main.h"

int main(void)
{
    int no_failed = 0;
    SRunner * sr;
    sr = srunner_create(count_elements_suite());
    srunner_add_suite(sr, key_suite());
    srunner_add_suite(sr, mysort_suite());
    srunner_add_suite(sr, binary_search_suite());
    srunner_add_suite(sr, compare_int_suite());
    srunner_add_suite(sr, fill_new_arr_suite());
    srunner_add_suite(sr, find_min_element_suite());
    srunner_add_suite(sr, find_max_element_suite());
    srunner_add_suite(sr, swap_suite());
    srunner_run_all(sr, CK_VERBOSE);
    no_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
