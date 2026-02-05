/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:35:39 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/29 12:47:29 by dlanehar         ###   ########.fr       */
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
