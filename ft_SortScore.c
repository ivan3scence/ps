/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_SortScore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortscore(t_all *all, t_score *score)
{
	while (score->count_a > 0)
	{
		if (score->flag_a == -1)
			ft_reverserotate_a(&all->stack_a, 1);
		else
			ft_rotate_a(&all->stack_a, 1);
		score->count_a--;
	}
	while (score->count_b > 0)
	{
		if (score->flag_b == -1)
			ft_reverserotate_b(&all->stack_b, 1);
		else
			ft_rotate_b(&all->stack_b, 1);
		score->count_b--;
	}
	ft_push_a(all, 1);
}
