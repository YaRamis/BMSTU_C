#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int el)
{
	if (el > 1)
	{
		int j = 2;
		while (j < el)
		{
			if ((el / j) * j == el)
			{
				return 0;
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(void)
{
	int n;
	
	if (scanf("%d", &n) != 1)
	{
		return EXIT_FAILURE;
	}
	
	int a[n], i;
	
	for (i = 0; i < n; ++i)
	{
		if (scanf("%d", &a[i]) != 1)
		{
			return EXIT_FAILURE;
		}
	}
	
	for (i = 0; i < n; ++i)
	{
		if (is_prime(a[i]) == 0)
		{
			printf("%d yes\n", a[i]);
		}
		else
		{
			printf("%d no\n", a[i]);
		}
	}
	
	return EXIT_SUCCESS;
}