/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 07:57:11 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/15 01:52:56 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dda(t_strc *strc)
{
	strc->dda.wall_pos.x = floor((double)strc->player.pos.x);
	strc->dda.wall_pos.y = floor((double)strc->player.pos.y);
	strc->dda.hit.hit = FALSE;
	strc->dda.line_size.x = strc->dda.to_side.x;
	strc->dda.line_size.y = strc->dda.to_side.y;
	while (strc->dda.hit.hit == FALSE)
	{
		if (strc->dda.line_size.x < strc->dda.line_size.y)
		{
			strc->dda.wall_pos.x += strc->dda.step.x;
			strc->dda.line_size.x += strc->dda.delta.x;
			strc->dda.hit.side = 0;
		}
		else
		{
			strc->dda.wall_pos.y += strc->dda.step.y;
			strc->dda.line_size.y += strc->dda.delta.y;
			strc->dda.hit.side = 1;
		}
		if (strc->map.map[(int)strc->dda.wall_pos.y]
			[(int)strc->dda.wall_pos.x] == '1')
			strc->dda.hit.hit = TRUE;
	}
}

void	raycasting(t_strc *strc, int pixel)
{
	double		wall_line_height;
	t_vector	point1;
	t_vector	point2;

	wall_line_height = HEIGHT / strc->dda.perpendicular;
	point1.x = (double)pixel;
	point1.y = HEIGHT / 2 - wall_line_height / 2;
	point2.x = (double)pixel;
	point2.y = HEIGHT / 2 + wall_line_height / 2;
	if (strc->dda.hit.side == 0)
		bresenham(&point1, &point2, strc, get_rgb(255, 0, 0));
	if (strc->dda.hit.side == 1)
		bresenham(&point1, &point2, strc, get_rgb(0, 0, 255));
}
