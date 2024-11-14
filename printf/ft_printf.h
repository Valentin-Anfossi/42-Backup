/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:57:36 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/14 03:46:06 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "ft_putchar_fd.c"
#include "ft_putnbr_fd.c"
#include "ft_putstr_fd.c"
#include "ft_strlen.c"
#include "ft_strtrim.c"
#include "ft_strdup.c"

// typedef struct s_printelement {
// 	char* type;
// 	int	width;
// 	int prec;
// 	int sign;
// 	void *value;
// 	struct t_elem *next;
// } t_elem;

int ft_printf(const char *form, ...);

static char * ft_itohex(unsigned long nb);

static int ft_print_hexlow(va_list ptr);

static int ft_print_hexup(va_list ptr);

static int ft_print_char(va_list ptr);

static int ft_print_void(va_list ptr);

static int ft_print_dec(va_list ptr);

static int ft_print_str(va_list ptr);

static int ft_print_int(va_list ptr);

static int ft_print_usign(va_list ptr);

static int ft_print_perc(void);

void	ft_putchar_fd(char c, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putstr_fd(char *s, int fd);

char	*ft_strtrim(char const *s1, char const *set);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s);




