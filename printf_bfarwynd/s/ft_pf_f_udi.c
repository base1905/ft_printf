/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_f_udi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:25 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/20 21:46:49 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

void						ft_pf_f_udi(const char **tm, va_list arg)
{
	long long int			udi;
	int						len;

	udi = 0;
	if (*(*tm) == 'd' || *(*tm) == 'i')
		udi = va_arg(arg, int);
	else if (*(*tm) == 'u')
		udi = va_arg(arg, unsigned int);
	len = ft_pf_f_udi_len(udi);
	if (s_fl.z && s_fl.a < 0)
		s_fl.a = udi < 1 ? s_fl.w - 1 : s_fl.w;
	if (s_fl.w != 0 && s_fl.w != s_fl.a)
		ft_pf_print_w(&udi, len, tm);
	else if (s_fl.a != 0 && s_fl.a > len)
		ft_pf_print_a(len, 0, &udi, tm);
	else if (s_fl.d == 1 && s_fl.a == 0)
		return ;
	else
		ft_putnbr(udi);
}

long long int				ft_pf_f_udi_len(long long int udi)
{
	unsigned long long int	n;
	int						i;

	i = 0;
	n = udi;
	if (udi < 0)
		udi *= -1;
	n = udi;
	if (udi == 0)
		i++;
	while (n > 0 && i++ >= 0)
		n = n / 10;
	return (i);
}
