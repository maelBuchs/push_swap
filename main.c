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



void	tab_to_stack(char **tab, t_stack *stack, int mode)
{
	int	i;
	int	content;

	i = 0;
	while (tab[i])
	{
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

int get_index(t_stack *stack, int value)
{
	int	i;
	int	returned;

	i = 0;
	returned = 1;
	stack->selected = stack->top;
	while(i < ft_lstsize(stack->top))
	{
		if (stack->selected->content < value)
			returned++;
		stack->selected = stack->selected->next;
		i++;
	}
	return (returned);
}

int	index_values(t_stack *stack)
{
	int i;
	t_stack *copy;

	i = 0;
	copy = copy_stack(stack);
	stack->selected = stack->top;
	while (i < ft_lstsize(stack->top))
	{
		stack->selected->content = get_index(copy, stack->selected->content);
		// printf("index = %ld\n", stack->selected->content);
		stack->selected = stack->selected->next;
		i++;
	}
	printf("%ld\n", sizeof(copy));
	free_stack(copy, 1);
}

void sort_3(t_stack *stack)
{
	stack->selected = stack->top;
	if(stack->selected->content == 3 && stack->selected->next->content == 2)
	{
		ra(stack);
		sa(stack);
	}
	else if(stack->selected->content == 2 && stack->selected->next->content == 3) // OK
		rra(stack);
	else if(stack->selected->content == 2 && stack->selected->next->content == 1) // OK
		sa(stack);
	else if(stack->selected->content == 1 && stack->selected->next->content == 3)
	{
		rra(stack);
		sa(stack);
	}
	else if(stack->selected->content == 3 && stack->selected->next->content == 1)
		ra(stack);
}

void sort_5(t_stack *stack_a, t_stack *stack_b)
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


void select_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize(stack_a->top)== 2)
	{
		if(stack_a->top->content > stack_a->top->next->content)
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

void	check_input(char **str, int mode)
{
	int	i;
	int	j;
	int nb;

	i = 0;
	while (str[i])
	{
		if(atol(str[i]) > 2147483647 || atol(str[i]) < -2147483648)
		{
			if(mode)
				free_tab(str);
			print_error(0);
		}
		j = 0;
		nb = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]))
				nb++;
			if (!ft_isdigit(str[i][j]) && !is_namespace(str[i][j])
				&& !((str[i][j] != '-' || str[i][j] != '+') && nb == 0))
				{
					if(mode)
						free_tab(str);
					print_error(0);
				}
			j++;
		}
		if(nb == 0)
		{
			if(mode)
				free_tab(str);
			print_error(0);
		}
		i++;
	}
}

void free_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}	
	free(tab);
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
		int i = 0;
		int is_solo = 0;
		while (argv[1][i])
		{
			if(argv[1][i] == ' ')
				is_solo++;
			i++;
		}
		if (is_solo)
		{
			tab = ft_split(argv[1], ' ');
			check_input(tab, 1);
			tab_to_stack(tab, &stack_a, 1);
			i = 0;
			free_tab(tab);
		}
		else
			return 0;
	}
	if (argc > 2)
	{
		tab = &argv[1];
		check_input(tab, 0);
		tab_to_stack(tab, &stack_a, 0);
	}
	if(is_double(&stack_a))
	{
		free_stack(&stack_a, 0);
		print_error(0);
	}
	if(!is_sorted(&stack_a))
	{
		free_stack(&stack_a, 0);
		return (0);
	}
	index_values(&stack_a);
	// print_stack(&stack_a);
	select_sort(&stack_a, &stack_b);
	free_stack(&stack_a, 0);

	return (0);
}

