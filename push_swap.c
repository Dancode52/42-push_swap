
#include "libft/Headers/libft.h"
#include <stdio.h>
#include <stdlib.h>

int	input_check(int argc, char **split_input)
{
	int i;
	int j;

	i = 1;
	if (argc < 2)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	while (split_input[i])
	{
		j = 0;
		while (split_input[i][j])
		{
			if ((ft_isdigit(split_input[i][j]) && (split_input[i][j + 1] == '\0' || ft_isdigit(split_input[i][j + 1]))) || ((split_input[i][j] == '+'
			|| split_input[i][j] == '-') && ft_isdigit(split_input[i][j + 1])))
				j++;
			else
			{
				write(1, "Error\n", 7);
				return (0);
			}
		}
		i++;
	}
	return(1);
}


static void	free_memory(char **badmem)
{
	int	i;

	i = 0;
	while (badmem[i])
	{
		free(badmem[i]);
		i++;
	}
	free(badmem);
	return ;
}

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

int	main(int argc, char **argv)
{
	char *input;
	char **split_input;
	int i;
	int	min_max_compare;
	// join the inputs together into a single string
	input = join_input(argv, argc);
	printf("String created: %s\n", input);

	// split them all into an array
	split_input = ft_split(input, ' ');
	free(input);
	if (!input_check(argc, split_input))
	{
		free_memory(split_input);
		return (0);
	}
	printf("Made it through input check func\n");
	//check each string to see if it is a valid input
	i = 0;
	while (split_input[i])
	{
		printf("%s\n", split_input[i]);
		i++;
	}
	// while (split_input[i])
	// {
	// 	if (ft_strlen(split_input[i]) == 1 && !ft_isdigit(split_input[i][0]))
	// 	{
	// 		write(2, "Error\n", 7);
	// 		free_memory(split_input);
	// 		return (0);
	// 	}
	// 	if ((split_input[i][0] == '+' || split_input[i][0] == '-') && !ft_isdigit(split_input[i][1]))
	// 	{
	// 		write(2, "Error\n", 7);
	// 		free_memory(split_input);
	// 		return (0);
	// 	}
	// 	if (ft_strlen(split_input[i]) > ft_strlen("-2147483648"))
	// 	{
	// 		write(2, "Error\n", 7);
	// 		//printf("i value: %i.\nInvalid input: %s\n", i, split_input[i]);
	// 		free_memory(split_input);
	// 		return (0);
	// 	}
	// 	if (ft_strlen(split_input[i]) == ft_strlen("-2147483648") && !((split_input[i][0] == '+') || (split_input[i][0] == '-')))
	// 	{
	// 		write(2, "Error\n", 7);
	// 		//printf("banana i value: %i.\nInvalid input: %s\n", i, split_input[i]);
	// 		free_memory(split_input);
	// 		return (0);
	// 	}
	// 	if (split_input[i][0] == '+')
	// 	{
	// 		min_max_compare = ft_strncmp("+2147483647", split_input[i], 12);
	// 		if (min_max_compare < 0)
	// 		{
	// 			write(2, "Error\n", 7);
	// 			//printf("i value: %i.\nInvalid input: %s\n", i, split_input[i]);
	// 			free_memory(split_input);
	// 			return (0);
	// 		}
	// 	}
	// 	if (split_input[i][0] == '-')
	// 	{
	// 		min_max_compare = ft_strncmp("-2147483648", split_input[i], 12);
	// 		if (min_max_compare < 0)
	// 		{
	// 			//write(2, "Error\n", 7);
	// 			printf("i value: %i.\nInvalid input: %s\n", i, split_input[i]);
	// 			free_memory(split_input);
	// 			return (0);
	// 		}
	// 	}
	// 	printf("i value: %i\n", i);
	// 	i++;
	// }
	free_memory(split_input);
	// if (atoi(argv[1]))
	// 	printf("valid input of number %i\n", atoi(argv[1]));
	// else
	// 	printf("RIP BOZO\n");
	// if (!input_check(argc, argv))
	// 	return (0);
	// test = join_input(argv, argc);
	// printf("%s\n", test);
	// free(test);
	// return (0);
}
