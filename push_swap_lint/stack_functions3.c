/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:04:05 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 04:29:34 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
int ra(s_stack **a)
{
	if(*a != NULL)
	{
		*a = (*a)->next;
		printf("ra\n");
		return (1);
	}

	return (0);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
int rb(s_stack **b)
{
    *b = (*b)->next;
	printf("rb\n");
	return (1);
}
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
int rra(s_stack **a)
{
    *a = (*a)->prev;
	printf("rra\n");
	return (1);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
int rrb(s_stack **b)
{
	printf("rrb\n");
	*b = (*b)->prev;
	return (1);
}

int rrr(s_stack **a, s_stack **b)
{
    *a = (*a)->prev;
	*b = (*b)->prev;
	printf("rrr\n");
	return(1);
}