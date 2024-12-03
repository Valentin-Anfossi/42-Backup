/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:03:04 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/03 22:38:29 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create an element for each arg in arg array, then push it to the top of the returned stack
s_stack *stack_build(int *arg_array, int argc)
{
	int i;
	s_stack *stack;
	s_stack *new;

	stack = NULL;
	new = NULL;
	i = 0;
	while(i < argc-1)
	{
		new = stack_create_element(arg_array[i]);
		stack_add_to_top(&new,&stack);
		i++;
	}
	stack_circularize(&stack);
	return(stack);
}
// MAKE STACK CIRCULAR (DUH)
void stack_circularize(s_stack **stack)
{
	s_stack *start;
	s_stack *temp;
	s_stack *end;

	start = *stack;
	while(temp)
	{
		temp = temp -> next;
	}
	end = temp;
	(*stack)->prev = end;
	return ;
}

s_stack *stack_create_element(int val)
{
	s_stack *s;

	s = (s_stack*)malloc(sizeof(s_stack));
	if(!s)
		return(NULL);
	s -> costa = 0;
	s -> costb = 0;
	s -> index = 0;
	s -> next = (void *)NULL;
	s -> prev = (void *)NULL;
	s -> val = val;
	return(s);
}

void stack_add_to_top(s_stack **element, s_stack **stack)
{
	s_stack *new;
	s_stack *dest;

	if(!*stack)
	{
		*stack = *element;
		return ;
	}
	(*element)->next = *stack;
	(*stack)->prev = *element;
	*stack = *element;
}
