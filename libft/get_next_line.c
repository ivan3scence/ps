/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:37:50 by sdonny            #+#    #+#             */
/*   Updated: 2021/10/11 15:18:46 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ost_from_line(char *str_file)
{
	unsigned int	len_n;
	unsigned int	i;
	char			*ost;

	len_n = 0;
	i = 0;
	while (str_file[len_n] != '\n' && str_file[len_n])
		len_n++;
	if (!str_file[len_n])
	{
		free(str_file);
		return (NULL);
	}
	ost = (char *)malloc(sizeof(char) * (ft_strlen(str_file) - len_n + 1));
	if (!ost)
		return (NULL);
	len_n++;
	while (str_file[len_n] && str_file[len_n] != '\0')
		ost[i++] = str_file[len_n++];
	ost[i] = '\0';
	free(str_file);
	return (ost);
}

static char	*ft_copy_line(char *str_file)
{
	unsigned int	i;
	char			*new_line;

	i = 0;
	if (!str_file[i])
		return (NULL);
	while (str_file[i] != '\n' && str_file[i])
		i++;
	new_line = (char *)malloc((i + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = -1;
	while (str_file[++i] && str_file[i] != '\n')
		new_line[i] = str_file[i];
	if (str_file[i] == '\n')
	{
		new_line[i] = str_file[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

static char	*ft_read_from_file(int fd, char *str_file, char *buf)
{
	int		kol_b;
	char	*string;

	kol_b = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		free(str_file);
	if (!buf)
		return (NULL);
	while (!ft_strchr(str_file, '\n') && kol_b > 0)
	{
		kol_b = read(fd, buf, BUFFER_SIZE);
		if (kol_b == -1)
		{
			free(buf);
			free(str_file);
			return (NULL);
		}
		buf[kol_b] = '\0';
		string = str_file;
		str_file = ft_strjoin(str_file, buf);
		free(string);
	}
	free(buf);
	return (str_file);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*buf;
	static char	*str_file;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(str_file))
		str_file = ft_strdup("");
	str_file = ft_read_from_file(fd, str_file, buf);
	if (!(str_file))
		return (NULL);
	result = ft_copy_line(str_file);
	str_file = ft_ost_from_line(str_file);
	return (result);
}
