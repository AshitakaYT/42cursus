/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:24:42 by aucousin          #+#    #+#             */
/*   Updated: 2022/01/01 15:42:54 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_moveup(t_program *program)
{
	if (program->map.mapchar[program->sprite_position.i - 1]
		[program->sprite_position.j] == 'E')
	{
		printf("Show me your moves ! ----- %d -----  GG !! \n", program->moves);
		ft_free_fct(program->map.mapchar, program->map.mapheight);
		ft_close(program);
	}
	if (program->map.mapchar[program->sprite_position.i - 1]
		[program->sprite_position.j] != '1')
	{
		program->map.mapchar[program->sprite_position.i - 1]
		[program->sprite_position.j] = 'P';
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j] = '0';
		program->sprite_position.y -= program->sprite.size.y;
		program->moves++;
	}
}

void	ft_movedown(t_program *program)
{
	if (program->map.mapchar[program->sprite_position.i + 1]
		[program->sprite_position.j] == 'E')
	{
		printf("Show me your moves ! ----- %d -----  GG !! \n", program->moves);
		ft_free_fct(program->map.mapchar, program->map.mapheight);
		ft_close(program);
	}
	if (program->map.mapchar[program->sprite_position.i + 1]
		[program->sprite_position.j] != '1')
	{
		program->map.mapchar[program->sprite_position.i + 1]
		[program->sprite_position.j] = 'P';
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j] = '0';
		program->sprite_position.y += program->sprite.size.y;
		program->moves++;
	}
}

void	ft_moveleft(t_program *program)
{
	if (program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j - 1] == 'E')
	{
		printf("Show me your moves ! ----- %d -----  GG !! \n", program->moves);
		ft_free_fct(program->map.mapchar, program->map.mapheight);
		ft_close(program);
	}
	if (program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j - 1] != '1')
	{
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j - 1] = 'P';
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j] = '0';
		program->sprite_position.x -= program->sprite.size.x;
		program->moves++;
	}
}

void	ft_moveright(t_program *program)
{
	if (program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j + 1] == 'E')
	{
		printf("Show me your moves ! ----- %d -----  GG !! \n", program->moves);
		ft_free_fct(program->map.mapchar, program->map.mapheight);
		ft_close(program);
	}
	if (program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j + 1] != '1')
	{
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j + 1] = 'P';
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j] = '0';
		program->sprite_position.x += program->sprite.size.x;
		program->moves++;
	}
}
