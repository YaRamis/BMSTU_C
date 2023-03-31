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

int checking_repeating(size_t word_index, char compared_words[][WORD_LEN])
{
    for (size_t i = 0; i < word_index; i++)
        if (strcmp(compared_words[word_index], compared_words[i]) == 0)
            return 1;
    return 0;
}

int checking_word(char *word, char compared_words[][WORD_LEN], size_t *words_len)
{
    for (size_t i = 0; i < *words_len; i++)
    {
        if (strcmp(word, compared_words[i]) == 0)
            return 0;
    }
    return 1;
}