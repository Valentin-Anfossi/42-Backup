/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:10:52 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/06 04:20:17 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SORTS THE N LENGTH ARRAY ARR
void array_sort(int arr[], int N) 
{
	int i;

	i = 1;
    while (i < N) 
	{
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
		i++;
    }
}

int *stack_to_array(s_stack **stack)
{
	int i;
	int *ar;
	s_stack *tmp;
	
	i = 0;
	tmp = *stack;
	ar = malloc(sizeof(int) * stack_size(stack));
	if(!ar)
		return (0);
	if(tmp->next == tmp)
	{
		ar[0] = tmp->val;
		return(ar);
	}
	while(tmp)
	{
		ar[i] = tmp->val;
		tmp = tmp->next;
		i++;
		if(tmp == *stack)
			break;
	}
	return (ar);
}