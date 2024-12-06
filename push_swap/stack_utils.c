/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:03:04 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 04:46:38 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create an element for each arg in arg array, then returns completed stack
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
		stack_add_to_bot(&new,&stack);
		i++;
	}
	stack_circularize(&stack);
	stack_index(&stack);
	return(stack);
}
// MAKE STACK CIRCULAR (DUH)
void stack_circularize(s_stack **stack)
{
	s_stack *end;

	end = *stack;
	while(end->next)
	{
		end = end -> next;
	}
	(*stack)->prev = end;
	end -> next = *stack;
}

s_stack *stack_create_element(int val)
{
	s_stack *s;

	s = (s_stack*)malloc(sizeof(s_stack));
	if(!s)
		return(NULL);
	s -> cost_a = 0;
	s -> cost_b = 0;
	s -> index = 0;
	s -> next = (void *)NULL;
	s -> prev = (void *)NULL;
	s -> val = val;
	return(s);
}

void stack_add_to_bot(s_stack **element, s_stack **stack)
{
	if(!*stack)
	{
		*stack = *element;
		return ;
	}
	stack_circularize(stack);
	(*element)->prev = stack_get_last(stack);
	(stack_get_last(stack))->next = *element;
}

s_stack *stack_get_last(s_stack **stack)
{
	s_stack *tmp;
	
	tmp = *stack;
	if(*stack == NULL)
		return (NULL);
	while(tmp != NULL)
	{
		if(tmp->next == *stack)
			return(tmp);
		else
			tmp = tmp->next;
	}
	return(NULL);
}

void stack_index(s_stack **stack)
{
	int *ar;
	int j;
	s_stack *tmp;
	tmp = *stack;
	
	if(*stack == NULL)
		return ;
	j = 0;
	ar = stack_to_array(stack);
	array_sort(ar,stack_size(stack));
	while(tmp)
	{
		while(j < stack_size(stack))
		{
			if(ar[j] == tmp->val)
				tmp->index = j;
			j ++;
		}
		j = 0;
		tmp = tmp->next;
		if(tmp == *stack)
			break;	
	}
}

// RETURNS STACK NODE WITH SMALEST -> VAL
s_stack* stack_find_min(s_stack **stack)
{
	s_stack *s;
	s_stack *start;
	s_stack *min;

	if(*stack == NULL)
		return (NULL);
	s = *stack;
	start = *stack;
	min = s;
	s = s->next;
	while(s != start)
	{
		if(s->val < min->val)
			min = s;
		s = s->next;
	}
	return(min);
}

// RETURNS STACK NODE WITH BIGGEST -> VAL
s_stack* stack_find_max(s_stack **stack)
{
	s_stack *s;
	s_stack *start;
	s_stack *max;

	if(*stack == NULL)
		return (NULL);
	s = *stack;
	start = *stack;
	max = s;
	s = s->next;
	while(s != start)
	{
		if(s->val > max->val)
			max = s;
		s = s->next;
	}
	return(max);
}
int stack_size(s_stack **stack)
{
	s_stack *s;
	int len;

	len = 1;
	if((*stack) == NULL)
		return (0);
	if((*stack)->next == *stack)
		return (1);
	s = (*stack)->next;
	while(s != *stack)
	{
		s = s->next;
		len ++;
	}
	return (len);
}

int stack_is_sorted(s_stack **stack)
{
	s_stack *tmp;
	
	tmp = *stack;
	if(*stack == NULL)
		return (0);
	if(*stack != stack_find_min(stack))
		return (0);
	while(tmp->next != *stack)
	{
		 if(tmp->val > tmp->next->val)
		 	return(0);
		tmp = tmp->next;
	}
	if(tmp->val < (*stack)->val)
		return(0);
	return(1);
}