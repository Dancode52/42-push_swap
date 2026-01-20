// #include "libft/Headers/libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include "libft.h"
// #include "push_swap.h"

// int	int_len_check(char **split_input, int i)
// {
// 	char *int_min;

// 	int_min = "-2147483648";
// 	if (ft_strlen(split_input[i]) > ft_strlen(int_min) ||
// 	 	(ft_strlen(split_input[i]) == ft_strlen(int_min)
// 		&& !((split_input[i][0] == '+') || (split_input[i][0] == '-'))))
// 			return (0);
// 	return (1);
// }

// int	signed_min_max_check(char **split_input, int i)
// {
// 	if (split_input[i][0] == '+')
// 		{
// 			if (ft_strncmp("+2147483647", split_input[i], 12) < 0)
// 				return (0);
// 		}
// 	if (split_input[i][0] == '-')
// 		{
// 			if (ft_strncmp("-2147483648", split_input[i], 12) < 0)
// 				return (0);
// 		}
// 	return (1);
// }

// int	nosign_int_max(char **split_input, int i)
// {
// 	char *int_max;
// 	size_t len_of_max;

// 	int_max = "2147483647";
// 	len_of_max = ft_strlen(int_max);
// 	if (ft_strlen(split_input[i]) == len_of_max)
// 		{
// 			if (ft_strncmp(int_max, split_input[i], len_of_max) < 0)
// 				return (0);
// 		}
// 	return (1);
// }

// int	input_min_max_check(char **split_input, int i)
// {
// 	if (!int_len_check(split_input, i))
// 	{
// 		write(2, "Error\n", 7);
// 		return (0);
// 	}
// 	if (ft_strlen(split_input[i]) == ft_strlen("-2147483648"))
// 	{
// 		if (!signed_min_max_check(split_input, i))
// 		{
// 			write(2, "Error\n", 7);
// 			return (0);
// 		}
// 	}
// 	if (!nosign_int_max(split_input, i))
// 	{
// 		write(2, "Error\n", 7);
// 		return (0);
// 	}
// 	return (1);
// }
