/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:16:07 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/16 00:33:31 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

static void	ft_read(char **lines, char *buff, int fd)
{
	char	*tmp;
	int		i;

	if (!lines[fd])
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		lines[fd] = ft_substr(buff, 0, i);
	}
	if (!ft_strchr(lines[fd], '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		while (i > 0 && !ft_strchr(lines[fd], '\n'))
		{
			buff[i] = '\0';
			tmp = lines[fd];
			lines[fd] = ft_strjoin(lines[fd], buff);
			free(tmp);
			if (ft_strchr(lines[fd], '\n'))
				break ;
			i = read(fd, buff, BUFFER_SIZE);
		}
	}
}

char	*ft_return(char **lines, int fd)
{
	char	*tmp;
	char	*ret;
	int		j;

	if (!lines[fd])
		return (NULL);
	if (!ft_strchr(lines[fd], '\n'))
	{
		if (lines[fd][0] == '\0')
		{
			free(lines[fd]);
			lines[fd] = NULL;
			return (NULL);
		}
		ret = ft_substr(lines[fd], 0, ft_strlen(lines[fd]));
		free(lines[fd]);
		lines[fd] = NULL;
		return (ret);
	}
	j = ft_strlen(ft_strchr(lines[fd], '\n'));
	ret = ft_substr(lines[fd], 0, ft_strlen(lines[fd]) - j + 1);
	tmp = lines[fd];
	lines[fd] = ft_substr(ft_strchr(lines[fd], '\n'), 1, j);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*lines[OPEN_MAX + 1];

	if (fd < 0 || read(fd, buff, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	ft_read(lines, buff, fd);
	return (ft_return(lines, fd));
}
