/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:18:38 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/25 04:48:36 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	

	
	//if stack missing, give the prompt back
	//check the stack, return error \n if invalid stack
	//initialise stack B, same size as stack A
	//count and malloc both stacks
	
	//start logic
	//pass stacks to sorting func
	//get count of operations in return (changed stacks are passed)
}

int **build_stack(int argc, char **argv)
{
	int i;
	int j;
	int **a;

	a = malloc(sizeof(int) * argc);

	while (i < argc)
	{
		while(argv[i][j])
		{
			a[i] = 
		}
	}	
}
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