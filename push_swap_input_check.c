#include "libft/Headers/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	input_check(char **split_input)
{
	int i;
	int j;

	i = 1;
	while (split_input[i])
	{
		j = 0;
		while (split_input[i][j])
		{
			if ((ft_isdigit(split_input[i][j]) && (split_input[i][j + 1] == '\0' || ft_isdigit(split_input[i][j + 1]))) || ((split_input[i][j] == '+'
			|| split_input[i][j] == '-') && split_input[i][j + 1] != '\0' && ft_isdigit(split_input[i][j + 1] )))
				j++;
			else
			{
				write(1, "Error\n", 7);
				return (0);
			}
		}
		i++;
	}
	return(i);
}
