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

#include "push_swap.h"

void	swap(t_stack *stack)
{
	long long temp;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
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

// void	pa(t_stack *stack)
// /* b[0] -> a[0] */
// {
// 	ft_putstr_fd("pa\n", 1);
// }

// void	pb(t_stack *stack)
// /* a[0] -> b[0] */
// {
// 	ft_putstr_fd("pb\n", 1);
// }

// void	ra(t_stack *stack, int vers)
// /* a[last] -> a[0] || a[0] -> a[1] */
// {
// 	if (!vers)
// 		ft_putstr_fd("ra\n", 1);
// }

// void	rb(t_stack *stack, int vers)
// /* b[last] -> b[0] || b[0] -> b[1] */
// {
// 	if (!vers)
// 		ft_putstr_fd("rb\n", 1);
// }

// void	rr(t_stack *stack)
// /* ra + rb */
// {
// 	ra(stack, 1);
// 	rb(stack, 1);
// 	ft_putstr_fd("rr\n", 1);
// }

// void	rra(t_stack *stack, int vers)
// /* a[0] -> a[last] || a[1] -> a[0] */
// {
// 	if (!vers)
// 		ft_putstr_fd("rra\n", 1);
// }

// void	rrb(t_stack *stack, int vers)
// /* b[0] -> b[last] || b[1] -> b[0] */
// {
// 	if (!vers)
// 		ft_putstr_fd("rrb\n", 1);
// }

// void	rrr(t_stack *stack)
// /* rra + rrb */
// {
// 	rra(stack, 1);
// 	rrb(stack, 1);
// 	ft_putstr_fd("rrr\n", 1);
// }
