#include "my_funcs.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc;
    
    char str[STR_LEN];
    size_t str_len = 0;
    char words[WORDS_COUNT][WORD_LEN];
    size_t words_len = 0;
    char new_str[STR_LEN] = { 0 };
    
    printf("Enter a string:\n");
    rc = input_str(str, &str_len);
    if (rc != 0)
        return EXIT_FAILURE;
    
    rc = get_words(str, words, str_len, &words_len);
    if (rc != 0)
        return EXIT_FAILURE;
    
    rc = making_new_str(words, words_len, new_str);
    if (rc != 0)
        return EXIT_FAILURE;
    
    printf("Result: %s\n", new_str);
    
    return EXIT_SUCCESS;
}