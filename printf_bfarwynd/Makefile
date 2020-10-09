# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfarwynd <bfarwynd@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 12:54:20 by bfarwynd          #+#    #+#              #
#    Updated: 2020/07/24 14:11:14 by bfarwynd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = h/ft_printf.h

OBJ =  s/ft_atoi.o\
s/ft_pf_f.o\
s/ft_pf_f_sc.o\
s/ft_pf_f_udi.o\
s/ft_pf_f_xp.o\
s/ft_pf_print_final.o\
s/ft_pf_print_m.o\
s/ft_pf_print_s.o\
s/ft_pf_print_udixpc.o\
s/ft_pf_utils.o\
s/ft_printf.o

SRC = $(OBJ:.o=.c)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):$(OBJ) $(HEADER)
	ar rc $(NAME) $?
	ranlib $(NAME)
%.o:%.c
	gcc $(FLAGS) -I ../$(HEADER) -c $< -o $@
clean:
	/bin/rm -f $(OBJ)
fclean:clean
	/bin/rm -f $(NAME)
re:fclean all