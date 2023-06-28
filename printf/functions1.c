#include <stdarg.h>
#include <unistd.h>

int print_unsigned(va_list types)
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
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    for (int j = i - 1; j >= 0; j--)
        write(1, &buffer[j], 1);

    return i;
}

int print_octal(va_list types)
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
        buffer[i++] = (n % 8) + '0';
        n /= 8;
    }

    for (int j = i - 1; j >= 0; j--)
        write(1, &buffer[j], 1);

    return i;
}

int print_hexadecimal(va_list types)
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
        buffer[i++] = "0123456789abcdef"[n % 16];
        n /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
        write(1, &buffer[j], 1);

    return i;
}

int print_hexa_upper(va_list types)
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
        buffer[i++] = "0123456789ABCDEF"[n % 16];
        n /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
        write(1, &buffer[j], 1);

    return i;
}

