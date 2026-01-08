#include "push_swap.h"

myStack	*ft_pslstlast(myStack *lst)
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

// myStack	*ft_pslstmap(myStack *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	myStack	*newlst;
// 	myStack	*newptr;
// 	void	*i;

// 	newlst = NULL;
// 	if (!lst || !f || !del)
// 		return (NULL);
// 	while (lst)
// 	{
// 		i = f(lst->number);
// 		newptr = ft_pslstnew(i);
// 		if (newptr == NULL)
// 		{
// 			del(i);
// 			ft_pslstclear(&newlst, del);
// 			newlst = NULL;
// 			return (NULL);
// 		}
// 		ft_pslstadd_back(&newlst, newptr);
// 		lst = lst->next;
// 	}
// 	return (newlst);
// }

myStack	*ft_pslstnew(int number)
{
	myStack	*nodetest;

	nodetest = malloc(sizeof(myStack));
	if (!nodetest)
		return (NULL);
	nodetest->number = number;
	nodetest->next = NULL;
	return (nodetest);
}

int	ft_pslstsize(myStack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

