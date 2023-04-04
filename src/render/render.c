/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:16:40 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/04 19:18:03 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pixel_put(t_image img, int x, int y, int color)
{
	char	*pixel;

	pixel = img.addr + (y * img.line_size + x * (img.bpp / 8));
	*(int *)pixel = color;
}

void	render_background(t_image img, int sky_color, int floor_color)
{
	int	x;
	int	y;

	y = 0;
	while (y < 400)
	{
		x = 0;
		while (x < 400)
		{
			if (y < 400 / 2)
				img_pixel_put(img, x, y, sky_color);
			else
				img_pixel_put(img, x, y, floor_color);
			x++;
		}
		y++;
	}	
}

int	render(t_strc *strc)
{
	render_background(strc->img, strc->img.sky_color, strc->img.floor_color);
	mlx_put_image_to_window(strc->game.mlx_ptr, strc->game.wind_ptr,
		strc->img.ptr, 0, 0);
	return (0);
}
