/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:59:42 by bfarwynd          #+#    #+#             */
/*   Updated: 2020/07/24 14:11:10 by bfarwynd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

struct				s_struct
{
	int w;
	int w_s;
	int a;
	int a_s;
	int d;
	int z;
	int m;
}					s_fl;

int					ft_printf(const char *format, ...);
int					ft_putchar(const char c, int end);
void				ft_pf_f(const char **tm, va_list arg);
void				ft_pf_f_sc(const char **tm, va_list arg);
void				ft_pf_f_sc_s(char *str, int len, const char **tm);
void				ft_pf_f_sc_c(char c, const char **tm);
void				ft_pf_print_w_s(void *var, int len,
							const char **tm);
void				ft_pf_print_a_s(void *var, int len,
							const char **tm);
void				ft_pf_f_udi(const char **tm, va_list arg);
long long int		ft_pf_f_udi_len(long long int udi);
unsigned long int	ft_nbr_len_base(unsigned long int nb, int base);
void				ft_pf_f_xp(const char **tm, va_list arg);
void				ft_pf_f_xp_p(unsigned long p, int len,
							const char **tm);
void				ft_pf_f_f(const char **tm, va_list arg);
void				ft_pf_f_f_star(const char **tm, va_list arg);
void				ft_pf_print(int len, void *var, const char **tm);
void				ft_pf_print_w(void *var, int len, const char **tm);
void				ft_pf_print_a(int len, int w, void *var,
							const char **tm);
void				ft_pf_print_a_z(int len, void *var,
							const char **tm);
void				ft_pf_print_m(int w, void *var, const char **tm);
void				ft_itoa_xp(unsigned long int n, const char **tm);
void				ft_putnbr(long long int n);
void				ft_putstr(char *s, size_t len);
size_t				ft_strlen(const char *str);
int					is_atoi_sep(char a);
int					ft_atoi(const char **tm);

#endif
