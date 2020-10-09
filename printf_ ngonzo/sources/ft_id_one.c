/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 11:00:06 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/29 11:00:11 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		check_id(const char **line, va_list ap, int *checks, char *flags)
{
	int				argument;
	int				printlen;
	int				len;

	*line = *line + 1;
	printlen = 0;
	argument = va_arg(ap, int);
	len = ft_nbrlen(argument);
	printlen = prefix_fill_id(&argument, checks, flags, len);
	return (printlen);
}

int		prefix_fill_id(int *arg, int *checks, char *flags, int len)
{
	int				printlen;

	printlen = 0;

	if (ft_strchr(flags, '+') || *arg < 0 || ft_strchr(flags, ' '))
		checks[0] = checks[0] - 1;
	if (checks[1] >= len)
	{
		if (checks[0] >= checks[1])
		{
			printlen = fill_id_width_pre_len_one(&arg, checks, flags, len);
			printlen += fill_id_width_pre_len_two(&arg, checks, flags, len);
		}
		else if (checks[1] >= checks[0])
			printlen = fill_id_pre_width_len(&arg, checks, flags, len);
	}
	else if (len >= checks[1])
	{
		if (checks[0] >= len)
		{
			printlen = fill_id_width_len_pre_one(&arg, checks, flags, len);
			printlen += fill_id_width_len_pre_two(&arg, checks, flags, len);
		}
		else if (len >= checks[0])
			printlen = fill_id_len_pre_width(&arg, checks, flags, len);
	}
	return (printlen);
}

int		fill_id_negative(int **argument)
{
	int				printlen;

	printlen = 0;
	if (**argument < 0)
	{
		printlen += ft_putchar('-');
		**argument = -**argument;
	}
	return (printlen);
}

int		fill_id_positive(int **argument, char *flags)
{
	int				printlen;

	printlen = 0;
	if (ft_strchr(flags, '+'))
		printlen += ft_putchar('+');
	else if (ft_strchr(flags, ' ') && **argument > 0)
		printlen += ft_putchar(' ');
	return (printlen);
}

int		fill_id_len_pre_width(int **arg, int *checks, char *flags, int len)
{
	int				printlen;

	printlen = 0;
	printlen += fill_id_positive(arg, flags);
	if (**arg < 0)
		checks[0] += 2;
	if (**arg == 0 && checks[1] == 0)
		;
	else
		printlen += ft_putnbr(**arg);
	if (checks[0] < 0)
		printlen += ft_nputchar(' ', (-checks[0] - len));
	return (printlen);
}
