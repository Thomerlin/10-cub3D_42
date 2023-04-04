/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:13:29 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/04 00:49:50 by llopes-n         ###   ########.fr       */
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

typedef struct s_image
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line_size;
	int			endian;
	int			width;
	int			height;
	int			sky_color;
	int			floor_color;
}	t_image;

typedef struct s_win
{
	void	*ptr;
	int		width;
	int		height;
}	t_win;

/**
 * @brief struct of game information
 * 
 */
typedef struct s_game
{
	void	*wind_ptr;
	void	*mlx_ptr;
	int		screen_width;
	int		screen_height;
	t_win	win;
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

/**
 * @brief struct containing information of the map
 * 
 */
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

/**
 * @brief an struct containing others structs of the game making easy for 
 * access
 * 
 */
typedef struct s_strc
{
	t_game		game;
	t_map		map;
	t_dda		dda;
	t_draw		draw;
	t_player	player;
	t_image		img;
}	t_strc;

// load map
/**
 * @brief check map information and load textures and map info
 * 
 * @param strc 
 * @return TRUE if information is correct FALSE if cannot load or 
 * information is wrong
 */
t_bool	map_data(t_strc *strc);
///
// exit
/**
 * @brief close window and exit of the game with success
 * 
 * @param strc struct of game structs
 * @return exit with 0
 */
int		exit_game(t_strc *strc);
/**
 * @brief if map have error free the map and exit with 1
 * 
 * @param strc struct of game structs
 */
void	exit_map_error(t_strc *strc);
///

// load game
/**
 * @brief call map_data and map verification and init window
 * 
 * @param strc struct of game structs
 * @param map_path char of the parameter with map path
 */
void	load_game(t_strc *strc, char *map_path);
///

// validate
/**
 * @brief load textures an check textures extension
 * 
 * @param textures path of the textures
 * @param strc struct of game structs
 * @return if can open textures and extension is corret TRUE else FALSE
 */
t_bool	check_text_data(char **textures, t_strc *strc);
/**
 * @brief check if map as 2 consecutive break line 
 * 
 * @param map_line an array of the whole map
 */
void	check_map_break_line(char *map_line);
/**
 * @brief check all lines of the map and validate if is correct
 * 
 * @param strc struct of game structs
 */
void	check_map(t_strc *strc);
///

// render
/**
 * @brief calls all funtions of rendering
 * 
 * @param strc struct of game structs
 */
int		render(t_strc *strc);
///

// color
int		get_rgb(int r, int g, int b);
void	itorgb(int color, t_rgb *result);
void	intorgb(int *r, int *g, int *b, unsigned int *color);

// algorithm
void	init_perpendicular(t_strc *c);
void	init_raydir_and_delta(t_strc *c);
void	init_camera(t_map *map, t_strc *c);
void	init_dist_to_side(t_strc *c);
void	init_step_xy(t_strc *c);
void	raycasting(t_strc *c, int pixel);
void	dda(t_strc *c);
void	bresenham(t_vector *point1, t_vector *point2, t_strc *c, int color);

#endif
