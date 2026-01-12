
#include "libft/Headers/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

static void print_list(myStack *list)
{
	while (list)
	{
		printf("List value is: %i\n", list->number);
		printf("List position is: %f\n", list->position);
		list = list->next;
	}
}

// int	find_max_index(myStack *b)
// {
// 	myStack *tempo;
// 	int temp;
// 	int i;
// 	int position;

// 	tempo = b;
// 	temp = 0;
// 	i = 0;
// 	while (tempo->next != NULL || tempo->number > temp)
// 	{
// 		if (tempo->number > temp)
// 		{
// 			temp = tempo->number;
// 			position = i;
// 		}
// 		tempo = tempo->next;
// 		i++;
// 	}
// 	return (position);
// }


void K_Distribution_Sort(myStack **a, myStack **b)
{
    int n = ft_pslstsize(*a);
	printf("a is %i long\n", n);
    int delta = ((n / 20) + 7);
    int threshold = 0;
    while (*a)
    {
        if (((*a)->position) <= (threshold + delta))
        {
            push_b(b, a);
            if ((*b)->position <= threshold)
                rotate_b(b);        // rb
            threshold++;
        }
        else
        {
            rotate_a(a);            // ra
        }
    }
}

int	main(int argc, char **argv)
{
	myStack *StackA;
	myStack *StackB;

	if (argc < 3)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	StackA = input_creation(argc, argv);
	StackB = NULL;
	if (!StackA)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	print_list(StackA);
	K_Distribution_Sort(&StackA, &StackB);
	print_list(StackB);
	test_clear(&StackA);
	test_clear(&StackB);
	printf("Mundo PUSHswap PUSHswap PUSHswap\n");
	return (0);
}
