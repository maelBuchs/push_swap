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
	int	i;

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

void	tab_to_stack(char **tab, t_stack *stack)
{
	int	i;
	int	content;

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

int	delnode(t_stack *stack, t_list *node)
{
	t_list	*tmp;
	t_list	*prev;
	int		content;

	tmp = stack->top;
	prev = NULL;
	while (tmp)
	{
		if (tmp == node)
		{
			if (prev)
				prev->next = tmp->next;
			else
				stack->top = tmp->next;
			content = tmp->content;
			free(tmp);
			return (content);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (content);
}

int	is_sorted(t_stack *stack)
{
	stack->selected = stack->top;
	while(stack->selected->next)
	{
		if(stack->selected->next->content < stack->selected->content)
			return (1);
		stack->selected = stack->selected->next;
	}
	return (0);
}

int is_double(t_stack *stack)
{
	t_list *tmp;

	stack->selected = stack->top;
	while(stack->selected->next)
	{
		tmp = stack->selected;
		while(tmp->next)
		{
			tmp = tmp->next;
			if(tmp->content == stack->selected->content)
				return(1);
		}
		stack->selected = stack->selected->next;
	}
	return (0);
}

int check_stack(t_stack *stack)
{
	if(is_double(stack))
	{
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
}

void get_index(t_stack *stack)
{
	int		i;
	t_list	*temp;

	i = 0;
	while(i < ft_lstsize(stack->top))
	{
		temp = stack->top;
		stack->selected = stack->selected->next;
		while (temp)
		{
			if(temp->content > stack->selected->content)
				temp = stack->selected;
			stack->selected = stack->selected->next;

		}
		i++;
	}
}

void select_sort(t_stack *stack_a, t_stack *stack_b)
{
	if(ft_lstsize(stack_a) > 5)
			
}

int	main(int argc, char *argv[])
{	
	t_stack	stack_a;
	t_stack	stack_b;
	char	**tab;

	if (argc < 2)
		return (0);
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
	check_stack(&stack_a);
	if(!is_sorted(&stack_a))
	{
		return (0);
	}
	select_sort(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// rra(&stack_a);
	// rrb(&stack_b);
	printf("stack A :\n");
	print_stack(&stack_a);
	// printf("stack B :\n");
	// print_stack(&stack_b);
	return (0);
}

