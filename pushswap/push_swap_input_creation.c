/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_creation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:35:03 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/16 10:09:10 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

char	*join_input(char **strings, int nb_of_strings)
{
	static char	*res = NULL;
	char		*temp;
	char		*temp2;
	int			i;

	i = 1;
	while (i < nb_of_strings)
	{
		if (!spaceoremptychecker(strings[i], res))
			return (NULL);
		temp = ft_strjoin(strings[i], " ");
		if (!temp)
			input_mallocfail(res);
		temp2 = ft_strjoin(res, temp);
		if (!temp2)
			input_mallocfail(res);
		if (res)
			free(res);
		res = temp2;
		free(temp);
		i++;
	}
	return (res);
}

int	*str_array_to_int_array(size_t nb_of_nbs, char **split_input)
{
	int		*digit_array;
	size_t	i;
	int		error;

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

size_t	indexer(int number, size_t nb_of_nbs, int *array)
{
	size_t	i;
	size_t	count;

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

t_stack	*create_stack_a(int *digit_array, size_t nb_of_nbs)
{
	size_t		i;
	t_stack		*head;
	size_t		index;

	i = 0;
	if (!digit_array || !nb_of_nbs)
		return (0);
	index = indexer(digit_array[i], nb_of_nbs, digit_array);
	head = ft_pslstnew(digit_array[i], index);
	if (!head)
	{
		free(digit_array);
		return (NULL);
	}
	i++;
	while (i < nb_of_nbs)
	{
		create_link_nodes(&head, digit_array, nb_of_nbs, i);
		i++;
	}
	free(digit_array);
	return (head);
}

t_stack	*input_creation(int argc, char **argv)
{
	char	*input;
	char	**split_input;
	size_t	nb_of_nbs;
	int		*digit_array;
	t_stack	*stack;

	if (argc < 2)
		exit (EXIT_FAILURE);
	input = join_input(argv, argc);
	split_input = splitting_input(input);
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
