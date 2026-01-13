
#include "libft/Headers/libft.h"
#include <stdlib.h>
#include "push_swap.h"

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

void Reintegration_Sort(myStack **StackA, myStack **StackB)
{
	int max_index;
	int pos;
	int size;

	while (*StackB)
	{
		max_index = find_max_index(*StackB);
		pos = find_max_position(*StackB, max_index);
		size = ft_pslstsize(*StackB);
		if (pos <= size / 2)
		{
			while ((*StackB)->position != max_index)
				rotate_b(StackB);
		}
		else
		{
			while ((*StackB)->position != max_index)
				r_rotate_b(StackB);
		}
		push_a(StackA, StackB);
	}
}


void K_Distribution_Sort(myStack **a, myStack **b)
{
    int n = ft_pslstsize(*a);
    int delta = ((n / 20) + 7);
    int threshold = 0;
    while (*a)
    {
        if (((*a)->position) <= (threshold + delta))
        {
            push_b(b, a);
            if ((*b)->position <= threshold)
                rotate_b(b);
            threshold++;
        }
        else
        {
            rotate_a(a);
        }
    }
}


int	main(int argc, char **argv)
{
	myStack *StackA;
	myStack *StackB;

	if (argc < 2)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	StackA = input_creation(argc, argv);
	if (check_order(StackA))
	{
		test_clear(&StackA);
		return (0);
	}
	StackB = NULL;
	if (!StackA)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	K_Distribution_Sort(&StackA, &StackB);
	Reintegration_Sort(&StackA, &StackB);
	test_clear(&StackA);
	test_clear(&StackB);
	return (0);
}
