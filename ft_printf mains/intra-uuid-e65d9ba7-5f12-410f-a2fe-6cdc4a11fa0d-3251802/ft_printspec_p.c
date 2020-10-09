/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printspec_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 23:47:37 by arannara          #+#    #+#             */
/*   Updated: 2020/07/28 23:47:39 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	len_definer(char *str, t_flags flag, int len, int len_prec)
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
		bytes += ft_putstr(str, len);
	}
	else
	{
		if (len_prec)
			bytes += zero(len_prec);
		bytes += ft_putstr(str, len);
		if (flag.width > len + len_prec)
			bytes += whitespace(flag.width - len - len_prec);
	}
	return (bytes);
}

int			ft_printspec_p(unsigned long int n, t_flags flag)
{
	int		bytes;
	char	*str;
	int		len;
	int		len_prec;

	bytes = 2 + ft_numsize_base(n, 16);
	if (!(str = (char *)malloc((bytes + 1) * sizeof(char))))
		return (0);
	str[bytes--] = '\0';
	if (n == 0)
		str[bytes--] = '0';
	while (n != 0)
	{
		str[bytes--] = "0123456789abcdef"[n % 16];
		n = n / 16;
	}
	str[bytes--] = 'x';
	str[bytes] = '0';
	len = ft_strlen(str);
	len_prec = flag.precision > len ? flag.precision - len : 0;
	if (flag.dot && !flag.precision && str[2] == '0')
		len--;
	bytes = len_definer(str, flag, len, len_prec);
	free(str);
	return (bytes);
}
