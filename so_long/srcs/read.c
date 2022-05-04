/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 11:19:05 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/27 16:48:50 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

char	*ft_fullfill_tab(int fd, char *res1, char buf)
{
	int	size;

	size = 0;
	while (read(fd, &buf, 1))
	{
		res1[size] = buf;
		if (size > 0 && res1[size] == '\n' && res1[size - 1] == '\n')
		{
			free(res1);
			return (NULL);
		}
		size++;
	}
	res1[size] = '\0';
	return (res1);
}

char	*ft_get_file(char *dico)
{
	int		fd;
	char	*res1;
	int		size;
	char	buf;

	size = 0;
	fd = open(dico, O_RDWR);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1))
		size++;
	res1 = malloc(sizeof(char) * size + 1);
	if (!res1)
		return (0);
	if (close(fd) == -1)
		return (0);
	fd = open(dico, O_RDWR);
	if (fd == -1)
		return (0);
	res1 = ft_fullfill_tab(fd, res1, buf);
	close(fd);
	return (res1);
}
