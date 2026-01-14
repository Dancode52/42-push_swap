#include "push_swap.h"

void	ft_pslstadd_back(myStack **lst, myStack *new)
{
	myStack	*ptr;

	if (lst != NULL && new != NULL)
	{
		if (*lst != NULL)
		{
			ptr = ft_pslstlast(*lst);
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_pslstadd_front(myStack **lst, myStack *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		new->next = NULL;
	else
		new->next = *lst;
	*lst = new;
}

void	free_stack_mem(myStack *lst)
{
	myStack	*save;

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

