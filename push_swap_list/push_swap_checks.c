/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:57:28 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/25 13:09:52 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_stack_digits(int argc, char** argv)
{
	int i;
	int j;
	
	j = 0;
	i = 1;
	while (argv[i])
	{
		while(argv[i][j])
		{
			if(argv[i][j] == '-' && j == 0)
				j++;
			if(!ft_isdigit(argv[i][j]))
				return 0;
			j ++;
		}
		j = 0;
		i ++;
	}
	return (1);
}
int check_stack_duplicates(int *a, int size)
{
	int j;
    int i;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while(i < size)
	{
    	while (j < size) {
        	if (a[j] == a[i]) 
				count ++;
			if(count > 1)
			 return(0);
        	j++;
    	}
		count = 0;
		j = 0;
		i++;
	}
    return 1;
}