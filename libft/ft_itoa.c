/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:33:10 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/08 13:34:01 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_int_size(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count ++;
		n = -n;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa_mallocu(int n)
{
	char	*string;

	string = malloc((n + 1));
	if (!string)
		return (0);
	string[0] = '0';
	return (string);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*string;
	long	nbr;
	int		i;

	length = ft_int_size(n);
	nbr = n;
	string = ft_itoa_mallocu(length);
	if (nbr < 0)
		nbr *= -1;
	i = length - 1;
	while (nbr != 0)
	{
		string[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i --;
	}
	if (n < 0)
		string[0] = '-';
	string[length] = 0;
	return (string);
}

// int main(void)
// {
// 	printf("%s",ft_itoa(-98744));
// }