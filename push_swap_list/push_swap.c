/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:18:38 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/25 14:13:45 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int *a;
	int *b;

	if(argc == 1)
		return (0);
	if(!check_stack_digits(argc, argv))
		return(error_message(1));
	a = build_stack_a(argc,argv);
	if(!check_stack_duplicates(a, argc-1))
		return(error_message(2));
	b = build_stack_b(argc);
	pre_sorting(a,b,argc-1);
	print_stacks(a,b,argc);
}
// NOTES :
// Maybe better using struct with next/previous values ?
// Instead of an int array

//if stack missing, give the prompt back
//check the stack, return error \n if invalid stack
//initialise stack B, same size as stack A
//count and malloc both stacks

//start logic
//pass stacks to sorting func
//get count of operations in return (changed stacks as param)

// bubble sort function

//logic functions:
//sa (swap 2 first elements of stack a)
//sb (...                            b)
//ss (sa & sb)
//pa (take 1st of b put it top of a, do nothing if b is empty
//pb
//ra (shifts up all elements of a)
//rb
//rr
//rra (shifts down)
//rrb
//rrr