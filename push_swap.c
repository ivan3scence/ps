/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_stack_null(t_all *stack, t_stack *list)
{
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	list->score = 0;
}

void	ft_sorted(t_all *all)
{
	if (all->len_a <= 3)
		ft_sortedthree(all);
	else if (all->len_a <= 5)
		ft_sortedfive(all);
	else
		ft_globalsort(all);
}

int	main(int argc, char *argv[])
{
	t_stack		list;
	t_all		all;

	ft_stack_null(&all, &list);
	if (argc < 2)
		return (0);
	if (ft_parse(argc, argv))
	{
		ft_copying(argc, argv, &all);
		if (!ft_sortedstack(&(all.stack_a)))
		{
			ft_list_sort(all.stack_a, &all);
			ft_sorted(&all);
		}
	}
	ft_free(&all);
	return (0);
}
