/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printspec_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:47:36 by arannara          #+#    #+#             */
/*   Updated: 2020/07/28 17:47:39 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printspec_c(char c, t_flags flag)
{
	int bytes;

	bytes = 0;
	if (!flag.minus)
	{
		if (flag.width || flag.zero)
			bytes += (flag.zero) ? zero(flag.width - 1) :
			whitespace(flag.width - 1);
		bytes += ft_putchar(c);
	}
	else
	{
		bytes += ft_putchar(c);
		bytes += whitespace(flag.width - 1);
	}
	return (bytes);
}
