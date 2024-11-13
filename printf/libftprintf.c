/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:38:07 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/12 00:38:07 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static int ft_print_char(va_list ptr)
{
	char c;
	c = va_arg(ptr, int);
	write(1,&c,1);
	return (2);
}

static int ft_print_void(va_list ptr)
{
	// Convertir en hexa
	void *a;
	a = va_arg(ptr,void*);
	ft_putnbr_fd((int)&a,1);
	return(2);
}

static int ft_print_dec(va_list ptr)
{
	ft_putnbr_fd(va_arg(ptr,signed int),1);
	return (2);
}

static int ft_print_str(va_list ptr)
{
	ft_putstr_fd(va_arg(ptr,char*),1);
	return (2);
}

static int ft_print_int(va_list ptr)
{
	ft_putnbr_fd(va_arg(ptr,int),1);
	return (2);
}

static int ft_print_usign(va_list ptr)
{
	ft_putnbr_fd(va_arg(ptr, unsigned int),1);
	return (2);
}

static int ft_print_hexlow(va_list ptr)
{
	return (2);
}

static int  ft_print_hexup(va_list ptr)
{
	return (2);
}

static int ft_print_perc(void)
{
	char c;
	c = '%';
	write(1, &c, 1);
	return (2);
}

int ft_printf(const char *form, ...)
{
	va_list ptr;

	va_start(ptr,form);
	int i = 0;

	while (i < ft_strlen(form))
	{
		if(form[i] == '%' && form[i+1] == 'c')
			i += ft_print_char(ptr);
		if(form[i] == '%' && form[i+1] == 's')
			i += ft_print_str(ptr);
		if(form[i] == '%' && form[i+1] == 'p')
			i += ft_print_void(ptr);
		if(form[i] == '%' && form[i+1] == 'd')
			i += ft_print_dec(ptr);
		if(form[i] == '%' && form[i+1] == 'i')
			i += ft_print_int(ptr);
		if(form[i] == '%' && form[i+1] == 'u')
			i += ft_print_usign(ptr);
		if(form[i] == '%' && form[i+1] == 'x')
			i += ft_print_hexlow(ptr);
		if(form[i] == '%' && form[i+1] == 'X')
			i += ft_print_hexup(ptr);
		if(form[i] == '%' && form[i+1] == '%')
			i += ft_print_perc();
		else 
			ft_putchar_fd(form[i],1);
		i++;
	}
	va_end(ptr);
	return (1);
}

int main (void)
{
	void *vptr;
	ft_printf("char:%c string:%s void:%p dec:%d int:%i udec:%u hexl:%x hexu:%X per:%%", 'B', "ceci est une string.", vptr, -420, 420, 420, 16,16);
	printf("\n");
	printf("char:%c string:%s void:%p dec:%d int:%i udec:%u hexl:%x hexu:%X per:%%", 'B', "ceci est une string.", vptr, -420, 420, 420, 16,16);
	return (1);
}