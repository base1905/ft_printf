#include "libftprintf.h"
#include <stdlib.h>

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstc;
	const char	*srccc;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dstc = (char *)dst;
	srccc = (const char *)src;
	while (n--)
		dstc[n] = srccc[n];
	return (dst);
}

static char	*ft_strdup(const char *s1)
{
	char	*rtn;
	size_t	len;

	len = ft_strlen(s1) + 1;
	rtn = malloc(sizeof(char) * len);
	if (!rtn)
		return (0);
	rtn = ft_memcpy(rtn, s1, len);
	return (rtn);
}

static int		ft_estim(long n)
{
	size_t	estim;
	int		isneg;

	estim = 0;
	isneg = 0;
	if (n < 0)
	{
		estim++;
		isneg++;
		n = -n;
	}
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

static char		*ft_gen(char *rtn, long nbr, int len, int isneg)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	isneg = 0;
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

static char			*ft_itoa(int n)
{
	int		len;
	char	*rtn;
	long	nbr;
	int		isneg;

	nbr = n;
	len = ft_estim(nbr);
	rtn = 0;
	isneg = 0;
	if (!(rtn = ft_gen(rtn, nbr, len, isneg)))
		return (0);
	return (rtn);
}
static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


static int		ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}


static int		ft_treat_width(int width, int minus, int has_zero)
{
	int i;

	i = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		i++;
	}
	return (i);
}

static int		ft_putstrprec(char *str, int prec)
{
	int i;

	i = 0;
	while (str[i] && i < prec)
		ft_putchar(str[i++]);
	return (i);
}

static int	ft_in_put_part_int(char *d_i, int save_i, struct s_flags flag)
{
	int char_count;

	char_count = 0;
	if (save_i < 0 && flag.dot >= 0)
		ft_putchar('-');
	if (flag.dot >= 0)
		char_count += ft_treat_width(flag.dot - 1, ft_strlen(d_i) - 1, 1);
	char_count += ft_putstrprec(d_i, ft_strlen(d_i));
	return (char_count);
}

static int	ft_put_part_int(char *d_i, int save_i, struct s_flags flag)
{
	int char_count;

	char_count = 0;
	if (flag.minus == 1)
		char_count += ft_in_put_part_int(d_i, save_i, flag);
	if (flag.dot >= 0 && (size_t)flag.dot < ft_strlen(d_i))
		flag.dot = ft_strlen(d_i);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		char_count += ft_treat_width(flag.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flag.width, ft_strlen(d_i), flag.zero);
	if (flag.minus == 0)
		char_count += ft_in_put_part_int(d_i, save_i, flag);
	return (char_count);
}

int	ft_printspec_di(int i, struct s_flags flag)
{
	char	*d_i;
	int		save_i;
	int		char_count;

	save_i = i;
	char_count = 0;
	if (flag.dot == 0 && i == 0)
	{
		char_count += ft_treat_width(flag.width, 0, 0);
		return (char_count);
	}
	if (i < 0 && (flag.dot >= 0 || flag.zero == 1))
	{
		if (flag.zero == 1 && flag.dot == -1)
			ft_putstrprec("-", 1);
		i *= -1;
		flag.zero = 1;
		flag.width--;
		char_count++;
	}
	d_i = ft_itoa(i);
	char_count += ft_put_part_int(d_i, save_i, flag);
	free(d_i);
	return (char_count);
}