#include "my_funcs.h"

int input_str(char *str, size_t *str_len)
{
    char sym;
    size_t i = 0;
    sym = getchar();
    
    while (sym != EOF && sym != '\n')
    {
        if (i == STR_LEN - 1)
            return 1;
        str[i] = sym;
        i++;
        sym = getchar();
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
        if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!' || str[i] == '-' || str[i] == ';' || str[i] == ':')
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

int making_new_str(char words[][WORD_LEN], size_t words_len, char *new_str)
{
    size_t k = 0;
    for (size_t i = 0; i < words_len - 1; i++)
        if (strcmp(words[words_len - 2 - i], words[words_len - 1]) != 0)
        {
            for (size_t j = 0; j < strlen(words[words_len - 2 - i]); j++)
            {
                if (words[words_len - 2 - i][j] != '\0')
                {
                    if (words[words_len - 2 - i][j] == words[words_len - 2 - i][0] && j != 0)
                        continue;
                    new_str[k] = words[words_len - 2 - i][j];
                    k++;
                }
            }
            if (i == words_len - 2)
                new_str[k] = '\0';
            else
                new_str[k] = ' ';
            k++;
        }
    if (k == 0)
        return 1;
    return 0;
}