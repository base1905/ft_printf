/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 11:22:22 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/29 11:22:24 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		fill_u_width_pre_len(unsigned int arg, int *checks,
									char *flags, int len)
{
	int				printlen;

	printlen = 0;
	if (!ft_strchr(flags, '-'))
	{
		if (ft_strchr(flags, '0') && checks[1] < 0)
			printlen += ft_nputchar('0', (checks[0] - len));
		else
		{
			printlen += ft_nputchar(' ', (checks[0] - checks[1]));
			printlen += ft_nputchar('0', (checks[1] - len));
		}
	}
	if (ft_strchr(flags, '-'))
	{
		if (ft_strchr(flags, '0') && checks[1] < 0)
			printlen += ft_nputchar('0', (checks[0] - len));
		else
			printlen += ft_nputchar('0', (checks[1] - len));
	}
	printlen += ft_putnbr(arg);
	if (ft_strchr(flags, '-'))
		printlen += ft_nputchar(' ', (checks[0] - checks[1]));
	return (printlen);
}

int		fill_u_pre_width_len(unsigned int argument, int *checks,
										char *flags, int len)
{
	int				printlen;

	printlen = 0;
	if (!ft_strchr(flags, '-'))
		printlen += ft_nputchar('0', (checks[1] - len));
	if (ft_strchr(flags, '-'))
		printlen += ft_nputchar('0', (checks[1] - len));
	printlen += ft_putnbr(argument);
	return (printlen);
}

int		fill_u_width_len_pre(unsigned int arg, int *checks,
									char *flags, int len)
{
	int				printlen;

	printlen = 0;
	if (!ft_strchr(flags, '-'))
	{
		if (ft_strchr(flags, '0') && checks[1] < 0)
			printlen += ft_nputchar('0', (checks[0] - len));
		else
			printlen += ft_nputchar(' ', (checks[0] - len));
	}
	if (arg == 0 && checks[1] == 0)
		printlen += ft_putchar(' ');
	else
		printlen += ft_putnbr(arg);
	if (ft_strchr(flags, '-'))
	{
		if (ft_strchr(flags, '0') && checks[1] < 0)
			printlen += ft_nputchar('0', (checks[0] - len));
		else
			printlen += ft_nputchar(' ', (checks[0] - len));
	}
	return (printlen);
}

int		fill_u_len_pre_width(unsigned int argument, int *checks)
{
	int				printlen;

	printlen = 0;
	if (argument == 0 && checks[1] == 0)
		;
	else
		printlen += ft_putnbr(argument);
	return (printlen);
}
