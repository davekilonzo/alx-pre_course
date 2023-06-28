#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    for (int j = 0; str[j] != '\0'; j++)
                    {
                        write(1, &str[j], 1);
                        count++;
                    }
                    break;
                }
                case '%':
                {
                    write(1, "%", 1);
                    count++;
                    break;
                }
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
    }

    va_end(args);
    return count;
}

