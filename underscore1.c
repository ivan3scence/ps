/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underscore1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_swap_a(t_all *all, int flag)
{
	if (all && all->stack_a && all->stack_a->next)
		ft_swap_a(all->stack_a, flag);
}

void	f_swap_b(t_all *all, int flag)
{
	if (all && all->stack_b && all->stack_b->next)
		ft_swap_b(all->stack_b, flag);
}

void	f_swap_a_b(t_all *all, int flag)
{
	f_swap_a(all, flag);
	f_swap_b(all, flag);
	if (flag == 1)
		write (1, "ss\n", 3);
}

void	f_push_a(t_all *all, int flag)
{
	if (all && all->stack_b)
		ft_push_a(all, flag);
}

void	f_push_b(t_all *all, int flag)
{
	if (all && all->stack_a)
		ft_push_b(all, flag);
}
