/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 08:28:31 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/14 10:09:47 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		ft_printf(const char *line, ...)
{
	va_list			ap;
	int				printlen;

	va_start(ap, line);
	printlen = function(line, ap);
	va_end(ap);
	return (printlen);
}

int		function(const char *line, va_list ap)
{
	int				printlen;
	int				checks[2];
	char			*flags;

	printlen = 0;
	while (*line != '\0')
	{
		if (*line == '%')
		{
			line++;
			flags = check_flags(&line);
			checks[0] = check_width(&line, ap);
			checks[1] = check_precision(&line, ap);
			printlen += check_type(&line, ap, checks, flags);
			ft_free(flags);
		}
		else if (*line != '\0')
		{
			printlen += ft_putchar(*line);
			line++;
		}
	}
	return (printlen);
}

char	*check_flags(const char **line)
{
	char			*tmp;
	int				j;

	j = 0;
	while (*(*line + j) == '-' || *(*line + j) == '+' || *(*line + j) == ' ' ||
			*(*line + j) == '#' || *(*line + j) == '0')
		j++;
	tmp = (char *)malloc(sizeof(char *) * (j + 1));
	if (!tmp)
		return (NULL);
	tmp[j] = '\0';
	while (j > 0)
	{
		tmp[j - 1] = **line;
		*line = *line + 1;
		j--;
	}
	return (tmp);
}

int		check_width(const char **line, va_list ap)
{
	int				tmp;

	tmp = 0;
	if (**line == '*')
	{
		*line = *line + 1;
		tmp = va_arg(ap, int);
		return (tmp);
	}
	while (ft_isdigit(**line))
	{
		tmp = (tmp * 10) + (**line - '0');
		*line = *line + 1;
	}
	return (tmp);
}

int		check_precision(const char **line, va_list ap)
{
	int				tmp;

	tmp = -1;
	if (**line == '.')
	{
		*line = *line + 1;
		tmp = 0;
		if (**line == '*')
		{
			*line = *line + 1;
			tmp = va_arg(ap, int);
			return (tmp);
		}
		while (ft_isdigit(**line))
		{
			tmp = (tmp * 10) + (**line - '0');
			*line = *line + 1;
		}
	}
	return (tmp);
}
