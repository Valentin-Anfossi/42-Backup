/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:17:51 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/08 04:13:08 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	clear_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != 0)
	{
		buffer[i] = 0;
		i ++;
	}
}

int	checker_moves(char *buffer, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(buffer, "sa\n", 3))
		return (sa(a, 0));
	else if (!ft_strncmp(buffer, "sb\n", 3))
		return (sb(b, 0));
	else if (!ft_strncmp(buffer, "ss\n", 3))
		return (ss(a, b, 0));
	else if (!ft_strncmp(buffer, "pa\n", 3))
		return (pa(a, b, 0));
	else if (!ft_strncmp(buffer, "pb\n", 3))
		return (pb(a, b, 0));
	else if (!ft_strncmp(buffer, "ra\n", 3))
		return (ra(a, 0));
	else if (!ft_strncmp(buffer, "rb\n", 3))
		return (rb(b, 0));
	else if (!ft_strncmp(buffer, "rr\n", 3))
		return (rr(a, b, 0));
	else if (!ft_strncmp(buffer, "rra\n", 4))
		return (rra(a, 0));
	else if (!ft_strncmp(buffer, "rrb\n", 4))
		return (rrb(b, 0));
	else if (!ft_strncmp(buffer, "rrr\n", 4))
		return (rrr(a, b, 0));
	else
		return (0);
}

int	read_input(t_stack **a, t_stack **b)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * 11);
	while (1)
	{
		buffer = get_next_line(0);
		if (buffer == NULL)
			return (0);
		if (!checker_moves(buffer, a, b))
			return (1);
		if (stack_is_sorted(a))
			return (0);
		clear_buffer(buffer);
	}
}

int	main(int argc, char **argv)
{
	int		*arg_array;
	t_stack	*a;
	t_stack	*b;
	int		result;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!argv[1][0] && argc == 2)
		return (print_error());
	if (!args_check(argc, argv) || argc <= 1)
		return (print_error());
	arg_array = process_args(argc, argv);
	a = stack_build(arg_array, argc);
	result = read_input(&a, &b);
	if (stack_is_sorted(&a) == 1 && result == 0)
		ft_printf("OK\n");
	else if (result == 1)
		ft_fprintf(2, "Error\n");
	else
		ft_printf("KO\n");
	free(arg_array);
	free_stack(&a);
	free_stack(&b);
}
