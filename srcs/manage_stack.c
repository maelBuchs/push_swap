/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:17:02 by mbuchs            #+#    #+#             */
/*   Updated: 2024/01/22 12:17:02 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->range = 0;
	stack->top = NULL;
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

int	get_index(t_stack *stack, int value)
{
	int	i;
	int	returned;

	i = 0;
	returned = 1;
	stack->selected = stack->top;
	while (i < ft_lstsize(stack->top))
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
	int		i;
	t_stack	*copy;

	i = 0;
	copy = copy_stack(stack);
	stack->selected = stack->top;
	while (i < ft_lstsize(stack->top))
	{
		stack->selected->content = get_index(copy, stack->selected->content);
		stack->selected = stack->selected->next;
		i++;
	}
	free_stack(copy, 1);
}
