/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:34:36 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/27 19:38:03 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//SWAP A
int sa(elem **stack)
{
	if(*stack == NULL || (*stack)->next == NULL)
		return (1);
		
	elem *elem1;
	elem *elem2;

	elem1 = *stack;
	elem2 = elem1->next;
	*stack = elem2;
	elem1->next = elem2->next;
	elem2->prev = NULL;
	elem2->next = elem1;
	elem1->prev = elem2;
	return(0);
}
//LA MEME MAIS SAPPELLE SB (PARCE QUE)
int sb(elem **stack)
{
	if(*stack == NULL || (*stack)->next == NULL)
		return (1);
		
	elem *elem1;
	elem *elem2;

	elem1 = *stack;
	elem2 = elem1->next;
	*stack = elem2;
	elem1->next = elem2->next;
	elem2->prev = NULL;
	elem2->next = elem1;
	elem1->prev = elem2;
	return (0);
}
//A TON AVIS
int ss(elem **stacka, elem** stackb)
{
	if(sa(stacka) && sb(stackb))
		return (0);
	return(1);
}
//PUSH A (PUT FIRST B TO TOP OF A)
int pa(elem **stacka, elem **stackb)
{
    if (*stackb == NULL)
        return 0;
    elem *topb;
	
	topb = *stackb;
    *stackb = topb->next;
    if (*stackb)
        (*stackb)->prev = NULL;
    topb->next = *stacka;
    if (*stacka)
        (*stacka)->prev = topb;
    *stacka = topb;
    topb->prev = NULL;
    return 1;
}
//PUSH B (PUT FIRST A ON TOP OF B)
int pb(elem **stacka, elem **stackb)
{
    if (*stacka == NULL)
        return 0;
    elem *topa;
	
	topa = *stacka;
    *stacka = topa->next;
    if (*stacka)
        (*stacka)->prev = NULL;
    topa->next = *stackb;
    if (*stackb)
        (*stackb)->prev = topa;
    *stackb = topa;
    topa->prev = NULL;
    return 1;
}
//ROTATE A (SHIFTS UP ALL BY 1, FIRST BECOMES LAST)
int ra(elem**stacka)
{
	if(*stacka == NULL || (*stacka)->next == NULL)
		return 0;
	elem *last;
	elem *first;
	
	last = *stacka;
	while(last->next != NULL)
		last = last->next;
	first = *stacka;
	first->prev = last;
	(first->next)->prev = NULL; 
	*stacka = first->next;
	last->next = first;
	first->next = NULL;
	return(1);
}
//ROTATE B (SHIFTS UP ALL BY 1, FIRST BECOMES LAST)
int rb(elem**stackb)
{
	if(*stackb == NULL || (*stackb)->next == NULL)
		return 0;
	elem *last;
	elem *first;
	
	last = *stackb;
	while(last->next != NULL)
		last = last->next;
	first = *stackb;
	first->prev = last;
	(first->next)->prev = NULL; 
	*stackb = first->next;
	last->next = first;
	first->next = NULL;
	return(1);
}
//ROTATE BOTH
int rr(elem *stacka, elem *stackb)
{
	if(ra(&stacka))
		if(rb(&stackb))
			return (1);
	return (0);
}
//Reverse rotate A (SHIFTS DOWN ALL BY 1, LAST BECOMES FIRST)
int rra(elem **stacka)
{
	if(stacka == NULL || *stacka == NULL || (*stacka)->next == NULL)
		return (0);
		
	elem *last;
	elem *secondlast;
	elem *first;
	
	last = *stacka;
	while(last->next != NULL)
		last = last->next;
	secondlast = last->prev;
	secondlast->next = NULL;
	last->prev = NULL;
	first = *stacka;
	last -> next = first;
	first -> prev = last;
	*stacka = last;
	return(1);
}
//Reverse rotate B (SHIFTS DOWN ALL BY 1, LAST BECOMES FIRST)
int rrb(elem **stackb)
{
	if(stackb == NULL || *stackb == NULL || (*stackb)->next == NULL)
		return (0);
		
	elem *last;
	elem *secondlast;
	elem *first;
	
	last = *stackb;
	while(last->next != NULL)
		last = last->next;
	secondlast = last->prev;
	secondlast->next = NULL;
	last->prev = NULL;
	first = *stackb;
	last -> next = first;
	first -> prev = last;
	*stackb = last;
	return(1);
}
//Reverse rotate both
int rrr(elem **stacka, elem **stackb)
{
	if(rra(stacka) && rrb(stackb))
		return (1);
	return(0);
}