# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 04:36:42 by vanfossi          #+#    #+#              #
#    Updated: 2024/11/13 20:29:36 by vanfossi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SOURCES	= libftprintf.c

OFILES	= $(SOURCES:.c=.o)

CC	= gcc

FLAGS	= -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

bonus : $(OFILES) $(BONUSOFILES)
	ar rcs $(NAME) $(OFILES) $(BONUSOFILES)

#Compile .o < .c seulement si changes
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	rm -f $(BONUSOFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
