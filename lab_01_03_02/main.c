#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double r1, r2, r3;
    double r;
	
    if (scanf("%lf", &r1) != 1)
        return EXIT_FAILURE;
    if (scanf("%lf", &r2) != 1)
        return EXIT_FAILURE;
    if (scanf("%lf", &r3) != 1)
        return EXIT_FAILURE;
    if ((r1 * r2 + r2 * r3 + r1 * r3) == 0)
        return EXIT_FAILURE;

    r = (r1 * r2 * r3) / (r1 * r2 + r2 * r3 + r1 * r3);

    printf("%.6lf", r);

    return EXIT_SUCCESS;
}