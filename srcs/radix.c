/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:10:39 by mbuchs            #+#    #+#             */
/*   Updated: 2024/01/20 14:10:39 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	set_max_bits(t_stack *stack)
{
	int	max_bits;
	int	i;
	int	temp;

	max_bits = 0;
	i = 0;
	stack->selected = stack->top;
	temp = stack->selected->content;
	while (stack->selected->next)
	{
		if (stack->selected->content > temp)
			temp = stack->selected->content;
		stack->selected = stack->selected->next;
	}
	while ((temp >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	i = 0;
	size = ft_lstsize(stack_a->top);
	max_bits = set_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (stack_a->top->content >> i & 1)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (ft_lstsize(stack_b->top) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

void	sort_3(t_stack *stack)
{
	stack->selected = stack->top;
	if (stack->selected->content == 3
		&& stack->selected->next->content == 2)
	{
		ra(stack);
		sa(stack);
	}
	else if (stack->selected->content == 2
		&& stack->selected->next->content == 3)
		rra(stack);
	else if (stack->selected->content == 2
		&& stack->selected->next->content == 1)
		sa(stack);
	else if (stack->selected->content == 1
		&& stack->selected->next->content == 3)
	{
		rra(stack);
		sa(stack);
	}
	else if (stack->selected->content == 3
		&& stack->selected->next->content == 1)
		ra(stack);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	while (ft_lstsize(stack_b->top) <= 1)
	{
		if (stack_a->top->content == 1 || stack_a->top->content == 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (stack_b->top->content == 1)
		sb(stack_b);
	if (stack_a->top->next->next->content != 5)
	{
		if (stack_a->top->content == 5)
			ra(stack_a);
		else
			rra(stack_a);
	}
	if (stack_a->top->content > stack_a->top->next->content)
		sa(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	select_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize(stack_a->top) == 2)
	{
		if (stack_a->top->content > stack_a->top->next->content)
			sa(stack_a);
		return ;
	}
	else if (ft_lstsize(stack_a->top) == 3)
	{
		sort_3(stack_a);
		return ;
	}
	else if (ft_lstsize(stack_a->top) == 5)
	{
		sort_5(stack_a, stack_b);
		return ;
	}
	else
		radix_sort(stack_a, stack_b);
}
