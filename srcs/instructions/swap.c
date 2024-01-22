/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:46:38 by mbuchs            #+#    #+#             */
/*   Updated: 2023/12/11 13:46:38 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack->top || !stack->top->next)
		return ;
	temp = stack->top->content;
	stack->top->content = stack->top->next->content;
	stack->top->next->content = temp;
}

void	sa(t_stack *stack)
/* switch a[0] et a[1] */
{
	swap(stack);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack)
/* switch b[0] et b[1] */
{
	swap(stack);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
/* sa + sb */
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
