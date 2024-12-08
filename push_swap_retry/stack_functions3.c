/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:04:05 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/08 14:35:46 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
int	ra(t_stack **a, int print)
{
	if (*a != NULL)
	{
		*a = (*a)->next;
		if (print)
			ft_printf("ra\n");
		return (1);
	}
	return (0);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
int	rb(t_stack **b, int print)
{
	if (*b != NULL)
	{
		*b = (*b)->next;
		if (print)
			ft_printf("rb\n");
		return (1);
	}
	return (0);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
int	rra(t_stack **a, int print)
{
	if (*a != NULL)
	{
		*a = (*a)->prev;
		if (print)
			ft_printf("rra\n");
		return (1);
	}
	return (0);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
int	rrb(t_stack **b, int print)
{
	ft_printf("rrb\n");
	if (print)
		*b = (*b)->prev;
	return (1);
}

int	rrr(t_stack **a, t_stack **b, int print)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
	if (print)
		ft_printf("rrr\n");
	return (1);
}
