
#include "libft/Headers/libft.h"
#include <stdio.h>
#include <stdlib.h>

// int	input_check(int argc, char **argv)
// {
// 	int i;
// 	int j;

// 	i = 1;
// 	if (argc < 2)
// 	{
// 		write(1, "Error\n", 7);
// 		return (0);
// 	}
// 	while (argv[i])
// 	{
// 		j = 0;
// 		while (argv[i][j])
// 		{
// 			if (ft_isdigit(argv[i][j]) || argv[i][j] == ' ')
// 				j++;
// 			else
// 			{
// 				write(1, "Error\n", 7);
// 				return (0);
// 			}
// 		}
// 		i++;
// 	}
// 	return(1);
// }
// int valid_int_check(int argc, char **argv)
// {

// }

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
	// check each string to see if it is a valid input
	i = 0;
	while (split_input[i])
	{
		if ((split_input[i][0] == '+' || split_input[i][0] == '-') && !ft_isdigit(split_input[i][1]))
		{
			i = 0;
			while (split_input[i])
				{
					free(split_input[i]);
					i++;
				}
			free(split_input);
			return (0);
		}
		if (ft_strlen(split_input[i]) > ft_strlen("-2147483648"))
		{
			//write(2, "Error\n", 7);
			printf("i value: %i.\nInvalid input: %s\n", i, split_input[i]);
			i = 0;
			while (split_input[i])
				{
					free(split_input[i]);
					i++;
				}
			free(split_input);
			return (0);
		}
		if (ft_strlen(split_input[i]) == ft_strlen("-2147483648") && !((split_input[i][0] == '+') || (split_input[i][0] == '-')))
		{
			//write(2, "Error\n", 7);
			printf("banana i value: %i.\nInvalid input: %s\n", i, split_input[i]);
			i = 0;
			while (split_input[i])
				{
					free(split_input[i]);
					i++;
				}
			free(split_input);
			return (0);
		}
		if (split_input[i][0] == '+')
		{
			min_max_compare = ft_strncmp("+2147483647", split_input[i], 12);
			if (min_max_compare < 0)
			{
				printf("i value: %i.\nInvalid input: %s\n", i, split_input[i]);
				//write(2, "Error\n", 7);
			}
		}
		if (split_input[i][0] == '-')
		{
			min_max_compare = ft_strncmp("-2147483648", split_input[i], 12);
			if (min_max_compare < 0)
			{
				printf("i value: %i.\nInvalid input: %s\n", i, split_input[i]);
				//write(2, "Error\n", 7);
			}
		}
		printf("i value: %i\n", i);
		i++;
	}
	i = 0;
	while (split_input[i])
	{
		free(split_input[i]);
		i++;
	}
	free(split_input);
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
