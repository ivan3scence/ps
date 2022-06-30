/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_units.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkk(unsigned long result, int sign)
{
	if (result >= 9223372036854775807 && sign > 0)
		return (-1);
	if (result >= 9223372036854775807 && sign < 0)
		return (0);
	return (1);
}

int64_t	ft_atoii(const char *str)
{
	int				i;
	unsigned long	result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (ft_checkk(result, sign) != 1)
		return (ft_checkk(result, sign));
	return (result * sign);
}

void	ft_min_max(int64_t res, char **mass_str)
{
	if (res > 2147483647 || res < -2147483648)
	{
		ft_clean_split(mass_str);
		ft_error();
	}
}
