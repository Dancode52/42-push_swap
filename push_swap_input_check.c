/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 08:45:04 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/16 02:42:56 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/Headers/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

static int	only_digits(char **split_input, int i, int j)
{
	if ((ft_isdigit(split_input[i][j]) && (ft_isdigit(split_input[i][j + 1])
		|| split_input[i][j + 1] == '\0')))
		return (1);
	else
		return (0);
}

static int	plus_minus_check(char **split_input, int i, int j)
{
	if (((split_input[i][j] == '+' || split_input[i][j] == '-')
		&& split_input[i][j + 1] != '\0'
		&& ft_isdigit(split_input[i][j + 1])))
		return (1);
	else
		return (0);
}

int	input_check(char **split_input)
{
	int	i;
	int	j;

	i = 0;
	while (split_input[i])
	{
		j = 0;
		while (split_input[i][j])
		{
			if (only_digits(split_input, i, j)
				|| plus_minus_check(split_input, i, j))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (i);
}

int	dupe_check(int *digit_array, int nb_of_nbs)
{
	int	i;
	int	j;

	i = 0;
	if (!digit_array)
		return (0);
	while (i < nb_of_nbs)
	{
		j = i + 1;
		while (j < nb_of_nbs)
		{
			if (digit_array[i] == digit_array[j])
			{
				free(digit_array);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_order(myStack *stack)
{
	myStack	*temp;

	temp = stack;
	if (!temp)
		return (0);
	while (temp->next)
	{
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}
