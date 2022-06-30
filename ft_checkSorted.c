/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkSorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sortedstack(t_stack **stack)
{
	t_stack	*list;
	t_stack	*next;

	list = *stack;
	next = list->next;
	while (list && next)
	{
		if (next->num > list->num)
		{
			list = next;
			next = list->next;
		}
		else
			return (0);
	}
	return (1);
}
