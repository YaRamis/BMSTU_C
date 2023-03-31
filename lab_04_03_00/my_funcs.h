#ifndef _MY_FUNCS_H_
#define _MY_FUNCS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 257
#define WORDS_COUNT 128
#define WORD_LEN 17

int input_str(char *str, size_t *str_len);
int get_words(char *str, char words[][WORD_LEN], size_t str_len, size_t *words_len);
int making_new_str(char words[][WORD_LEN], size_t words_len, char *new_str);

#endif