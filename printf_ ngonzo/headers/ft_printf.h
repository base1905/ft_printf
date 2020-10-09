/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:17:37 by ngonzo            #+#    #+#             */
/*   Updated: 2020/07/14 09:30:05 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
**# include <stdlib.h> malloc, free
**# include <unistd.h> write
**# include <stdarg.h> va_start, va_arg, va_copy, va_end
*/

int		ft_printf(const char *line, ...);
int		function(const char *line, va_list ap);
char	*check_flags(const char **line);
int		check_width(const char **line, va_list ap);
int		check_precision(const char **line, va_list ap);
void	ft_free(char *pointer);
int		ft_isdigit(int c);
int		ft_putchar(char c);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);
int		ft_nbrlen(int nbr);
int		ft_ns16len(long int ns10);
int		ft_nputchar(char c, int number);
int		ft_putstr(char *str);
int		ft_putstrl(char *str, int number);
int		ft_putnbr(long long int num);
int		ft_putns16(long int ns10, char c);
int		check_id(const char **line, va_list ap, int *checks, char *flags);
int		prefix_fill_id(int *arg, int *checks, char *flags, int len);
int		fill_id_negative(int **argument);
int		fill_id_positive(int **argument, char *flags);
int		fill_id_len_pre_width(int **arg, int *checks, char *flags, int len);
int		fill_id_width_pre_len_one(int **arg, int *checks, char *flags, int len);
int		fill_id_width_pre_len_two(int **arg, int *checks, char *flags, int len);
int		fill_id_pre_width_len(int **arg, int *checks, char *flags, int len);
int		fill_id_width_len_pre_one(int **arg, int *checks, char *flags, int len);
int		fill_id_width_len_pre_two(int **arg, int *checks, char *flags, int len);
int		check_x(const char **line, va_list ap, int *checks, char *flags);
int		prefix_fillers_x(const char line, unsigned int arg,
								int *checks, char *flags);
int		fill_x_len_pre_width(const char line, unsigned int arg, int *checks);
int		fill_x_flago_prenegative_one(int *checks, char *flags, int len, int fl);
int		fill_x_flago_prenegative_two(int *checks, char *flags, int len);
int		fill_x_width_pre_len(const char line, unsigned int arg,
									int *checks, char *flags);
int		fill_x_pre_width_len(const char line, unsigned int arg,
									int *checks, char *flags);
int		fill_x_width_len_pre(const char line, unsigned int arg,
									int *checks, char *flags);
int		check_u(const char **line, va_list ap, int *checks, char *flags);
int		prefix_fillers_u(unsigned int arg, int *checks, char *flags);
int		fill_u_width_pre_len(unsigned int arg, int *checks,
									char *flags, int len);
int		fill_u_pre_width_len(unsigned int argument, int *checks,
										char *flags, int len);
int		fill_u_width_len_pre(unsigned int arg, int *checks,
									char *flags, int len);
int		fill_u_len_pre_width(unsigned int argument, int *checks);
int		check_s(const char **line, va_list ap, int *checks, char *flags);
int		prefix_fillers_s(char *argument, int *checks, char *flags);
int		check_type(const char **line, va_list ap, int *checks, char *flags);
int		check_p(const char **line, va_list ap, int *checks, char *flags);
int		check_c(const char **line, va_list ap, int *checks, char *flags);
int		checksymbol(const char **line);

#endif
