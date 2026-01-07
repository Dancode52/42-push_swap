
#include "libft/Headers/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int *digit_array;

	digit_array = input_creation(argc, argv);
	if (!digit_array)
		return (0);
	printf("Mundo PUSHswap PUSHswap PUSHswap\n");
	free(digit_array);
	return (0);
}
// old code

	// input = join_input(argv, argc);
	// printf("String created: %s\n", input);

	// // split them all into an array
	// split_input = ft_split(input, ' ');
	// if (!split_input)
	// 	return (0);
	// free(input);
	// //first input check
	// digit_num = input_check(split_input);
	// if (!digit_num)
	// {
	// 	free_memory(split_input);
	// 	return (0);
	// }
	// //convert to int and check if valid int
	// digit_array = (int *)malloc(digit_num * sizeof(int));
	// if (!digit_array)
	// 	return (0);
	// i = 0;
	// while (i < digit_num)
	// {
	// 	digit_array[i] = ft_atoi(split_input[i]);
	// 	printf("Made digit %i from string %s\n", digit_array[i], split_input[i]);
	// 	i++;
	// }
	// printf("Made it through input check func\n");
	// i = 0;
	// free(digit_array);

	//check each string to see if it is a valid input
	// i = 0;
	// while (split_input[i])
	// {
	// 	printf("%s\n", split_input[i]);
	// 	i++;
	// }
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
