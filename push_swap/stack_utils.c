/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:03:04 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 23:27:46 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create an element for each arg in arg array, then returns completed stack
t_stack	*stack_build(int *arg_array, int argc)
{
	int		i;
	t_stack	*stack;
	t_stack	*new;

	stack = NULL;
	new = NULL;
	i = 0;
	while (i < argc - 1)
	{
		new = stack_create_element(arg_array[i]);
		stack_add_to_bot(&new, &stack);
		i++;
	}
	stack_circularize(&stack);
	stack_index(&stack);
	return (stack);
}

// MAKE STACK CIRCULAR (DUH)
void	stack_circularize(t_stack **stack)
{
	t_stack	*end;

	end = *stack;
	while (end->next)
	{
		end = end -> next;
	}
	(*stack)->prev = end;
	end -> next = *stack;
}

t_stack	*stack_create_element(int val)
{
	t_stack	*s;

	s = (t_stack *) malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s -> cost_a = 0;
	s -> cost_b = 0;
	s -> index = 0;
	s -> next = (void *) NULL;
	s -> prev = (void *) NULL;
	s -> val = val;
	return (s);
}

void stack_add_to_bot(t_stack **element, t_stack **stack)
{
	if (!*stack)
	{
		*stack = *element;
		return ;
	}
	stack_circularize(stack);
	(*element)->prev = stack_get_last(stack);
	(stack_get_last(stack))->next = *element;
}

t_stack	*stack_get_last(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		if (tmp->next == *stack)
			return (tmp);
		else
			tmp = tmp->next;
	}
	return (NULL);
}

