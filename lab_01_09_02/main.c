#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double g_get(double s1, double n1)
{
    return (1 / n1) * s1;
}

int main(void)
{
    double x;
    double g;
    double s = 0.0, n = 0.0;
    int read;

    read = scanf("%lf", &x);

    if (read != 1 || x < 0.0)
        return EXIT_FAILURE;

    while (read == 1 && x >= 0.0)
    {
        n++;
        s += sqrt(n + x);
        read = scanf("%lf", &x);
        if (read != 1)
            return EXIT_FAILURE;
    }

    g = g_get(s, n);

    printf("%lf", g);

    return EXIT_SUCCESS;
}