/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_check_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:35:25 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/28 15:38:24 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spaceoremptychecker(char *input)
{
	int	i;
	int	len;
	int	count;

	i = 0;
	len = ft_strlen(input);
	count = 0;
	if (input[0] == '\0')
	{
		write(2, "Error\n", 7);
		exit (EXIT_FAILURE);
	}
	while (input[i])
	{
		if (input[i] == ' ')
			count++;
		i++;
	}
	if (count != len)
		return ;
	else
	{
		write(2, "Error\n", 7);
		exit (EXIT_FAILURE);
	}
}
