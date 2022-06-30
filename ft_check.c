/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_spaces(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n' || string[i] == '\t' || string[i] == '\v'
			|| string[i] == '\r' || string[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_valid_argv(char *str)
{
	int	i;
	int	count;
	int	s;

	i = 0;
	s = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			count ++;
		else if (((str[i] == '+' || str[i] == '-') && (str[i + 1]))
			&& (s == 0 && count == 0))
			s ++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (count == 0 && s != 0)
				ft_error();
			s = 0;
			count = 0;
		}
		else
			ft_error();
		i ++;
	}
}

void	ft_valid_check(char *ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		if (ar[i] >= '0' && ar[i] <= '9')
			return ;
		i ++;
	}
	ft_error();
}

int	ft_parse(int argc, char **argv)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (i < argc)
	{
		if (ft_spaces(argv[i]))
		{
			ft_valid_check(argv[i]);
			ft_valid_argv(argv[i]);
			flag = 1;
		}
		i++;
	}
	return (flag);
}
