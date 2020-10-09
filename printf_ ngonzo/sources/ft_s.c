/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 11:26:50 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/29 11:26:52 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		check_s(const char **line, va_list ap, int *checks, char *flags)
{
	char			*argument;
	int				printlen;

	*line = *line + 1;
	printlen = 0;
	argument = va_arg(ap, char *);
	if (argument == NULL)
	{
		argument = "(null)";
		if (checks[1] < 6 && checks[1] > 0)
			return (ft_nputchar(' ', checks[0]));
	}
	printlen += prefix_fillers_s(argument, checks, flags);
	return (printlen);
}

int		prefix_fillers_s(char *argument, int *checks, char *flags)
{
	int				printlen;
	int				len;

	printlen = 0;
	len = ft_strlen(argument);
	if (checks[1] >= 0)
		if (len > checks[1])
			len = checks[1];
	if (!ft_strchr(flags, '-'))
		printlen += ft_nputchar(' ', (checks[0] - len));
	if (checks[1] >= 0)
		printlen += ft_putstrl(argument, len);
	else
		printlen += ft_putstr(argument);
	if (ft_strchr(flags, '-'))
		printlen += ft_nputchar(' ', (checks[0] - len));
	if (checks[0] < 0)
		printlen += ft_nputchar(' ', (-checks[0] - len));
	return (printlen);
}
