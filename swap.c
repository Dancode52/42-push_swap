#include "push_swap.h"

void	swap_a(myStack **stack_a)
{
	int temp;

	if (!stack_a || *stack_a || ft_pslstsize(*stack_a) <= 1)
		return ;
	temp = (*stack_a)->number;
	(*stack_a)->number = (*stack_a)->next->number;
	(*stack_a)->next->number = temp;
	write(1, "sa\n", 3);
}

void	swap_b(myStack **stack_b)
{
	int temp;

	if (!stack_b || !*stack_b || ft_pslstsize(*stack_b) <= 1)
		return ;
	temp = (*stack_b)->number;
	(*stack_b)->number = (*stack_b)->next->number;
	(*stack_b)->next->number = temp;
	write(1, "sb\n", 3);
}

void	swaps(myStack **stack_a, myStack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	//write(1, "ss\n", 3);
}


