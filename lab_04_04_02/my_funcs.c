#include "my_funcs.h"

int input_str(char *str, size_t *str_len)
{
    char sym;
    size_t i = 0;
    
    while ((sym = getchar()) != EOF)
    {
        if (i == STR_LEN - 1)
            return 2;
        str[i] = sym;
        i++;
    }
    str[i] = '\0';
    *str_len = i;
    if (i == 0)
        return 1;        
    return 0;
}

int get_words(char *str, char words[][WORD_LEN], size_t str_len, size_t *words_len)
{
    size_t j = 0, k = 0;
    
    for (size_t i = 0; i < str_len; i++)
    {
        if (isspace(str[i]) != 0)
        {
            if (k != 0)
            {
                words[j][k] = '\0';
                j++;
                k = 0;
            }
            continue;
        }
        if (k == WORD_LEN - 1)
            return 1;
        words[j][k] = str[i];
        k++;
    }
    if (k != 0)
    {
        words[j][k] = '\0';
        j++;
    }
    *words_len = j;
    return 0;
}

void all_tolower(char *str, size_t str_len)
{
    for (size_t i = 0; i < str_len; i++)
        str[i] = (char) tolower(str[i]);
}

int is_leap_year(int year)
{
    if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
        return 1;
    return 0;
}

void my_atoi(char *str_num, int *num)
{
    int rank = 1;
    char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    for (int i = strlen(str_num) - 1; i >= 0 ; i--, rank *= 10)
    {
        for (int j = 0; j < 10; j++)
            if (str_num[i] == digits[j])
                *num += j * rank;
    }
}

int looking_for_date(char words[][WORD_LEN], size_t m_ind)
{
    int day = 0, year = 0;
    
    for (size_t i = 0; i < strlen(words[0]); i++)
        if (isdigit(words[0][i]) == 0)
            return 1;
    
    for (size_t i = 0; i < strlen(words[2]); i++)
        if (isdigit(words[2][i]) == 0)
            return 1;
    
    my_atoi(words[0], &day);
    my_atoi(words[2], &year);
    
    if (day > 0 && day < 32 && year > 0)
    {
        if (m_ind == 2)
            if ((is_leap_year(year) == 1 && day > 28) || (is_leap_year(year) == 0 && day > 29))
                return 1;
        if (day == 31)
            if ((m_ind < 8 && m_ind % 2 == 0) || (m_ind > 7 && m_ind % 2 == 1))
                return 1;
    }
    else
        return 1;
    
    return 0;
}