/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 11:22:14 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/29 11:22:16 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		check_u(const char **line, va_list ap, int *checks, char *flags)
{
	unsigned int	argument;
	int				printlen;

	*line = *line + 1;
	argument = va_arg(ap, unsigned int);
	printlen = prefix_fillers_u(argument, checks, flags);
	return (printlen);
}

int		prefix_fillers_u(unsigned int arg, int *checks, char *flags)
{
	int				printlen;
	int				len;

	len = ft_nbrlen(arg);
	printlen = 0;
	if (checks[1] >= len)
	{
		if (checks[0] >= checks[1])
			printlen += fill_u_width_pre_len(arg, checks, flags, len);
		else if (checks[1] >= checks[0])
			printlen += fill_u_pre_width_len(arg, checks, flags, len);
	}
	else if (len >= checks[1])
	{
		if (checks[0] >= len)
			printlen += fill_u_width_len_pre(arg, checks, flags, len);
		else if (len >= checks[0])
			printlen += fill_u_len_pre_width(arg, checks);
	}
	return (printlen);
}
