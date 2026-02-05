/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:36:06 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/05 10:25:59 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = (*b)->next;
	ft_pslstadd_front(a, *b);
	*b = temp;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = (*a)->next;
	ft_pslstadd_front(b, *a);
	*a = temp;
	write(1, "pb\n", 3);
}
