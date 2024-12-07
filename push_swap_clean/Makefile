# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 02:27:42 by vanfossi          #+#    #+#              #
#    Updated: 2024/12/07 02:43:49 by vanfossi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

BONUSNM = checker

LIBFT 	= ./libft/libft.a

SOURCES	= args_utils.c array_utils.c debug_utils.c misc_utils.c print_error.c \
		  push_swap.c stack_functions.c stack_functions2.c stack_functions3.c \
		  stack_sorting.c stack_sorting2.c stack_sorting3.c stack_utils.c \
		  stack_utils2.c

BONUSSRCS = 

OFILES	= $(SOURCES:.c=.o)

BONUSOFILES = $(BONUSSRCS:.c=.o)

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	 $(CC) $(FLAGS) -o $(NAME) $(OFILES) $(LIBFT) 

bonus : $(BONUSOFILES)
	$(CC) $(FLAGS) -o $(BONUSNM) $(BONUSOFILES) $(LIBFT)

#Compile .o < .c seulement si changes
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	rm -f $(BONUSOFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all