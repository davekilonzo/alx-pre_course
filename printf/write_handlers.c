#include <unistd.h>

int handle_write_char(char c, int width, int flags)
{
    int count = 0;
    char padd = (flags & F_ZERO) ? '0' : ' ';

    if (width > 1 && !(flags & F_MINUS))
    {
        for (int i = 0; i < width - 1; i++)
        {
            write(1, &padd, 1);
            count++;
        }
    }

    write(1, &c, 1);
    count++;

    if (width > 1 && (flags & F_MINUS))
    {
        for (int i = 0; i < width - 1; i++)
        {
            write(1, &padd, 1);
            count++;
        }
    }

    return count;
}

int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision)
{
    int length = BUFF_SIZE - ind - 1;
    char padd = (flags & F_ZERO) && !(flags & F_MINUS) ? '0' : ' ';
    char extra_ch = is_negative ? '-' : (flags & F_PLUS) ? '+' : (flags & F_SPACE) ? ' ' : 0;

    if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
        return 0;

    if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
        buffer[ind] = padd = ' ';

    if (precision > length)
        padd = ' ';

    while (precision > length)
        buffer[--ind] = '0', length++;

    if (extra_ch != 0)
        length++;

    return write_num(ind, buffer, flags, width, length, padd, extra_ch);
}

int write_num(int ind, char buffer[], int flags, int width, int length, char padd, char extra_ch)
{
    int count = 0;

    if (width > length && !(flags & F_MINUS))
    {
        for (int i = 0; i < width - length; i++)
        {
            write(1, &padd, 1);
            count++;
        }
    }

    if (extra_ch != 0)
    {
        write(1, &extra_ch, 1);
        count++;
    }

    for (int i = ind; i < BUFF_SIZE - 1; i++)
    {
        write(1, &buffer[i], 1);
        count++;
    }

    if (width > length && (flags & F_MINUS))
    {
        for (int i = 0; i < width - length; i++)
        {
            write(1, &padd, 1);
            count++;
        }
    }

    return count;
}

int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision)
{
	return write_number(is_negative, ind,
		buffer,
		flags,
		width,
		precision);
}

