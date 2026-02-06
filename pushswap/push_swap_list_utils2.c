/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:35:42 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/06 16:02:42 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_pslstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack	*ft_pslstnew(int number, size_t index)
{
	t_stack	*nodetest;

	nodetest = malloc(sizeof(t_stack));
	if (!nodetest)
		return (NULL);
	nodetest->number = number;
	nodetest->index = index;
	nodetest->next = NULL;
	return (nodetest);
}

size_t	ft_pslstsize(t_stack *lst)
{
	size_t		i;
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
