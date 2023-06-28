#include <stdarg.h>
#include <unistd.h>

typedef struct fmt_t
{
    char fmt;
    int (*fn)(va_list);
} fmt_t;

int handle_print(const char *fmt, int *ind, va_list list)
{
    fmt_t fmt_types[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'i', print_int},
        {'d', print_int},
        {'b', print_binary},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hexadecimal},
        {'X', print_hexa_upper},
        {'p', print_pointer},
        {'S', print_non_printable},
        {'r', print_reverse},
        {'R', print_rot13string},
        {'\0', NULL}
    };

    for (int i = 0; fmt_types[i].fmt != '\0'; i++)
    {
        if (fmt[*ind] == fmt_types[i].fmt)
            return fmt_types[i].fn(list);
    }

    if (fmt[*ind] != '\0')
    {
        write(1, "%", 1);
        write(1, &fmt[*ind], 1);
        return 2;
    }

    return -1;
}

