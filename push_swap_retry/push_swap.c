/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:44:30 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/09 02:07:10 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		args_precheck(char ** argv, int argc, char*** argscharray);
char	**charray_popfirst(char **ar, int n);


//MAKE STACK & THEN!! MAKE IT CIRCULAR
int	main(int argc, char **argv)
{
	char 	**arg_charray;
	int		*arg_array;
	t_stack	*a;
	t_stack	*b;
	int i = 0;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!argv[1][0] && argc == 2)
		return (print_error());
	argc = args_precheck(argv, argc, &arg_charray);
	if (!args_check(argc, arg_charray))
		return (print_error());
	if (!arg_charray)
		return(print_error());
	arg_array = process_args(argc, arg_charray);
	i = 0;
	a = stack_build(arg_array, argc);
	if (stack_is_sorted(&a) == 1)
		return(free_all(&a,&b,&arg_array));
	stack_index(&a);
	main_sort(&a, &b);
	return(free_all(&a,&b,&arg_array));
}

int args_precheck(char **argv, int argc, char*** argscharray)
{
	int 	len;
	
	len = 0;
	if (argc == 2 && argv[1])
	{
		*argscharray = ft_split(argv[1],' ');
		while((*argscharray)[len] != NULL)
			len++;
		return(len);
	}
	*argscharray = charray_popfirst(argv,argc);
	return(argc-1);
}
char	**charray_popfirst(char **ar, int n)
{
	int i;
	char **result;

	result = malloc(sizeof(char *)*n);
	i = 0;
	i ++;
	while(ar[i])
	{
		result[i-1] = malloc(sizeof(ar[i]));
		result[i-1] = ar[i];
		i++;
	}
	return (result);
}

