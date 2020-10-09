/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 11:13:57 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/29 11:14:00 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		fill_x_flago_prenegative_one(int *checks, char *flags, int len, int fl)
{
	int				printlen;

	printlen = 0;
	if (ft_strchr(flags, '0') && checks[1] < 0)
		printlen += ft_nputchar('0', (checks[0] - len));
	else
	{
		if (fl == 0)
			printlen += ft_nputchar(' ', (checks[0] - checks[1]));
		printlen += ft_nputchar('0', (checks[1] - len));
	}
	return (printlen);
}

int		fill_x_flago_prenegative_two(int *checks, char *flags, int len)
{
	int				printlen;

	printlen = 0;
	if (ft_strchr(flags, '0') && checks[1] < 0)
		printlen += ft_nputchar('0', (checks[0] - len));
	else if (checks[0] == len)
		printlen += ft_nputchar(' ', (checks[0] - len + 1));
	else
		printlen += ft_nputchar(' ', (checks[0] - len));
	return (printlen);
}

int		fill_x_width_pre_len(const char line, unsigned int arg,
									int *checks, char *flags)
{
	int				printlen;
	int				len;

	printlen = 0;
	len = ft_ns16len(arg);
	if (!ft_strchr(flags, '-'))
		printlen += fill_x_flago_prenegative_one(checks, flags, len, 0);
	if (ft_strchr(flags, '-'))
		printlen += fill_x_flago_prenegative_one(checks, flags, len, 1);
	printlen += ft_putns16(arg, line);
	if (ft_strchr(flags, '-'))
		printlen += ft_nputchar(' ', (checks[0] - checks[1]));
	return (printlen);
}

int		fill_x_pre_width_len(const char line, unsigned int arg,
									int *checks, char *flags)
{
	int				printlen;
	int				len;

	printlen = 0;
	len = ft_ns16len(arg);
	if (!ft_strchr(flags, '-'))
		printlen += ft_nputchar('0', (checks[1] - len));
	if (ft_strchr(flags, '-'))
		printlen += ft_nputchar('0', (checks[1] - len));
	printlen += ft_putns16(arg, line);
	return (printlen);
}

int		fill_x_width_len_pre(const char line, unsigned int arg,
									int *checks, char *flags)
{
	int				printlen;
	int				len;

	printlen = 0;
	len = ft_ns16len(arg);
	if (!ft_strchr(flags, '-'))
		printlen += fill_x_flago_prenegative_two(checks, flags, len);
	if (arg == 0 && checks[1] == 0)
		printlen += ft_putchar(' ');
	else
		printlen += ft_putns16(arg, line);
	if (ft_strchr(flags, '-'))
		printlen += fill_x_flago_prenegative_two(checks, flags, len);
	return (printlen);
}
