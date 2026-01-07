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
		digit_array[i] = ft_atoi(split_input[i]);
		i++;
	}
	return (digit_array);
}

int *input_creation(int argc, char **argv)
{
	char	*input;
	char	**split_input;
	int		nb_of_nbs;
	int		*digit_array;

	if (argc < 2)
		return (0);
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
	free_memory(split_input);
	if (!dupe_check(digit_array, nb_of_nbs) || check_order(digit_array, nb_of_nbs))
		return (0);
	return (digit_array);
}
