/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 04:52:02 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/25 15:46:49 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STACKSIZE 15

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "./libft/libft.h"

//Struct
typedef struct elem{
	int val;
	struct elem *prec;
	struct elem *next;
}elem;

//Utils
void print_stacks(int *a, int *b, int argc);
int *build_stack_a(int argc, char **argv);
int *build_stack_b(int argc);
void clear_stack(int *stack);
int error_message(int reason);

//Checks
int check_stack_digits(int argc, char** argv);
int check_stack_duplicates(int *a, int size);

//Sorting
int pre_sorting(int *a, int *b,int size);
int sorting_func_1(int *a, int *b, int size);
void sa(int *a, int *b);

// Logic Functions
void sb(int *a, int *b);
void ss(int *a, int *b);
void pa(int *a, int *b);
void pb(int *a, int *b);
void ra(int *a, int *b);
void rb(int *a, int *b);
void rr(int *a, int *b);
void rra(int *a, int *b);
void rrb(int *a, int *b);
void rrr(int*a , int *b);
