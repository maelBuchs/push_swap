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
		node->previous = node;
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

void	remove_node(t_stack *stack, t_node *node)
{
	if(stack->range > 1)
	{
		node->previous->next = node->next;
		node->next->previous = node->previous;
		if (stack->top == node)
			stack->top = node->next;
		if (stack->bottom == node)
			stack->bottom = node->previous;
	}
	stack->range -= 1;
	free(node);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;

	stack->selected = stack->bottom;
	while (i < stack->range)
	{
		stack->selected = stack->selected->next;
		ft_putnbr_fd(stack->selected->content, 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	print_error(int error)
{
	if (error == 0)
		ft_putstr_fd("Error\nwrong input\n", 1);
	exit (0);
}

void tab_to_stack(char **tab, t_stack *stack)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (atoi(tab[i]) == 0 && tab[i][0] != '0')
			print_error(0);
		add_node(stack, (long long) atoi(tab[i]));
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_stack stack_a;
	t_stack stack_b;
	char **tab;
	if (argc < 2)
		return 0;
	init_stack(&stack_a);
	init_stack(&stack_b);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		tab_to_stack(tab, &stack_a);
	}
	if (argc > 2)
	{
		tab = &argv[1];
		tab_to_stack(tab, &stack_a);
	}
	ra(&stack_a);
	printf("stack A :\n");
	print_stack(&stack_a);
	printf("stack B :\n");
	print_stack(&stack_b);
	return (0);
}

