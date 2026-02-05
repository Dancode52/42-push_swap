/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:35:54 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/05 10:25:38 by dlanehar         ###   ########.fr       */
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

int	find_max_index(t_stack **b)
{
	int		max_index;
	t_stack	*temp;

	temp = *b;
	max_index = 0;
	while (temp)
	{
		if (temp->position > max_index)
			max_index = temp->position;
		temp = temp->next;
	}
	return (max_index);
}

int	find_min_index(t_stack *b)
{
	int		min_index;
	t_stack	*temp;

	temp = b;
	min_index = 0;
	while (temp)
	{
		if (temp->position < min_index)
			min_index = temp->position;
		temp = temp->next;
		min_index++;
	}
	return (min_index);
}

int	find_max_position(t_stack **stack, int max_index)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->position == max_index)
			break ;
		i++;
		temp = temp->next;
	}
	return (i);
}

void	split_stack(t_stack **StackA, t_stack **StackB, int count)
{
	int	max_index;
	int	max_pos;
	int	size_a;
	int	i;

	i = 0;
	while (i < count / 2)
	{
		size_a = ft_pslstsize(*StackA);
		max_index = find_max_index(StackA);
		max_pos = find_max_position(StackA, max_index);
		if (max_pos > size_a / 2)
		{
			while ((*StackA)->position != max_index)
				r_rotate_a(StackA);
		}
		else
		{
			while ((*StackA)->position != max_index)
				rotate_a(StackA);
		}
		push_b(StackB, StackA);
		i++;
	}
}
