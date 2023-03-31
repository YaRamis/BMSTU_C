#include "my_funcs.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc;
    
    char first_str[STR_LEN], second_str[STR_LEN];
    size_t str_1_len = 0, str_2_len = 0;
    char first_words[WORDS_COUNT][WORD_LEN], second_words[WORDS_COUNT][WORD_LEN];
    size_t words_1_len = 0, words_2_len = 0;
    
    printf("Enter first string:\n");
    rc = input_str(first_str, &str_1_len);
    if (rc != 0)
        return EXIT_FAILURE;
    printf("Enter second string:\n");
    rc = input_str(second_str, &str_2_len);
    if (rc != 0)
        return EXIT_FAILURE;
    
    rc = get_words(first_str, first_words, str_1_len, &words_1_len);
    if (rc != 0)
        return EXIT_FAILURE;
    rc = get_words(second_str, second_words, str_2_len, &words_2_len);
    if (rc != 0)
        return EXIT_FAILURE;
    
    printf("Result: ");
    for (size_t i = 0; i < words_1_len; i++)
        if (checking_repeating(i, first_words) == 0)
        {
            if (checking_word(first_words[i], second_words, &words_2_len) == 0)
                printf("%s yes\n", first_words[i]);
            else
                printf("%s no\n", first_words[i]);
        }
    
    return EXIT_SUCCESS;
}