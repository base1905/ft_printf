/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printspec_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:18:24 by arannara          #+#    #+#             */
/*   Updated: 2020/07/28 20:18:26 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_print_hex(unsigned int n, char c)
{
	char		*str;
	int			bytes;

	bytes = 0;
	str = (c == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	if (n >= 16)
		bytes += ft_print_hex(n / 16, c);
	bytes += ft_putchar(str[n % 16]);
	return (bytes);
}

static int		len_definer(unsigned int n, t_flags flag, int len, int len_prec)
{
	int			bytes;

	bytes = 0;
	if (!flag.minus)
	{
		if (flag.width > len + len_prec)
		{
			if (flag.zero && !flag.dot)
				bytes += zero(flag.width - len - len_prec);
			else
				bytes += whitespace(flag.width - len - len_prec);
		}
		if (len_prec)
			bytes += zero(len_prec);
		bytes += ft_print_hex(n, flag.specifier);
	}
	else
	{
		if (len_prec)
			bytes += zero(len_prec);
		bytes += ft_print_hex(n, flag.specifier);
		if (flag.width > len + len_prec)
			bytes += whitespace(flag.width - len - len_prec);
	}
	return (bytes);
}

int				ft_printspec_x(unsigned int n, struct s_flags flag)
{
	int			bytes;
	int			len;
	int			len_prec;

	bytes = 0;
	len = ft_numsize_base(n, 16);
	len_prec = flag.precision > len ? flag.precision - len : 0;
	if (flag.dot && n == 0 && flag.precision == 0)
	{
		len = 0;
		bytes += whitespace(flag.width);
	}
	else
		bytes += len_definer(n, flag, len, len_prec);
	return (bytes);
}
