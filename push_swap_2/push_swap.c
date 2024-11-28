/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:44:30 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/28 11:18:13 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO
// SORTING (SELECTION SORT)
// SORTING (COUNTING SORT)
// TEST CHECKS
// RETURN COUNT OF OPS
// INTEGRATE FT_PRINTF from school repo
// UPDATE LIBFT
// PRINTF OPS CALLED

int main(int argc, char **argv)
{
	elem *stacka;
	elem *stackb;

	stacka = NULL;
	stackb = NULL;
	if(!stack_check(argc,argv))
	{
		printf("Error. \n");
		return(1);
	}
	stacka = build_stacka(argc,argv);
	printStacks(stacka,stackb);
	pb(&stacka,&stackb);
	pb(&stacka,&stackb);
	printStacks(stacka,stackb);
	return (0);
}
