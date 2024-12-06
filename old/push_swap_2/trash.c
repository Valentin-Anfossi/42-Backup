/*
int **stack_to_array(elem **stacka)
{
	int** ar;
	
	
}

int *radix_sort(elem **stacka)
{
	elem *sel;
	sel = *stacka;
	int *ar;
	int i;
	i = 0;
		
	while(sel)
	{
		ar[i] = sel->val;
		sel = sel->next;
		i ++;
	}

}
// NEEDS TO USE LOGICFUNCTIONS ?
int max_value(elem **stacka)
{
	int maxval;
	elem *sela;

	sela = *stacka;
	maxval = sela->val;
	while(sela != NULL)
	{
		if (sela->val > maxval)
			maxval = sela->val;
		sela = sela->next;
	}
	return (maxval);
}

int simplesort(elem** stacka, elem **stackb)
{
	int count;
	int maxvalue;
	elem *sela;
	
	count = 0;
	maxvalue = max_value(stacka);
	sela = *stacka;
	while(sela->val != maxvalue)
	{
		ra(stacka);
		count ++;
		sela = *stacka;
	}
	pb(stacka,stackb);
	count ++;
	return (count);
}

int index_stack(elem **stacka)
{
	int minval;
	minval = (*stacka)->val;
	while(*stacka != NULL)
	{
			if((*stacka)->val < minval)
				minval = (*stacka)->val;
			*stacka = (*stacka)->next;
	}
}
int pivotsortrec(elem **stacka, elem** stackb)
{
	int piv;
	int sorted;

	sorted = 0;
	piv = (*stacka)->val;
	pb(stacka,stackb);
	
	while(*stacka != NULL)
	{
		if((*stacka)->val > piv && (*stacka)->next != NULL)
		{
			pb(stacka,stackb);
		}
		else if((*stacka)->next != NULL)
		{
			ra(stacka);
		}
		else
			return(0);
	}
}
// int pivotsort(elem **stacka, elem **stackb)
// {
// 	int pivot;
// 	int len;

// 	pivot = (*stacka)->val;
// 	len = length_stack(stacka);
// 	ra(stacka);
// 	while((*stacka)->val != pivot)
// 	{
// 		if((*stacka)->val < pivot)
// 		{
// 			pb(stacka,stackb);
// 		}
// 		else
// 			ra(stacka);
// 	}
// 	pb(stacka,stackb);
// }

*/