int get_width(const char *format, int *i, va_list list)
{
    int width = 0;
    bool done = false;

    (*i)++;

    while (!done)
    {
        if (format[*i] >= '0' && format[*i] <= '9')
        {
            width *= 10;
            width += format[*i] - '0';
            (*i)++;
        }
        else if (format[*i] == '*')
        {
            width = va_arg(list, int);
            (*i)++;
            done = true;
        }
        else
            done = true;
    }

    return width;
}

