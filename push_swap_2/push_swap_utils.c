/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:16:10 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/28 07:21:28 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return(1);
}
void printStacks(elem *stacka, elem *stackb)
{
	elem *tmp;
	tmp = stacka;
	while(tmp != NULL)
	{
		printf("[%d]", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = stackb;
	while(tmp != NULL)
	{
		printf("[%d]", tmp->val);
		tmp = tmp->next;
	}
	printf("\n----\n");
}
elem* build_stacka(int argc, char**argv)
{
	int i;
	elem *stack;
	
	stack = NULL;
	i = 1;
	while(i < argc)
	{
		int val = ft_atoi_pushswap(argv[i]);
		addElemOnTop(&stack,val);
		i ++;
	}
	return (stack);
}