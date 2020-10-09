/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:12:47 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/20 21:46:46 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

void		ft_pf_print_w_s(void *var, int len, const char **tm)
{
	if (s_fl.w < 0)
		s_fl.m = 1;
	if (s_fl.w < 0)
		s_fl.w *= -1;
	s_fl.w = s_fl.d != 1 ||
	s_fl.a < 0 ? s_fl.w - len : s_fl.w;
	if (s_fl.d == 1 && s_fl.a >= 0)
		ft_pf_print_a_s(var, len, tm);
	else if (s_fl.m != 1)
	{
		while (s_fl.w-- > 0)
			ft_putchar(' ', 1);
		ft_pf_print(len, var, tm);
	}
	else if (s_fl.m == 1)
	{
		ft_pf_print(len, var, tm);
		while (s_fl.w-- > 0)
			ft_putchar(' ', 1);
	}
}

void		ft_pf_print_a_s(void *var, int len, const char **tm)
{
	s_fl.w = s_fl.a < len ?
	s_fl.w - s_fl.a : s_fl.w - len;
	if (s_fl.m == 0)
	{
		while (s_fl.w-- > 0)
			ft_putchar(' ', 1);
		ft_pf_print(s_fl.a, var, tm);
	}
	else if (s_fl.m == 1)
	{
		ft_pf_print(s_fl.a, var, tm);
		while (s_fl.w-- > 0)
			ft_putchar(' ', 1);
	}
	else
		ft_pf_print(s_fl.a, var, tm);
}
