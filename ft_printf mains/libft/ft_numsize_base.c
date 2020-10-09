/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numsize_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:40:03 by arannara          #+#    #+#             */
/*   Updated: 2020/07/28 12:40:31 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numsize_base(long int n, int base)
{
	int		size;

	size = 1;
	while ((n / base != 0))
    {
		n = n / base;
        size++;
    }
	return (size);
}
