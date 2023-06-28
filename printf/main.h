#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

typedef struct fmt_t
{
    char fmt;
    int (*fn)(va_list);
} fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *ind, va_list list);

int print_char(va_list types);
int print_string(va_list types);
int print_percent(va_list types);
int print_int(va_list types);
int print_binary(va_list types);
int print_unsigned(va_list types);
int print_octal(va_list types);
int print_hexadecimal(va_list types);
int print_hexa_upper(va_list types);
int print_pointer(va_list types);
int print_non_printable(va_list types);
int print_reverse(va_list types);
int print_rot13string(va_list types);

#endif /* MAIN_H */

