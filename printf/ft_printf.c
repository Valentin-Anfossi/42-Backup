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

#include "ft_printf.h"

static int	ft_get_intlen(int nb)
{
	int	i;

	i = !nb;
	if (nb < 0)
	{
		nb *= -1;
		i ++;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static char	*ft_itohex(unsigned long nb)
{
	char			*hex_base;
	char			*result;
	int				len;
	unsigned long	d;
	int				i;

	hex_base = "0123456789abcdef";
	d = 1;
	len = 1;
	i = 0;
	while ((nb / d) >= 16)
	{
		len ++;
		d *= 16;
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = 0;
	while (d > 0)
	{
		result[i++] = hex_base[(nb / d) % 16];
		d /= 16;
	}
	return (result);
}

static int	ft_print_hexlow(va_list ptr)
{
	char			*hex_base;
	unsigned long	d;
	int				nb;
	int				len;

	hex_base = "0123456789abcdef";
	nb = va_arg(ptr, unsigned long);
	d = 1;
	len = 0;
	while ((nb / d) >= 16)
		d *= 16;
	while (d > 0)
	{
		ft_putchar_fd(hex_base[(nb / d) % 16], 1);
		d /= 16;
		len ++;
	}
	return (len);
}

static int	ft_print_hexup(va_list ptr)
{
	char			*hex_base;
	unsigned long	d;
	int				nb;
	int				len;

	hex_base = "0123456789ABCDEF";
	nb = va_arg (ptr, unsigned long);
	d = 1;
	len = 0;
	while ((nb / d) >= 16)
		d *= 16;
	while (d > 0)
	{
		ft_putchar_fd(hex_base[(nb / d) % 16], 1);
		d /= 16;
		len ++;
	}
	return (len);
}

static int	ft_print_char(va_list ptr)
{
	char	c;

	c = va_arg (ptr, int);
	write(1, &c, 1);
	return (1);
}

static int	ft_print_void(va_list ptr)
{
	void			*a;
	unsigned long	adr;
	char			*result;
	int				len;

	a = va_arg (ptr, void *);
	adr = (unsigned long)a;
	result = ft_itohex(adr);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(result, 1);
	len = ft_strlen(result) + 2;
	free(result);
	return (len);
}

static int	ft_print_dec(va_list ptr)
{
	signed int	nb;
	int			length;

	nb = va_arg(ptr, signed int);
	length = (ft_get_intlen(nb));
	ft_putnbr_fd(nb, 1);
	return (length);
}

static int	ft_print_str(va_list ptr)
{
	char	*str;

	str = va_arg (ptr, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	ft_print_int(va_list ptr)
{
	int		i;

	i = va_arg (ptr, int);
	ft_putnbr_fd(i, 1);
	return (ft_get_intlen(i));
}

static int	ft_print_usign(va_list ptr)
{
	int	i;

	i = va_arg(ptr, unsigned int);
	ft_putnbr_fd(i, 1);
	return (ft_get_intlen(i));
}

static int	ft_print_perc(void)
{
	char	c;

	c = '%';
	write(1, &c, 1);
	return (1);
}

int	ft_printf_types(char *form, va_list ptr, int i)
{
	int	count;

	count = 0;
	if (form[i + 1] == 'c')
		count += ft_print_char(ptr);
	else if (form[i + 1] == 's')
		count += ft_print_str(ptr);
	else if (form[i + 1] == 'p')
		count += ft_print_void(ptr);
	else if (form[i + 1] == 'd')
		count += ft_print_dec(ptr);
	else if (form[i + 1] == 'i')
		count += ft_print_int(ptr);
	else if (form[i + 1] == 'u')
		count += ft_print_usign(ptr);
	else if (form[i + 1] == 'x')
		count += ft_print_hexlow(ptr);
	else if (form[i + 1] == 'X')
		count += ft_print_hexup(ptr);
	else if (form[i + 1] == '%' || form[i + 1] == ' ')
		count += ft_print_perc();
	return (count);
}

int	ft_printf_parsing(char *form, va_list ptr)
{
	int	i;
	int	count;

	i = 0;
	while (i < (int)ft_strlen(form))
	{
		if (form[i] == '%')
		{
			count += ft_printf_types(form, ptr, i);
			i += 2;
		}
		else
		{
			ft_putchar_fd(form[i], 1);
			count ++;
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *form, ...)
{
	va_list	ptr;
	int		count;

	count = 0;
	va_start (ptr, form);
	count += ft_printf_parsing((char *)form, ptr);
	va_end (ptr);
	return (count);
}

// int main	(void)
// {
// 	void *vptr;
// 	ft_printf("%d",ft_printf("char:%c string:%s void:%p dec:%d int:%i udec:%u hexl:%x hexu:%X per:%% \n", 'B', "ceci est une string.", vptr, -420, 420, 420, 255,1023));
// 	printf("\n");

// 	printf("%d",printf("char:%c string:%s void:%p dec:%d int:%i udec:%u hexl:%x hexu:%X per:%% \n", 'B', "ceci est une string.", vptr, -420, 420, 420, 255,1023));
// 	printf("\n");

// 	// printf("%d",ft_printf("string:%s hexu:%X void:%p \n", "ceci est une string.",420, vptr));
// 	// printf("\n");

// 	// printf("%d",printf("string:%s hexu:%X void:%p \n", "ceci est une string.",420, vptr));
// 	// printf("\n");

// 	// printf("%d",ft_printf(" "));
// 	// printf("\n");

// 	// printf("%d",printf(" "));
// 	// printf("\n");
	
// 	// ft_printf("  %c  ",'0');
// 	// printf("\n");
	
// 	// printf("  %c  ",'0');
// 	// printf("\n");

// 	// printf("char:%c string:%s void:%p dec:%d int:%i udec:%u hexl:%x hexu:%X per:%%", 'B', "ceci est une string.", vptr, -420, 420, 420, 255,1023);
// 	// printf("\n");
// 	return (1);
// }