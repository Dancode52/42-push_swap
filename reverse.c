#include "push_swap.h"
#include <stdio.h>

void r_rotate_a(myStack **a)
{
	myStack *last;
	myStack *beforelast;

	last = *a;
	while (last->next != NULL)
	{
		beforelast = last;
		last = last->next;
	}
	beforelast->next = NULL;
	ft_pslstadd_front(a, last);
	write(1, "rra\n", 4);
}

void r_rotate_b(myStack **b)
{
	myStack *last;
	myStack *beforelast;

	last = *b;
	while (last->next != NULL)
	{
		beforelast = last;
		last = last->next;
	}
	beforelast->next = NULL;
	ft_pslstadd_front(b, last);
	write(1, "rrb\n", 4);
}

void rr_rotate(myStack **a, myStack **b)
{
	r_rotate_a(a);
	r_rotate_b(b);
	write(1, "we also did rrb btw :) \n", 25);
}
