/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:36:12 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/29 10:15:50 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	revrotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*beforelast;

	if (!stack || !*stack || !(*stack)->next)
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

void	r_rotate_a(t_stack **a)
{
	revrotate(a);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **b)
{
	revrotate(b);
	write(1, "rrb\n", 4);
}

void	rr_rotate(t_stack **a, t_stack **b)
{
	revrotate(a);
	revrotate(b);
	write(1, "rrr\n", 4);
}
