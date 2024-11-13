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

}

static int ft_print_void(va_list ptr)
{
	void *a;
	a = va_arg(ptr,void*);
	ft_putnbr_fd(&a,1);
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
		{}
		if(form[i] == '%' && form[i+1] == 'u')
		{}
		if(form[i] == '%' && form[i+1] == 'x')
		{}
		if(form[i] == '%' && form[i+1] == 'X')
		{}
		if(form[i] == '%' && form[i+1] == '%')
		{
			
		}
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
	ft_printf("int:%d int:%d string:%s void:%p  oh", 10,256,"asdksladkas",vptr);
	printf("\n");
	return (1);
}