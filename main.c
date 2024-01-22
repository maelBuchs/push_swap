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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	stack_set(char **argv, t_stack *stack_a, char **tab)
{
	int	i;
	int	is_solo;

	i = 0;
	is_solo = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			is_solo++;
		i++;
	}
	if (is_solo)
	{
		tab = ft_split(argv[1], ' ');
		check_input(tab, 1);
		tab_to_stack(tab, stack_a, 1);
		free_tab(tab);
	}
	else
		exit(0);
}

void	verif_stack(t_stack *stack_a)
{
	if (is_double(stack_a))
	{
		free_stack(stack_a, 0);
		print_error(0);
	}
	if (!is_sorted(stack_a))
	{
		free_stack(stack_a, 0);
		exit(0);
	}
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
		stack_set(argv, &stack_a, tab);
	if (argc > 2)
	{
		tab = &argv[1];
		check_input(tab, 0);
		tab_to_stack(tab, &stack_a, 0);
	}
	index_values(&stack_a);
	select_sort(&stack_a, &stack_b);
	free_stack(&stack_a, 0);
	return (0);
}
