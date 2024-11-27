/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:18:00 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/27 20:23:33 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_check(int argc, char **argv)
{
	int i;
	int j;
	long int n;
	
	i = 1;
	j = 0;
	while(i < argc)
	{
		while(argv[i][j])
		{
			if(ft_isdigit(argv[i][j]))
				j++;
			else
				return(0);
		}
		j = 0;
		n = ft_atoi(argv[i]);
		if(n > INT_MAX || n < INT_MIN)
			return(0);
	}
	return(1);
}
