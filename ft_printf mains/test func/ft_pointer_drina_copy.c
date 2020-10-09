#include "libftprintf.h"


static int num_base(size_t n, int base)
{
    int len;

    len = 1;
    while (n / base != 0)
    {
        n /= base;
        len++;
    }
    return (len);
}

int check_sym(char **list)
{
    int count;

    count = 0;
    if ((*list)[0] == '0' && (*list)[1] == 'x')
        ft_putchar('0');
        ft_putchar('x');
    (*list) += count;
    return (count);
}

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
    {
       // bytes += check_sym(&list);
        bytes += zero(flag.width - len);
    }
    if (flag.dot && flag.precision > len)
    {
        //bytes += check_sym(&list);
        bytes += zero(flag.precision - len);
    }
    bytes += ft_putstr(list, len);
    if (flag.minus)
        bytes += whitespace(flag.precision >= len ? flag.width - flag.precision : flag.width - len);
    return (bytes);
}


int ft_pointer(unsigned long int number, struct s_flags flag)
{
    int count;
    char *list;
    
    count = 2 + num_base(number, 16);
    list = (char *)malloc((count + 1) * sizeof(char));
    if (!list)
        return (0);
    list[count--] = '\0';
    if (number == 0)
        list[count--] = '0';
    while (number != 0)
    {
        list[count] = "0123456789abcdef"[number % 16];
        number = number / 16;
        count--;
    }
    list[count--] = 'x';
    list[count] = '0';
    count = print_pointer(list, flag);
    free(list);
    return(count);
}