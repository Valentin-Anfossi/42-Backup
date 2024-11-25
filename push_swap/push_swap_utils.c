/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:37:42 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/25 11:37:52 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(int *a, int *b, int argc)
{
	int i;
	i = 0;
	while(i < argc-1)
	{
		printf("%d ",a[i]);
		i ++;
	}
	i = 0;
	printf("\n");
	while(i < argc-1)
	{
		printf("%d ",b[i]);
		i ++;
	}
	printf("\n");
}