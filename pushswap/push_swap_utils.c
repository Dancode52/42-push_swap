/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:35:54 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/08 03:37:17 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/Headers/libft.h"
#include <stdlib.h>
#include "push_swap.h"

void	free_memory(char **badmem)
{
	int	i;

	i = 0;
	while (badmem[i])
	{
		free(badmem[i]);
		i++;
	}
	free(badmem);
	return ;
}

size_t	find_max_index(t_stack **b)
{
	size_t	max_index;
	t_stack	*temp;

	temp = *b;
	max_index = 0;
	while (temp)
	{
		if (temp->index > max_index)
			max_index = temp->index;
		temp = temp->next;
	}
	return (max_index);
}

size_t	find_min_index(t_stack *b)
{
	size_t	min_index;
	t_stack	*temp;

	temp = b;
	min_index = 0;
	while (temp)
	{
		if (temp->index < min_index)
			min_index = temp->index;
		temp = temp->next;
		min_index++;
	}
	return (min_index);
}

size_t	find_max_index_position(t_stack **stack, size_t max_index)
{
	size_t		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->index == max_index)
			break ;
		i++;
		temp = temp->next;
	}
	return (i);
}

void	split_stack(t_stack **StackA, t_stack **StackB, size_t count)
{
	size_t	max_index;
	size_t	max_pos;
	size_t	size_a;
	size_t	i;

	i = 0;
	while (i < count / 2)
	{
		size_a = ft_pslstsize(*StackA);
		max_index = find_max_index(StackA);
		max_pos = find_max_index_position(StackA, max_index);
		if (max_pos > size_a / 2)
		{
			while ((*StackA)->index != max_index)
				r_rotate_a(StackA);
		}
		else
		{
			while ((*StackA)->index != max_index)
				rotate_a(StackA);
		}
		push_b(StackB, StackA);
		i++;
	}
}
