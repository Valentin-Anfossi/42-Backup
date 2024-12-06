/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:03:23 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 04:47:39 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pb (push b): Take the first element at the top of a
// Do nothing if a is empty.
int pb(s_stack **a, s_stack **b)
{
	s_stack *tmp_a;
	
	if(*a == NULL)
		return(0);
	tmp_a = *a;
	if((*a)->next == *a)
		*a = NULL;
	else
	{
		(*a)->next->prev = (*a)->prev;
		*a = (*a)->next;
		*a = tmp_a->next;
		(*a)->prev = tmp_a->prev;
		(*a)->prev->next = *a;
	}
	pb_helper(b,tmp_a);
	printf("pb\n");
	return(1);
}
// IDK WHOS THE SMOOTHBRAIN WHO DECIDED 25 LINES
// BUT IM HOPING HE EAT SPAGHETTI A LA DIARRHEA
void pb_helper(s_stack **b, s_stack *tmp_a)
{
	if(*b == NULL)
	{
		tmp_a -> next = tmp_a;
		tmp_a -> prev = tmp_a;
		*b = tmp_a;
	}
	else
	{
		tmp_a->prev = (*b)->prev;
		tmp_a->next = *b;
		(*b)->prev->next = tmp_a;
		(*b)->prev = tmp_a;
		*b = tmp_a;
	}
}

// rr : ra and rb at the same time.
int rr(s_stack **a, s_stack **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	printf("rr\n");
	return (1);
}

