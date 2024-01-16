/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 01:34:46 by mbuchs            #+#    #+#             */
/*   Updated: 2024/01/16 01:34:46 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int			range;
	int			median;
	t_list		*selected;
	t_list		*top;
}	t_stack;

/* Instructions */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* Fonctions */
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	tab_to_stack(char **tab, t_stack *stack);
void	print_error(int error);
void	print_stack(t_stack *stack);
void	add_top(t_stack *stack, long long value);
void	add_bottom(t_stack *stack, long long value);
void	init_stack(t_stack *stack);
void	remove_node(t_stack *stack, t_list *node);
int		delnode(t_stack *stack, t_list *node);
int		is_sorted(t_stack *stack);

#endif