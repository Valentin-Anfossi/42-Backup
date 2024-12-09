/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:20:49 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/09 01:41:00 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//MAIN FUNC THAT CREATES THE INT ARRAY HOLDING ARGVS IF THEY ARE VALID
int	*process_args(int argc, char **argv)
{
	int	i;
	int	*args;

	i = 0;
	if (args_check(argc, argv))
	{
		args = malloc(sizeof(int) * argc);
		while (i < argc)
		{
			args[i] = ft_atoi_pushswap(argv[i]);
			i++;
		}
	}
	else
	{
		return (NULL);
	}
	return (args);
}

//CALLED BY PROCESS_ARGS TO CHECKS THE ARGVS FOR CHAR/DOUBLE SIGNS ETC...
//ALSO CALLED ON ITS OWN FOR RETURNING ERROR IN MAIN
int	args_check(int argc, char **argv)
{
	int			i;
	long int	n;
	int			*a;

	i = 0;
	a = malloc(sizeof(int) * argc);
	while (i < argc)
	{
		if (!args_check_digits(argv, i))
			return (0);
		n = ft_atoi_pushswap(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		a[i] = n;
		i++;
	}
	return (args_check_duplicates(a, argc));
}

int	args_check_digits(char **argv, int i)
{
	int	j;
	int	fu;

	j = 0;
	while (argv[i][j])
	{
		if (!ft_isdigit(argv[i][j]))
		{
			fu = argv[i][j];
			if (j == 0 && (fu == '-' || fu == '+') && ft_isdigit(argv[i][1]))
				j++;
			else
				return (0);
		}
		else
			j++;
	}
	return (1);
}

// CHECKS THE INT ARRAY MADE BY ARGS_CHECKS FOR DUPLICATES
int	args_check_duplicates(int *a, int argc)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < argc)
	{
		while (j < argc)
		{
			if (a[j] == a[i])
				count++;
			if (count > 1)
			{
				return (0);
			}
			j++;
		}
		j = 0;
		count = 0;
		i++;
	}
	free(a);
	return (1);
}
