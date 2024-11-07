# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 04:36:42 by vanfossi          #+#    #+#              #
#    Updated: 2024/11/07 04:36:42 by vanfossi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr.c \
			ft_putstr_fd.c ft_split_backup.c ft_split_copy.c ft_split.c ft_strchr.c \
			ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OFILES = $(SOURCES:.c=.o)


CC = GCC

FLAGS = -Wall -Wextra -Werror

all : $(CC) $(FLAGS) -c $(SOURCES) -I./
	ar -rc $(NAME) $(OFILES)
