/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:08:16 by mbuchs            #+#    #+#             */
/*   Updated: 2024/01/20 14:08:16 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	content;

	i = 0;
	stack->selected = stack->top;
	while (i < ft_lstsize(stack->top) - 1)
	{
		stack->selected = stack->selected->next;
		i++;
	}
	content = delnode(stack, stack->selected);
	ft_lstadd_front(&stack->top, ft_lstnew(content));
}

void	rra(t_stack *stack)
/* a[last] -> a[0] || a[0] -> a[1] */
{
	reverse_rotate(stack);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack)
/* b[last] -> b[0] || b[0] -> b[1] */
{
	reverse_rotate(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
/* ra + rb */
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
