#include "libft/Headers/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	free_memory(char **badmem)
{
	int	i;

	i = 0;
	while (badmem[i])
	{
		free(badmem[i]);
		i++;
	}
	free(badmem);
	return ;
}

int	find_max_index(myStack *b)
{
	int max_index;
	myStack *temp;

	temp = b;
	max_index = 0;
	while (temp)
	{
		if (temp->position > max_index)
			max_index = temp->position;
		temp = temp->next;
	}
	return (max_index);
}

int	find_min_index(myStack *b)
{
	int min_index;
	myStack *temp;

	temp = b;
	min_index = 0;
	while (temp)
	{
		if (temp->position < min_index)
			min_index = temp->position;
		temp = temp->next;
		min_index++;
	}
	return (min_index);
}

int find_max_position(myStack *stack, int max_index)
{
	int i;
	myStack *temp;

	i = 0;
	temp = stack;
	while (temp)
	{
		if (temp->position == max_index)
			break;
		i++;
		temp = temp->next;
	}
	return (i);
}

void split_stack(myStack **StackA, myStack **StackB, int count)
{
	int max_index;
	int max_pos;
	int sizeA;
	int i;

	i = 0;
	while (i < count / 2)
	{
		sizeA = ft_pslstsize(*StackA);
		max_index = find_max_index(*StackA);
		max_pos = find_max_position(*StackA, max_index);
		if (max_pos > sizeA / 2)
		{
			while ((*StackA)->position != max_index)
				r_rotate_a(StackA);
		}
		else
		{
			while ((*StackA)->position != max_index)
				rotate_a(StackA);
		}
		push_b(StackB, StackA);
		i++;
	}
}

