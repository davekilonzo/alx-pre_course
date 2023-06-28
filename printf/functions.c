#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_char(va_list types)
{
    char c = va_arg(types, int);
    write(1, &c, 1);
    return 1;
}

int print_string(va_list types)
{
    char *str = va_arg(types, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";

    for (int i = 0; str[i] != '\0'; i++)
    {
        write(1, &str[i], 1);
        count++;
    }

    return count;
}

int print_percent(va_list types)
{
    write(1, "%", 1);
    return 1;
}

int print_int(va_list types)
{
    int n = va_arg(types, int);
    char buffer[32];
    int i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }

    while (n > 0)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    for (int j = i - 1; j >= 0; j--)
        write(1, &buffer[j], 1);

    return i;
}

int print_binary(va_list types)
{
    unsigned int n = va_arg(types, unsigned int);
    char buffer[32];
    int i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    while (n > 0)
    {
        buffer[i++] = (n % 2) + '0';
        n /= 2;
    }

    for (int j = i - 1; j >= 0; j--)
        write(1, &buffer[j], 1);

    return i;
}

