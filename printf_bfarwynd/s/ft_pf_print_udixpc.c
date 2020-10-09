/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_udixpc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:12:47 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/20 21:49:04 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

void	ft_pf_print_w(void *var, int len, const char **tm)
{
	int		w;

	if (s_fl.w < 0)
		s_fl.m = 1;
	if (s_fl.w < 0)
		s_fl.w *= -1;
	w = s_fl.w - (len >= s_fl.a ? len : s_fl.a);
	if (*(*tm) == 'd' || *(*tm) == 'i')
		w -= *((int*)var) < 0 ? 1 : 0;
	if (s_fl.d == 1 && s_fl.a > len)
		ft_pf_print_a(len, w, var, tm);
	else if (s_fl.m != 1)
	{
		while (w-- > 0)
			ft_putchar(' ', 1);
		if (s_fl.a == 0 && s_fl.d == 1)
			ft_putchar(' ', 1);
		if (*(*tm) != 'p' && s_fl.a == 0 && s_fl.d == 1)
			return ;
		ft_pf_print(0, var, tm);
	}
	else if (s_fl.m == 1)
		ft_pf_print_m(w, var, tm);
}

void	ft_pf_print_a(int len, int w, void *var, const char **tm)
{
	if (s_fl.m == 0 && s_fl.a > len && s_fl.a < s_fl.w)
	{
		while (w-- > 0)
			ft_putchar(' ', 1);
		ft_pf_print_a_z(len, var, tm);
		ft_pf_print(0, var, tm);
	}
	else if (s_fl.a > len && s_fl.w > len)
	{
		ft_pf_print_a_z(len, var, tm);
		ft_pf_print(0, var, tm);
		while (w-- > 0)
			ft_putchar(' ', 1);
	}
	else if (s_fl.a > len && s_fl.a > s_fl.w)
	{
		ft_pf_print_a_z(len, var, tm);
		ft_pf_print(0, var, tm);
	}
}

void	ft_pf_print_a_z(int len, void *var, const char **tm)
{
	if ((*(*tm) == 'd' || *(*tm) == 'i'))
		if (s_fl.z == 1 && s_fl.d != 1)
			if (*((int*)var) < 0)
				len += 1;
	while ((s_fl.a - len) > 0)
	{
		if (*((int*)var) < 0 && len < s_fl.a &&
		(*(*tm) == 'd' || *(*tm) == 'i'))
		{
			*((int*)var) *= -1;
			ft_putchar('-', 1);
		}
		ft_putchar('0', 1);
		s_fl.a--;
	}
}
