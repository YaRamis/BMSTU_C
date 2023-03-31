#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <stddef.h>

#define STR_LEN 257

typedef char my_string[STR_LEN];
char *my_strpbrk(my_string, my_string);
size_t my_strspn(my_string, my_string);
size_t my_strcspn(my_string, my_string);
char *my_strchr(my_string, int);
char *my_strrchr(my_string, int);

#endif