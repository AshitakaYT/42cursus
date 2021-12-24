/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:55:40 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/18 21:16:41 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

static void	ft_read(char **lines, char *buff, int fd)
{
	char	*tmp;
	int		i;

	if (!*lines)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		*lines = ft_substr(buff, 0, i);
	}
	if (!ft_strchr(*lines, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		while (i > 0 && !ft_strchr(*lines, '\n'))
		{
			buff[i] = '\0';
			tmp = *lines;
			*lines = ft_strjoin(*lines, buff);
			free(tmp);
			if (ft_strchr(*lines, '\n'))
				break ;
			i = read(fd, buff, BUFFER_SIZE);
		}
	}
}

char	*ft_return(char **lines)
{
	char	*tmp;
	char	*ret;
	int		j;

	if (!*lines)
		return (NULL);
	if (!ft_strchr(*lines, '\n'))
	{
		if (*lines[0] == '\0')
		{
			free(*lines);
			*lines = NULL;
			return (NULL);
		}
		ret = ft_substr(*lines, 0, ft_strlen(*lines));
		free(*lines);
		*lines = NULL;
		return (ret);
	}
	j = ft_strlen(ft_strchr(*lines, '\n'));
	ret = ft_substr(*lines, 0, ft_strlen(*lines) - j + 1);
	tmp = *lines;
	*lines = ft_substr(ft_strchr(*lines, '\n'), 1, j);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*lines;

	if (fd < 0 || read(fd, buff, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	ft_read(&lines, buff, fd);
	return (ft_return(&lines));
}
