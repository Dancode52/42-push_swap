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
		printf("Inside join_input: temp = %s\n", temp);
		temp2 = ft_strjoin(res, temp);
	//	printf("Inside join_input: temp2 = %s\n", temp2);
		if (res)
			free(res);
		res = ft_strdup(temp2);
		printf("inside join_input: res = %s\n", res);
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
		printf("Made digit %i from string %s\n", digit_array[i], split_input[i]);
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
	digit_array = str_array_to_int_array(nb_of_nbs, split_input);
	free_memory(split_input);
	return (digit_array);
}
