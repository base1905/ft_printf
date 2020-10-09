/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 11:00:17 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/29 11:00:19 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		fill_id_width_pre_len_one(int **arg, int *checks, char *flags, int len)
{
	int				printlen;

	printlen = 0;
	if (!ft_strchr(flags, '-'))
	{
		if (ft_strchr(flags, '0') && checks[1] < 0)
		{
			printlen += fill_id_negative(arg);
			printlen += ft_nputchar('0', (checks[0] - len));
		}
		else
		{
			printlen += ft_nputchar(' ', (checks[0] - checks[1]));
			printlen += fill_id_negative(arg);
			printlen += ft_nputchar('0', (checks[1] - len));
		}
	}
	return (printlen);
}

int		fill_id_width_pre_len_two(int **arg, int *checks, char *flags, int len)
{
	int				printlen;

	printlen = 0;
	printlen += fill_id_positive(arg, flags);
	if (ft_strchr(flags, '-'))
	{
		printlen += fill_id_negative(arg);
		if (ft_strchr(flags, '0') && checks[1] < 0)
			printlen += ft_nputchar('0', (checks[0] - len));
		else
			printlen += ft_nputchar('0', (checks[1] - len));
	}
	printlen += ft_putnbr(**arg);
	if (ft_strchr(flags, '-'))
		printlen += ft_nputchar(' ', (checks[0] - checks[1]));
	return (printlen);
}

int		fill_id_pre_width_len(int **arg, int *checks, char *flags, int len)
{
	int				printlen;

	printlen = 0;
	{
		printlen += fill_id_negative(arg);
		printlen += fill_id_positive(arg, flags);
		if (!ft_strchr(flags, '-'))
			printlen += ft_nputchar('0', (checks[1] - len));
		if (ft_strchr(flags, '-'))
			printlen += ft_nputchar('0', (checks[1] - len));
		printlen += ft_putnbr(**arg);
	}
	return (printlen);
}

int		fill_id_width_len_pre_one(int **arg, int *checks, char *flags, int len)
{
	int				printlen;

	printlen = 0;
	if (!ft_strchr(flags, '-'))
	{
		if (ft_strchr(flags, '0') && checks[1] < 0)
		{
			printlen += fill_id_negative(arg);
			printlen += ft_nputchar('0', (checks[0] - len));
		}
		else
			printlen += ft_nputchar(' ', (checks[0] - len));
	}
	printlen += fill_id_positive(arg, flags);
	if (**arg == 0 && checks[1] == 0)
		printlen += ft_putchar(' ');
	else
		printlen += ft_putnbr(**arg);
	return (printlen);
}

int		fill_id_width_len_pre_two(int **arg, int *checks, char *flags, int len)
{
	int				printlen;

	printlen = 0;
	if (ft_strchr(flags, '-'))
	{
		if (ft_strchr(flags, '0') && checks[1] < 0)
		{
			printlen += fill_id_negative(arg);
			printlen += ft_nputchar('0', (checks[0] - len));
		}
		else
			printlen += ft_nputchar(' ', (checks[0] - len));
	}
	return (printlen);
}
