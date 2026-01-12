#include "push_swap.h"

void rotate_a(myStack **a)
{
	myStack *temp1;

	if (!a || !*a)
		return ;
	temp1 = (*a)->next;
	ft_pslstadd_back(a, (*a));
	(*a)->next = NULL;
	(*a) = temp1;
	write(2, "ra\n", 3);
}

void rotate_b(myStack **b)
{
	myStack *temp1;

	if (!b || !*b)
		return ;
	temp1 = (*b)->next;
	ft_pslstadd_back(b, (*b));
	(*b)->next = NULL;
	(*b) = temp1;
	write(2, "rb\n", 3);
}

void	rrotate(myStack **a, myStack **b)
{
	rotate_a(a);
	rotate_b(b);
	write(2, "rr\n",3);
}
