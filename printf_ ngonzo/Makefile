# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngonzo <ngonzo@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 08:32:17 by ngonzo            #+#    #+#              #
#    Updated: 2020/07/14 08:50:57 by ngonzo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
WWW = -Wall -Wextra -Werror
GCC = gcc -c
SRC = 	sources/ft_printf.c\
	sources/ft_len_function.c\
	sources/ft_put_function.c\
	sources/ft_fisp_function.c\
	sources/ft_id_one.c\
	sources/ft_id_two.c\
	sources/ft_x_one.c\
	sources/ft_x_two.c\
	sources/ft_u_one.c\
	sources/ft_u_two.c\
	sources/ft_s.c\
	sources/ft_check_type_p_c.c
HDR =	headers/ft_printf.h
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HDR)
	$(GCC) $(WWW) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: fclean all
