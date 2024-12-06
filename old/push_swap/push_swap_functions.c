/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:02:40 by vanfossi          #+#    #+#             */
/*   Updated: 2024/11/25 15:43:08 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(int *a, int *b)
{
	int temp;
	temp = 0;

	temp = a[0];
	a[0] = a[1];
	a[1] = a[0];
}
void sb(int *a, int *b)
{
	int temp;
	temp = 0;

	temp = b[0];
	b[0] = b[1];
	b[1] = b[0];
}
void ss(int *a, int *b)
{
	void sa(int *a, int *b);
	void sb(int *a, int *b);
}
void pa(int *a, int *b)
{
	if(b[0] == 0 && b[1] == 0)
		return;
	rra(a,b);
	a[0] = b[0];
	rb(a,b);
}
void pb(int *a, int *b)
{
	if(a[0] == 0 && a[1] == 0)
		return;
	rrb(a,b);
	b[0] = a[0];
	ra(a,b);	
}