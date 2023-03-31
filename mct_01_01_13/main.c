#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	double x = 0;
	double g;
	
	g = sqrt(x);
	
	while (scanf("%lf", &x) == 1)
	{
		
		if (g + x < 0)
		{
			return EXIT_FAILURE;
		}
		
		g = sqrt(g + x);
	}
	
	printf("%lf", g);
	
	return EXIT_SUCCESS;
}