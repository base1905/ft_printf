/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_f_sc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:26:24 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/20 21:46:50 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

void	ft_pf_f_sc(const char **tm, va_list arg)
{
	char	*str;
	char	c;
	size_t	len;

	c = '%';
	str = "";
	if (*(*tm) == 'c')
		c = va_arg(arg, int);
	if (*(*tm) == 's')
		str = va_arg(arg, char*);
	if (*(*tm) == 's' && str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (*(*tm) == 's')
		ft_pf_f_sc_s(str, len, tm);
	else if (*(*tm) == 'c' || *(*tm) == '%')
		ft_pf_f_sc_c(c, tm);
}

void	ft_pf_f_sc_c(char c, const char **tm)
{
	if (s_fl.w != 0 && s_fl.w != s_fl.a)
		ft_pf_print_w(&c, 1, tm);
	else if (s_fl.a != 0)
		ft_pf_print_a(1, 0, &c, tm);
	else
		ft_putchar(c, 1);
}

void	ft_pf_f_sc_s(char *str, int len, const char **tm)
{
	if (s_fl.w != 0)
		ft_pf_print_w_s(str, len, tm);
	else if (s_fl.a > 0)
		ft_pf_print_a_s(str, len, tm);
	else if (s_fl.a == 0 && s_fl.d == 1)
		return ;
	else
		ft_putstr(str, len);
}
