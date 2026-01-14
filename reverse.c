#include "push_swap.h"
#include <stdio.h>

static void revrotate(myStack **stack)
{
	myStack *last;
	myStack *beforelast;

	if (!stack || !*stack)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		beforelast = last;
		last = last->next;
	}
	beforelast->next = NULL;
	ft_pslstadd_front(stack, last);
}

void r_rotate_a(myStack **a)
{
	revrotate(a);
	write(1, "rra\n", 4);
	// myStack *last;
	// myStack *beforelast;

	// if (!a || !*a)
	// 	return ;
	// last = *a;
	// while (last->next != NULL)
	// {
	// 	beforelast = last;
	// 	last = last->next;
	// }
	// beforelast->next = NULL;
	// ft_pslstadd_front(a, last);
}

void r_rotate_b(myStack **b)
{
	revrotate(b);
	write(1, "rrb\n", 4);
	// myStack *last;
	// myStack *beforelast;

	// if (!b || !*b)
	// 	return ;
	// last = *b;
	// while (last->next != NULL)
	// {
	// 	beforelast = last;
	// 	last = last->next;
	// }
	// beforelast->next = NULL;
	// ft_pslstadd_front(b, last);
}

void rr_rotate(myStack **a, myStack **b)
{
	revrotate(a);
	revrotate(b);
	write(1, "rrr\n", 4);
}
