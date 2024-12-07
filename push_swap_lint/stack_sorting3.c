/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:30:59 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 15:04:44 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_mean(s_stack **a, s_stack **b)
{
	float mean;

	while(stack_size(a)>3)
	{
		mean = sort_get_mean(a);
		if((*a)->val < mean)
			pb(a,b);
		else
			ra(a);
	}
	return ;
}

// int sort_optimize_cost(s_stack *temp_b)
// {
// 	int new_cost;
// 	int cost_a;
// 	int cost_b;

// 	new_cost = 0;
// 	cost_a = temp_b ->cost_a;
// 	cost_b = temp_b ->cost_b;

// 	if(cost_a > 0 && cost_b > 0)
// 		new_cost = ft_abs;
// 	else if(cost_b < 0)

// 	return (new_cost);
// }
