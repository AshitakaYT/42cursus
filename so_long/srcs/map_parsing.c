/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:01:00 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/28 11:06:50 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_is_cep01(char c)
{
	if (c != '0' && c != '1'
		&& c != 'E' && c != 'C'
		&& c != 'P')
		return (0);
	return (1);
}

int	ft_is_one_cep(struct s_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->mapchar[i])
	{
		j = 0;
		while (map->mapchar[i][j])
		{
			if (!ft_is_cep01(map->mapchar[i][j]))
				return (0);
			else if (map->mapchar[i][j] == 'E')
				map->exit++;
			else if (map->mapchar[i][j] == 'C')
				map->col++;
			else if (map->mapchar[i][j] == 'P')
				map->pos++;
			j++;
		}
		i++;
	}
	if (map->exit != 1 || map->col == 0 || map->pos != 1)
		return (0);
	return (1);
}

int	ft_is_parsing_ok(struct s_map *map)
{
	map->exit = 0;
	map->col = 0;
	map->pos = 0;
	if (!ft_is_size_ok(map))
		return (0);
	if (!ft_is_one_cep(map))
		return (0);
	if (!ft_is_wall_ok(*map))
		return (0);
	return (1);
}

int	ft_get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_parsing(char *av, t_program *program)
{
	if (!ft_check_ber(av))
		return (0);
	program->map.file = ft_get_file(av);
	if (!program->map.file)
		return (0);
	program->map.mapchar = ft_split(program->map.file, '\n');
	free(program->map.file);
	if (!program->map.mapchar || !program->map.mapchar[0])
		return (0);
	program->map.mapheight = ft_get_height(program->map.mapchar);
	if (!ft_is_parsing_ok(&program->map))
	{
		ft_free_fct(program->map.mapchar, program->map.mapheight);
		return (0);
	}
	return (1);
}
