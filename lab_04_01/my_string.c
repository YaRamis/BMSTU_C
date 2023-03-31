#include "my_string.h"

char *my_strpbrk(my_string str1, my_string str2)
{
    for (size_t i = 0; str1[i]; i++)
        for (size_t j = 0; str2[j]; j++)
            if (str1[i] == str2[j])
                return str1 + i;
    return NULL;
}

size_t my_strspn(my_string str1, my_string str2)
{
    int f;
    size_t i;
    for (i = 0; str1[i]; i++)
    {
        f = 1;
        for (size_t j = 0; str2[j]; j++)
            if (str1[i] == str2[j])
                f = 0;
        if (f)
            return i;
    }
    return i;
}

size_t my_strcspn(my_string str1, my_string str2)
{
    int f;
    size_t i;
    for (i = 0; str1[i]; i++)
    {
        f = 0;
        for (size_t j = 0; str2[j]; j++)
            if (str1[i] == str2[j])
                f = 1;
        if (f)
            return i;
    }
    return i;
}

char *my_strchr(my_string str, int a)
{
    size_t i;
    for (i = 0; str[i]; i++)
        if (str[i] == a)
            return str + i;
    if (str[i] == a)
        return str + i;
    return NULL;
}

char *my_strrchr(my_string str, int a)
{
    char *p = NULL;
    size_t i;
    for (i = 0; str[i]; i++)
        if (str[i] == a)
            p = str + i;
    if (str[i] == a)
        p = str + i;
    return p;
}