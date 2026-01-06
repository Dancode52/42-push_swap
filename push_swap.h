#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int	input_check(char **split_input);
char	*join_input(char **strings, int nb_of_strings);
void	free_memory(char **badmem);
int *input_creation(int argc, char **argv);


#endif
