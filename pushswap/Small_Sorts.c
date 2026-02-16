/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Small_Sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:36:17 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/16 10:10:04 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_two(t_stack **StackA)
{
	swap_a(StackA);
}

void	sort_three(t_stack **StackA)
{
	t_stack	**temp;
	size_t	max;
	size_t	max_pos;

	temp = StackA;
	max = find_max_index(temp);
	max_pos = find_max_index_position(temp, max);
	while (!check_order(*temp))
	{
		if (max_pos == 0)
			rotate_a(temp);
		if (max_pos == 1)
			r_rotate_a(temp);
		if (check_order(*temp))
			return ;
		else
			swap_a(temp);
		if (check_order(*temp))
			return ;
	}
}

void	sort_four(t_stack **StackA, t_stack **StackB)
{
	size_t	size;
	size_t	max_index;
	size_t	max_pos;

	size = ft_pslstsize(*StackA);
	max_index = find_max_index(StackA);
	max_pos = find_max_index_position(StackA, max_index);
	if (max_pos <= size / 2)
	{
		while ((*StackA)->index != max_index)
			rotate_a(StackA);
	}
	else
	{
		while ((*StackA)->index != max_index)
			r_rotate_a(StackA);
	}
	push_b(StackB, StackA);
	if (!check_order(*StackA))
		sort_three(StackA);
	push_a(StackA, StackB);
	rotate_a(StackA);
}

void	sort_five(t_stack **StackA, t_stack **StackB)
{
	size_t	size;

	size = ft_pslstsize(*StackA);
	split_stack(StackA, StackB, size);
	if (!check_order(*StackA))
		sort_three(StackA);
	if (!check_order(*StackB))
		sort_two(StackB);
	push_a(StackA, StackB);
	rotate_a(StackA);
	push_a(StackA, StackB);
	rotate_a(StackA);
}
