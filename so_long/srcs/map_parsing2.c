/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 11:14:43 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/28 09:11:38 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

void	ft_print_char_tab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		ft_putstr_fd(tab[y], 1);
		ft_putchar_fd('\n', 1);
		y++;
	}
}

int	ft_is_size_ok(struct s_map *map)
{
	int	i;

	i = 0;
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

int	ft_check_ber(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i > 4 && str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
	{
		return (1);
	}
	return (0);
}
