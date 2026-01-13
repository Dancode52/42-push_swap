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

myStack	*ft_pslstnew(int number, int index)
{
	myStack	*nodetest;

	nodetest = malloc(sizeof(myStack));
	if (!nodetest)
		return (NULL);
	nodetest->number = number;
	nodetest->position = index;
	nodetest->next = NULL;
	return (nodetest);
}

int	ft_pslstsize(myStack *lst)
{
	int	i;
	myStack	*tmp;

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

