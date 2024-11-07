/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:29:25 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/07 04:29:25 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void ft_putnbr_fd(int n, int fd)
{
	int	c;

	if (n != -2147483648)
	{
		if (n < 0)
		{
			c = '-';
			write(fd, &c, 1);
			ft_putnbr(n * -1);
		}
		else if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
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