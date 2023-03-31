#include "list.h"

(words_list_t *) creat_node(char *data)
{
    words_list_t *new = (words_list_t *)malloc(sizeof(words_list_t));
    if (new != NULL)
    {
        strcpy(new->word, data);
		new->next = NULL;
    }
	return new;
}

int push(char *data, words_list_t **list)
{
	words_list_t *node = creat_node(data);
	if (node == NULL)
		return EXIT_FAILURE;
	words_list_t *tmp = *list;
	*list = node;
	node->next = tmp;
	return EXIT_SUCCESS;
}
