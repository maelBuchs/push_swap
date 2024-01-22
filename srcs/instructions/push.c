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

void	pa(t_stack *stack_a, t_stack *stack_b)
/* b[0] -> a[0] */
{
	int	temp;

	temp = delnode(stack_b, stack_b->top);
	ft_lstadd_front(&stack_a->top, ft_lstnew(temp));
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
/* a[0] -> b[0] */
{
	int	temp;

	temp = delnode(stack_a, stack_a->top);
	ft_lstadd_front(&stack_b->top, ft_lstnew(temp));
	ft_putstr_fd("pb\n", 1);
}
