/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanfossi <vanfossi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:18:49 by vanfossi          #+#    #+#             */
/*   Updated: 2024/12/03 13:10:09 by vanfossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int array_length(int *ar)
{
	int i;

	i = 0;	
	while(ar[i])
		i++;
	return(i);
}
void index_elems(elem *stacka, int *stackc)
{
	elem *tmp;
	int i;
	
	i = 0;
	tmp = stacka;
	while(tmp)
	{
		while(stackc[i])
		{
			if(stackc[i] == tmp->val)
			{
				tmp->index = i;
				break;
			}
			i ++;
		}
		i = 0;
		tmp = tmp->next;
	}
}

int get_element_position(elem *stack, int target_index) {
    elem *current = stack;
    int position = 0;
    while (current) {
        if (current->index == target_index) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}
int *stack_to_int(elem *stacka)
{
	int i;
	elem *tmp;
	int *ar;

	i = 0;
	tmp = stacka;
	ar = malloc(sizeof(int) * length_stack(stacka));
	if(!ar)
		return (0);
	while(tmp != NULL)
	{
		ar[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	//ar[i] = tmp->val;
	// i ++;
	// ar[i] = NULL;
	return (ar);
}
//INSERTION SORTING OF THE INT ARRAY
void int_sort(int *ar, int arlen)
{
    int i;
    int j;
    int comp;
    
    i = 1;
    while(i < arlen)
    {
        comp = ar[i];
        j = i - 1;
        while(j >= 0 && ar[j] > comp)
        {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = comp;
        i++;
    }
}
elem *get_stack_median(elem *stack)
{
	elem* temp;
	int *stackc;
	stackc = stack_to_int(stack);
	
	int i;
	i = 0;
	//printf("%d,",length_stack(stack));
	// while(stackc[i] < length_stack(stack))
	// {
	// 	printf("%d ",stackc[i]);
	// 	i ++;
	// }
	int_sort(stackc,length_stack(stack));
	index_elems(stack,stackc);
	int median = stackc[length_stack(stack)/2];
	temp = stack;
	while(temp != NULL)
	{
		if(temp->val == median)
			return (temp);
		else
			temp = temp->next;
	}
	return (0);
}

int get_pos(elem *el)
{
    int pos;
    elem *tmp;
   
    pos = 0;
    tmp = el;
    while (tmp)
    {
        if (pos == 0 && !tmp->prev)
            return 0;
        tmp = tmp->prev;
        pos++;
    }
    return (pos-1);
}

int get_cost_to_top(elem *stack, elem *el)
{
   int pos;
   int len;
   int r;
   
   if (!stack || !el)
       return (0);
   pos = get_pos(el);
   len = length_stack(stack);
   if (pos > len / 2)
       r = pos - len;
   else
       r = pos;
   return (r);
}
elem *find_closest_elem(elem *stack, elem *e)
{
	int val;
	elem *tmp;
	
	val = e->index;
	tmp = stack;
	while(tmp)
	{
		if(tmp->index == val+1)
			return(tmp);
		tmp = tmp->next;
	}
	return(NULL);
}
elem *find_closest_elem_r(elem *stack, elem *e)
{
	int val;
	elem *tmp;
	
	val = e->index;
	tmp = stack;
	while(tmp)
	{
		if(tmp->index == val-1)
			return(tmp);
		tmp = tmp->next;
	}
	return(NULL);
}
int *calculate_cost(elem *stacka, elem *stackb)
{
	elem *a;
	elem *b;
	elem *closest;
	int pos;
	int cost_ar[2];	
	
	a = stacka;
	b = stackb;

	while(b)
	{
		b -> costb = get_cost_to_top(stackb,b);	
		b -> costa = get_cost_to_top(stacka,find_closest_elem(stacka,b));
		if(!find_closest_elem(stacka,b))
			b->costa = length_stack(stackb);
		if(find_closest_elem_r(stacka,b))
			b->costa = get_cost_to_top(stacka,find_closest_elem_r(stacka,b))+1;
		//printf("val : %d, index : %d, costa: %d, costb : %d total cost = %d\n",b->val,b->index,b->costa,b->costb,ft_abs(b->costa)+ft_abs(b->costb));
		b = b->next;
	}
}
int ft_abs(int n)
{
	if(n < 0)
		return(n * -1);
	else
		return(n);
}

elem *find_cheapest(elem **stack)
{
	elem *tmp;
	elem *cheapest;
	int cost;
	int cheapest_cost;
	
	tmp = *stack;
	cheapest = *stack;
	cheapest_cost = 9999999;
	cost = 0;

	while(tmp)
	{
		cost = ft_abs(tmp->costa) + ft_abs(tmp->costb);
		//printf("test %d cost:%d/ ",tmp->val,cost);
		if(cost < cheapest_cost)
		{
			cheapest_cost = cost;
			cheapest = tmp;
		}
		tmp = tmp->next; 		
	}
	return(cheapest);
}
//HEEHEE
void do_the_moves(elem *el,elem **stacka, elem **stackb)
{
	int amoves;
	int bmoves;

	amoves = el->costa;
	bmoves = el->costb;
		//printf("\namoves %d, bmoves %d\n",amoves,bmoves);
	while(amoves != 0 || bmoves != 0)
	{
		// if(amoves > 0 && bmoves > 0)
		// {
		// 	rr(stacka,stackb);
		// 	amoves --;
		// 	bmoves --;
		// }
		// else if(amoves < 0 && bmoves < 0)
		// {
		// 	rrr(stacka,stackb);
		// 	amoves ++;
		// 	bmoves ++;
		// }
		if(amoves > 0)
		{
			ra(stacka);
			printf("ra\n");
			amoves --;
		}
		else if(amoves < 0)
		{
			rra(stacka);
			printf("rra\n");
			amoves ++;
		}	
		else if(bmoves > 0)
		{
			rb(stackb);
			printf("rb\n");
			bmoves --;
		}
		else if(bmoves < 0)
		{
			rrb(stackb);
			printf("rrb\n");
			bmoves ++;
		}	
	}
	pa(stacka,stackb);
	printf("pa\n");
}

void main_sort(elem **stacka,elem **stackb)
{
	//"SMART" INSERT OF CHEAPEST ELEMENT AFTER MEDIAN SPLIT (AAAAAAAAAH)
	//FIND MEDIAN OF STACKA

	//FIND A WAY TO GET CLOSEST ELEMENT WITH A LOWER VALUE AS WELL (RN ITS ONLY THE ONE HIGHER THATS FOUND)
	//DEAL WITH 0
	int median = get_stack_median(*stacka)->val;
	int selected_index;
	//printf("%d",median);
	while(length_stack(*stacka))
	{
		//printStacks(*stacka,*stackb);
		selected_index = (*stacka)->index;
		if((*stacka)->val > median)
		{
			pb(stacka,stackb);
			printf("pb\n");
		}
		else
		{
			pb(stacka,stackb);
			printf("pb\n");
			rb(stackb);
			printf("rb\n");
		}
	}
	printf("PRESORTINGDONE\n");
	pa(stacka,stackb);
	int i = 0;
	//printStacks(*stacka,*stackb);
	while(*stackb)
	{
		//printStacks(*stacka,*stackb);
		calculate_cost(*stacka,*stackb);
		do_the_moves(find_cheapest(stackb),stacka,stackb);		
		i ++;
	}

	//calculate_cost(*stacka,*stackb);


printStacks(*stacka, *stackb);

		// elem *cheapest_elem = find_cheapest(*stackb);
		//FIND CHEAPEST
		//EXECUTE ITS MOVE COSTS

}
int selection_sort(elem **stacka, elem **stackb)
{
	main_sort(stacka,stackb);
}