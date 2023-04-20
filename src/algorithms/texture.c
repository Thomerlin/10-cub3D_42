/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:23:55 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/20 04:54:05 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static unsigned int	draw_pixel(t_strc *strc)
{
	unsigned int	pixel;

	if (strc->dda.hit.side == 0)
	{
		if (strc->dda.raydir.x < 0)
			pixel = get_pixel(&strc->map.we_text, strc->draw.tex_x,
					strc->draw.tex_y);
		else
			pixel = get_pixel(&strc->map.ea_text, strc->draw.tex_x,
					strc->draw.tex_y);
	}
	else
	{
		if (strc->dda.raydir.y < 0)
			pixel = get_pixel(&strc->map.no_text, strc->draw.tex_x,
					strc->draw.tex_y);
		else
			pixel = get_pixel(&strc->map.so_text, strc->draw.tex_x,
					strc->draw.tex_y);
	}
	return (pixel);
}

static void	draw_wall(t_strc *strc, int pixel)
{
	char	*dist;
	int		y;

	y = strc->draw.start;
	while (y < strc->draw.end)
	{
		strc->draw.tex_y = (int)strc->draw.tex_pos & (strc->map.ea_text.height \
		- 1);
		strc->draw.tex_pos += strc->draw.step;
		strc->draw.color = draw_pixel(strc);
		dist = strc->img.addr + (y * strc->img.line_size + (strc->game. \
		screen_w - pixel) * (strc->img.bpp) / 8);
		*(unsigned int *) dist = strc->draw.color;
		y++;
	}
}

void	show_texture(t_strc *strc, int pixel, t_image *img_text)
{
	if (strc->dda.hit.side == 0)
		strc->draw.wall_x = strc->player.pos.y + strc->dda.perpendicular * \
		strc->dda.raydir.y;
	else
		strc->draw.wall_x = strc->player.pos.x + strc->dda.perpendicular * \
		strc->dda.raydir.x;
	strc->draw.wall_x -= floor((strc->draw.wall_x));
	strc->draw.tex_x = (double)(strc->draw.wall_x * (double)img_text->width);
	if (strc->dda.hit.side == 0 && strc->dda.raydir.x > 0)
		strc->draw.tex_x = img_text->width - strc->draw.tex_x - 1;
	if (strc->dda.hit.side == 1 && strc->dda.raydir.y < 0)
		strc->draw.tex_x = img_text->width - strc->draw.tex_x - 1;
	strc->draw.step = 1 * (double)img_text->height / strc->draw. \
	wall_line_h;
	strc->draw.tex_pos = (strc->draw.start - (double) strc->game.\
		screen_h / 2 + (double) strc->draw.wall_line_h / 2) * \
			strc->draw.step;
	draw_wall(strc, pixel);
}
