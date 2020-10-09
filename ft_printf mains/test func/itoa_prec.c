#include "libftprintf.h"

static char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = ft_strlen((char*)str);
	new = (char*)malloc(sizeof(*str) * (len + 1));
	if (!new)
		return (NULL);
	while (i <= len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static int ft_unsignint(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

static int ft_nmlen(int n, int prec)
{
    int len;

    len = 1;
    while (n / 10 != 0)
    {
        n /= 10;
        len++;
    }
    if (prec > 2147483645)
        prec = 2147483645;
    if (prec > len)
        len = prec;
    return (len);
}

char *ft_itoa_prec(int n, int prec)
{
    int i;
    int len;
    char *array;

    len = ft_nmlen(n,prec);
    if (n<0)
        len++;
    if (!(array = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    while (i < len)
        array[i++] = '0';
    if (n < 0)
        array[0] = '-';
    array[len] = '\0';
    while (n / 10 != 0)
    {
        array[--len] = ft_unsignint(n % 10) + '0';
        n /= 10;
    }
    array[--len] = ft_unsignint(n % 10) + '0';
    return (array);
}

ft_printnbr (int n, struct s_flags flag)
{
    char *arr;
    int rtval;
    int prec;

    prec = flag.precision;

    if (((flag.dot && prec >=0) || flag.width < 0 || flag.minus) && flag.zero)
        flag.zero = 0;
    if (flag.zero)
    {
        prec = flag.width;
        if (n < 0)
            prec--;
        flag.width = 0;
    }
    if (flag.dot && prec == 0 && n == 0 && flag.zero == 0)
        arr = ft_strdup("");
    else
        arr = ft_itoa_prec(n, prec);
    if (arr == NULL)
        return (-1);
    rtval = ft_printspec_s(arr, flag);
    free(arr);
    return (rtval);
}