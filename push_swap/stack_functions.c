/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:38:58 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 23:27:46 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
int sa(t_stack **a, int print)
{
    t_stack *tmp;
	t_stack *tmp_2;
	
	if(*a == NULL || (*a)->next == NULL)
		return(0);
	
	tmp = *a;
	tmp_2 = tmp->next;
	
	*a = tmp_2;
	tmp->next = tmp_2->next;
	tmp_2->prev = tmp -> prev;
	tmp_2->next = tmp;
	(tmp_2->prev)->next = tmp_2;
	(tmp->next)->prev = tmp;
	tmp->prev = tmp_2;
	if(print)
		printf("sa\n");
	return(1);	
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
int sb(t_stack **b, int print)
{
    t_stack *tmp;
	t_stack *tmp_2;
	
	if(*b == NULL || (*b)->next == NULL)
		return(0);
	
	tmp = *b;
	tmp_2 = tmp->next;
	
	*b = tmp_2;
	tmp->next = tmp_2->next;
	tmp_2->prev = tmp -> prev;
	tmp_2->next = tmp;
	(tmp_2->prev)->next = tmp_2;
	(tmp->next)->prev = tmp;
	tmp->prev = tmp_2;
	if(print)
		printf("sb\n");
	return(1);	    
}

// ss : sa and sb at the same time.
int ss(t_stack **a, t_stack **b)
{
	if(sa(a,0) && sb(b,0))
	{
		printf("ss\n");
		return (1);
	}
	return(0);
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
int pa(t_stack **a, t_stack **b)
{
	t_stack *tmp_b;
	
	if(*b == NULL)
		return(0);
	tmp_b = *b;
	if((*b)->next == *b)
		*b = NULL;
	else
	{
		(*b)->next->prev = (*b)->prev;
		*b = (*b)->next;
		*b = tmp_b->next;
		(*b)->prev = tmp_b->prev;
		(*b)->prev->next = *b;
	}
	pa_helper(a,tmp_b);
	printf("pa\n");
	return(1);	
}
// F U NORMINETTE
void pa_helper(t_stack**a, t_stack *tmp_b)
{
	if(*a == NULL)
	{
		tmp_b -> next = tmp_b;
		tmp_b -> prev = tmp_b;
		*a = tmp_b;
	}
	else
	{
		tmp_b->prev = (*a)->prev;
		tmp_b->next = *a;
		(*a)->prev->next = tmp_b;
		(*a)->prev = tmp_b;
		*a = tmp_b;
	}
}


