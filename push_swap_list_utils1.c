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

// void	ft_pslstclear(myStack **lst, void (*del)(void*))
// {
// 	myStack	*save;

// 	if (!lst || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		save = (*lst)->next;
// 		ft_pslstdelone((*lst), del);
// 		(*lst) = save;
// 	}
// }

void	test_clear(myStack **lst)
{
	myStack	*save;

	if (!lst)
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		free(*lst);
		(*lst) = save;
	}
}

// void	ft_pslstdelone(myStack *lst, void (*del)(void*))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->number);
// 	free(lst);
// }

// void	ft_pslstiter(myStack *lst, void (*f)(void *))
// {
// 	if (!lst || !f)
// 		return ;
// 	while (lst)
// 	{
// 		f(lst->number);
// 		lst = lst->next;
// 	}
// }
