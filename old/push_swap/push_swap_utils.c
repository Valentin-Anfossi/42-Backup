/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:37:42 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/25 13:34:29 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(int *a, int *b, int argc)
{
	int i;
	i = 0;
	while(i < argc-1)
	{
		printf("%d ",a[i]);
		i ++;
	}
	i = 0;
	printf("\n");
	while(i < argc-1)
	{
		printf("%d ",b[i]);
		i ++;
	}
	printf("\n");
}
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
void clear_stack(int *stack)
{
	int i;
	i = 0;

	while(stack[i])
	{
		stack[i] = 0;
		i ++;
	}
}
int error_message(int reason)
{
	if(reason == 1)
		write(1,"Error : Invalid stack element\n",30);
	if(reason == 2)
		write(2,"Error : Duplicate detected\n",27);
	return(1);
}