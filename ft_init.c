/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_contein(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->num == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_initiation(t_stack *element, int number, int flag)
{
	element->num = number;
	element->index = flag;
	element->next = NULL;
}

void	ft_init_push(t_stack **stack, int number, char **mass)
{
	t_stack	*element;
	t_stack	*last;

	last = *stack;
	element = (t_stack *)malloc(sizeof(t_stack));
	if (!ft_contein(*stack, number) || !element)
	{
		ft_clean_split(mass);
		free(mass);
		ft_free_stack(stack);
		ft_error();
	}
	ft_initiation(element, number, -1);
	if (!last)
	{
		*stack = element;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = element;
}

void	ft_copying(int argc, char **argv, t_all *all)
{
	int		i;
	int		j;
	char	**mass_str;

	i = 1;
	all->len_a = 0;
	all->len_b = 0;
	while (i < argc)
	{
		j = -1;
		mass_str = ft_split(argv[i], ' ');
		if (!mass_str)
			ft_error();
		while (mass_str[++j])
		{
			ft_min_max(ft_atoii(mass_str[j]), mass_str);
			ft_init_push(&(all->stack_a), ft_atoii(mass_str[j]), mass_str);
			all->len_a ++;
		}
		ft_clean_split(mass_str);
		free(mass_str);
		i++;
	}
}

void	ft_initscore(t_score *score)
{
	score->count_a = -1;
	score->count_a = -1;
	score->flag_a = 0;
	score->flag_b = 0;
}
