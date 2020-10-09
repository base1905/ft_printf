/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 11:13:46 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/29 11:13:51 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		check_x(const char **line, va_list ap, int *checks, char *flags)
{
	unsigned int	argument;
	int				printlen;

	argument = va_arg(ap, unsigned int);
	printlen = prefix_fillers_x(**line, argument, checks, flags);
	*line = *line + 1;
	return (printlen);
}

int		prefix_fillers_x(const char line, unsigned int arg,
								int *checks, char *flags)
{
	int				printlen;
	int				len;

	printlen = 0;
	len = ft_ns16len(arg);
	if (checks[1] >= len)
	{
		if (checks[0] >= checks[1])
			printlen += fill_x_width_pre_len(line, arg, checks, flags);
		else if (checks[1] >= checks[0])
			printlen += fill_x_pre_width_len(line, arg, checks, flags);
	}
	else if (len >= checks[1])
	{
		if (checks[0] >= len)
			printlen += fill_x_width_len_pre(line, arg, checks, flags);
		else if (len >= checks[0])
			printlen += fill_x_len_pre_width(line, arg, checks);
	}
	return (printlen);
}

int		fill_x_len_pre_width(const char line, unsigned int arg, int *checks)
{
	int				printlen;

	printlen = 0;
	if (arg == 0 && checks[1] == 0)
		;
	else
		printlen += ft_putns16(arg, line);
	return (printlen);
}
