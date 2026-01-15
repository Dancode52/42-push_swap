#include "push_swap.h"

static void	swap(myStack **stack)
{
	int temp;

	if (!stack || !*stack || ft_pslstsize(*stack) <= 1)
		return ;
	temp = (*stack)->number;
	(*stack)->number = (*stack)->next->number;
	(*stack)->next->number = temp;
}

void	swap_a(myStack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(myStack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	swaps(myStack **stack_a, myStack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}


