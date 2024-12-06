/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:39:00 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/26 15:41:19 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_add(elem **stack, int val)
{
	elem *newel = malloc(sizeof (newel));
	newel->val = val;
	newel->prec = *stack;
	*stack = newel;
}

int stack_length(elem *el)
{
	int i;
	i = 0;

	while(el)
	{
		i ++;
		el = el->prec;
	}

	return (i);
}