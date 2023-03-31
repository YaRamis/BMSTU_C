#include "input.h"

int input(FILE *f, words_list_t **list)
{
	if (f == NULL)
		return EXIT_FAILURE;
	char *str;
	while (f != EOF)
	{
		if (fscanf(f, "%s", str) != 1)
			return EXIT_FAILURE;
		if (push(str, list) != EXIT_SUCCESS)
			return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
