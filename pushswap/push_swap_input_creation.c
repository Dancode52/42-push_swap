/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_creation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:35:03 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/05 10:25:35 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/Headers/libft.h"
#include <stdlib.h>
#include "push_swap.h"

char	*join_input(char **strings, int nb_of_strings)
{
	static char	*res;
	char		*temp;
	char		*temp2;
	int			i;

	i = 1;
	while (i < nb_of_strings)
	{
		spaceoremptychecker(strings[i]);
		temp = ft_strjoin(strings[i], " ");
		if (!temp)
			return (NULL);
		temp2 = ft_strjoin(res, temp);
		if (!temp2)
			return (NULL);
		if (res)
			free(res);
		res = ft_strdup(temp2);
		free(temp);
		free(temp2);
		i++;
	}
	return (res);
}

int	*str_array_to_int_array(int nb_of_nbs, char **split_input)
{
	int	*digit_array;
	int	i;
	int	error;

	error = 0;
	digit_array = (int *)malloc(nb_of_nbs * sizeof(int));
	if (!digit_array)
		return (0);
	i = 0;
	while (i < nb_of_nbs)
	{
		digit_array[i] = ft_atoi_limit_check(split_input[i], &error);
		if (error == -2)
		{
			free_memory(split_input);
			free(digit_array);
			return (0);
		}
		i++;
	}
	free_memory(split_input);
	return (digit_array);
}

int	indexer(int number, int nb_of_nbs, int *array)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < nb_of_nbs)
	{
		if (number > array[i])
			count++;
		i++;
	}
	return (count);
}

t_stack	*create_stack_a(int *digit_array, int nb_of_nbs)
{
	int		i;
	t_stack	*head;
	t_stack	*stacks;
	int		index;

	i = 0;
	if (!digit_array)
	{
		return (0);
	}
	index = indexer(digit_array[i], nb_of_nbs, digit_array);
	head = ft_pslstnew(digit_array[i], index);
	head->size = i;
	i++;
	while (i < nb_of_nbs)
	{
		index = indexer(digit_array[i], nb_of_nbs, digit_array);
		stacks = ft_pslstnew(digit_array[i], index);
		stacks->size = i;
		ft_pslstadd_back(&head, stacks);
		i++;
	}
	free(digit_array);
	return (head);
}

t_stack	*input_creation(int argc, char **argv)
{
	char	*input;
	char	**split_input;
	int		nb_of_nbs;
	int		*digit_array;
	t_stack	*stack;

	if (argc < 2)
		exit (EXIT_FAILURE);
	input = join_input(argv, argc);
	split_input = ft_split(input, ' ');
	if (!split_input)
		return (0);
	free(input);
	nb_of_nbs = input_check(split_input);
	if (nb_of_nbs == 0)
	{
		free_memory(split_input);
		return (0);
	}
	digit_array = str_array_to_int_array(nb_of_nbs, split_input);
	if (!dupe_check(digit_array, nb_of_nbs))
		return (0);
	stack = create_stack_a(digit_array, nb_of_nbs);
	return (stack);
}
