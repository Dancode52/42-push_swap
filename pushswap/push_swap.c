/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:35:58 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/08 03:38:57 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/Headers/libft.h"
#include <stdlib.h>
#include "push_swap.h"

int	small_sorts(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	if (ft_pslstsize(*stack_a) == 2)
	{
		sort_two(stack_a);
		return (1);
	}
	if (ft_pslstsize(*stack_a) == 3)
	{
		sort_three(stack_a);
		return (1);
	}
	if (ft_pslstsize(*stack_a) == 4)
	{
		sort_four(stack_a, stack_b);
		return (1);
	}
	if (ft_pslstsize(*stack_a) == 5)
	{
		sort_five(stack_a, stack_b);
		return (1);
	}
	return (0);
}

void	reintegration_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	max_index;
	size_t	pos;
	size_t	size;

	while (*stack_b)
	{
		max_index = find_max_index(stack_b);
		pos = find_max_index_position(stack_b, max_index);
		size = ft_pslstsize(*stack_b);
		if (pos <= size / 2)
		{
			while ((*stack_b)->index != max_index)
				rotate_b(stack_b);
		}
		else
		{
			while ((*stack_b)->index != max_index)
				r_rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
	}
}

void	k_distribution_sort(t_stack **a, t_stack **b)
{
	size_t	n;
	size_t	delta;
	size_t	threshold;

	n = ft_pslstsize(*a);
	delta = ((n / 20) + 7);
	threshold = 0;
	while (*a)
	{
		if (((*a)->index) <= (threshold + delta))
		{
			push_b(b, a);
			if ((*b)->index <= threshold)
				rotate_b(b);
			threshold++;
		}
		else
		{
			rotate_a(a);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = input_creation(argc, argv);
	stack_b = NULL;
	if (!stack_a)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	if (check_order(stack_a))
	{
		free_stack_mem(stack_a);
		return (0);
	}
	if (small_sorts(&stack_a, &stack_b) == 1)
	{
		free_stack_mem(stack_a);
		return (0);
	}
	k_distribution_sort(&stack_a, &stack_b);
	reintegration_sort(&stack_a, &stack_b);
	free_stack_mem(stack_a);
	return (0);
}
