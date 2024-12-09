# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 02:27:42 by vanfossi          #+#    #+#              #
#    Updated: 2024/12/08 22:18:35 by vanfossi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

BONUSNM = checker

LIBFT 	= ./libft/libft.a

MAIN 	= push_swap.c

SOURCES	= args_utils.c array_utils.c debug_utils.c misc_utils.c print_error.c \
		  stack_functions.c stack_functions2.c stack_functions3.c \
		  stack_sorting.c stack_sorting2.c stack_sorting3.c stack_utils.c \
		  stack_utils2.c

BONUSSRCS = ./checker_srcs/checker_main.c

MOFILE = $(MAIN:.c=.o)

OFILES	= $(SOURCES:.c=.o)

BONUSOFILES = $(BONUSSRCS:.c=.o)

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MOFILE) $(OFILES)
	 $(CC) $(FLAGS) -o $(NAME) $(MOFILE) $(OFILES) $(LIBFT) 

bonus : $(OFILES) $(BONUSOFILES)
	$(CC) $(FLAGS) -o $(BONUSNM) $(OFILES) $(BONUSOFILES) $(LIBFT)

#Compile .o < .c seulement si changes
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

./checker_srcs/%.o: ./checker_srcs/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	rm -f $(MOFILE)
	rm -f $(BONUSOFILES)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUSNM)

re: fclean all