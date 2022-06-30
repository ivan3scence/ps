/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}

int	ft_sortedstack_checker(t_stack **stack)
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

void	ft_terminalcheck(t_all *all, char *command)
{
	if (ft_strncmp(command, "sa", (ft_strlen(command) - 1)) == 0)
		f_swap_a(all, 0);
	else if (ft_strncmp(command, "sb", (ft_strlen(command) - 1)) == 0)
		f_swap_b(all, 0);
	else if (ft_strncmp(command, "ss", (ft_strlen(command) - 1)) == 0)
		f_swap_a_b(all, 0);
	else if (ft_strncmp(command, "pa", (ft_strlen(command) - 1)) == 0)
		f_push_a(all, 0);
	else if (ft_strncmp(command, "pb", (ft_strlen(command) - 1)) == 0)
		f_push_b(all, 0);
	else if (ft_strncmp(command, "ra", (ft_strlen(command) - 1)) == 0)
		f_rotate_a(all, 0);
	else if (ft_strncmp(command, "rb", (ft_strlen(command) - 1)) == 0)
		f_rotate_b(all, 0);
	else if (ft_strncmp(command, "rr", (ft_strlen(command) - 1)) == 0)
		f_rotate_a_b(all, 0);
	else if (ft_strncmp(command, "rra", (ft_strlen(command) - 1)) == 0)
		f_reverserotate_a(all, 0);
	else if (ft_strncmp(command, "rrb", (ft_strlen(command) - 1)) == 0)
		f_reverserotate_b(all, 0);
	else if (ft_strncmp(command, "rrr", (ft_strlen(command) - 1)) == 0)
		f_reverserotate_a_b(all, 0);
	else
		ft_error();
}

void	ft_line(t_all *all)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strlen(line) < 3 || ft_strlen(line) > 4)
			ft_error();
		ft_terminalcheck(all, line);
		free(line);
		line = NULL;
	}
}

int	main(int argc, char *argv[])
{
	t_stack		list;
	t_all		all;

	ft_stack_null(&all, &list);
	if (argc < 2)
		return (0);
	if (ft_parse(argc, argv))
	{
		ft_copying(argc, argv, &all);
		ft_line(&all);
		if ((ft_sortedstack_checker(&(all.stack_a))) && all.len_b == 0)
			write (1, "OK\n", 3);
		else
			write (1, "KO\n", 3);
	}
	ft_free(&all);
	return (0);
}
