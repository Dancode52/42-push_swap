#include "push_swap.h"
#include <stdio.h>

void sort_two(myStack **StackA)
{
	swap_a(StackA);
}

void sort_three(myStack **StackA)
{
	myStack **temp;
	int max;
	int max_pos;

	temp = StackA;
	max = find_max_index((*temp));
	max_pos = find_max_position(*temp, max);
	while (!check_order(*temp))
	{
		if (max_pos == 0)
			rotate_a(temp);
		if (max_pos == 1)
			r_rotate_a(temp);
		if (check_order(*temp))
			return ;
		else
			swap_a(temp);
		if (check_order(*temp))
			return ;
	}
}

void sort_four(myStack **StackA, myStack **StackB)
{
	int size;
	int max_index;
	int max_pos;

	size = ft_pslstsize(*StackA);
	max_index = find_max_index(*StackA);
	max_pos = find_max_position(*StackA, max_index);
	if (max_pos <= size / 2)
	{
		while ((*StackA)->position != max_index)
			rotate_a(StackA);
	}
	else
	{
		while ((*StackA)->position != max_index)
			r_rotate_a(StackA);
	}
	push_b(StackB, StackA);
	if (!check_order(*StackA))
		sort_three(StackA);
	push_a(StackA, StackB);
	rotate_a(StackA);
}

void sort_five(myStack **StackA, myStack **StackB)
{
	int size;

	size = ft_pslstsize(*StackA);
	split_stack(StackA, StackB, size);
	if (!check_order(*StackA))
		sort_three(StackA);
	if (!check_order(*StackB))
		sort_two(StackB);
	push_a(StackA, StackB);
	rotate_a(StackA);
	push_a(StackA, StackB);
	rotate_a(StackA);
}
