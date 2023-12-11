/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:11:32 by mbuchs            #+#    #+#             */
/*   Updated: 2023/12/10 22:11:32 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->range = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

void	add_node(t_stack *stack, long long value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if(stack->range == 0)
	{
		node->next = node;
		node->previous = stack->bottom;
		stack->top = node;
		stack->bottom = node;
		node->content = value;
		stack->bottom->next = node;
		stack->range += 1;
		return ;
	}
	node->next = stack->top;
	node->previous = stack->bottom;
	stack->top = node;
	node = stack->top;
	node->content = value;
	stack->bottom->next = stack->top;
	stack->range += 1;
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	stack->selected = stack->bottom;
	while (i < stack->range - 1)
	{
		stack->selected = stack->selected->next;
		ft_putnbr_fd(stack->selected->content, 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

int main(void)
{
	t_stack stack_a;
	t_stack stack_b;

	init_stack(&stack_a);
	add_node(&stack_a, 8);
	add_node(&stack_a, 1);
	add_node(&stack_a, 2);
	add_node(&stack_a, 3);
	add_node(&stack_a, 4);
	add_node(&stack_a, 5);
	add_node(&stack_a, 6);
	add_node(&stack_a, 7);
	add_node(&stack_a, 8);
	init_stack(&stack_b);
	print_stack(&stack_a);
	print_stack(&stack_b);
	return (0);
}
