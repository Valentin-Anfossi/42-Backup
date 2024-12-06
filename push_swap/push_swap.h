/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:45:02 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 04:29:04 by vanfossi         ###   ########.fr       */
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
	struct t_stack* match;
	int val;
	int index;
	int cost_a;
	int cost_b;
} s_stack ;

//ARGS_UTILS.C
int *process_args(int argc, char **argv);
int args_check_duplicates(int *a);
int args_check(int argc, char **argv);
long int	ft_atoi_pushswap(const char *str);

//SORTING FUNCTIONS
int main_sort(s_stack **a, s_stack **b);
void sort_mean(s_stack **a, s_stack **b);
float sort_get_mean(s_stack **a);
void sort_find_match(s_stack **a, s_stack **b);
int sort_cost_to_top(s_stack **stack, s_stack *a);
void sort_cost_of_best_match(s_stack **a, s_stack **b);
s_stack *sort_cheapest_best_match(s_stack **b);
int sort_do_moves(s_stack **a, s_stack **b, s_stack *cheapest);
void sort_three(s_stack **a);
void sort_final_sort(s_stack **a);

//PRINT_ERROR.C
int print_error(void);

//STACK_UTILS.C
s_stack *stack_build(int *arg_array, int argc);
s_stack *stack_create_element(int val);
void stack_add_to_bot(s_stack **element, s_stack **stack);
void stack_circularize(s_stack **stack);
s_stack *stack_find_max(s_stack **stack);
s_stack *stack_find_min(s_stack **stack);
int stack_size(s_stack **stack);
void stack_index(s_stack **stack);
int *stack_to_array(s_stack **stack);
s_stack *stack_get_last(s_stack **stack);
int stack_is_sorted(s_stack **stack);

//ARRAY_UTILS.C
void array_sort(int arr[], int N);

// !!DEBUG!!
void debug_print_elem(s_stack *a);
void debug_print_array(int *ar, int arlen);
void debug_print_stack(s_stack *stack);

//STACK_FUNCTIONS(1/2/3).C
int sa(s_stack **a, int print);
int sb(s_stack **b, int print);
int ss(s_stack **a, s_stack **b);
int pa(s_stack **a, s_stack **b);
void pa_helper(s_stack**a, s_stack *tmp_b);
int pb(s_stack **b, s_stack **a);
void pb_helper(s_stack **b, s_stack *tmp_a);
int ra(s_stack **a);
int rb(s_stack **b);
int rr(s_stack **a, s_stack **b);
int rra(s_stack **a);
int rrb(s_stack **b);
int rrr(s_stack **a, s_stack **b);

//MISC_UTILS.c
int ft_abs(int i);
