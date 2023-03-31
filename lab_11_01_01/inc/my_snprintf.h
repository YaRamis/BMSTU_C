#ifndef _MY_SNPRINTF_H_
#define _MY_SNPRINTF_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define STRING_SIZE 150

int my_snprintf(char *restrict str, size_t n, const char *restrict format, ...);
size_t get_rank(long long num, unsigned base);
size_t get_rank_unsigned(unsigned long long num, unsigned base);
size_t get_dec_number_as_string(char *str, long long num);
size_t conv_to_another_num_sys_as_str(char *str, unsigned long long num, unsigned base);

#endif
