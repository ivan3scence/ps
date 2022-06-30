/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_SwapPush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack *stack, int flag)
{
	int	buffer;

	buffer = 0;
	buffer = stack->num;
	stack->num = stack->next->num;
	stack->next->num = buffer;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack *stack, int flag)
{
	int	buffer;

	buffer = 0;
	buffer = stack->num;
	stack->num = stack->next->num;
	stack->next->num = buffer;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ft_swap_a_b(t_all *all, int flag)
{
	ft_swap_a(all->stack_a, flag);
	ft_swap_b(all->stack_b, flag);
	if (flag == 1)
		write (1, "ss\n", 3);
}

void	ft_push_a(t_all *all, int flag)
{
	t_stack	*a;

	all->len_a ++;
	all->len_b --;
	a = all->stack_b;
	all->stack_b = all->stack_b->next;
	a->next = all->stack_a;
	all->stack_a = a;
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	ft_push_b(t_all *all, int flag)
{
	t_stack	*b;

	all->len_a --;
	all->len_b ++;
	b = all->stack_a;
	all->stack_a = all->stack_a->next;
	b->next = all->stack_b;
	all->stack_b = b;
	if (flag == 1)
		write(1, "pb\n", 3);
}
