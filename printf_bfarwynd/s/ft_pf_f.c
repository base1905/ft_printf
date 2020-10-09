/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:22:22 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/22 16:20:30 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

void	ft_pf_f(const char **tm, va_list arg)
{
	s_fl.w = 0;
	s_fl.w_s = 0;
	s_fl.a = 0;
	s_fl.a_s = 0;
	s_fl.d = 0;
	s_fl.z = 0;
	s_fl.m = 0;
	++(*tm);
	if (*(*tm) == '%' || *(*tm) == ' ')
		ft_putchar(*(*tm), 1);
	if (*(*tm) == '%')
		return ;
	if ((*(*tm) >= '0' && *(*tm) <= '9') || *(*tm) == '-' ||
	*(*tm) == '.' || *(*tm) == '*' || *(*tm) == ' ')
		ft_pf_f_f(tm, arg);
	if (*(*tm) == 's' || *(*tm) == 'c' || *(*tm) == '%')
		ft_pf_f_sc(tm, arg);
	else if (*(*tm) == 'u' || *(*tm) == 'd' || *(*tm) == 'i')
		ft_pf_f_udi(tm, arg);
	else if (*(*tm) == 'x' || *(*tm) == 'X' || *(*tm) == 'p')
		ft_pf_f_xp(tm, arg);
}

void	ft_pf_f_f(const char **tm, va_list arg)
{
	while (*(*tm) == '-' || *(*tm) == '0' || *(*tm) == '.'
	|| *(*tm) == ' ')
	{
		if (*(*tm) == '-')
			s_fl.m = 1;
		if (*(*tm) == '0')
			s_fl.z = 1;
		if (*(*tm) == '.')
			s_fl.d = 1;
		++(*tm);
	}
	ft_pf_f_f_star(tm, arg);
	s_fl.w = (s_fl.d != 1 && s_fl.w_s != 1) ? ft_atoi(tm) : s_fl.w;
	ft_pf_f_f_star(tm, arg);
	s_fl.a = (s_fl.d == 1 && s_fl.a_s != 1) ? ft_atoi(tm) : s_fl.a;
	s_fl.a = (s_fl.d != 1 && s_fl.z == 1 &&
	s_fl.m != 1) ? s_fl.w : s_fl.a;
	if ((*(*tm) == '-' || *(*tm) == '0' || *(*tm) == '.'
	|| *(*tm) == ' '))
		ft_pf_f_f(tm, arg);
}

void	ft_pf_f_f_star(const char **tm, va_list arg)
{
	if (*(*tm) == '*')
	{
		if (!s_fl.d)
		{
			s_fl.w_s = 1;
			s_fl.w = va_arg(arg, int);
			if (s_fl.w < 0 && s_fl.z == 1 && s_fl.m != 1)
				s_fl.m = 1;
		}
		else if (s_fl.d)
		{
			s_fl.a_s = 1;
			s_fl.a = va_arg(arg, int);
		}
		++(*tm);
		if (*(*tm) == '.')
		{
			s_fl.d = 1;
			++(*tm);
			if (*(*tm) == '*')
				ft_pf_f_f_star(tm, arg);
		}
	}
}
