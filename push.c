#include "push_swap.h"

void push_a(myStack **a, myStack **b)
{
	myStack *temp;

	// if (!*b)
	// 	return ;
	temp = (*b)->next;
	ft_pslstadd_front(a, *b);
	*b = temp;
	write(1, "pa\n", 3);
}

void push_b(myStack **b, myStack **a)
{
	myStack *temp;

	// if (!*a)
	// 	return ;
	temp = (*a)->next;
	ft_pslstadd_front(b, *a);
	*a = temp;
	write(1, "pb\n", 3);
}
