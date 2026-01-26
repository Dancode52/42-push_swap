/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:35:42 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/26 08:55:34 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_pslstlast(t_stack *lst)
{
	int	i;
	int	end;

	if (!lst)
		return (NULL);
	i = 0;
	end = ft_pslstsize(lst);
	while (i < end - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

t_stack	*ft_pslstnew(int number, int index)
{
	t_stack	*nodetest;

	nodetest = malloc(sizeof(t_stack));
	if (!nodetest)
		return (NULL);
	nodetest->number = number;
	nodetest->position = index;
	nodetest->next = NULL;
	return (nodetest);
}

int	ft_pslstsize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = lst;
	if (!tmp)
		return (0);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
