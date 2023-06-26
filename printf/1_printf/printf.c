#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c)
{
    return (write(1, &c, 1));
}

int print_string(char *s)
{
    int count = 0;
    int i;

    if (s == NULL)
        return (0);
    for (i = 0; s[i] != '\0'; i++)
    {
        _putchar(s[i]);
        count++;
    }
    return (count);
}

int _printf(const char *format, ...)
{
    int i;
    int count = 0;
    char c;
    char *string;
    va_list args;

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            ++i;
            if (format[i] == 'c')
            {
                c = va_arg(args, int);
                count = _putchar(c);
                continue;
            }
            else if (format[i] == 's')
            {
                string = va_arg(args, char *);
                count += print_string(string);
                continue;
            }
        }
        _putchar(format[i]);
        count++;
    }
    va_end(args);
    return (count);
}

