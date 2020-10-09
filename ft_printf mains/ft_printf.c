/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:53:42 by arannara          #+#    #+#             */
/*   Updated: 2020/07/13 10:54:17 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

t_flags		ft_zerostruct(void)
{
	t_flags	flag;

	flag.zero = 0;
	flag.minus = 0;
	flag.width = 0;
	flag.dot = 0;
	flag.precision = 0;
	flag.specifier = 0;
	return (flag);
}

int			ft_specifier(char s)
{
	if (s == 'c' || s == 's' || s == 'p' ||
		s == 'd' || s == 'i' || s == 'u' ||
		s == 'x' || s == 'X' || s == '%')
		return (1);
	return (0);
}

t_flags		parser(const char **s, va_list ap)
{
	t_flags	flag;

	flag = ft_zerostruct();
	(*s)++;
	while (**s && !ft_specifier(**s))
	{
		if (**s == '-')
			flag.minus = 1;
		else if (**s == '0' && !flag.minus)
			flag.zero = 1;
		else if (**s == '.' && !flag.dot)
			flag.precision = ft_getprecision(&(*s), ap, &flag);
		else if (ft_isdigit(**s) || **s == '*')
			flag.width = ft_getwidth(&(*s), ap, &flag);
		else
			break ;
		(*s)++;
	}
	return (flag);
}

int			ft_processor(va_list ap, const char **s)
{
	t_flags	flag;

	flag = parser(&(*s), ap);
	if (**s == 'c')
		return (ft_printspec_c(va_arg(ap, int), flag));
	else if (**s == 's')
	{
		flag.specifier = 's';
		return (ft_printspec_s(va_arg(ap, char *), flag));
	}
	else if (**s == 'd' || **s == 'i')
		return (ft_printspec_di(va_arg(ap, int), flag));
	else if (**s == 'u')
		return (ft_printspec_u(va_arg(ap, unsigned int), flag));
	else if (**s == 'x' || **s == 'X')
	{
		flag.specifier = (**s == 'x') ? 'x' : 'X';
		return (ft_printspec_x(va_arg(ap, unsigned int), flag));
	}
	else if (**s == 'p')
		return (ft_printspec_p(va_arg(ap, unsigned long int), flag));
	else if (**s == '%')
		return (ft_printspec_c('%', flag));
	else
		return (putchar(**s));
}

int			ft_printf(const char *s, ...)
{
	va_list	ap;
	int		bytes;

	bytes = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
			bytes += ft_processor(ap, &s);
		else
			bytes += ft_putchar(*s);
		if (*s)
			s++;
	}
	va_end(ap);
	return (bytes);
}
