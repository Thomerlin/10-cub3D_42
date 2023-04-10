/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:13:29 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/09 23:10:20 by tyago-ri         ###   ########.fr       */
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
# include <math.h>

# define ERROR_WALL "The map need to be close and not have spaces in the middle"
# define BREAK_ERROR "the map have 2 consecutive break lines"
# define MUCH_PLAYER_ERROR "number of players is more than 1"
# define WRONG_CHAR "wrong char in the map"

# define FREE_MATRIX 1
# define FREE_CHAR 2

# define WIDTH 	1080
# define HEIGHT	720

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

typedef struct s_window
{
	void	*ptr;
	int		width;
	int		height;
}	t_window;

/**
 * @brief struct of game information
 * 
 */
typedef struct s_game
{
	t_image		img;
	// t_window	window;
	void		*window_ptr;
	void		*mlx_ptr;
	int			screen_width;
	int			screen_height;
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
	char		player_dir;
	int			player_num;
}	t_player;

typedef struct s_line
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	dist_y;
	int	dist_x;
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
	int			s_color;
	int			f_color;
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
	t_image		img;
	t_window	window;
	t_camera	camera;
	t_map		map;
	t_player	player;
	t_draw		draw;
	t_dda		dda;
}	t_strc;

// validate map chars
/**
 * @brief Validate if map have corret chars and take player posix
 * 
 * @param strc struct of game structs
 * @param map map matrix
 */
void	check_chars(t_strc *strc, char **map);
///
// load map
/**
 * @brief check map information and load textures and map info
 * 
 * @param strc struct of game structs
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
 * @param message error message
 */
void	exit_map_error(t_strc *strc, char *message, char *str, int exit_mode);
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
void	check_map_break_line(char *map_line, t_strc *strc);
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
void	img_pixel_put(t_image img, int x, int y, int color);
void	init_perpendicular(t_strc *c);
void	init_raydir_and_delta(t_strc *c);
void	init_camera(t_strc *c);
void	init_dist_to_side(t_strc *c);
void	init_step_xy(t_strc *c);
void	raycasting(t_strc *c, int pixel);
void	dda(t_strc *c);
void	bresenham(t_vector *point1, t_vector *point2, t_strc *c, int color);

void	get_player_data(t_strc *strc, int x, int y);

#endif
