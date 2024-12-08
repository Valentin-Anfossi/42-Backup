/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:09:22 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 23:55:00 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_index(t_stack **stack)
{
	int		*ar;
	int		j;
	t_stack	*tmp;

	tmp = *stack;
	if (*stack == NULL)
		return ;
	j = 0;
	ar = stack_to_array(stack);
	array_sort(ar, stack_size(stack));
	while (tmp)
	{
		while (j < stack_size(stack))
		{
			if (ar[j] == tmp->val)
				tmp->index = j;
			j ++;
		}
		j = 0;
		tmp = tmp->next;
		if (tmp == *stack)
			break ;
	}
	free(ar);
}

// RETURNS STACK NODE WITH SMALEST -> VAL
t_stack	*stack_find_min(t_stack **stack)
{
	t_stack	*s;
	t_stack	*start;
	t_stack	*min;

	if (*stack == NULL)
		return (NULL);
	s = *stack;
	start = *stack;
	min = s;
	s = s->next;
	while (s != start)
	{
		if (s->val < min->val)
			min = s;
		s = s->next;
	}
	return (min);
}

// RETURNS STACK NODE WITH BIGGEST -> VAL
t_stack	*stack_find_max(t_stack **stack)
{
	t_stack	*s;
	t_stack	*start;
	t_stack	*max;

	if (*stack == NULL)
		return (NULL);
	s = *stack;
	start = *stack;
	max = s;
	s = s->next;
	while (s != start)
	{
		if (s->val > max->val)
			max = s;
		s = s->next;
	}
	return (max);
}

int	stack_size(t_stack **stack)
{
	t_stack	*s;
	int		len;

	len = 1;
	if ((*stack) == NULL)
		return (0);
	if ((*stack)->next == *stack)
		return (1);
	s = (*stack)->next;
	while (s != *stack)
	{
		s = s->next;
		len ++;
	}
	return (len);
}

int	stack_is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack == NULL)
		return (0);
	if (*stack != stack_find_min(stack))
		return (0);
	while (tmp->next != *stack)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->val < (*stack)->val)
		return (0);
	return (1);
}
