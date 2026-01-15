
#include "libft/Headers/libft.h"
#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>


int	Small_Sorts(myStack **StackA, myStack **StackB)
{
	(void)StackB;
	if (ft_pslstsize(*StackA) == 2)
	{
		sort_two(StackA);
		return (1);
	}
	if (ft_pslstsize(*StackA) == 3)
	{
		sort_three(StackA);
		return (1);
	}
	if (ft_pslstsize(*StackA) == 4)
	{
		sort_four(StackA, StackB);
		return (1);
	}
	if (ft_pslstsize(*StackA) == 5)
	{
		sort_five(StackA, StackB);
		return (1);
	}
	return(0);
}

void	Reintegration_Sort(myStack **StackA, myStack **StackB)
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


void	K_Distribution_Sort(myStack **a, myStack **b)
{
    int n = ft_pslstsize(*a);
    int delta = ((n / 20) + 5);
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

	StackA = input_creation(argc, argv);
	if (!StackA)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	if (check_order(StackA))
	{
		free_stack_mem(StackA);
		return (0);
	}
	StackB = NULL;
	if (Small_Sorts(&StackA, &StackB) == 1)
	{
		free_stack_mem(StackA);
		return (0);
	}
	K_Distribution_Sort(&StackA, &StackB);
	Reintegration_Sort(&StackA, &StackB);
	free_stack_mem(StackA);
	return (0);
}
