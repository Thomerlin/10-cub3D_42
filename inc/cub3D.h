/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:13:29 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/01 12:49:19 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <X11/keysymdef.h>
# include <X11/X.h>
# include <mlx.h>
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef enum s_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_game
{
	void	*wind;
	void	*mlx;
	int		screen_width;
	int		screen_height;
}	t_game;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_texture
{
	int		width;
	int		height;
}	t_texture;

typedef struct s_draw
{
	int				wall_line_height;
	int				start;
	int				end;
	double			wall_x;
}	t_draw;

typedef struct s_vector
{
	double		y;
	double		x;
}	t_vector;

typedef struct s_camera
{
	t_vector	pixel;
	t_vector	plane;
	t_vector	speed;
}	t_camera;

typedef struct s_player
{
	t_vector	dir;
	t_vector	pos;
	t_camera	camera;
}	t_player;

typedef struct s_line
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	dy;
	int	dx;
}	t_line;

typedef struct s_hit
{
	t_bool		hit;
	int			side;
}	t_hit;

typedef struct s_dda
{
	int			pixel;
	double		perpendicular;
	t_hit		hit;
	t_vector	delta;
	t_vector	to_side;
	t_vector	step;
	t_vector	raydir;
	t_vector	line_size;
	t_vector	wall_pos;
}	t_dda;

typedef struct s_map
{
	int			no_textu;
	int			so_textu;
	int			we_textu;
	int			ea_textu;
	char		**map;
	int			path;
	int			wall_start;
	t_player	player;
}	t_map;

typedef struct s_strc
{
	t_game	game;
	t_map	map;
}	t_strc;

typedef struct s_algo
{
	t_game		mlx;
	t_map		map;
	t_dda		dda;
	t_draw		draw;
}	t_algo;

int		exit_game(t_strc *strc);
void	exit_map_error(t_strc *strc);
void	load_game(t_strc *strc, char *map_path);
t_bool	check_text_data(char **textures, t_strc *strc);
void	check_map_break_line(char *map_line);
void	check_map_is_close(t_strc *strc);
int		wall_posix(char *map_line, int posix_mode);
t_bool	check_lef_wall(char **map, int start_wall, int y_inx, int next_wall);
t_bool	check_rig_wall(char **map, int start_wall, int y_inx, int next_wall);

// color
int		get_rgb(int r, int g, int b);
void	itorgb(int color, t_rgb *result);
void	intorgb(int *r, int *g, int *b, unsigned int *color);

// algorithm
void	init_perpendicular(t_algo *c);
void	init_raydir_and_delta(t_algo *c);
void	init_camera(t_map *map, t_algo *c);
void	init_dist_to_side(t_algo *c);
void	init_step_xy(t_algo *c);
void	raycasting(t_algo *c, int pixel);
void	dda(t_algo *c);
void	bresenham(t_vector *point1, t_vector *point2, t_algo *c, int color);

#endif
