/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_final.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:03:55 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/20 20:18:45 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

void	ft_pf_print(int len, void *var, const char **tm)
{
	if (*(*tm) == 'd' || *(*tm) == 'i')
		ft_putnbr(*((int *)var));
	else if (*(*tm) == 'u')
		ft_putnbr(*((unsigned int*)var));
	else if (*(*tm) == 'x' || *(*tm) == 'X' || *(*tm) == 'p')
		ft_itoa_xp(*((unsigned long int *)var), tm);
	else if (*(*tm) == 's')
		ft_putstr(((char *)var), len);
	else
		ft_putchar(*((int *)var), 1);
}
