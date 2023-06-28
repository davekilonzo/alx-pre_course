#include <stdbool.h>

int get_precision(const char *format, int *i, va_list list)
{
    int precision = -1;
    bool done = false;

    if (format[*i + 1] != '.')
        return precision;

    (*i) += 2;
    precision = 0;

    while (!done)
    {
        if (format[*i] >= '0' && format[*i] <= '9')
        {
            precision *= 10;
            precision += format[*i] - '0';
            (*i)++;
        }
        else if (format[*i] == '*')
        {
            precision = va_arg(list, int);
            (*i)++;
            done = true;
        }
        else
            done = true;
    }

    return precision;
}

