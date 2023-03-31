#include "../inc/my_snprintf.h"

size_t get_rank(long long num, unsigned base)
{
    size_t result = 0;
    while (num != 0)
    {
        result++;
        num /= base;
    }
    return result;
}

size_t get_rank_unsigned(unsigned long long num, unsigned base)
{
    size_t result = 0;
    while (num != 0)
    {
        result++;
        num /= base;
    }
    return result;
}

size_t get_dec_number_as_string(char *str, long long num)
{
    char *digits_str = "0123456789";
    size_t digits_count = 0;
    int is_neg = 1;
    
    if (num == 0)
        str[digits_count++] = digits_str[0];
    else
    {
        if (num < 0)
        {
            str[digits_count++] = '-';
            is_neg = -1;
        }
        size_t rank = get_rank(num, 10);

        while (rank != 0)
        {
            long long tmp = 1;
            for (size_t k = 0; k < rank - 1; k++)
                tmp *= 10;
            str[digits_count++] = digits_str[(num / tmp) * is_neg];
            num %= tmp;
            --rank;
        }
    }
    return digits_count;
}

size_t conv_to_another_num_sys_as_str(char *str, unsigned long long num, unsigned base)
{
    char *digits_str = "0123456789abcdef";;
    size_t digits_count = 0;
    
    if (num == 0)
        str[digits_count++] = digits_str[0];
    else
    {
        size_t rank = get_rank_unsigned(num, base);

        while (rank != 0)
        {
            unsigned long long tmp = 1;
            for (size_t k = 0; k < rank - 1; k++)
                tmp *= base;
            str[digits_count++] = digits_str[num / tmp];
            num %= tmp;
            --rank;
        }
    }
    return digits_count;
}

int my_snprintf(char *restrict str, size_t n, const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);
    size_t len = 0;
    char str_buf[STRING_SIZE] = { 0 };

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case '%':
                    str_buf[len++] = '%';
                    break;
                case 'c':
                    str_buf[len++] = va_arg(args, int);
                    break;
                case 's':
                    {
                        char *tmp = va_arg(args, char*);
                        if (tmp == NULL)
                            tmp = "(null)";
                        while (*tmp)
                            str_buf[len++] = *tmp++;
                        break;
                    }
                case 'd':
                    {
                        char tmp[STRING_SIZE] = { '\0' };
                        size_t digits_count = get_dec_number_as_string(tmp, va_arg(args, int));
                        for (size_t i = 0; i < digits_count; i++)
                            str_buf[len++] = tmp[i];
                        break;
                    }
                case 'o':
                    {
                        char tmp[STRING_SIZE] = { '\0' };
                        size_t digits_count = conv_to_another_num_sys_as_str(tmp, va_arg(args, unsigned int), 8);
                        for (size_t i = 0; i < digits_count; i++)
                            str_buf[len++] = tmp[i];
                        break;
                    }
                case 'x':
                    {
                        char tmp[STRING_SIZE] = { '\0' };
                        size_t digits_count = conv_to_another_num_sys_as_str(tmp, va_arg(args, unsigned int), 16);
                        for (size_t i = 0; i < digits_count; i++)
                            str_buf[len++] = tmp[i];
                        break;
                    }
                case 'l':
                    {
                        format++;
                        switch (*format)
                        {
                            case 'd':
                                {
                                    char tmp[STRING_SIZE] = { '\0' };
                                    size_t digits_count = get_dec_number_as_string(tmp, va_arg(args, long));
                                    for (size_t i = 0; i < digits_count; i++)
                                        str_buf[len++] = tmp[i];
                                    break;
                                }
                            case 'o':
                                {
                                    char tmp[STRING_SIZE] = { '\0' };
                                    size_t digits_count = conv_to_another_num_sys_as_str(tmp, va_arg(args, unsigned long), 8);
                                    for (size_t i = 0; i < digits_count; i++)
                                        str_buf[len++] = tmp[i];
                                    break;
                                }
                            case 'x':
                                {
                                    char tmp[STRING_SIZE] = { '\0' };
                                    size_t digits_count = conv_to_another_num_sys_as_str(tmp, va_arg(args, unsigned long), 16);
                                    for (size_t i = 0; i < digits_count; i++)
                                        str_buf[len++] = tmp[i];
                                    break;
                                }
                            default:
                                return len;
                        }
                        break;
                    }
                default:
                    return len;
            }
            format++;
        }
        else
            str_buf[len++] = *format++; 
    }
    va_end(args);
    
    if (n > 0)
    {
        if (len < n - 1)
            str_buf[len] = '\0';
        else
            str_buf[n - 1] = '\0';
    }

    if (!str)
        return len;

    if (n == 0)
        str[0] = '\0';
    else
    {
        size_t i;
        for (i = 0; i < len && i < n - 1; i++)
            str[i] = str_buf[i];
        str[i] = '\0';
    }

    return len;
}
