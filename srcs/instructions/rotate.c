/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:07:05 by mbuchs            #+#    #+#             */
/*   Updated: 2024/01/20 14:07:05 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_stack *stack)
{
	int content;

	content = delnode(stack, stack->top);
	ft_lstadd_back(&stack->top, ft_lstnew(content));
}

void	ra(t_stack *stack)
/* a[0] -> a[last] || a[1] -> a[0] */
{
	rotate(stack);
	ft_putstr_fd("rra\n", 1);
}

void	rb(t_stack *stack)
/* b[0] -> b[last] || b[1] -> b[0] */
{
	rotate(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
/* rra + rrb */
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}