/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:44:30 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/03 21:31:46 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//MAKE STACK & THEN!! MAKE IT CIRCULAR

int main(int argc, char **argv)
{
	int *arg_array;
	s_stack *a;

	a = NULL;
	if(!args_check(argc, argv) || argc <= 1)
		return(print_error());
	arg_array = process_args(argc, argv);
	debug_print_array(arg_array,argc-1);
	a = stack_build(arg_array,argc);
	debug_print_stack(a);
	// if(arg_array != NULL)
	// 	a = stack_create(arg_array,argc);
	// if(a)
	// 	sorting_start(a);
	
		
}
