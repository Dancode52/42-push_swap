#include "push_swap.h"

static void	rotate(myStack **stack)
{
	myStack *temp1;

	if (!stack || !*stack)
		return ;
	temp1 = (*stack)->next;
	ft_pslstadd_back(stack, (*stack));
	(*stack)->next = NULL;
	(*stack) = temp1;

}

void	rotate_a(myStack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
	// myStack *temp1;

	// if (!a || !*a)
	// 	return ;
	// temp1 = (*a)->next;
	// ft_pslstadd_back(a, (*a));
	// (*a)->next = NULL;
	// (*a) = temp1;
}

void	rotate_b(myStack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
	// myStack *temp1;

	// if (!b || !*b)
	// 	return ;
	// if (ft_pslstsize(*b) <=1 )
	// 	return ;
	// temp1 = (*b)->next;
	// ft_pslstadd_back(b, (*b));
	// (*b)->next = NULL;
	// (*b) = temp1;
}

void	rrotate(myStack **a, myStack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n",3);
}
