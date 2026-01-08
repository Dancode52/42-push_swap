#include "push_swap.h"

void push_a(myStack **a, myStack **b)
{
	myStack *temp;

	temp = (*b)->next;
	ft_pslstadd_front(a, &b);
	free(*b);
	(*b) = temp;
}

void push_b(myStack **b, myStack **a)
{
	myStack *temp;

	temp = (*a)->next;
	ft_pslstadd_front(b, &a);
	free(*a);
	(*a) = temp;
}
