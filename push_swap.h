#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"


typedef struct s_node
{
	long long		content;
	int				rank;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	int			range;
	int			median;
	t_node		*selected;
	t_node		*top;
	t_node		*bottom;
}	t_stack;

/* Instructions */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack, int vers);
void	rb(t_stack *stack, int vers);
void	rr(t_stack *stack);
void	rra(t_stack *stack, int vers);
void	rrb(t_stack *stack, int vers);
void	rrr(t_stack *stack);

/* Fonctions */
void	swap(t_stack *stack);
void	tab_to_stack(char **tab, t_stack *stack);
void	print_error(int error);
void	print_stack(t_stack *stack);
void	add_node(t_stack *stack, long long value);
void	init_stack(t_stack *stack);

#endif