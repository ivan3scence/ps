/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.BigSortc                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_firstscore(t_stack *stack, int len)
{
	t_stack	*buffer;
	int		i;
	int		j;

	buffer = stack;
	i = 0;
	j = len / 2;
	while (i <= j)
	{
		buffer->score = i;
		buffer->ra = 1;
		buffer = buffer->next;
		i++;
	}
	if ((len % 2) == 0)
		i--;
	i--;
	while (i != 0)
	{
		buffer->score = i;
		buffer->ra = -1;
		buffer = buffer->next;
		i--;
	}
}

void	ft_minscore(t_all *all, t_score	*score)
{
	t_stack	*start_a;
	t_stack	*start_b;
	int		minscore;

	minscore = -1;
	start_a = all->stack_a;
	start_b = all->stack_b;
	while (all->stack_b)
	{
		minscore = ft_findscore(all, all->stack_b, score, minscore);
		all->stack_b = all->stack_b->next;
		all->stack_a = start_a;
	}
	all->stack_b = start_b;
}

void	ft_globalsort(t_all *all)
{
	int	stop;

	stop = 2;
	while (all->len_a > stop)
	{
		if ((all->stack_a->num != all->min) && (all->stack_a->num != all->max))
		{
			ft_push_b(all, 1);
			if (all->stack_b->num > all->med)
				ft_rotate_b(&all->stack_b, 1);
		}
		else
			ft_rotate_a(&all->stack_a, 1);
	}
	if (all->stack_a->num < all->stack_a->next->num)
		ft_swap_a(all->stack_a, 1);
	ft_push_a(all, 1);
	ft_score(all);
}

int	ft_count_to_min(t_stack *a, int min)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->num == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

void	ft_score(t_all *all)
{
	t_score	*score;

	score = (t_score *)malloc(sizeof(t_score));
	if (!score)
		exit(1);
	while (all->len_b > 0)
	{
		ft_initscore(score);
		ft_firstscore(all->stack_a, all->len_a);
		ft_firstscore(all->stack_b, all->len_b);
		ft_minscore(all, score);
		ft_sortscore(all, score);
	}
	if ((ft_count_to_min(all->stack_a, all->min)) > all->len_a / 2)
	{
		while (all->stack_a->num != all->min)
			ft_reverserotate_a(&all->stack_a, 1);
	}
	else
		while (all->stack_a->num != all->min)
			ft_rotate_a(&all->stack_a, 1);
	free(score);
}
