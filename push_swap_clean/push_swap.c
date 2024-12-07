/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:44:30 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/07 04:17:09 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//MAKE STACK & THEN!! MAKE IT CIRCULAR
int	main(int argc, char **argv)
{
	int		*arg_array;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!argv[1][0] && argc == 2)
		return (print_error());
	if (!args_check(argc, argv) || argc <= 1)
		return (print_error());
	arg_array = process_args(argc, argv);
	a = stack_build(arg_array, argc);
	if (stack_is_sorted(&a) == 1)
	{
		free(arg_array);
		free_stack(&a);
		return (0);
	}
	stack_index(&a);
	main_sort(&a, &b);
	free(arg_array);
	free_stack(&a);
	free_stack(&b);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	tmp -> prev -> next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*stack = NULL;
}
