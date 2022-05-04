/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:24:42 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/28 11:49:29 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

void	ft_moveup(t_program *program, char toreplace)
{
	if (toreplace == 'E')
	{
		if (program->map.col != 0)
		{
			ft_printf("\033[2K\rYou need %d more behelit.\e[0m", program->map.col);
			return ;
		}
		ft_printf("\033[2K\rMoves : %d -----  GG !!\n", program->moves + 1);
		ft_free_fct(program->map.mapchar, program->map.mapheight);
		ft_close(program);
	}
	else if (toreplace != '1')
	{
		if (toreplace == 'C')
			program->map.col--;
		program->map.mapchar[program->sprite_position.i - 1]
		[program->sprite_position.j] = 'P';
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j] = '0';
		program->sprite_position.y -= program->sprite.size.y;
		program->moves++;
		ft_printf("\033[2K\rMoves : %d\e[0m", program->moves);
	}
}

void	ft_moveright(t_program *program, char toreplace)
{
	if (toreplace == 'E')
	{
		if (program->map.col != 0)
		{
			ft_printf("\033[2K\rYou need %d more behelit.\e[0m", program->map.col);
			return ;
		}
		ft_printf("\033[2K\rMoves : %d -----  GG !!\n", program->moves + 1);
		ft_free_fct(program->map.mapchar, program->map.mapheight);
		ft_close(program);
	}
	else if (toreplace != '1')
	{
		if (toreplace == 'C')
			program->map.col--;
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j + 1] = 'P';
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j] = '0';
		program->sprite_position.x += program->sprite.size.x;
		program->moves++;
		ft_printf("\033[2K\rMoves : %d\e[0m", program->moves);
	}
}

void	ft_moveleft(t_program *program, char toreplace)
{
	if (toreplace == 'E')
	{
		if (program->map.col != 0)
		{
			ft_printf("\033[2K\rYou need %d more behelit.\e[0m", program->map.col);
			return ;
		}
		ft_printf("\033[2K\rMoves : %d -----  GG !!\n", program->moves + 1);
		ft_free_fct(program->map.mapchar, program->map.mapheight);
		ft_close(program);
	}
	else if (toreplace != '1')
	{
		if (toreplace == 'C')
			program->map.col--;
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j - 1] = 'P';
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j] = '0';
		program->sprite_position.x -= program->sprite.size.x;
		program->moves++;
		ft_printf("\033[2K\rMoves : %d\e[0m", program->moves);
	}
}

void	ft_movedown(t_program *program, char toreplace)
{
	if (toreplace == 'E')
	{
		if (program->map.col != 0)
		{
			ft_printf("\033[2K\rYou need %d more behelit.\e[0m", program->map.col);
			return ;
		}
		ft_printf("\033[2K\rMoves : %d -----  GG !! \n", program->moves + 1);
		ft_free_fct(program->map.mapchar, program->map.mapheight);
		ft_close(program);
	}
	else if (toreplace != '1')
	{
		if (toreplace == 'C')
			program->map.col--;
		program->map.mapchar[program->sprite_position.i + 1]
		[program->sprite_position.j] = 'P';
		program->map.mapchar[program->sprite_position.i]
		[program->sprite_position.j] = '0';
		program->sprite_position.y += program->sprite.size.y;
		program->moves++;
		ft_printf("\033[2K\rMoves : %d\e[0m", program->moves);
	}
}
