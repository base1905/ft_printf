/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:58:39 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/20 21:58:41 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

void	ft_pf_print_m(int w, void *var, const char **tm)
{
	if (s_fl.a == 0 && s_fl.d == 1)
		w += 1;
	if (s_fl.d == 1 && s_fl.a == 0)
		while (w-- > 0)
			ft_putchar(' ', 1);
	if (s_fl.d == 1 && s_fl.a == 0)
		return ;
	ft_pf_print(0, var, tm);
	while (w-- > 0)
		ft_putchar(' ', 1);
}
