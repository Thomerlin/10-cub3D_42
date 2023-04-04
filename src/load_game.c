/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:54:48 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/04 19:22:14 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bool	load_map(char *map_path, t_strc *strc)
{
	strc->map.path = open(map_path, O_RDONLY);
	if (strc->map.path < 0)
		exit_map_error(strc, "Cannot open the map", NULL, 0);
	map_data(strc);
	return (TRUE);
}

void	load_game_img_and_colors(t_image *img, t_game *game)
{
	img->ptr = mlx_new_image(game->mlx_ptr, 400, 400);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size,
			&img->endian);
	img->sky_color = get_rgb(175, 173, 170);
	img->floor_color = get_rgb(255, 205, 140);
}

void	init_init_var(t_strc *strc)
{
	strc->player.player_num = 0;
}

void	load_game(t_strc *strc, char *map_path)
{
	load_map(map_path, strc);
	init_init_var(strc);
	check_chars(strc, strc->map.map);
	strc->game.mlx_ptr = mlx_init();
	strc->game.wind_ptr = mlx_new_window(strc->game.mlx_ptr, 400, 400, "Cub3D");
	load_game_img_and_colors(&strc->img, &strc->game);
}
