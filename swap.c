#include "push_swap.h"

void	swap_a(struct myStack **stack_a)
{
	int temp;

	temp = (*stack_a)->number;
	(*stack_a)->number = (*stack_a)->next->number;
	(*stack_a)->next->number = temp;
}


