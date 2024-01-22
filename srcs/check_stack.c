/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:43:57 by mbuchs            #+#    #+#             */
/*   Updated: 2024/01/22 12:43:57 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	stack->selected = stack->top;
	while (stack->selected->next)
	{
		if (stack->selected->next->content < stack->selected->content)
			return (1);
		stack->selected = stack->selected->next;
	}
	return (0);
}

int	is_double(t_stack *stack)
{
	t_list	*tmp;

	stack->selected = stack->top;
	while (stack->selected->next)
	{
		tmp = stack->selected;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (tmp->content == stack->selected->content)
				return (1);
		}
		stack->selected = stack->selected->next;
	}
	return (0);
}

void	check_int(char **str, int i, int mode)
{
	if (atol(str[i]) > 2147483647 || atol(str[i]) < -2147483648)
	{
		if (mode)
			free_tab(str);
		print_error(0);
	}
}

void	error_parse(int mode, char **str)
{
	if (mode)
		free_tab(str);
	print_error(0);
}

void	check_input(char **str, int mode)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (str[i])
	{
		check_int(str, i, mode);
		j = 0;
		nb = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]))
				nb++;
			if (!ft_isdigit(str[i][j]) && !is_namespace(str[i][j])
				&& !((str[i][j] != '-' || str[i][j] != '+') && nb == 0))
				error_parse(mode, str);
			j++;
		}
		if (nb == 0)
			error_parse(mode, str);
		i++;
	}
}
