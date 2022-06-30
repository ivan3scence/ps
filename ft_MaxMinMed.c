/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_MaxMinMed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_copy_from_stack(int	*buf, t_stack *stack)
{
	t_stack	*start;
	int		i;

	start = stack;
	i = 0;
	while (stack)
	{
		buf[i] = stack->num;
		stack = stack->next;
		i++;
	}
	stack = start;
	return (buf);
}

int	ft_len_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		result;

	result = 0;
	tmp = stack;
	while (stack)
	{
		stack = stack->next;
		result++;
	}
	stack = tmp;
	return (result);
}

int	*ft_result_sort(int	*mass, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < (len - 1))
	{
		j = -1;
		while (++j < (len - i - 1))
		{
			if (mass[j] > mass[j + 1])
			{
				tmp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = tmp;
			}
		}
	}
	return (mass);
}

void	ft_list_sort(t_stack *stack, t_all *all)
{
	int	len;
	int	*buffer;

	len = ft_len_stack(stack);
	all->len_a = len;
	all->len_b = 0;
	buffer = malloc(sizeof(int) * len);
	if (!buffer)
		return ;
	buffer = ft_copy_from_stack(buffer, stack);
	buffer = ft_result_sort(&(*buffer), len);
	all->max = buffer[len - 1];
	all->min = buffer[0];
	all->med = buffer[len / 2];
	free(buffer);
}
