/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 07:57:11 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/01 07:57:24 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dda(t_algo *c)
{
	c->dda.wall_pos.x = floor((double)c->map.player.pos.x);
	c->dda.wall_pos.y = floor((double)c->map.player.pos.y);
	c->dda.hit.hit = FALSE;
	c->dda.line_size.x = c->dda.to_side.x;
	c->dda.line_size.y = c->dda.to_side.y;
	while (c->dda.hit.hit == FALSE)
	{
		if (c->dda.line_size.x < c->dda.line_size.y)
		{
			c->dda.wall_pos.x += c->dda.step.x;
			c->dda.line_size.x += c->dda.delta.x;
			c->dda.hit.side = 0;
		}
		else
		{
			c->dda.wall_pos.y += c->dda.step.y;
			c->dda.line_size.y += c->dda.delta.y;
			c->dda.hit.side = 1;
		}
		if (c->map.map[(int)c->dda.wall_pos.x][(int)c->dda.wall_pos.y] == '1')
			c->dda.hit.hit = TRUE;
	}
}

static t_texture	get_direction_texture(t_algo *c)
{
	if (c->dda.hit.side == 0)
	{
		if (c->dda.raydir.x < 0)
			return (c->map.no_tex);
		else
			return (c->map.so_tex);
	}
	else
	{
		if (c->dda.raydir.y < 0)
			return (c->map.we_tex);
		else
			return (c->map.ea_tex);
	}
}

void	raycasting(t_algo *c, int pixel)
{
	t_texture	tex;

	c->draw.wall_line_height = (int) c->mlx.win.height / c->dda.perpendicular;
	c->draw.start = -c->draw.wall_line_height / 2 + (double) \
		c->mlx.win.height / 2;
	if (c->draw.start < 0)
		c->draw.start = 0;
	c->draw.end = c->draw.wall_line_height / 2 + (double) c->mlx.win.height / 2;
	if (c->draw.end >= c->mlx.win.height)
		c->draw.end = c->mlx.win.height - 1;
	tex = get_direction_texture(c);
	// precisa desenhar na tela funcao Draw() 
}
