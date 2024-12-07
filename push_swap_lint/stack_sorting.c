/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:23:34 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 06:24:01 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main_sort(s_stack **a, s_stack **b)
{
	while(stack_size(a)>3)
		sort_mean(a,b);
	if(stack_size(a) < 3)
		if(!stack_is_sorted(a))
			sa(a,1);
	sort_three(a);
	while(*b)
	{
		sort_find_match(a,b);
		sort_cost_of_best_match(a,b);
		sort_cheapest_best_match(b);
		sort_do_moves(a,b, sort_cheapest_best_match(b));
	}
	sort_final_sort(a);
	return(1);
}

//PUT THE MIN ON TOP AT THE END
void sort_final_sort(s_stack **a)
{
	if(sort_cost_to_top(a,stack_find_min(a)) > 0)
	{
		while( *a != stack_find_min(a))
		{
			ra(a);
		}	
	}
	else
	{
		while( *a != stack_find_min(a))
		{
			rra(a);
		}		
	}
}

// FIND THE CLOSEST MATCH IN VALUE FOR EACH ELEMENT IN STACK B
// HAHA 25 LINES, UP YOURs NORMINETTE
void sort_find_match(s_stack **a, s_stack **b)
{
	s_stack *tmp_a;
	s_stack *tmp_b;
	int diff;

	tmp_a = *a;
	tmp_b = *b;
	while(tmp_b != NULL)
	{
		diff = INT_MAX;	
		while(tmp_a != NULL)
		{
			if(tmp_a-> val - tmp_b->val < diff && tmp_a->val - tmp_b->val > 0)
			{
				diff = tmp_a-> val - tmp_b->val;
				tmp_b -> match = tmp_a;
			}
			if(tmp_a->next == *a)
				break;
			tmp_a = tmp_a -> next;
		}
		if(tmp_b->next == *b)
			break;
		tmp_a = *a;
		tmp_b = tmp_b->next;
	}
}

// CALCULATE COST FOR BEST MATCH
void sort_cost_of_best_match(s_stack **a, s_stack **b)
{
	s_stack *tmp_b;
	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b -> cost_b = sort_cost_to_top(b, tmp_b);
		tmp_b -> cost_a = sort_cost_to_top(a,tmp_b->match);
		tmp_b = tmp_b->next;
		
		if(tmp_b == *b)
			break;
	}
}

// SIMPLE SORT IF ONLY 3 ELEM IN STACK (MANGLED BY THE NORMINETTE)
void sort_three(s_stack **a)
{
	int mid;
	int bot;
	
	while(!stack_is_sorted(a))
	{
		mid = (*a) -> next -> val;
		bot = (*a) -> prev -> val;
		if((*a) -> val > mid && mid > bot)
		{
			sa(a,1);
			rra(a);
		}
		if((*a) -> val > bot && bot > mid)
			ra(a);
		if(mid > (*a) -> val && (*a) -> val > bot)
			rra(a);
		if(mid > bot && bot > (*a) -> val)
			sa(a,1);
		if(bot > (*a) -> val && (*a) -> val > mid)
		{
			sa(a,1);
			ra(a);
		}
	}
}
