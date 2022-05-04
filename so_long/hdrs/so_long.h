/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 08:28:13 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/28 11:40:50 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

// ----------------------------------
// MACROS

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

// ----------------------------------
// STRUCTS

/* vector with an x and y */
typedef struct s_vector
{
	int	x;
	int	y;
	int	i;
	int	j;
}				t_vector;

/* A pointer to the window and its size */
typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

/* The 4 values that define a color */
typedef struct s_color {
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

/* all info needed for an image */
typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

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

typedef struct s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_image		fond;
	t_image		coll;
	t_image		wall;
	t_image		exit;
	t_vector	sprite_position;
	t_vector	index;
	t_map		map;
	int			moves;
}				t_program;

// ---------------------------------
// FUNCTIONS

// MLX FCT--------------------------
t_window	ft_new_window(void *mlx, int widht, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);
t_color		new_color(int r, int g, int b, int a);
void		turn_img_to_color(t_image *image, t_color color);
int			ft_input(int key, void *program);
int			ft_update(void *param);
int			ft_close(t_program *win);
void		ft_mlx(t_program program);

// PARSINGS FCT------------------------
int			ft_is_one_cep(struct s_map *map);
int			ft_is_cep01(char c);
int			ft_parsing(char *av, t_program *program);
int			ft_is_parsing_ok(struct s_map *map);
int			ft_is_size_ok(struct s_map *map);
int			ft_check_wall_line(char *str);
int			ft_is_wall_ok(struct s_map map);
char		*ft_get_file(char *dico);
char		*ft_fullfill_tab(int fd, char *res1, char buf);
int			ft_check_ber(char *str);

// SO_LONG FCTS

int			ft_map(void *param, int xpos, int ypos);
void		ft_moveright(t_program *program, char toreplace);
void		ft_moveleft(t_program *program, char toreplace);
void		ft_moveup(t_program *program, char toreplace);
void		ft_movedown(t_program *program, char toreplace);

// UTILS

void		ft_print_char_tab(char **tab);
char		**ft_free_fct(char **split, int i);

#endif
