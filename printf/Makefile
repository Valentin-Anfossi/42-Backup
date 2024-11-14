# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 05:21:17 by vanfossi          #+#    #+#              #
#    Updated: 2024/11/14 05:22:47 by vanfossi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SOURCES	= libftprintf.c

LIBFT = libft.h libft.a

OFILES	= libftprint.o

CC	= gcc

FLAGS	= -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

#Compile .o < .c seulement si changes
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
