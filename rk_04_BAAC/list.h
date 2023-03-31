#ifndef _LIST_H_
#define _LIST_H_

#include "structures.h"
#include <string.h>
#include <stdlib.h>

(words_list_t *) creat_node(char *data);
int push(char *data, words_list_t **list);

#endif
