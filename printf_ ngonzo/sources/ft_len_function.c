/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:23:14 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/28 15:23:16 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		ft_strlen(const char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_nbrlen(int nbr)
{
	int				len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int		ft_ns16len(long int ns10)
{
	int				len;

	len = 0;
	if (ns10 > 15)
	{
		len += ft_ns16len(ns10 / 16);
		len += ft_ns16len(ns10 % 16);
	}
	else if (ns10 > 9)
		len++;
	else
		len++;
	return (len);
}
