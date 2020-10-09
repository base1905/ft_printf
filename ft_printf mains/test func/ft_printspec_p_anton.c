#include "libftprintf.h"

static void ft_print_hex(unsigned int n)
{
	char	*str;

	str = "0123456789abcdef";
	if ( n >= 16)
		ft_print_hex(n / 16);
	ft_putchar(str[n % 16]);
}

static void len_definer(size_t p, struct s_flags flag, int len)
{
    //char *base;

    //base = "0123456789abcdef";
    if (!flag.minus)
    {
        if (flag.width > len)
            whitespace(flag.width - len);
        write (1, "0x", 2);
        if (!(p == 0 && flag.dot))  
            ft_print_hex(p);
    }
    else
    {
        write (1, "0x", 2);
        if (!(p == 0 && flag.dot))  
            ft_print_hex(p);
        if (flag.width > len)
           whitespace(flag.width - len);
    }
}

int		ft_printspec_p(size_t p, struct s_flags flag)
{
    int bytes;
    int len;

    bytes = 0;
    len = 2 + ft_numlen(p, 16);
    if (p == 0 && flag.dot)
        len--;
    len_definer(p, flag, len);
    if (flag.width > len)
        bytes += flag.width;
    else
        bytes += len;
    return (bytes);
}
