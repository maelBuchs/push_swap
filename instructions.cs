/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:46:38 by mbuchs            #+#    #+#             */
/*   Updated: 2023/12/11 13:46:38 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int vers)
/* switch a[0] et a[1] */
{
	t_stack *temp;

	temp = data->top_stack_a-;
	data->top_stack_a = top_stack_a->next;
	top_stack_a->next = temp;
	if (!vers)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_data *data, int vers)
/* switch b[0] et b[1] */
{
	if (!vers)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_data *data)
/* sa + sb */
{
	sa(data, 1);
	sb(data, 1);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_data *data)
/* b[0] -> a[0] */
{
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_data *data)
/* a[0] -> b[0] */
{
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_data *data, int vers)
/* a[last] -> a[0] || a[0] -> a[1] */
{
	if (!vers)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_data *data, int vers)
/* b[last] -> b[0] || b[0] -> b[1] */
{
	if (!vers)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_data *data)
/* ra + rb */
{
	ra(data, 1);
	rb(data, 1);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_data *data, int vers)
/* a[0] -> a[last] || a[1] -> a[0] */
{
	if (!vers)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_data *data, int vers)
/* b[0] -> b[last] || b[1] -> b[0] */
{
	if (!vers)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_data *data)
/* rra + rrb */
{
	rra(data, 1);
	rrb(data, 1);
	ft_putstr_fd("rrr\n", 1);
}
