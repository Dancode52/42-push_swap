#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <limits.h>

typedef struct my_ps_Stack {
	int number;
	int position;
	int size;
	struct my_ps_Stack *next;
}	myStack;

//------------ INPUT CHECKING ----------------

int	input_check(char **split_input);
char	*join_input(char **strings, int nb_of_strings);
void	free_memory(char **badmem);
myStack *input_creation(int argc, char **argv);
int input_min_max_check(char **split_input, int i);
int dupe_check(int *digit_array, int nb_of_nbs);
int check_order(myStack *stack);
int	ft_atoi_limit_check(const char *str, int *error);

int find_max_position(myStack *stack, int max_index);
int	find_max_index(myStack *b);
int	find_min_index(myStack *b);

//------------ LIST UTILITIES ----------------

void	ft_pslstadd_back(myStack **lst, myStack *new);
void	ft_pslstadd_front(myStack **lst, myStack *new);
myStack	*ft_pslstlast(myStack *lst);
myStack	*ft_pslstnew(int number, int index);
int		ft_pslstsize(myStack *lst);
void	free_stack_mem(myStack *lst);

// ----------- PUSHING -----------------------

void	push_a(myStack **a, myStack **b);
void	push_b(myStack **b, myStack **a);

// ----------- SWAPPING ----------------------

void	swap_a(myStack **stack_a);
void	swap_b(myStack **stack_b);
void	swaps(myStack **stack_a, myStack **stack_b);

void	rotate_a(myStack **a);
void	rotate_b(myStack **b);
void	rrotate(myStack **a, myStack **b);

void	r_rotate_a(myStack **a);
void	r_rotate_b(myStack **b);
void	rr_rotate(myStack **a, myStack **b);

// ----------- SMALL SORTS -------------------

void sort_two(myStack **StackA);
void sort_three(myStack **StackA);
void sort_four(myStack **StackA, myStack **StackB);
void sort_five(myStack **StackA, myStack **StackB);
int Small_Sorts(myStack **StackA, myStack **StackB);
void split_stack(myStack **StackA, myStack **StackB, int count);

#endif



