/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:04:42 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/05 19:04:42 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_sign(char *str)
{
	int	sign;
	int	i;

	sign = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			sign -= 1;
		i++;
	}
	if (sign % 2 != 0)
		return (-1);
	else
		return (1);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	i;
	int	stop;

	stop = 0;
	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9' && str[i])
		{
			nb = nb * 10 + (str[i] - '0');
			i++;
			stop = 1;
		}
		if (stop == 1)
			return (nb * ft_sign(str));
		i++;
	}
	return (0);
}


int main(void)
{
    printf("%d \n",ft_atoi("  ---++sads1234sad123ads"));
    printf("%d \n",ft_atoi("  ---98789asd"));
    printf("%d \n",ft_atoi(""));
    printf("%d \n",ft_atoi("   123+123456asdsd2128"));
    
    printf("\n%d \n",atoi("-1234sad123ads"));
    printf("%d \n",atoi("-98789asd"));
    printf("%d \n",atoi(""));
    printf("%d \n",atoi("123+123456asdsd2128"));
}
