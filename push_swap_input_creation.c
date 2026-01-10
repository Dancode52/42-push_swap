#include "libft/Headers/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

char	*join_input(char **strings, int nb_of_strings)
{
	static char *res;
	char *temp;
	char *temp2;
	int i;

	i = 1;
	while (i < nb_of_strings)
	{
		temp = ft_strjoin(strings[i], " ");
		if (!temp)
			return (NULL);
		temp2 = ft_strjoin(res, temp);
		if (!temp2)
			return (NULL);
		if (res)
			free(res);
		res = ft_strdup(temp2);
		free(temp);
		free(temp2);
		i++;
	}
	return(res);
}

int	*str_array_to_int_array(int nb_of_nbs, char **split_input)
{
	int	*digit_array;
	int	i;

	digit_array = (int *)malloc(nb_of_nbs * sizeof(int));
	if (!digit_array)
		return (0);
	i = 0;
	while (i < nb_of_nbs)
	{
		digit_array[i] = ft_atoi(split_input[i]); //try replacing this with our psatoi function.
		i++;
	}
	free_memory(split_input);
	return (digit_array);
}

myStack *create_stack_a(int *digit_array, int nb_of_nbs)
{
	int i;
	myStack *head;
	myStack *stacks;

	i = 0;
	head = ft_pslstnew(digit_array[i]);
	i++;
	while (i < nb_of_nbs)
	{
		stacks = ft_pslstnew(digit_array[i]);
		ft_pslstadd_back(&head, stacks);
		i++;
	}
	free(digit_array);
	return (head);

}

myStack *input_creation(int argc, char **argv)
{
	char	*input;
	char	**split_input;
	int		nb_of_nbs;
	int		*digit_array;
	myStack	*stack;

	input = join_input(argv, argc);
	split_input = ft_split(input, ' ');
	if (!split_input)
		return (0);
	free(input);
	nb_of_nbs = input_check(split_input);
	if (nb_of_nbs == 0)
	{
		free_memory(split_input);
		return (0);
	}
	digit_array = str_array_to_int_array(nb_of_nbs, split_input);
	//free_memory(split_input);
	if (!dupe_check(digit_array, nb_of_nbs) || check_order(digit_array, nb_of_nbs))
		return (0);
	stack = create_stack_a(digit_array, nb_of_nbs);
	return (stack);
}

int	ft_atoi_limit_check(const char *str, int *error) //psatoi
{

	int	i;
	int	nb;
	int	s;

	i = 0;
	nb = 0;
	s = 1;
	if (str[i] == '-')
		s = s * -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * s);

}
