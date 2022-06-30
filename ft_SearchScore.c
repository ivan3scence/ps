/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_SearchScore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_smallelem(t_stack *a, int buff, int src)
{
	t_stack	*save;
	int		ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->num < buff && save->num > src)
			ret = 1;
		save = save->next;
	}
	return (ret);
}

void	ft_searchscore(t_all *all, t_stack *b, int *score, int *ptr)
{
	while (all->stack_a)
	{
		*ptr = all->stack_a->num;
		if (b->num > all->stack_a->num)
		{
			*score += 1;
			if (b->num < all->stack_a->next->num)
				break ;
			all->stack_a = all->stack_a->next;
		}
		else
			break ;
	}
	if ((ft_smallelem(all->stack_a, *ptr, b->num)))
	{
		while (all->stack_a)
		{
			if (all->stack_a->num < *ptr && all->stack_a->num > b->num)
				break ;
			*score += 1;
			all->stack_a = all->stack_a->next;
		}
	}
}

int	ft_findscore(t_all *all, t_stack *b, t_score *score, int minscore)
{
	int	s;
	int	ptr;
	int	addscore;

	s = 0;
	ptr = 0;
	ft_searchscore(all, b, &s, &ptr);
	if (all->stack_a->ra == -1)
		s = all->len_a - s;
	if (minscore == -1 || (s + b->score) < minscore)
	{
		score->count_a = s;
		score->count_b = b->score;
		score->flag_a = all->stack_a->ra;
		score->flag_b = b->ra;
		addscore = s + b->score;
	}
	else
		s = minscore;
	return (addscore);
}
