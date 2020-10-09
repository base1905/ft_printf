/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:34:15 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/20 16:52:54 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

int						is_atoi_sep(char a)
{
	if (a == ' ' || a == '\n' || a == '\t' ||
			a == '\v' || a == '\f' || a == '\r')
		return (1);
	else
		return (0);
}

int						ft_atoi(const char **tm)
{
	unsigned long long	ret;
	long				m;

	ret = 0;
	m = 1;
	while (is_atoi_sep(*(*tm)))
		++(*tm);
	if (*(*tm) == '-')
		m = -1;
	if (*(*tm) == '-' || *(*tm) == '+')
		++(*tm);
	while (*(*tm) >= '0' && '9' >= *(*tm) && *(*tm) != '\0')
	{
		ret = (ret * 10) + (*(*tm) - '0');
		if (ret > 4294967294 && m == 1)
			return (-1);
		if (ret > 4294967296 && m == -1)
			return (0);
		++(*tm);
	}
	return (ret * m);
}
