# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arannara <base1905@yandex.ru>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 12:52:37 by arannara          #+#    #+#              #
#    Updated: 2020/07/11 12:43:02 by arannara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a

SRC = 	ft_printf.c \
		ft_printf_utils.c \
		ft_printspec_c.c \
		ft_printspec_s.c \
		ft_printspec_di.c \
		ft_printspec_u.c \
		ft_printspec_x.c \
		ft_printspec_p.c 
OBJ = $(SRC:.c=.o)
HEADER = libftprintf.h
LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)
	@echo "\n"
	@echo "Objects created"
	@echo "\n"

%.o: %.c $(HEADER) $(LIBFT)
	gcc -Wall -Wextra -Werror -c $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)
	cp $(LIBFT) ./$(NAME)

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all
