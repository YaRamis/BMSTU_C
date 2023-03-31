#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

#define MAX_WORD_LEN 100

typedef struct node_t
{
	char word[MAX_WORD_LEN];
	node_t *next;
} words_list_t;

#endif
