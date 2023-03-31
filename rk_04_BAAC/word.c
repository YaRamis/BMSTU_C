#include "word.h"

int reverse_words(words_list_t **list)
{
	if (*list == NULL)
		return EXIT_FAILURE;
	words_list_t *head = *list;
	while (*list != NULL)
	{
		reverse_word(*list->word);
		*list = *list->next;
	}
	*list = head;
	return EXIT_SUCCESS;
}

void reverse_word(char *str)
{
	char str_tmp[100];
	strcpy(str_tmp, str);
	int i = 0;
	while (str_tmp[i] == '\0')
		i++;
	for (int j = 0; j < i; j--)
		str[j] = str_tmp[i - j - 1];
}