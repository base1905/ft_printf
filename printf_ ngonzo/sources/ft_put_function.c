/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:23:05 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/28 15:23:06 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		ft_nputchar(char c, int number)
{
	int				len;

	len = 0;
	while (len < number)
	{
		write(1, &c, 1);
		len++;
	}
	return (len);
}

int		ft_putstr(char *str)
{
	int				len;
	int				strlen;

	len = 0;
	strlen = ft_strlen(str);
	while (len < strlen)
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}

int		ft_putstrl(char *str, int number)
{
	int				len;

	len = 0;
	while (len < number)
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}

int		ft_putnbr(long long int num)
{
	int				len;

	len = 0;
	if (num < 0)
	{
		len += ft_putchar('-');
		num = -num;
	}
	if (num < 10)
	{
		len++;
		ft_putchar(num + '0');
	}
	else
	{
		len += ft_putnbr(num / 10);
		len += ft_putnbr(num % 10);
	}
	return (len);
}

int		ft_putns16(long int ns10, char c)
{
	int				len;

	len = 0;
	if (ns10 > 15)
	{
		len += ft_putns16(ns10 / 16, c);
		len += ft_putns16(ns10 % 16, c);
	}
	else if (ns10 > 9)
	{
		if (c == 'X')
			len += ft_putchar(ns10 - 10 + 'A');
		else
			len += ft_putchar(ns10 - 10 + 'a');
	}
	else
		len += ft_putchar(ns10 + '0');
	return (len);
}
