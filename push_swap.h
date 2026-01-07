#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <limits.h>

struct myStack {
	int number;
	int position;
	struct myStack *next;
};

int	input_check(char **split_input);
char	*join_input(char **strings, int nb_of_strings);
void	free_memory(char **badmem);
int *input_creation(int argc, char **argv);
int input_min_max_check(char **split_input, int i);
int dupe_check(int *digit_array, int nb_of_nbs);
int check_order(int *digit_array, int nb_of_nbs);

int	ft_atoi_limit_check(const char *str, int *error);


#endif
