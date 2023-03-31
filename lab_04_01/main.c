#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc = EXIT_SUCCESS;
    
    // Тест функции strpbrk
    printf("strpbrk TESTS:\n");
    if (strpbrk("", "") == my_strpbrk("", ""))
        printf("Test 1 PASSED\n");
    else
    {
        printf("Test 1 FAILED\n");
        rc = EXIT_FAILURE;
    }
    
    if (strpbrk("hello", "hello") == my_strpbrk("hello", "hello"))
        printf("Test 2 PASSED\n");
    else
    {
        printf("Test 2 FAILED\n");
        rc = EXIT_FAILURE;
    }
    
    if (strpbrk("hello", "cat") == my_strpbrk("hello", "cat"))
        printf("Test 3 PASSED\n");
    else
    {
        printf("Test 3 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strpbrk("hello", "cato") == my_strpbrk("hello", "cato"))
        printf("Test 4 PASSED\n");
    else
    {
        printf("Test 4 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strpbrk("hello", "adios") == my_strpbrk("hello", "adios"))
        printf("Test 5 PASSED\n");
    else
    {
        printf("Test 5 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strpbrk("hello", "") == my_strpbrk("hello", ""))
        printf("Test 6 PASSED\n");
    else
    {
        printf("Test 6 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strpbrk("", "bye") == my_strpbrk("", "bye"))
        printf("Test 7 PASSED\n");
    else
    {
        printf("Test 7 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    printf("\n");
    
    // Teст функции strspn
    printf("strspn TESTS:\n");
    if (strspn("", "") == my_strspn("", ""))
        printf("Test 1 PASSED\n");
    else
    {
        printf("Test 1 FAILED\n");
        rc = EXIT_FAILURE;
    }
    
    if (strspn("hello", "hello") == my_strspn("hello", "hello"))
        printf("Test 2 PASSED\n");
    else
    {
        printf("Test 2 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strspn("hello", "cat") == my_strspn("hello", "cat"))
        printf("Test 3 PASSED\n");
    else
    {
        printf("Test 3 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strspn("hello", "el") == my_strspn("hello", "el"))
        printf("Test 4 PASSED\n");
    else
    {
        printf("Test 4 FAILED\n");
        rc = EXIT_FAILURE;
    }
    
    if (strspn("hello", "") == my_strspn("hello", ""))
        printf("Test 5 PASSED\n");
    else
    {
        printf("Test 5 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strspn("", "hello") == my_strspn("", "hello"))
        printf("Test 6 PASSED\n");
    else
    {
        printf("Test 6 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strspn("hello", "eh") == my_strspn("hello", "eh"))
        printf("Test 7 PASSED\n");
    else
    {
        printf("Test 7 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    printf("\n");
    
    // Teст функции strcspn
    printf("strcspn TESTS:\n");
    if (strcspn("", "") == my_strcspn("", ""))
        printf("Test 1 PASSED\n");
    else
    {
        printf("Test 1 FAILED\n");
        rc = EXIT_FAILURE;
    }
    
    if (strcspn("hello", "hello") == my_strcspn("hello", "hello"))
        printf("Test 2 PASSED\n");
    else
    {
        printf("Test 2 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strcspn("hello", "cat") == my_strcspn("hello", "cat"))
        printf("Test 3 PASSED\n");
    else
    {
        printf("Test 3 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strcspn("hello", "el") == my_strcspn("hello", "el"))
        printf("Test 4 PASSED\n");
    else
    {
        printf("Test 4 FAILED\n");
        rc = EXIT_FAILURE;
    }
    
    if (strcspn("hello", "") == my_strcspn("hello", ""))
        printf("Test 5 PASSED\n");
    else
    {
        printf("Test 5 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strcspn("", "hello") == my_strcspn("", "hello"))
        printf("Test 6 PASSED\n");
    else
    {
        printf("Test 6 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strcspn("hello", "eh") == my_strcspn("hello", "eh"))
        printf("Test 7 PASSED\n");
    else
    {
        printf("Test 7 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    printf("\n");
    
    // Teст функции strchr
    printf("strchr TESTS:\n");
    if (strchr("", '\0') == my_strchr("", '\0'))
        printf("Test 1 PASSED\n");
    else
    {
        printf("Test 1 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strchr("hello", 'h') == my_strchr("hello", 'h'))
        printf("Test 2 PASSED\n");
    else
    {
        printf("Test 2 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strchr("hello", 'l') == my_strchr("hello", 'l'))
        printf("Test 3 PASSED\n");
    else
    {
        printf("Test 3 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strchr("hello", 'o') == my_strchr("hello", 'o'))
        printf("Test 4 PASSED\n");
    else
    {
        printf("Test 4 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strchr("hello", 'd') == my_strchr("hello", 'd'))
        printf("Test 5 PASSED\n");
    else
    {
        printf("Test 5 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strchr("hello", '\0') == my_strchr("hello", '\0'))
        printf("Test 6 PASSED\n");
    else
    {
        printf("Test 6 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strchr("", 'a') == my_strchr("", 'a'))
        printf("Test 7 PASSED\n");
    else
    {
        printf("Test 7 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    printf("\n");
    
    // Teст функции strrchr
    printf("strrchr TESTS:\n");
    if (strrchr("", '\0') == my_strrchr("", '\0'))
        printf("Test 1 PASSED\n");
    else
    {
        printf("Test 1 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strrchr("hello", 'h') == my_strrchr("hello", 'h'))
        printf("Test 2 PASSED\n");
    else
    {
        printf("Test 2 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strrchr("hello", 'l') == my_strrchr("hello", 'l'))
        printf("Test 3 PASSED\n");
    else
    {
        printf("Test 3 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strrchr("hello", 'o') == my_strrchr("hello", 'o'))
        printf("Test 4 PASSED\n");
    else
    {
        printf("Test 4 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strrchr("hello", 'd') == my_strrchr("hello", 'd'))
        printf("Test 5 PASSED\n");
    else
    {
        printf("Test 5 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strrchr("hello", '\0') == my_strrchr("hello", '\0'))
        printf("Test 6 PASSED\n");
    else
    {
        printf("Test 6 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    if (strrchr("", 'a') == my_strrchr("", 'a'))
        printf("Test 7 PASSED\n");
    else
    {
        printf("Test 7 FAILED\n");
        rc = EXIT_FAILURE;
    }
        
    printf("\n");
        
    return rc;
}
