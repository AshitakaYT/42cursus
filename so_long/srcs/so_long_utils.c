/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:05:05 by aucousin          #+#    #+#             */
/*   Updated: 2021/12/19 11:41:41 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = ft_strlen(str);
	write(1, str, i);
}

void	ft_print_char_tab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		ft_putstr(tab[y]);
		ft_putchar('\n');
		y++;
	}
}

char	*ft_fullfill_tab(int fd, char *res1, char buf)
{
	int	size;

	size = 0;
	while (read(fd, &buf, 1))
	{
		res1[size] = buf;
		size++;
	}
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
	res1[size] = '\0';
	close(fd);
	return (res1);
}

int	ft_is_size_ok(struct s_map *map)
{
	int	i;

	i = 0;
	ft_print_char_tab(map->mapchar);
	if (!map->mapchar || !map->mapchar[i])
		return (0);
	map->mapwidth = ft_strlen(map->mapchar[i]);
	while (map->mapchar[i])
	{
		if (ft_strlen(map->mapchar[i]) != map->mapwidth)
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	map->mapheight = i;
	return (1);
}

int	ft_check_wall_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_wall_ok(struct s_map map)
{
	int	i;

	i = 0;
	printf("mapwidth = %d\n", map.mapwidth);
	printf("mapheight = %d\n", map.mapheight);
	while (map.mapchar[i])
	{
		if (map.mapchar[i][0] != '1' || map.mapchar[i][map.mapwidth - 1] != '1')
			return (0);
		i++;
	}
	if (!ft_check_wall_line(map.mapchar[0]) || \
		!ft_check_wall_line(map.mapchar[i - 1]))
		return (0);
	return (1);
}
