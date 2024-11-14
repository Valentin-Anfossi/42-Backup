/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:57:36 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/14 18:59:02 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "./libft/libft.h"

#include <stdio.h>

int		ft_printf(const char *form, ...);

char	*ft_itohex(unsigned long nb);

int		ft_print_hexlow(va_list ptr);

int		ft_print_hexup(va_list ptr);

int		ft_print_char(va_list ptr);

int		ft_print_void(va_list ptr);

int		ft_print_dec(va_list ptr);

int		ft_print_str(va_list ptr);

int		ft_print_int(va_list ptr);

int		ft_print_usign(va_list ptr);

int		ft_print_perc(void);

int		ft_putunbr(unsigned int n);

int		ft_get_uintlen(unsigned int nb);

int		ft_get_intlen(int nb);
