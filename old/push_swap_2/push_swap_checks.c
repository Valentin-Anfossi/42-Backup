/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:18:00 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/28 09:27:37 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// CHECK IF CHAR THEN CALL CHECK DUPLICATES
// TODO REDO CHECK + & -, doesnt work rn (REDID, CHECK)
int stack_check(int argc, char **argv)
{
	int i;
	int j;
	long int n;
	int *a;
	
	i = 1;
	j = 0;
	a = malloc(sizeof(int) * argc - 1);
	while(i < argc)
	{
		while(argv[i][j])
		{
			if(!ft_isdigit(argv[i][j]))
				if(j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
					j++;
				else
					return(0);
			else
				j++;
		}
		j = 0;
		n = ft_atoi_pushswap(argv[i]);
		if(n > INT_MAX || n < INT_MIN)
			return(0);
		a[i-1] = n;
		i++;
	}
	return(stack_check_duplicates(a));
}

int stack_check_duplicates(int *a)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while(a[i])
	{
		while(a[j])
		{
			if(a[j] == a[i])
				count++;
			if(count > 1)
				return(0);
			j++;
		}
		j = 0;
		count = 0;
		i++;
	}
	return (1);	
}
long int	ft_atoi_pushswap(const char *str)
{
	long int	nb;
	int	i;
	long int	n;

	n = 1;
	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		n *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * n);
}
