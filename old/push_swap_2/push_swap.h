/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:45:02 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/03 11:26:17 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

//STACK TYPEDEF
typedef struct elem{
	struct elem* next;
	struct elem* prev;
	int val;
	int index;
	int costa;
	int costb;
} elem ;

typedef struct t_ops{
	int count;
} t_ops;

//LOGIC FUNCTIONS
int sa(elem **stack);
int sb(elem **stack);
int ss(elem **stacka, elem **stackb);
int pa(elem **stacka, elem **stackb);
int pb(elem **stacka, elem **stackb);
int ra(elem **stacka);
int rb(elem **stackb);
int rr(elem **stacka, elem **stackb);
int rra(elem **stacka);
int rrb(elem **stackb);
int rrr(elem **stacka, elem **stackb);

//SORTING FUNCS
int selection_sort(elem **stacka, elem **stackb);

//STACK UTILS
elem *createElem(int val);
void addElemOnTop(elem **stack, int val);
int remElemOnTop(elem **stack);
void printStacks(elem *stacka, elem* stackb);
elem* build_stacka(int argc, char**argv);
int length_stack(elem *stack);

//UTILS
long int	ft_atoi_pushswap(const char *str);
int ft_abs(int n);

//CHECKS
int stack_check(int argc, char **argv);
int stack_check_duplicates(int *a);
