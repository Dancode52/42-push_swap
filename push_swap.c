
#include "libft/Headers/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

static void print_list(myStack *list)
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
	myStack *StackB;

	StackA = input_creation(argc, argv);
	StackB = NULL;
	if (!StackA)
		return (0);
	print_list(StackA);
	write(1, "Now Swap!\n", 11);
	swap_a(&StackA);
	print_list(StackA);
	write(1, "Now Rotate!\n", 13);
	rotate_a(&StackA);
	print_list(StackA);
	write(1, "Now Reverse Rotate!\n", 21);
	r_rotate_a(&StackA);
	print_list(StackA);
	rr_rotate(&StackA);
	print_list(StackA);
	test_clear(&StackA);
	printf("Mundo PUSHswap PUSHswap PUSHswap\n");
	return (0);
}
