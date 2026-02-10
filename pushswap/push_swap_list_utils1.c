/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:35:39 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/10 11:29:26 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pslstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (lst != NULL && new != NULL)
	{
		if (*lst != NULL)
		{
			ptr = ft_pslstlast((*lst));
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_pslstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		new->next = NULL;
	else
		new->next = *lst;
	*lst = new;
}

void	free_stack_mem(t_stack *lst)
{
	t_stack	*save;

	if (!lst)
		return ;
	while (lst)
	{
		save = lst->next;
		free(lst);
		lst = save;
	}
	free(lst);
}

void	create_link_nodes(t_stack **head, int *dig_ar, size_t n_nbs, size_t i)
{
	t_stack	*node;
	size_t	index;

	index = indexer(dig_ar[i], n_nbs, dig_ar);
	node = ft_pslstnew(dig_ar[i], index);
	if (!node)
	{
		free_stack_mem(*head);
		free(dig_ar);
		return ;
	}
	ft_pslstadd_back(head, node);
}
