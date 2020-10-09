/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_f_xp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:30:59 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/20 21:46:48 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

void				ft_pf_f_xp(const char **tm, va_list arg)
{
	unsigned long int	xp;
	int					len;

	xp = 0;
	len = 0;
	xp = va_arg(arg, unsigned long int);
	len = ft_nbr_len_base(xp, 16);
	if (*(*tm) != 'p')
		if (s_fl.w != 0 && s_fl.w != s_fl.a)
			ft_pf_print_w(&xp, len, tm);
		else if (s_fl.a != 0 && s_fl.a > len)
			ft_pf_print_a(len, 0, &xp, tm);
		else if (s_fl.d == 1 && s_fl.a == 0)
			return ;
		else
			ft_itoa_xp(xp, tm);
	else if (*(*tm) == 'p')
		ft_pf_f_xp_p(xp, len, tm);
}

void				ft_pf_f_xp_p(unsigned long p, int len, const char **tm)
{
	if (s_fl.w != 0 && s_fl.w != s_fl.a)
		ft_pf_print_w(&p, len + 2, tm);
	else if (s_fl.a != 0 && s_fl.a > len)
		ft_pf_print_a(len + 2, 0, &p, tm);
	else
		ft_itoa_xp(p, tm);
}

void				ft_itoa_xp(unsigned long int n, const char **tm)
{
	const char	*str = "0123456789abcdef";
	int			remainder[21];
	int			i;

	i = 0;
	if (*(*tm) == 'p')
		ft_putstr("0x", 2);
	while (n >= 16 && i++ >= 0)
	{
		remainder[i - 1] = n % 16;
		n = n / 16;
	}
	ft_putchar(n > 9 && *(*tm) == 'X' ?
	str[n] - 32 : str[n], 1);
	while (i-- > 0)
		ft_putchar(remainder[i] > 9 && *(*tm) == 'X' ?
		str[remainder[i]] - 32 : str[remainder[i]], 1);
}
