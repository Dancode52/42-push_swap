#include "push_swap.h"

void	swap_a(myStack **stack_a)
{
	int temp;

	temp = (*stack_a)->number;
	(*stack_a)->number = (*stack_a)->next->number;
	(*stack_a)->next->number = temp;
	write(1, "sa", 2);
}

void	swap_b(myStack **stack_b)
{
	int temp;

	temp = (*stack_b)->number;
	(*stack_b)->number = (*stack_b)->next->number;
	(*stack_b)->next->number = temp;
	write(1, "sb", 2);
}

void	swaps(myStack **stack_a, myStack **stack_b)
{
	swap_a(&stack_a);
	swap_b(&stack_b);
	write(1, "ss", 2);
}


