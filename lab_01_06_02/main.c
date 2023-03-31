#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define E 1e-8

double area_triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a, b, c;
    double p;

    a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

    p = (a + b + c) / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main(void)
{
    double xa, ya, xb, yb, xc, yc;
    double xp, yp;
    double s, s1, s2, s3;

    if (scanf("%lf %lf", &xa, &ya) != 2)
        return EXIT_FAILURE;

    if (scanf("%lf %lf", &xb, &yb) != 2)
        return EXIT_FAILURE;

    if (scanf("%lf %lf", &xc, &yc) != 2)
        return EXIT_FAILURE;

    if (scanf("%lf %lf", &xp, &yp) != 2)
        return EXIT_FAILURE;

    if (fabs(area_triangle(xa, ya, xb, yb, xc, yc)) <= E)
        return EXIT_FAILURE;

    s = area_triangle(xa, ya, xb, yb, xc, yc);
    s1 = area_triangle(xp, yp, xb, yb, xc, yc);
    s2 = area_triangle(xa, ya, xp, yp, xc, yc);
    s3 = area_triangle(xa, ya, xb, yb, xp, yp);

    if ((s1 + s2 + s3) - E < s && s < (s1 + s2 + s3) + E)
    {
        if (fabs(s1) <= E || fabs(s2) <= E || fabs(s3) <= E)
        {
            printf("1");
            return EXIT_SUCCESS;
        }
        printf("0");
        return EXIT_SUCCESS;
    }
		

    printf("2");

    return EXIT_SUCCESS;
}