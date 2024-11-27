/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:44:30 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/27 14:56:39 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct elem{
	struct elem* next;
	struct elem* prev;
	int val;
} elem;

elem* createElem(int val)
{
	elem *newElem = (elem *)malloc(sizeof(elem));
	newElem->val = val;
	newElem->prev = NULL;
	newElem->next = NULL;
	return (newElem);
}

void addElemOnTop(elem** stack, int val)
{
	elem *newElem;
	newElem = createElem(val);
	if(*stack == NULL)
	{
		*stack = newElem;
		return;
	}
	newElem->next = *stack;
	(*stack)->prev = newElem;
	*stack = newElem;
}
int remElemOnTop(elem** stack)
{
	if(*stack == NULL)
		return(0);
	elem *tmp = *stack;
	*stack = (*stack)->next;
	if(*stack  != NULL)
	{
		(*stack)->prev = NULL;
	}
	free (tmp);
}
void printStack(elem *stack)
{
	elem *tmp;
	tmp = stack;
	while(tmp != NULL)
	{
		printf("[%d]", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}

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

int main(void)
{
	elem *stacka;
	elem *stackb;

	stackb = NULL;
	stacka = NULL;
	addElemOnTop(&stacka, 12);
	addElemOnTop(&stacka, 13);
	addElemOnTop(&stacka, 14);
	addElemOnTop(&stackb,5);
	addElemOnTop(&stackb,8);
	sa(&stacka);
	pa(&stacka,&stackb);
	printStack(stacka);
	printStack(stackb);
	return (0);
}

