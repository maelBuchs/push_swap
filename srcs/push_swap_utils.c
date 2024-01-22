/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:32:38 by mbuchs            #+#    #+#             */
/*   Updated: 2024/01/22 12:48:26 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*copy;
	t_list	*tmp;

	copy = malloc(sizeof(t_stack));
	copy->top = NULL;
	tmp = stack->top;
	while (tmp)
	{
		ft_lstadd_back(&copy->top, ft_lstnew(tmp->content));
		tmp = tmp->next;
	}
	return (copy);
}

int	is_namespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	free_stack(t_stack *stack, int mode)
{
	while (stack->top)
		delnode(stack, stack->top);
	if (mode)
		free(stack);
}

long	atol(const char *str)
{
	int		i;
	int		sign;
	long	sum;

	i = 0;
	sign = 1;
	sum = 0;
	while ((str[i] == ' ' && str[i]) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!(ft_isdigit(str[i])) && !(ft_isdigit(str[i + 1])))
		return (0);
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str [i] <= '9'))
	{
		sum *= 10;
		sum += str[i] - 48;
		i++;
	}
	sum *= sign;
	return (sum);
}

void	print_error(int error)
{
	if (error == 0)
		ft_putstr_fd("Error\n", 2);
	exit (0);
}
