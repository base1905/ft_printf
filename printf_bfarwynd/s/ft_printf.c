/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:55:03 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/22 15:54:26 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		arg;
	const char	*tm;

	va_start(arg, format);
	tm = format;
	while (*tm)
	{
		if (*tm != '%')
			ft_putchar(*tm, 1);
		else
			ft_pf_f(&tm, arg);
		++tm;
	}
	va_end(arg);
	return (ft_putchar('0', 0));
}
