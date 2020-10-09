/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printspec_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:51:16 by arannara          #+#    #+#             */
/*   Updated: 2020/07/28 17:51:19 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putnbr_counter(unsigned int n)
{
	char	c;
	int		bytes;

	bytes = ft_numsize_base(n, 10);
	if (n > 9)
		ft_putnbr_counter(n / 10);
	c = n % 10 + '0';
	ft_putchar(c);
	return (bytes);
}

static int			len_definer(unsigned int n, t_flags flag, int len, int len_prec)
{
	int		bytes;

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
		bytes += ft_putnbr_counter(n);
	}
	else
	{
		if (len_prec)
			bytes += zero(len_prec);
		bytes += ft_putnbr_counter(n);
		if (flag.width > len + len_prec)
			bytes += whitespace(flag.width - len - len_prec);
	}
	return (bytes);
}

int			ft_printspec_u(unsigned int n, struct s_flags flag)
{
	int		bytes;
	int		len;
	int		len_prec;

	bytes = 0;
	len = ft_numsize_base(n, 10);
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
