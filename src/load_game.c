/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:54:48 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/20 04:53:20 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bool	load_map(char *map_path, t_strc *strc)
{
	int	int_path;

	int_path = open(map_path, O_RDONLY);
	if (int_path < 0)
		exit_map_error(&strc->map, "Cannot open the map", NULL, 0);
	map_data(&strc->map, &strc->player, &int_path);
	return (TRUE);
}

void	load_game_text(t_image *img, t_game *game)
{
	img->ptr = mlx_xpm_file_to_image(game->mlx_ptr, img->path, &img->width,
			&img->height);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size,
			&img->endian);
}

void	init_img(t_image *img, t_game *game, t_map *map)
{
	img->ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size,
			&img->endian);
	load_game_text(&map->no_text, game);
	load_game_text(&map->so_text, game);
	load_game_text(&map->we_text, game);
	load_game_text(&map->ea_text, game);
}

void	load_game(t_strc *strc, char *map_path)
{
	load_map(map_path, strc);
	strc->game.mlx_ptr = mlx_init();
	strc->game.window_ptr = mlx_new_window(strc->game.mlx_ptr, WIDTH,
			HEIGHT, "Cub3D");
	strc->game.screen_w = WIDTH;
	strc->game.screen_h = HEIGHT;
	strc->window.width = WIDTH;
	strc->window.height = HEIGHT;
	init_img(&strc->img, &strc->game, &strc->map);
}
