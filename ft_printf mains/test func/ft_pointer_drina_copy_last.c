#include "libftprintf.h"

int print_pointer(char *list, struct s_flags flag)
{
    int len;
    int bytes;

    bytes = 0;
    len = ft_strlen(list);
    if (flag.precision == 0 && flag.dot && list[2] == '0')
        len--;
    if (flag.precision > flag.width && flag.dot)
        len -= 2;
    if (flag.width && !flag.minus && !flag.zero && !flag.dot)
        bytes += whitespace(flag.width - len);
    else if (flag.width && (flag.dot || !flag.zero) && !flag.minus)
        bytes += whitespace(flag.precision > len ? flag.width - flag.precision : flag.width - len);
    if (flag.zero && !flag.minus && !flag.dot && flag.width)
        bytes += zero(flag.width - len);
    if (flag.dot && flag.precision > len)
        bytes += zero(flag.precision - len);
    bytes += ft_putstr(list, len);
    if (flag.minus)
        bytes += whitespace(flag.precision >= len ? flag.width - flag.precision : flag.width - len);
    return (bytes);
}


int ft_printspec_p(unsigned long int n, struct s_flags flag)
{
    int bytes;
    char *str;
    
    bytes = 2 + ft_numsize_base(n, 16);
    if (!(str = (char *)malloc((bytes + 1) * sizeof(char))))
        return (0);
    str[bytes--] = '\0';
    if (n == 0)
        str[bytes--] = '0';
    while (n != 0)
    {
        str[bytes] = "0123456789abcdef"[n % 16];
        n = n / 16;
        bytes--;
    }
    str[bytes--] = 'x';
    str[bytes] = '0';
    bytes = print_pointer(str, flag);
    free(str);
    return(bytes);
}