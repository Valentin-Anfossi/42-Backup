/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:44:30 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 14:55:31 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//MAKE STACK & THEN!! MAKE IT CIRCULAR
int main(long int argc, char **argv)
{
	int *arg_array;
	s_stack *a;
	s_stack *b;

	a = NULL;
	b = NULL;
	if(!args_check(argc, argv) || argc <= 1)
		return(print_error());
	arg_array = process_args(argc, argv);
	a = stack_build(arg_array,argc);
	// stack_index(&a);
	// stack_index(&b);
	main_sort(&a,&b);
	// free(a);
	// free(b);
	free(arg_array);
	free_all(&a,&b);
	return(0);
}
void free_all(s_stack **a, s_stack**b)
{
	// while(*a)
	// 	free(*a);
	// while(*b)
	// 	free(*b);
	free(*a);
	free(*b);
	return ;
}