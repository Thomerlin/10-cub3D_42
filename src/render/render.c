/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:16:40 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/14 22:34:25 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	background(t_strc *strc)
{
	t_vector	point1;
	t_vector	point2;

	strc->map.s_color = get_rgb(175, 173, 170);
	strc->map.f_color = get_rgb(255, 205, 140);
	point1.x = 0;
	point1.y = 0;
	point2.x = (double) strc->game.screen_width;
	point2.y = 0;
	while (point1.y <= (double) strc->game.screen_height)
	{
		if (point1.y <= (double) strc->game.screen_height / 2)
			bresenham(&point1, &point2, strc, strc->map.s_color);
		else
			bresenham(&point1, &point2, strc, strc->map.f_color);
		point1.y++;
		point2.y++;
	}
}

int	render(t_strc *strc)
{
	background(strc);
	while (strc->dda.pixel < WIDTH)
	{
		init_camera(strc);
		init_raydir_and_delta(strc);
		init_dist_to_side(strc);
		dda(strc);
		init_perpendicular(strc);
		raycasting(strc, strc->dda.pixel);
		strc->dda.pixel++;
	}
	strc->dda.pixel = 0;
	mlx_put_image_to_window(strc->game.mlx_ptr, strc->game.window_ptr,
		strc->img.ptr, 0, 0);
	return (0);
}
