#include "my_funcs.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc;
    
    char months[][WORD_LEN] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
    char str[STR_LEN];
    size_t str_len = 0;
    char words[WORDS_COUNT][WORD_LEN];
    size_t words_len = 0;
    
    rc = input_str(str, &str_len);
    if (rc == 2)
        return EXIT_FAILURE;
    else if (rc == 1)
    {
        printf("NO");
        return EXIT_SUCCESS;
    }
        
    
    all_tolower(str, str_len);
    
    rc = get_words(str, words, str_len, &words_len);
    
    if (rc == 0 && words_len == 3)
    {
        rc = 1;
        for (size_t i = 0; i < 12; i++)
            if (strcmp(words[1], months[i]) == 0)
                rc = looking_for_date(words, i + 1);
    }
        
    if (rc == 0 && words_len == 3)
        printf("YES");
    else
        printf("NO");
    
    return EXIT_SUCCESS;
}