#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int		value;
	t_stack	*next;
	t_stack	*previous;
}	t_stack;

typedef struct s_data
{
	t_stack	*top_stack_a;
	t_stack	*top_stack_b;
	int		op_count;
}	t_data;

#endif