/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:30:30 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 14:48:03 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int sort_do_moves(s_stack **a, s_stack **b, s_stack *cheapest)
// {
// 	int cost_a;
// 	int cost_b;

// 	cost_a = cheapest->cost_a;
// 	cost_b = cheapest->cost_b;
	
// 	while(cost_a != 0 || cost_b != 0)
// 	{
// 		if(cost_a > 0 && cost_b > 0)
// 		{
// 			rr(a,b);
// 			cost_a --;
// 			cost_b --;
// 		}
// 		if(cost_a < 0 && cost_b < 0 )
// 		{
// 			rrr(a,b);
// 			cost_a ++;
// 			cost_b ++;
// 		}
// 		if(cost_a > 0)
// 		{	
// 			ra(a);
// 			cost_a--;
// 		}
// 		if(cost_a < 0)
// 		{
// 			rra(a);
// 			cost_a ++;
// 		}	
// 		if(cost_b > 0)
// 		{
// 			rb(b);
// 			cost_b--;
// 		}
// 		if(cost_b < 0)
// 		{
// 			rrb(b);
// 			cost_b ++;
// 		}
// 	}
// 	pa(a,b);
// 	return(1);
// }

int	sort_do_moves(s_stack **a, s_stack **b, s_stack *cheapest)
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
s_stack *sort_cheapest_best_match(s_stack **b)
{
	int cost;
	s_stack *cheapest;
	s_stack *temp_b;
	int current_cost;
	
	temp_b = *b;
	cost = INT_MAX;
	temp_b = *b;
	cheapest = temp_b;
	while(temp_b)
	{
		current_cost = ft_abs(temp_b->cost_a) + ft_abs(temp_b->cost_b);
		if (current_cost < cost)
		{
			cost =	current_cost;
			cheapest = temp_b;
		}
		temp_b = temp_b->next;
		if (temp_b == *b)
			break;	
	}
	return (cheapest);
}

//CALCULATE COST TO TOP (IN BOTH DIRECTIONS)
int sort_cost_to_top(s_stack **stack, s_stack *a)
{
	int cost;
	s_stack *temp_a;

	temp_a = a;
	cost = 0;
	while(temp_a != *stack)
	{
		cost ++;
		temp_a = temp_a->prev;
	}
	if (cost > stack_size(stack)/2)
	{
		cost = cost - stack_size(stack);
	}
	return(cost);
}

float sort_get_mean(s_stack **a)
{
	int *ar;
	int i;
	float mean;

	i = 0;
	mean = 0;
	ar = stack_to_array(a);
	while(i < stack_size(a))
	{
		mean = mean + ar[i];
		i ++;
	}	
	mean = mean / stack_size(a);
	return (mean);
}

