/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:18:38 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/25 11:37:29 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *build_stack_a(int argc, char **argv)
{
	int i;
	int j;
	int *a;

	i = 1;
	j = 0;
	a = malloc(sizeof(int) * argc-1);
	while(argv[i] && i < argc)
	{
		a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (a);
}
int *build_stack_b(int argc)
{
	int i;
	int *b;

	i = 0;
	b = malloc(sizeof(int) * argc-1);
	while(i < argc)
	{
		b[i] = 0;
		i++;
	}
	return (b);
}


int check_stack_digits(int argc, char** argv)
{
	int i;
	int j;
	
	j = 0;
	i = 1;
	while (argv[i])
	{
		while(argv[i][j])
		{
			if(argv[i][j] == '-' && j == 0)
				j++;
			if(!ft_isdigit(argv[i][j]))
				return 0;
			j ++;
		}
		j = 0;
		i ++;
	}
	return (1);
}

int check_stack_duplicates(int *a, int size)
{
	int j;
    int i;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while(i < size)
	{
    	while (j < size) {
        	if (a[j] == a[i]) 
				count ++;
			if(count > 1)
			 return(0);
        	j++;
    	}
		count = 0;
		j = 0;
		i++;
	}
    return 1;
}

int error_message(int reason)
{
	if(reason == 1)
		write(1,"Error : Invalid stack element\n",30);
	if(reason == 2)
		write(2,"Error : Duplicate detected\n",27);
	return(1);
}
int	main(int argc, char **argv)
{
	int *a;
	int *b;
	int i;
	
	i = 0;
	if(argc == 1)
		return (0);
	if(!check_stack_digits(argc, argv))
		return(error_message(1));
	a = build_stack_a(argc,argv);
	if(!check_stack_duplicates(a, argc-1))
		return(error_message(2));
	b = build_stack_b(argc);
	print_stacks(a,b,argc);
}
//if stack missing, give the prompt back
//check the stack, return error \n if invalid stack
//initialise stack B, same size as stack A
//count and malloc both stacks

//start logic
//pass stacks to sorting func
//get count of operations in return (changed stacks are passed)

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