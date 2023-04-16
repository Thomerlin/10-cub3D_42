/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:49:46 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/15 19:04:26 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player(t_strc *strc, int x, int y)
{
	if (strc->map.map[y][x] == 'E')
	{
		strc->player.ang = 90;
		rotate_vector(&strc->player.dir, 90);
		rotate_vector(&strc->player.camera.plane, 90);
	}
	else if (strc->map.map[y][x] == 'S')
	{
		strc->player.ang = 180;
		rotate_vector(&strc->player.dir, 180);
		rotate_vector(&strc->player.camera.plane, 180);
	}
	else if (strc->map.map[y][x] == 'W')
	{
		strc->player.ang = 270;
		rotate_vector(&strc->player.dir, 270);
		rotate_vector(&strc->player.camera.plane, 270);
	}
	else if (strc->map.map[y][x] == 'N')
	{
		strc->player.ang = 0;
		rotate_vector(&strc->player.dir, 0);
		rotate_vector(&strc->player.camera.plane, 0);
	}
}

void	get_player_data(t_strc *strc, int x, int y)
{
	if (ft_strchr("NSEW", strc->map.map[y][x]))
	{
		strc->player.pos.x = x + 0.5;
		strc->player.pos.y = y + 0.5;
		strc->player.dir.x = 0;
		strc->player.dir.y = -1;
		strc->player.camera.plane.x = 0.66;
		strc->player.camera.plane.y = 0;
		strc->player.camera.pixel.x = 0;
		strc->player.camera.pixel.y = 0;
		strc->player.player_num++;
		rotate_player(strc, x, y);
		strc->map.map[y][x] = '0';
	}
}
