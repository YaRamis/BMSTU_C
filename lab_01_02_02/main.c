#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	double xa, ya, xb, yb, xc, yc;
	double ab, bc, ac;
	double p;
	
	if (scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc) != 6)
		return EXIT_FAILURE;
	
	ab = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
	bc = sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));
	ac = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));

	p = ab + bc + ac;

	printf("%.6lf", p);
	
	return EXIT_SUCCESS;
}