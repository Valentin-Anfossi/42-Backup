/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:29:25 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/15 23:05:13 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	c;

	if (n != -2147483648)
	{
		if (n < 0)
		{
			c = '-';
			write(fd, &c, 1);
			ft_putnbr_fd (n * -1, fd);
		}
		else if (n > 9)
		{
			ft_putnbr_fd (n / 10, fd);
			ft_putnbr_fd (n % 10, fd);
		}
		else
		{
			c = n + 48;
			write(fd, &c, 1);
		}
	}
	else
	{
		write(fd, "-2147483648", 11);
	}
}
