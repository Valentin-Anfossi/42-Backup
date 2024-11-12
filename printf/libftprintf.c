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
#include <string.h>

static char	*ft_form_sorting(char *form,va_list ptr,int i)
{

}

static int ft_form_count(char *form)
{
	int	i;
	int count;
	i = 0;

	while(form[i])
	{
		if (form[i] == '%')
		{
			count ++;
			i += 2;
		}
		else
			i++;
	}
	return(count);
}

int ft_printf(const char *form, ...)
{
	int	i;
	int	formcount;
	char	flag;
	char * n;
	va_list ptr;
	i = 0;
	
	va_start(ptr,form);
	formcount = ft_form_count((char *)form);

	while(i < formcount)
	{
		printf("%d\n",va_arg(ptr,int));
		i++;
	}
	va_end(ptr);
}

int main (void)
{
	ft_printf("%d %d", 10,256,99);
	return (1);
}