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

void	add_node(t_stack *stack, long long value);
void	init_stack(t_stack *stack);
void	print_stack(t_stack *stack);

#endif