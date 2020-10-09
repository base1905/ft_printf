/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printspec_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 14:38:12 by arannara          #+#    #+#             */
/*   Updated: 2020/07/28 14:38:26 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	absolute_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char		*ft_itoa_zero(int n, int prec)
{
	int		i;
	int		len;
	char	*str;

	len = ft_numsize_base(n, 10);
	if (prec > len)
		len = prec;
	if (n < 0)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = '0';
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	while (n / 10 != 0)
	{
		str[--len] = absolute_value(n % 10) + '0';
		n /= 10;
	}
	str[--len] = absolute_value(n % 10) + '0';
	return (str);
}

int			ft_printspec_di(int n, t_flags flag)
{
	char	*str;
	int		bytes;

	if (flag.zero && (flag.dot || flag.minus))
		flag.zero = 0;
	if (flag.zero)
	{
		flag.precision = flag.width;
		if (n < 0)
			flag.precision--;
	}
	if (flag.dot && !flag.precision && n == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_zero(n, flag.precision);
	bytes = ft_printspec_s(str, flag);
	free(str);
	return (bytes);
}
