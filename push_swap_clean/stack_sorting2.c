/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:30:30 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 23:54:42 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_do_moves(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	cost_a;
	int	cost_b;

	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	while (cost_a > 0 && cost_b > 0 && (rr(a, b), cost_a--, cost_b--))
		;
	while (cost_a < 0 && cost_b < 0 && (rrr(a, b), cost_a++, cost_b++))
		;
	while (cost_a > 0 && (ra(a), cost_a--))
		;
	while (cost_a < 0 && (rra(a), cost_a++))
		;
	while (cost_b > 0 && (rb(b), cost_b--))
		;
	while (cost_b < 0 && (rrb(b), cost_b++))
		;
	return (pa(a, b));
}

//OPTIMIZE BY RECALC COST IF RR OR RRR ARE TO BE USED
t_stack	*sort_cheapest_best_match(t_stack **b)
{
	int			cost;
	t_stack		*cheapest;
	t_stack		*temp_b;
	long int	current_cost;

	temp_b = *b;
	cost = INT_MAX;
	temp_b = *b;
	cheapest = temp_b;
	while (temp_b)
	{
		current_cost = ft_abs(temp_b->cost_a) + ft_abs(temp_b->cost_b);
		if (current_cost < cost)
		{
			cost = current_cost;
			cheapest = temp_b;
		}
		temp_b = temp_b->next;
		if (temp_b == *b)
			break ;
	}
	return (cheapest);
}

//CALCULATE COST TO TOP (IN BOTH DIRECTIONS)
int	sort_cost_to_top(t_stack **stack, t_stack *a)
{
	int		cost;
	t_stack	*temp_a;

	temp_a = a;
	cost = 0;
	while (temp_a != *stack)
	{
		cost ++;
		temp_a = temp_a->prev;
	}
	if (cost > stack_size(stack) / 2)
	{
		cost = cost - stack_size(stack);
	}
	return (cost);
}

//PUT THE MIN ON TOP AT THE END
void	sort_final_sort(t_stack **a)
{
	if (sort_cost_to_top(a, stack_find_min(a)) > 0)
	{
		while (*a != stack_find_min(a))
		{
			ra(a);
		}
	}
	else
	{
		while (*a != stack_find_min(a))
		{
			rra(a);
		}
	}
}
