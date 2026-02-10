/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_check_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:35:25 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/10 11:39:16 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*spaceoremptychecker(char *input, char *tofree)
{
	size_t	i;
	size_t	len;
	size_t	count;

	i = 0;
	len = ft_strlen(input);
	count = 0;
	if (input[0] == '\0')
	{
		free(tofree);
		return (NULL);
	}
	while (input[i])
	{
		if (input[i] == ' ' || input[i] >= 9 && input[i] <= 13)
			count++;
		i++;
	}
	if (count == len)
	{
		free(tofree);
		return (NULL);
	}
	return (input);
}

char	**splitting_input(char *input)
{
	size_t	i;
	char	**res;

	i = 0;
	if (!input)
		return (NULL);
	while (input[i])
	{
		if (input[i] >= 9 && input[i] <= 13)
		{
			free(input);
			write(2, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	res = ft_split(input, ' ');
	if (!res)
		return (NULL);
	return (res);
}

void	input_mallocfail(char *tofree)
{
	free(tofree);
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}
