/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:35:39 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/06 11:22:04 by dlanehar         ###   ########.fr       */
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

void	create_link_nodes(t_stack **head, int *dig_arr, int nb_of_nbs, int i)
{
	t_stack	*node;
	int		index;

	index = indexer(dig_arr[i], nb_of_nbs, dig_arr);
	node = ft_pslstnew(dig_arr[i], index);
	if (!node)
	{
			free_stack_mem(*head);
			free(dig_arr);
			return ;
	}
	node->size = i;
	ft_pslstadd_back(head, node);
}
