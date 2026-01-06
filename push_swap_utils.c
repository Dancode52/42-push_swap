#include "libft/Headers/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	free_memory(char **badmem)
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
