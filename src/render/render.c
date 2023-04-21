/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:16:40 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/20 22:21:05 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_pixel(t_image *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	return (*(int *)pixel);
}

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	render_background(t_image *img, int sky_color, int floor_color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
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
	render_background(&strc->img, strc->map.sky.color, strc->map.floor.color);
	strc->dda.pixel = 0;
	while (strc->dda.pixel < WIDTH)
	{
		init_camera(strc);
		init_raydir_and_delta(strc);
		init_dist_to_side(strc);
		dda(strc);
		init_perpendicular(strc);
		raycasting(strc, strc->dda.pixel, strc->img);
		strc->dda.pixel++;
	}
	mlx_put_image_to_window(strc->game.mlx_ptr, strc->game.window_ptr,
		strc->img.ptr, 0, 0);
	move(strc);
	return (0);
}
