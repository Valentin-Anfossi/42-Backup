/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:45:02 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 23:40:22 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

//t_stack TYPEDEF
typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*match;
	int				val;
	int				index;
	int				cost_a;
	int				cost_b;
}	t_stack;

//ARGS_UTILS.C
int			*process_args(int argc, char **argv);
int			args_check_duplicates(int *a, int argc);
int			args_check(int argc, char **argv);
int			args_check_digits(char **argv, int i);
long int	ft_atoi_pushswap(const char *str);

//SORTING FUNCTIONS
int			main_sort(t_stack **a, t_stack **b);
void		sort_mean(t_stack **a, t_stack **b);
float		sort_get_mean(t_stack **a);
void		sort_find_match(t_stack **a, t_stack **b);
int			sort_cost_to_top(t_stack **stack, t_stack *a);
void		sort_cost_of_best_match(t_stack **a, t_stack **b);
t_stack		*sort_cheapest_best_match(t_stack **b);
int			sort_do_moves(t_stack **a, t_stack **b, t_stack *cheapest);
void		sort_three(t_stack **a);
void		sort_final_sort(t_stack **a);
int			sort_optimize_cost(t_stack *temp_b);
void		sort_um(t_stack *tmp_a, t_stack *tmp_b, long long int *d);

//PRINT_ERROR.C
int			print_error(void);

//STACK_UTILS.C
t_stack		*stack_build(int *arg_array, int argc);
t_stack		*stack_create_element(int val);
void		stack_add_to_bot(t_stack **element, t_stack **stack);
void		stack_circularize(t_stack **stack);
t_stack		*stack_find_max(t_stack **stack);
t_stack		*stack_find_min(t_stack **stack);
int			stack_size(t_stack **stack);
void		stack_index(t_stack **stack);
int			*stack_to_array(t_stack **stack);
int			*stack_index_to_array(t_stack **stack);
t_stack		*stack_get_last(t_stack **stack);
int			stack_is_sorted(t_stack **stack);

//ARRAY_UTILS.C
void		array_sort(int arr[], int N);

// !!DEBUG!!
void		debug_print_elem(t_stack *a);
void		debug_print_array(int *ar, int arlen);
void		debug_print_stack(t_stack *stack);

//STACK_FUNCTIONS(1/2/3).C
int			sa(t_stack **a, int print);
int			sb(t_stack **b, int print);
int			ss(t_stack **a, t_stack **b);
int			pa(t_stack **a, t_stack **b);
void		pa_helper(t_stack**a, t_stack *tmp_b);
int			pb(t_stack **b, t_stack **a);
void		pb_helper(t_stack **b, t_stack *tmp_a);
int			ra(t_stack **a);
int			rb(t_stack **b);
int			rr(t_stack **a, t_stack **b);
int			rra(t_stack **a);
int			rrb(t_stack **b);
int			rrr(t_stack **a, t_stack **b);

//MISC_UTILS.c
int			ft_abs(int i);
void		free_stack(t_stack **stack);
