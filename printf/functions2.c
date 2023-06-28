#include <stdarg.h>
#include <unistd.h>

int print_pointer(va_list types)
{
    void *ptr = va_arg(types, void *);
    unsigned long n = (unsigned long)ptr;
    char buffer[32];
    int i = 0;

    if (ptr == NULL)
    {
        write(1, "(nil)", 5);
        return 5;
    }

    write(1, "0x", 2);

    while (n > 0)
    {
        buffer[i++] = "0123456789abcdef"[n % 16];
        n /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
        write(1, &buffer[j], 1);

    return i + 2;
}

int print_non_printable(va_list types)
{
    char *str = va_arg(types, char *);
    int count = 0;

    if (str == NULL)
    {
        write(1, "(null)", 6);
        return 6;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= ' ' && str[i] <= '~')
        {
            write(1, &str[i], 1);
            count++;
        }
        else
        {
            write(1, "\\", 1);
            write(1, "0123456789abcdef"[(str[i] >> 4) & 0xf], 1);
            write(1, "0123456789abcdef"[str[i] & 0xf], 1);
            count += 3;
        }
    }

    return count;
}

int print_reverse(va_list types)
{
    char *str = va_arg(types, char *);
    int count = 0;

    if (str == NULL)
    {
        write(1, "(null)", 6);
        return 6;
    }

    for (int i = 0; str[i] != '\0'; i++)
        count++;

    for (int i = count - 1; i >= 0; i--)
        write(1, &str[i], 1);

    return count;
}

int print_rot13string(va_list types)
{
    char *str = va_arg(types, char *);
    int count = 0;

    if (str == NULL)
    {
        write(1, "(null)", 6);
        return 6;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a' && str[i] <= 'm'))
            write(1, str[i] + 13, 1);
        else if ((str[i] >= 'N' && str[i] <= 'Z') || (str[i] >= 'n' && str[i] <= 'z'))
            write(1, str[i] - 13, 1);
        else
            write(1, &str[i], 1);

        count++;
    }

    return count;
}

