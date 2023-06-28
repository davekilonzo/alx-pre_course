#include <stdbool.h>

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

int get_flags(const char *format, int *i)
{
    int flags = 0;
    bool done = false;

    while (!done)
    {
        switch (format[*i + 1])
        {
            case '-':
                flags |= F_MINUS;
                break;
            case '+':
                flags |= F_PLUS;
                break;
            case '0':
                flags |= F_ZERO;
                break;
            case '#':
                flags |= F_HASH;
                break;
            case ' ':
                flags |= F_SPACE;
                break;
            default:
                done = true;
                break;
        }

        if (!done)
            (*i)++;
    }

    return flags;
}

