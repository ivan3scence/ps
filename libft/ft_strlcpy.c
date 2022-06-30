/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:37:50 by sdonny            #+#    #+#             */
/*   Updated: 2021/10/11 15:18:46 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		size;
	size_t		sl;

	sl = ft_strlen(src);
	size = dstsize;
	if (dstsize == 0)
		return (sl);
	while ((dstsize - 1 > 0) && *src)
	{
		*(unsigned char *)(dst++) = *(unsigned char *)(src++);
		dstsize--;
	}
	if (size > 0)
		*(unsigned char *) dst = '\0';
	return (sl);
}
