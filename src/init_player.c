/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:49:46 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/20 21:14:06 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player(t_player *player, t_map *map, int x, int y)
{
	if (map->map[y][x] == 'E')
	{
		rotate_vector(&player->dir, 270);
		rotate_vector(&player->camera.plane, 270);
	}
	else if (map->map[y][x] == 'S')
	{
		rotate_vector(&player->dir, 180);
		rotate_vector(&player->camera.plane, 180);
	}
	else if (map->map[y][x] == 'W')
	{
		rotate_vector(&player->dir, 90);
		rotate_vector(&player->camera.plane, 90);
	}
	else if (map->map[y][x] == 'N')
	{
		rotate_vector(&player->dir, 0);
		rotate_vector(&player->camera.plane, 0);
	}
}

void	get_player_data(t_map *map, t_player *player, int x, int y)
{
	if (ft_strchr("NSEW", map->map[y][x]))
	{
		player->pos.x = x + 0.5;
		player->pos.y = y + 0.5;
		player->dir.y = -1;
		player->camera.plane.x = 0.66;
		player->player_num++;
		rotate_player(player, map, x, y);
		map->map[y][x] = '0';
	}
}
