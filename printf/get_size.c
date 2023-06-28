#define S_LONG 1
#define S_SHORT 2

int get_size(const char *format, int *i)
{
    int size = 0;

    if (format[*i + 1] == 'l')
        size = S_LONG;
    else if (format[*i + 1] == 'h')
        size = S_SHORT;

    if (size != 0)
        (*i)++;

    return size;
}

