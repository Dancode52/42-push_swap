/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:36:15 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/26 08:56:09 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp1;

	if (!stack || !*stack)
		return ;
	temp1 = (*stack)->next;
	ft_pslstadd_back(stack, (*stack));
	(*stack)->next = NULL;
	(*stack) = temp1;
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rrotate(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
