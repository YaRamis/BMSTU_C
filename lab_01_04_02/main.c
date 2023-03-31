#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int s;
	int h, m;

	if (scanf("%d", &s) != 1)
		return EXIT_FAILURE;
	
	if (s < 0)
		return EXIT_FAILURE;

	h = s / 3600;
	s = s - h * 3600;
	m = s / 60;
	s = s - m * 60;

	printf("%d %d %d", h, m, s);
	
	return EXIT_SUCCESS;
}