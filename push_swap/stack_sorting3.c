/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:30:59 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 04:32:07 by vanfossi         ###   ########.fr       */
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