/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:34:46 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/15 13:39:48 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/so_long.h"

void	ft_create_sprites(t_program *program)
{
	program->sprite = ft_new_sprite(program->mlx, "./imgs/gutsd.xpm");
	program->fond = ft_new_sprite(program->mlx, "./imgs/fond.xpm");
	program->coll = ft_new_sprite(program->mlx, "./imgs/behelith.xpm");
	program->wall = ft_new_sprite(program->mlx, "./imgs/wall.xpm");
	program->exit = ft_new_sprite(program->mlx, "./imgs/puzzle.xpm");
}

void	ft_mlx(t_program program)
{
	program.moves = 0;
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, (program.map.mapwidth * 100),
			(program.map.mapheight * 100), "./so_long");
	ft_create_sprites(&program);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x,
		program.sprite_position.y);
	ft_map(&program, 0, 0);
	mlx_key_hook(program.window.reference, *ft_input, &program);
	mlx_loop_hook(program.mlx, *ft_map, &program);
	mlx_loop(program.mlx);
}

int	main(int ac, char **av)
{
	t_program	program;

	if (ac != 2)
	{
		printf("Error\nPlease input a map file (and only one !)\n");
		return (0);
	}
	if (ft_parsing(av[1], &program))
		ft_mlx(program);
	else
		printf("Error\nMap KO\n");
	return (0);
}
