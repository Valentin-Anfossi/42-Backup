/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:57:36 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/14 05:00:55 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

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
