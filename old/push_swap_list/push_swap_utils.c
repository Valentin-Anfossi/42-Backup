/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:37:42 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/26 15:50:43 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(int *a, int *b, int argc)
{

}
elem *build_stack_a(int argc, char **argv)
{
	int i;
	elem *stack;

	stack = NULL;
	i = 1;
	while(argv[i] && i < argc)
	{
		stack_add(stack, ft_atoi(argv[i]));
		i ++;
	}
	return (stack);
}
elem **build_stack_b(int argc)
{
}
void clear_stack(int *stack)
{
}
int error_message(int reason)
{
	if(reason == 1)
		write(1,"Error : Invalid stack element\n",30);
	if(reason == 2)
		write(2,"Error : Duplicate detected\n",27);
	return(1);
}