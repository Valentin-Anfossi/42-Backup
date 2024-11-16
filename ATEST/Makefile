# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 05:21:17 by vanfossi          #+#    #+#              #
#    Updated: 2024/11/15 23:08:18 by vanfossi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 			libftprintf.a

SOURCES	= 			ft_printf.c ft_printf_prints.c ft_printf_prints2.c ft_printf_utils.c \
					ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c

OFILES	= $(SOURCES:.c=.o)

CC	= gcc

FLAGS	= -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
