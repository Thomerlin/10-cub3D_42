/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 07:57:11 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/20 05:06:57 by tyago-ri         ###   ########.fr       */
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

void	raycasting(t_strc *strc, int pixel, t_image	img_text)
{
	strc->draw.wall_line_h = (int)strc->game.screen_h / strc->dda.perpendicular;
	strc->draw.start = -strc->draw.wall_line_h / 2 + \
	(double)strc->game.screen_h / 2;
	if (strc->draw.start < 0)
		strc->draw.start = 0;
	strc->draw.end = strc->draw.wall_line_h / 2 + \
	(double)strc->game.screen_h / 2;
	if (strc->draw.end >= strc->game.screen_h)
		strc->draw.end = strc->game.screen_h - 1;
	if (strc->dda.hit.side == 0)
	{
		if (strc->dda.raydir.x < 0)
			img_text = (strc->map.no_text);
		else
			img_text = (strc->map.so_text);
	}
	else
	{
		if (strc->dda.raydir.y < 0)
			img_text = (strc->map.no_text);
		else
			img_text = (strc->map.so_text);
	}
	show_texture(strc, pixel, &img_text);
}
