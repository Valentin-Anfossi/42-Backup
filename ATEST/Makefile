# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 05:21:17 by vanfossi          #+#    #+#              #
#    Updated: 2024/11/15 21:22:56 by vanfossi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 			libftprintf.a

SOURCES	= 			ft_printf.c ft_printf_prints.c ft_printf_prints2.c ft_printf_utils.c

LIBFT = 			./libft/libft.a

LIBFTPATH = 		./libft/

OFILES	= $(SOURCES:.c=.o)

CC	= gcc

FLAGS	= -Wall -Wextra -Werror -I.

all: $(NAME)

$(LIBFT): 
	make -C$(LIBFTPATH)

$(NAME): $(OFILES) $(LIBFT)
	ar rcs $(NAME) $(OFILES) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	make clean -C $(LIBFTPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
