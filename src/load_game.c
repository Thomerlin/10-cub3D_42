/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:54:48 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/01 14:19:14 by llopes-n         ###   ########.fr       */
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
	strc->game.mlx = mlx_init();
	strc->game.wind = mlx_new_window(strc->game.mlx, 400, 400, "Cub3D");
}
