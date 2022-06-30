/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*start;
	t_stack	*next;

	start = *stack;
	while (start)
	{
		next = start->next;
		free(start);
		start = next;
	}
	*stack = NULL;
}

void	ft_free(t_all *all)
{
	ft_free_stack(&all->stack_a);
	ft_free_stack(&all->stack_b);
}
