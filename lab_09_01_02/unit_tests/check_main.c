#include "check_main.h"

int main(void)
{
    int no_failed = 0;
    SRunner * sr;
    sr = srunner_create(input_items_suite());
    srunner_add_suite(sr, bubble_sort_suite());
    srunner_add_suite(sr, str_to_double_suite());
    srunner_run_all(sr, CK_VERBOSE);
    no_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
