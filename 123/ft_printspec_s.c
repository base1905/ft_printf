/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printspec_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:49:50 by arannara          #+#    #+#             */
/*   Updated: 2020/07/28 17:49:53 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printspec_s(char *s, t_flags flag)
{
	int bytes;
	int len;

	bytes = 0;
	if (s == NULL)
		return (ft_printspec_s("(null)", flag));
	len = ft_strlen(s);
	if (flag.precision < 0)
		flag.dot = 0;
	if (flag.specifier == 's' && flag.dot && flag.precision < len)
		len = flag.precision;
	if (!flag.minus)
	{
		if (flag.width > len)
			bytes += (flag.zero) ? zero(flag.width - len) :
			whitespace(flag.width - len);
		bytes += ft_putstr(s, len);
	}
	else
	{
		bytes += ft_putstr(s, len);
		if (flag.width > len)
			bytes += whitespace(flag.width - len);
	}
	return (bytes);
}
