/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:23:34 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/08 03:05:32 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main_sort(t_stack **a, t_stack **b)
{
	while (stack_size(a) > 3)
		sort_mean(a, b);
	if (stack_size(a) < 3)
		if (!stack_is_sorted(a))
			sa(a, 1);
	sort_three(a);
	while (*b)
	{
		sort_find_match(a, b);
		sort_cost_of_best_match(a, b);
		sort_cheapest_best_match(b);
		sort_do_moves(a, b, sort_cheapest_best_match(b));
	}
	sort_final_sort(a);
	return (1);
}

// FIND THE CLOSEST MATCH IN VALUE FOR EACH ELEMENT IN STACK B
// HAHA 25 LINES, UP YOURs NORMINETTE
void	sort_find_match(t_stack **a, t_stack **b)
{
	t_stack			*tmp_a;
	t_stack			*tmp_b;
	long long int	diff;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_b != NULL)
	{
		diff = INT_MAX;
		while (tmp_a != NULL)
		{
			sort_um(tmp_a, tmp_b, &diff);
			if (tmp_a->next == *a)
				break ;
			tmp_a = tmp_a -> next;
		}
		if (tmp_b->next == *b)
			break ;
		tmp_a = *a;
		tmp_b = tmp_b->next;
	}
}

//UPDATE MATCH (norminette problem AGAIN)
void	sort_um(t_stack *tmp_a, t_stack *tmp_b, long long int *diff)
{
	long long int	current;

	current = tmp_a->val - tmp_b->val;
	if (current < *diff && current > 0)
	{
		*diff = current;
		tmp_b->match = tmp_a;
	}
}

// CALCULATE COST FOR BEST MATCH
void	sort_cost_of_best_match(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b -> cost_b = sort_cost_to_top(b, tmp_b);
		tmp_b -> cost_a = sort_cost_to_top(a, tmp_b->match);
		tmp_b = tmp_b->next;
		if (tmp_b == *b)
			break ;
	}
}

// SIMPLE SORT IF ONLY 3 ELEM IN STACK (MANGLED BY THE NORMINETTE)
void	sort_three(t_stack **a)
{
	int	mid;
	int	bot;

	while (!stack_is_sorted(a))
	{
		mid = (*a)-> next -> val;
		bot = (*a)-> prev -> val;
		if ((*a)-> val > mid && mid > bot)
		{
			sa(a, 1);
			rra(a, 1);
		}
		if ((*a)-> val > bot && bot > mid)
			ra(a, 1);
		if (mid > (*a)-> val && (*a)-> val > bot)
			rra(a, 1);
		if (mid > bot && bot > (*a)-> val)
			sa(a, 1);
		if (bot > (*a)-> val && (*a)-> val > mid)
		{
			sa(a, 1);
			ra(a, 1);
		}
	}
}
