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
}

void	print_stack(t_stack *stack)
{
	int i;

	i = 0;
	stack->selected = stack->top;
	while (i < ft_lstsize(stack->top))
	{
		ft_putnbr_fd(stack->selected->content, 1);
		ft_putchar_fd('\n', 1);
		stack->selected = stack->selected->next;
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
	int content;
	i = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) == 0 && tab[i][0] != '0')
			print_error(0);
		content = ft_atoi(tab[i]);
		ft_lstadd_back(&stack->top, ft_lstnew(content));
		i++;
	}
}

int delnode(t_stack *stack, t_list *node)
{
	int i;
	int content;
	t_list *previous;

	stack->selected = stack->top;
	i = 0;
	while (ft_lstsize(stack->top) > i && node != stack->selected->next &&  stack->selected->next->next)
	{
		content = stack->selected->content;
		previous = stack->selected;
		stack->selected = stack->selected->next; 
		i++;
	}
	if (i == 1)
	{
		free(stack->selected);
		return (content);
	}
	free(previous);
	return (content);
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
	pa(&stack_a, &stack_b);
	printf("stack A :\n");
	print_stack(&stack_a);
	printf("stack B :\n");
	print_stack(&stack_b);
	return (0);
}

