/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:36:02 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/10 11:24:40 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/Headers/libft.h"
# include <limits.h>

typedef struct s_my_ps_stack
{
	int						number;
	size_t					index;
	struct s_my_ps_stack	*next;
}	t_stack;

//------------ INPUT CHECKING ----------------

int		input_check(char **split_input);
char	*join_input(char **strings, int nb_of_strings);
void	free_memory(char **badmem);
t_stack	*input_creation(int argc, char **argv);
int		input_min_max_check(char **split_input, int i);
int		dupe_check(int *digit_array, int nb_of_nbs);
int		check_order(t_stack *stack);
int		ft_atoi_limit_check(const char *str, int *error);
char	*spaceoremptychecker(char *input, char *tofree);
void	input_mallocfail(char *tofree);
char	**splitting_input(char *input);

size_t	find_max_index_position(t_stack **stack, size_t max_index);
size_t	find_max_index(t_stack **b);
size_t	find_min_index(t_stack *b);

//------------ LIST UTILITIES ----------------

void	ft_pslstadd_back(t_stack **lst, t_stack *new);
void	ft_pslstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_pslstlast(t_stack *lst);
t_stack	*ft_pslstnew(int number, size_t index);
size_t	ft_pslstsize(t_stack *lst);
void	free_stack_mem(t_stack *lst);
void	create_link_nodes(t_stack **head, int *dig_ar, size_t n_nbs, size_t i);
size_t	indexer(int number, size_t nb_of_nbs, int *array);

// ----------- PUSHING -----------------------

void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **b, t_stack **a);

// ----------- SWAPPING ----------------------

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swaps(t_stack **stack_a, t_stack **stack_b);

void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rrotate(t_stack **a, t_stack **b);

void	r_rotate_a(t_stack **a);
void	r_rotate_b(t_stack **b);
void	rr_rotate(t_stack **a, t_stack **b);

// ----------- SMALL SORTS -------------------

void	sort_two(t_stack **StackA);
void	sort_three(t_stack **StackA);
void	sort_four(t_stack **StackA, t_stack **StackB);
void	sort_five(t_stack **StackA, t_stack **StackB);
int		small_sorts(t_stack **StackA, t_stack **StackB);
void	split_stack(t_stack **StackA, t_stack **StackB, size_t count);

#endif
