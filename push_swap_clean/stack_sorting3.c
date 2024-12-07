/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:30:59 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 23:47:28 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_mean(t_stack **a, t_stack **b)
{
	float	mean;

	while (stack_size(a) > 3)
	{
		mean = sort_get_mean(a);
		if ((*a)->index < mean)
			pb(a, b);
		else
			ra(a);
	}
	return ;
}

float	sort_get_mean(t_stack **a)
{
	int		*ar;
	int		i;
	float	mean;

	i = 0;
	mean = 0;
	ar = stack_index_to_array(a);
	while (i < stack_size(a))
	{
		mean = mean + ar[i];
		i ++;
	}
	mean = mean / stack_size(a);
	free(ar);
	return (mean);
}
