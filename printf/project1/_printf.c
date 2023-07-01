#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);


/**
 * _printf - Prints formatted output
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list arg;
    int count1;

    va_start(arg, format);
    count1 = vprintf(format, arg);
    va_end(arg);

    return (count1);
}

