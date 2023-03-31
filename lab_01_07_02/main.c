#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double next_t(double t, double k, double x)
{
    return t * (k * k * x * x) / ((k + 1) * (k + 2));
}
double s_get(double x, double e)
{
    double s = 0;
    int k = 1;
    double t = x;
    
    while (fabs(t) > e)
    {
        s += t;
        t = next_t(t, k, x);
        k += 2;
    }
    
    return s;
}
int main(void)
{
    double x, e;
    double f, s, absolute_er, relative_er;

    if (scanf("%lf %lf", &x, &e) != 2 || 0 >= e || e > 1)
        return EXIT_FAILURE;

    if (fabs(x) > 1 || fabs(x) < 1e-8)
        return EXIT_FAILURE;

    f = asin(x);
    s = s_get(x, e);

    absolute_er = fabs(f - s);
    relative_er = absolute_er / fabs(f);

    printf("%.6lf %.6lf %.6lf %.6lf", s, f, absolute_er, relative_er);

    return EXIT_SUCCESS;
}
