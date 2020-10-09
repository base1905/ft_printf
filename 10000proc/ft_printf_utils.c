/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:29:43 by arannara          #+#    #+#             */
/*   Updated: 2020/07/28 20:29:44 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		whitespace(int len)
{
	int	bytes;

	bytes = 0;
	while (len > 0)
	{
		bytes += ft_putchar(' ');
		len--;
	}
	return (bytes);
}

int		zero(int len)
{
	int	bytes;

	bytes = 0;
	while (len > 0)
	{
		bytes += ft_putchar('0');
		len--;
	}
	return (bytes);
}

int		ft_getwidth(const char **s, va_list ap, t_flags *flag)
{
	int	width;

	width = 0;
	if (**s == '*')
		width = va_arg(ap, int);
	if (width < 0)
	{
		flag->minus = 1;
		width = -width;
	}
	if (ft_isdigit(**s))
	{
		width = ft_atoi(*s);
		while (ft_isdigit(*(*s + 1)))
			(*s)++;
	}
	return (width);
}

int		ft_getprecision(const char **s, va_list ap, t_flags *flag)
{
	int	precision;

	precision = 0;
	flag->dot = 1;
	if (*(*s + 1) == '*')
	{
		(*s)++;
		precision = va_arg(ap, int);
		if (precision < 0)
			flag->dot = 0;
	}
	if (ft_isdigit(*(*s + 1)))
	{
		(*s)++;
		precision = ft_atoi(*s);
		while (ft_isdigit(*(*s + 1)))
			(*s)++;
	}
	return (precision);
}
