/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:54:48 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/18 20:49:59 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bool	load_map(char *map_path, t_strc *strc)
{
	strc->img.int_path = open(map_path, O_RDONLY);
	if (strc->img.int_path < 0)
		exit_map_error(&strc->map, "Cannot open the map", NULL, 0);
	map_data(&strc->map, &strc->player, &strc->img.int_path);
	return (TRUE);
}

void	load_game_img(t_image *img, t_game *game, int width, int height)
{
	img->ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size,
			&img->endian);
	img->width = width;
	img->height = height;
}

void	init_img(t_image *img, t_game *game, t_map *map)
{
	load_game_img(img, game, WIDTH, HEIGHT);
	load_game_img(&map->no_text, game, 64, 64);
	load_game_img(&map->so_text, game, 64, 64);
	load_game_img(&map->we_text, game, 64, 64);
	load_game_img(&map->ea_text, game, 64, 64);
}

void	load_game(t_strc *strc, char *map_path)
{
	load_map(map_path, strc);
	strc->game.mlx_ptr = mlx_init();
	strc->game.window_ptr = mlx_new_window(strc->game.mlx_ptr, WIDTH,
			HEIGHT, "Cub3D");
	strc->game.screen_width = WIDTH;
	strc->game.screen_height = HEIGHT;
	strc->window.width = WIDTH;
	strc->window.height = HEIGHT;
	init_img(&strc->img, &strc->game, &strc->map);
}
