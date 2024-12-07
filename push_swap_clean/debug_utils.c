/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:17:56 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/07 01:59:23 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print_elem(t_stack *a)
{
	ft_printf(" -- ELEM -- \n");
	ft_printf("Index : %d\n", a->index);
	ft_printf("Value : %d\n", a->val);
	if (a->prev)
		ft_printf("Prev  : %d\n", (a->prev)->val);
	else
		ft_printf("Prev  : NULL\n");
	if (a->next)
		ft_printf("Next  : %d\n", (a->next)->val);
	else
		ft_printf("Next  : NULL\n");
	if (a->match)
		ft_printf("Match : %d\n", (a->match)->val);
	else
		ft_printf("Match : NULL\n");
	ft_printf("Costa : %d\n", (a->cost_a));
	ft_printf("Costb : %d\n", (a->cost_b));
}

// PRINT ARRAY (what did you expect)
void	debug_print_array(int *ar, int arlen)
{
	int	i;

	i = 0;
	ft_printf("\nARRAY\n");
	while (i < arlen)
	{
		ft_printf("{%d}", ar[i]);
		i ++;
	}
	ft_printf("\n");
}

//PRINT STACK IN ORDER
void	debug_print_stack(t_stack *stack)
{
	t_stack	*starting_elem;

	starting_elem = stack;
	if (stack)
	{
		ft_printf("// PRINTING STACK //\n");
		debug_print_elem(stack);
	}
	else
	{
		ft_printf("// EMPTY STACK //\n");
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
	ft_printf("// END  OF  STACK //\n");
	return ;
}
