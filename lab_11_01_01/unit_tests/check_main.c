#include <stdlib.h>
#include "check_main.h"

int main(void)
{
    int no_failed = 0;
    SRunner * sr;
    sr = srunner_create(my_snprintf_suite());
    srunner_run_all(sr, CK_VERBOSE);
    no_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
