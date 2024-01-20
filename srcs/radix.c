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

int set_max_bits(t_stack *stack)
{
	int	max_bits;
	int	i;
	int	temp;

	max_bits = 0;
	i = 0;
	stack->selected = stack->top;
	temp = stack->selected->content;
	while(stack->selected->next)
	{
		if(stack->selected->content > temp)
			temp = stack->selected->content;
		stack->selected = stack->selected->next;
	}
	while ((temp >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int size;
	int i;
	int j;

	i = 0;
	size = ft_lstsize(stack_a->top);
	max_bits = set_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (stack_a->top->content >> i & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(stack_b->top) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
