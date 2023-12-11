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
	t_node node;

	if(stack->range == 0)
	{
		node.next = &node;
		node.previous = &node;
		stack->top = &node;
		stack->bottom = &node;
		node.content = value;
		return ;
	}
	node.next = stack->top->next;
	node.previous = stack->bottom;
	stack->top = &node;
	node.next->previous = stack->top; 
	node.content = value;
	stack->range += 1;
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	stack->selected = stack->top;
	while (i < stack->range)
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

	init_stack(&stack_a);
	add_node(&stack_a, 1);
	add_node(&stack_a, 2);
	add_node(&stack_a, 3);
	add_node(&stack_a, 4);
	add_node(&stack_a, 5);
	add_node(&stack_a, 6);
	add_node(&stack_a, 7);
	add_node(&stack_a, 8);
	print_stack(&stack_a);

	return (0);
}