/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type_p_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 11:30:43 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/29 11:30:45 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		check_type(const char **line, va_list ap, int *checks, char *flags)
{
	if (**line == 'i' || **line == 'd')
		return (check_id(line, ap, checks, flags));
	if (**line == 'u')
		return (check_u(line, ap, checks, flags));
	if (**line == 's')
		return (check_s(line, ap, checks, flags));
	if (**line == 'p')
		return (check_p(line, ap, checks, flags));
	if (**line == 'x' || **line == 'X')
		return (check_x(line, ap, checks, flags));
	if (**line == 'c')
		return (check_c(line, ap, checks, flags));
	if (**line == '%')
		return (checksymbol(line));
	return (0);
}

int		check_p(const char **line, va_list ap, int *checks, char *flags)
{
	long int		argument;
	int				printlen;
	int				width;
	int				len;

	*line = *line + 1;
	printlen = 0;
	width = checks[0];
	argument = va_arg(ap, long int);
	len = ft_ns16len(argument);
	if (argument == 0)
		return (ft_putstr("(nil)"));
	if (!ft_strchr(flags, '-'))
		printlen += ft_nputchar(' ', (width - len - 2));
	printlen += ft_putstr("0x");
	printlen += ft_putns16(argument, 'x');
	if (ft_strchr(flags, '-'))
		printlen += ft_nputchar(' ', (width - len - 2));
	return (printlen);
}

int		check_c(const char **line, va_list ap, int *checks, char *flags)
{
	unsigned char	argument;
	int				width;
	int				printlen;

	*line = *line + 1;
	printlen = 0;
	width = checks[0];
	argument = (unsigned char)va_arg(ap, int);
	if (!ft_strchr(flags, '-'))
		printlen += ft_nputchar(' ', (width - 1));
	printlen += ft_putchar(argument);
	if (ft_strchr(flags, '-'))
		printlen += ft_nputchar(' ', (width - 1));
	return (printlen);
}

int		checksymbol(const char **line)
{
	*line = *line + 1;
	return (ft_putchar('%'));
}
