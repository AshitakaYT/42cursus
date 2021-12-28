/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:01:00 by aucousin          #+#    #+#             */
/*   Updated: 2021/12/19 11:50:37 by aucousin         ###   ########lyon.fr   */
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

int	ft_is_one_cep(struct s_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map.mapchar[i])
	{
		j = 0;
		while (map.mapchar[i][j])
		{
			if (!ft_is_cep01(map.mapchar[i][j]))
				return (0);
			else if (map.mapchar[i][j] == 'E')
				map.exit = 1;
			else if (map.mapchar[i][j] == 'C')
				map.col = 1;
			else if (map.mapchar[i][j] == 'P')
				map.pos = 1;
			j++;
		}
		i++;
	}
	if (map.exit != 1 || map.col != 1 || map.pos != 1)
		return (0);
	return (1);
}

int	ft_is_parsing_ok(struct s_map map)
{
//	if (!ft_is_size_ok(map) || !ft_is_one_cep(map) || !ft_is_wall_ok(map))
	printf("ok\n");
	if (!ft_is_size_ok(&map))
		return (0);
	printf("ok\n");
	if (!ft_is_one_cep(map))
		return (0);
	printf("ok\n");
	if (!ft_is_wall_ok(map))
		return (0);
	printf("ok\n");
	return (1);
}

int	ft_so_long(char *av)
{
	t_map	map;

	if (!ft_get_file(av))
		return (0);
	map.file = ft_get_file(av);
	if (!map.file)
		return (0);
	printf("%s\n", map.file);
	map.mapchar = ft_split(map.file, '\n');
	if (!map.mapchar || !map.mapchar[0])
		return (0);
	if (!ft_is_parsing_ok(map))
		return (0);
	return (1);
}

int	ft_close(t_ptrs *ptr)
{
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	exit(EXIT_SUCCESS);
}

int	ft_mlx(void)
{
	t_ptrs	ptr;

	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 1000, 1000, "so long");
	mlx_hook(ptr.win_ptr, 17, 1L << 2, ft_close, &ptr);
	mlx_loop(ptr.mlx_ptr);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (ft_so_long(av[1]))
		printf("map OK\n");
	else
		printf("map KO\n");
	ft_mlx();
	return (0);
}
