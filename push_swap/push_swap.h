/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:45:02 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/03 21:31:30 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

//s_stack TYPEDEF
typedef struct t_stack{
	struct t_stack* next;
	struct t_stack* prev;
	int val;
	int index;
	int costa;
	int costb;
} s_stack ;

//ARGS_UTILS.C
int *process_args(int argc, char **argv);
int args_check_duplicates(int *a);
int args_check(int argc, char **argv);
long int	ft_atoi_pushswap(const char *str);

//PRINT_ERROR.C
int print_error(void);

//STACK_UTILS.C
s_stack *stack_build(int *arg_array, int argc);
s_stack *stack_create_element(int val);
void stack_add_to_top(s_stack *element, s_stack **stack);

// !!DEBUG!!
void debug_print_elem(s_stack *a);
void debug_print_array(int *ar, int arlen);
void debug_print_stack(s_stack *stack);
