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

void	f_reverserotate_a_b(t_all *all, int flag)
{
	f_reverserotate_a(all, flag);
	f_reverserotate_b(all, flag);
	if (flag == 1)
		write(1, "rrr\n", 5);
}

void	f_reverserotate_b(t_all *all, int flag)
{
	if (all && all->stack_b && all->stack_b->next)
		ft_reverserotate_b(&all->stack_b, flag);
}

void	f_reverserotate_a(t_all *all, int flag)
{
	if (all && all->stack_a && all->stack_a->next)
		ft_reverserotate_a(&all->stack_a, flag);
}

void	f_rotate_a_b(t_all *all, int flag)
{
	f_rotate_a(all, flag);
	f_rotate_b(all, flag);
	if (flag == 1)
		write(1, "rr\n", 4);
}

void	f_rotate_a(t_all *all, int flag)
{
	if (all->stack_a && all->stack_a->next)
		return (ft_rotate_a(&all->stack_a, flag));
	return ;
}
