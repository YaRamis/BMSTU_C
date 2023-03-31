#include "output.h"

int output(FILE *f, words_list_t *list)
{
	if (list == NULL)
		return EXIT_FAILURE;
	
	while (list != NULL)
	{
		fprintf(f, "%s ", list->word);
		list = list->next;
	}
	return EXIT_SUCCESS;
}
