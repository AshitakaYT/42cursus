/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:46:28 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/28 11:43:06 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

/* Any functon that you hook with the key event must be like this:
* Recibing and int for the code of the key pressed
* and a void pointer in case you need to recibe something */

void	ft_print_elem(t_program *program, int xpos, int ypos)
{
	if (program->map.mapchar[program->index.y][program->index.x] == '1')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->wall.reference, xpos, ypos);
	else if (program->map.mapchar[program->index.y][program->index.x] == '0')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->fond.reference, xpos, ypos);
	else if (program->map.mapchar[program->index.y][program->index.x] == 'P')
	{
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite.reference, xpos, ypos);
		program->sprite_position.i = program->index.y;
		program->sprite_position.j = program->index.x;
	}
	else if (program->map.mapchar[program->index.y][program->index.x] == 'E')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->exit.reference, xpos, ypos);
	else if (program->map.mapchar[program->index.y][program->index.x] == 'C')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->coll.reference, xpos, ypos);
}

int	ft_map(void *param, int xpos, int ypos)
{
	t_program	*program;

	program = (t_program *)param;
	program->index.x = 0;
	program->index.y = 0;
	while (program->map.mapchar[program->index.y])
	{
		program->index.x = 0;
		xpos = 0;
		ft_print_elem(program, xpos, ypos);
		while (program->map.mapchar[program->index.y][program->index.x])
		{
			ft_print_elem(program, xpos, ypos);
			program->index.x++;
			xpos += 100;
		}
		ypos += 100;
		program->index.y++;
	}
	return (0);
}

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	mlx_clear_window(program->mlx, program->window.reference);
	ft_map(program, 0, 0);
	if (key == 2)
		ft_moveright(program, program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j + 1]);
	else if (key == 0)
		ft_moveleft(program, program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j - 1]);
	else if (key == 1)
		ft_movedown(program, program->map.mapchar
		[program->sprite_position.i + 1][program->sprite_position.j]);
	else if (key == 13)
		ft_moveup(program, program->map.mapchar[program->sprite_position.i - 1]
		[program->sprite_position.j]);
	else if (key == 53)
		ft_close(program);
	mlx_hook(program->window.reference, 17, 1L << 2, ft_close, program);
	ft_map(program, 0, 0);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*program;
	static int	frame;

	program = (t_program *)param;
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x,
		program->sprite_position.y);
	return (0);
}
