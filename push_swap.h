#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <limits.h>

typedef struct my_ps_Stack {
	int number;
	int position;
	struct my_ps_Stack *next;
}	myStack;

//------------ INPUT CHECKING ----------------

int	input_check(char **split_input);
char	*join_input(char **strings, int nb_of_strings);
void	free_memory(char **badmem);
myStack *input_creation(int argc, char **argv);
int input_min_max_check(char **split_input, int i);
int dupe_check(int *digit_array, int nb_of_nbs);
int check_order(int *digit_array, int nb_of_nbs);

//------------ LIST UTILITIES ----------------

void	ft_pslstadd_back(myStack **lst, myStack *new);
void	ft_pslstadd_front(myStack **lst, myStack *new);
void	ft_pslstclear(myStack **lst, void (*del)(void*));
void	ft_pslstdelone(myStack *lst, void (*del)(void*));
void	ft_pslstiter(myStack *lst, void (*f)(void *));
myStack	*ft_pslstlast(myStack *lst);
myStack	*ft_pslstmap(myStack *lst, void *(*f)(void *), void (*del)(void *));
myStack	*ft_pslstnew(int number);
int		ft_pslstsize(myStack *lst);
void	test_clear(myStack **lst);

void	swap_a(myStack **stack_a);
void rotate_a(myStack **a);
void r_rotate_a(myStack **a);
void rr_rotate(myStack **a, myStack **b)


//int	ft_atoi_limit_check(const char *str, int *error);


#endif
