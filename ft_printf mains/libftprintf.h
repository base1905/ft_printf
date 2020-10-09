/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:16:08 by arannara          #+#    #+#             */
/*   Updated: 2020/07/11 19:32:05 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int			minus;
	int			dot;
	int			zero;
	int			width;
	int			precision;
	char		specifier;
}				t_flags;

int				ft_printf(const char *s, ...);

int				whitespace(int len);
int				zero(int len);
int				ft_getwidth(const char **s, va_list ap, t_flags *flag);
int				ft_getprecision(const char **s, va_list ap, t_flags *flag);

int				ft_printspec_c(char s, t_flags flag);
int				ft_printspec_s(char *s, t_flags flag);
int				ft_printspec_di(int n, t_flags flag);
int				ft_printspec_u(unsigned int n, t_flags flag);
int				ft_printspec_x(unsigned int n, t_flags flag);
int				ft_printspec_p(unsigned long int number, t_flags flag);

#endif
