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
	int temp;
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


void	pa(t_stack *stack_a, t_stack *stack_b)
/* b[0] -> a[0] */
{
	int temp;

	temp = delnode(stack_b, stack_b->top);
	ft_lstadd_front(&stack_a->top, ft_lstnew(temp));
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
/* a[0] -> b[0] */
{
	int temp;

	temp = delnode(stack_a, stack_a->top);
	ft_lstadd_front(&stack_b->top, ft_lstnew(temp));
	ft_putstr_fd("pb\n", 1);
}


void	rotate(t_stack *stack)
{
	int i = 0;
	int content;

	stack->selected = stack->top;
	while(i < ft_lstsize(stack->top) - 1)
	{
		stack->selected = stack->selected->next;
		i++;
	}
	content = delnode(stack, stack->selected);
	ft_lstadd_front(&stack->top, ft_lstnew(content));
}

void	ra(t_stack *stack)
/* a[last] -> a[0] || a[0] -> a[1] */
{	
	rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack)
/* b[last] -> b[0] || b[0] -> b[1] */
{
	rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
/* ra + rb */
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate(t_stack *stack)
{
	int content;

	content = delnode(stack, stack->top);
	ft_lstadd_back(&stack->top, ft_lstnew(content));
}

void	rra(t_stack *stack)
/* a[0] -> a[last] || a[1] -> a[0] */
{
	reverse_rotate(stack);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack)
/* b[0] -> b[last] || b[1] -> b[0] */
{
	reverse_rotate(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
/* rra + rrb */
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
