/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:13:29 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/21 19:18:57 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define XK_MISCELLANY
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <mlx.h>
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define ERROR_WALL "Invalid map"
# define BREAK_ERROR "the map have 2 consecutive break lines"
# define MUCH_PLAYER_ERROR "number of players is more than 1"
# define WRONG_CHAR "wrong char in the map"
# define TEXT_ERROR "missing texture or wrong path"

# define FREE_MAP 1
# define FREE_STR 2

# define WIDTH 	1080
# define HEIGHT	720

# define STOP 0
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

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
	char		*path;
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
	void		*window_ptr;
	void		*mlx_ptr;
	int			screen_w;
	int			screen_h;
}	t_game;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	color;
}	t_rgb;

typedef struct s_vector
{
	double		x;
	double		y;
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
	double		ang;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			turn_left;
	int			turn_right;
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
	t_image		no_text;
	t_image		so_text;
	t_image		we_text;
	t_image		ea_text;
	char		**map;
	t_rgb		sky;
	t_rgb		floor;
}	t_map;

typedef struct s_draw
{
	unsigned int	color;
	int				wall_line_h;
	int				start;
	int				end;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
}	t_draw;

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
	t_dda		dda;
	t_draw		draw;
}	t_strc;

// validate map chars
/**
 * @brief Validate if map have corret chars and take player posix
 * 
 * @param strc struct of game structs
 * @param map map matrix
 */
void	check_chars(t_strc *strc, char **map);

// load file
/**
 * @brief check map information and load textures and map info
 * 
 * @param strc struct of game structs
 * @return TRUE if information is correct FALSE if cannot load or 
 * information is wrong
 */
t_bool	map_data(t_map *map, t_player *player, int *img_path);

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
 * @param str char to be free
 * @param exit_mode exit with 3 diferent options: 0 only exit; 1 or FREE_MATRIX
 *  free the map and exit; 2 or FREE_STR free str param and exit
 */
void	exit_map_error(t_map *map, char *message, char *str, int exit_mode);
/**
 * @brief Get the map RGB of the sky and floor
 * 
 * @param map struck with map data
 * @param data matrix with file data
 */
void	get_map_colors(t_map *map, char **data);
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
 * @param map map info struct
 * @return if can open textures and extension is corret return TRUE else FALSE
 */
t_bool	check_data(char **data, t_map *map);
/**
 * @brief check if map as 2 consecutive break line 
 * 
 * @param map_line an array of the whole map
 */
void	check_map_break_line(char *map_line, t_map *map);
/**
 * @brief check all lines of the map and validate if is correct
 * 
 * @param strc struct of game structs
 */
void	check_map(t_map *map, t_player *player);
///

// render
/**
 * @brief calls all funtions of rendering
 * 
 * @param strc struct of game structs
 */
int		render(t_strc *strc);

/**
 * @brief Get the pixel object
 * 
 * @param img 
 * @param x 
 * @param y 
 * @return int 
 */
int		get_pixel(t_image *img, int x, int y);
/**
 * @brief 
 * 
 * @param img 
 * @param x 
 * @param y 
 * @param color 
 */
void	img_pixel_put(t_image *img, int x, int y, int color);
///

// color
/**
 * @brief Get the rgb object
 * 
 * @param r 
 * @param g 
 * @param b 
 * @return int 
 */
int		get_rgb(int r, int g, int b);

// algorithm
/**
 * @brief 
 * 
 * @param c 
 */
void	init_perpendicular(t_strc *strc);

/**
 * @brief 
 * 
 * @param c 
 */
void	init_raydir_and_delta(t_strc *strc);

/**
 * @brief 
 * 
 * @param c 
 */
void	init_camera(t_strc *strc);

/**
 * @brief 
 * 
 * @param c 
 */
void	init_dist_to_side(t_strc *strc);

/**
 * @brief 
 * 
 * @param c 
 */
void	init_step_xy(t_strc *strc);

/**
 * @brief 
 * 
 * @param c 
 * @param pixel 
 */
void	raycasting(t_strc *strc, int pixel, t_image	img_text);

/**
 * @brief 
 * 
 * @param c 
 */
void	dda(t_strc *strc);

// init_player
/**
 * @brief Get the player data object
 * 
 * @param map 
 * @param player 
 * @param x 
 * @param y 
 */
void	get_player_data(t_map *map, t_player *player, int x, int y);

// player
/**
 * @brief 
 * 
 * @param strc 
 */
void	move(t_strc *strc);

/**
 * @brief 
 * 
 * @param vector 
 * @param ang 
 */
void	rotate_vector(t_vector *vector, double ang);

/**
 * @brief 
 * 
 * @param strc 
 */
void	look_left(t_strc *strc);

/**
 * @brief 
 * 
 * @param strc 
 */
void	look_right(t_strc *strc);

/**
 * @brief 
 * 
 * @param key 
 * @param strc 
 * @return int 
 */
int		key_unpressed(int key, t_strc *strc);

/**
 * @brief 
 * 
 * @param key 
 * @param strc 
 * @return int 
 */
int		key_pressed(int key, t_strc *strc);

/**
 * @brief 
 * 
 * @param strc 
 * @param pixel 
 * @param img_text 
 */
void	show_texture(t_strc *strc, int pixel, t_image *img_text);

#endif
