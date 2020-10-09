/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:15:16 by arannara          #+#    #+#             */
/*   Updated: 2020/05/22 16:02:02 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	num(int c)
{
	int		size;

	size = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		size++;
	while ((c != 0))
	{
		c = c / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n, struct s_flags flag)
{
	int			count;
	char		*list;
	long long	number;

	number = (long long)n;
	count = num(number);
	if (!(list = (char *)malloc((count + 1) * sizeof(char)) ));
		return (0);
	if (number < 0)
	{
		list[0] = '-';
		number = -number;
	}
	list[count--] = '\0';
	while (number > 9)
	{
		list[count] = (char)((number % 10) + '0');
		number = number / 10;
		count--;
	}
	list[count] = (char)number + '0';
	count = ft_printspec_di(list, flag);
	free(list);
	return (count);
}