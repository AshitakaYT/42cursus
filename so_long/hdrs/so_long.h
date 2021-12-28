/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:48:18 by aucousin          #+#    #+#             */
/*   Updated: 2021/12/19 11:37:56 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

//# include "../mlx/mlx_int.h"

typedef struct s_map
{
	char	**mapchar;
	int		mapwidth;
	int		mapheight;
	char	*file;
	int		exit;
	int		col;
	int		pos;
}			t_map;

typedef struct s_ptrs
{
	void	*win_ptr;
	void	*mlx_ptr;
}			t_ptrs;

char	*ft_fullfill_tab(int fd, char *res1, char buf);
char	*ft_get_file(char *dico);
int		ft_is_size_ok(struct s_map *map);
int		ft_check_wall_line(char *str);
int		ft_is_wall_ok(struct s_map map);

#endif