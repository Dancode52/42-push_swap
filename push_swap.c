
#include "libft/Headers/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void print_list(myStack *list)
{
	while (list)
	{
		printf("List value is: %i\n", list->number);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	myStack *StackA;

	StackA = input_creation(argc, argv);
	if (!StackA)
		return (0);
	print_list(StackA);
	test_clear(&StackA);
	printf("Mundo PUSHswap PUSHswap PUSHswap\n");
	return (0);
}
