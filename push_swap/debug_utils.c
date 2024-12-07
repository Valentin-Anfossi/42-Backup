/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:17:56 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 23:27:46 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print_elem(t_stack *a)
{
	printf(" -- ELEM -- \n");
	printf("Index : %d\n",a->index);
	printf("Value : %d\n",a->val);
	if (a->prev)
		printf("Prev  : %d\n",(a->prev)->val);
	else
		printf("Prev  : NULL\n");
	if (a->next)
		printf("Next  : %d\n",(a->next)->val);
	else
		printf("Next  : NULL\n");
	if (a->match)
		printf("Match : %d\n",(a->match)->val);
	else
		printf("Match : NULL\n");
	printf("Costa : %d\n", (a->cost_a));
	printf("Costb : %d\n", (a->cost_b));
}

// PRINT ARRAY (what did you expect)
void debug_print_array(int *ar, int arlen)
{
	int	i;

	i = 0;
	printf("\nARRAY\n");
	while (i < arlen)
	{
		printf("{%d}",ar[i]);
		i ++;
	}
	printf("\n");
}

//PRINT STACK IN ORDER
void	debug_print_stack(t_stack *stack)
{
	t_stack	*starting_elem;

	starting_elem = stack;
	if (stack)
	{
		printf("// PRINTING STACK //\n");
		debug_print_elem(stack);
	}
	else
	{
		printf("// EMPTY STACK //\n");
		return ;
	}
	if (stack->next && stack->next != starting_elem)
	{
		stack = stack->next;
		while (stack != starting_elem && stack)
		{
			debug_print_elem(stack);
			stack = stack->next;
		}
	}
	printf("// END  OF  STACK //\n");
	return ;
}
