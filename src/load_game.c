/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:54:48 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/04 00:36:16 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bool	load_map(char *map_path, t_strc *strc)
{
	strc->map.path = open(map_path, O_RDONLY);
	map_data(strc);
	return (TRUE);
}

void	load_game(t_strc *strc, char *map_path)
{
	load_map(map_path, strc);
	strc->game.mlx_ptr = mlx_init();
	strc->game.wind_ptr = mlx_new_window(strc->game.mlx_ptr, 400, 400, "Cub3D");
	strc->img.ptr = mlx_new_image(strc->game.mlx_ptr, 400, 400);
	strc->img.addr = mlx_get_data_addr(strc->img.ptr, &strc->img.bpp,
			&strc->img.line_size, &strc->img.endian);
	strc->img.sky_color = get_rgb(175, 173, 170);
	strc->img.floor_color = get_rgb(255, 205, 140);
}
