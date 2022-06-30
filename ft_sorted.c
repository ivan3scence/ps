/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_fromstack(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	tmp = stack;
	max = stack->num;
	while (tmp)
	{
		if (tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_sortedthree(t_all *all)
{
	int	max;

	max = ft_max_fromstack(all->stack_a);
	if (all->len_a == 1)
		return ;
	else if ((all->len_a == 2) && (all->stack_a->num > all->stack_a->next->num))
	{
		ft_swap_a(all->stack_a, 1);
		return ;
	}
	else if (all->len_a == 3)
	{
		if (all->stack_a->num == max)
			ft_rotate_a(&all->stack_a, 1);
		if (all->stack_a->next->num == max)
			ft_reverserotate_a(&all->stack_a, 1);
		if (all->stack_a->num > all->stack_a->next->num)
			ft_swap_a(all->stack_a, 1);
	}
}

void	ft_sortedfive(t_all *all)
{
	while (all->len_b != 2)
	{
		if (all->stack_a->num == all->max || all->stack_a->num == all->min)
			ft_push_b(all, 1);
		else
			ft_rotate_a(&all->stack_a, 1);
	}
	ft_sortedthree(all);
	while (all->len_b != 0)
		ft_push_a(all, 1);
	if (all->stack_a->num == all->max)
		ft_rotate_a(&all->stack_a, 1);
	else
	{
		ft_swap_a(all->stack_a, 1);
		ft_rotate_a(&all->stack_a, 1);
	}
}
