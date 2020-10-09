/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:37:34 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/20 21:37:58 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

void				ft_putnbr(long long int n)
{
	unsigned long long int	nb;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0', 1);
	}
	else if (n < 0)
	{
		nb = (unsigned long long int)(n * -1);
		ft_putchar('-', 1);
		ft_putnbr(nb);
	}
	else
	{
		ft_putchar(n % 10 + 48, 1);
	}
}

void				ft_putstr(char *s, size_t len)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && len-- > 0)
	{
		ft_putchar(s[i], 1);
		i++;
	}
}

int					ft_putchar(const char c, int end)
{
	static int				i = 0;
	int						k;

	if (end == 0)
		k = i;
	if (end == 0)
		i = 0;
	if (end == 0)
		return (k);
	write(1, &c, 1);
	i++;
	return (i);
}

unsigned long int	ft_nbr_len_base(unsigned long int nb, int base)
{
	int						i;

	i = 0;
	while (nb >= (unsigned long)base)
	{
		nb = nb / base;
		i++;
	}
	return (i + 1);
}

size_t				ft_strlen(const char *str)
{
	size_t					i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
