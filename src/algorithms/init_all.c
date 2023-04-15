/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 07:57:47 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/15 14:49:52 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_step_xy(t_strc *strc)
{
	if (strc->dda.raydir.x < 0)
		strc->dda.step.x = -1;
	else
		strc->dda.step.x = 1;
	if (strc->dda.raydir.y < 0)
		strc->dda.step.y = -1;
	else
		strc->dda.step.y = 1;
}

void	init_dist_to_side(t_strc *strc)
{
	t_vector	map_pos;

	map_pos.x = floor(strc->player.pos.x);
	map_pos.y = floor(strc->player.pos.y);
	if (strc->dda.raydir.x < 0)
		strc->dda.to_side.x = (strc->player.pos.x - map_pos.x) * \
		strc->dda.delta.x;
	else
		strc->dda.to_side.x = (map_pos.x + 1 - strc->player.pos.x)
			* strc->dda.delta.x;
	if (strc->dda.raydir.y < 0)
		strc->dda.to_side.y = (strc->player.pos.y - map_pos.y)
			* strc->dda.delta.y;
	else
		strc->dda.to_side.y = (map_pos.y + 1 - strc->player.pos.y)
			* strc->dda.delta.y;
	init_step_xy(strc);
}

void	init_camera(t_strc *strc)
{
	double	multiplier;

	multiplier = 2 * ((double)strc->dda.pixel / \
	(double) strc->window.width) - 1;
	strc->player.camera.pixel.x = strc->player.camera.plane.x * multiplier;
	strc->player.camera.pixel.y = strc->player.camera.plane.y * multiplier;
}

void	init_raydir_and_delta(t_strc *strc)
{
	strc->dda.raydir.x = strc->player.camera.pixel.x + strc->player.dir.x;
	strc->dda.raydir.y = strc->player.camera.pixel.y + strc->player.dir.y;
	if (strc->dda.raydir.x == 0)
	{
		strc->dda.delta.x = 1;
		strc->dda.delta.y = 0;
	}
	if (strc->dda.raydir.y == 0)
	{
		strc->dda.delta.x = 0;
		strc->dda.delta.y = 1;
	}
	if (strc->dda.raydir.y != 0 && strc->dda.raydir.x != 0)
	{
		strc->dda.delta.x = fabs(1 / strc->dda.raydir.x);
		strc->dda.delta.y = fabs(1 / strc->dda.raydir.y);
	}
}

void	init_perpendicular(t_strc *strc)
{
	if (strc->dda.hit.side == 0)
		strc->dda.perpendicular = (strc->dda.wall_pos.x - \
		strc->player.pos.x + ((1 - strc->dda.step.x) / 2)) / strc->dda.raydir.x;
	else
		strc->dda.perpendicular = (strc->dda.wall_pos.y - \
		strc->player.pos.y + ((1 - strc->dda.step.y) / 2)) / strc->dda.raydir.y;
}
