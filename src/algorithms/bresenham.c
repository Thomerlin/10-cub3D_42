/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 07:58:28 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/15 03:47:51 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	minor_slope(t_line *line, t_strc *strc, int color)
{
	int	dist;
	int	inc;
	int	point0;

	if (line->start_y > line->end_y)
		point0 = -1;
	else
		point0 = 1;
	img_pixel_put(&strc->img, line->start_x, line->start_y, color);
	dist = (2 * fabs((double) line->dist_y)) - fabs((double) line->dist_x);
	inc = -1;
	while (++inc < fabs((double) line->dist_x))
	{
		line->start_x++;
		if (dist < 0)
			dist += (2 * fabs((double) line->dist_y));
		else
		{
			line->start_y = line->start_x + point0;
			dist += (2 * fabs((double) line->dist_y) - (2 * fabs((double) \
			line->dist_x)));
		}
		img_pixel_put(&strc->img, line->start_x, line->start_y, color);
	}
}

static void	bigger_slope(t_line *l, t_strc *strc, int color)
{
	int	dist;
	int	inc;
	int	point0;

	if (l->start_y > l->end_y)
		point0 = -1;
	else
		point0 = 1;
	img_pixel_put(&strc->img, l->start_x, l->start_y, color);
	inc = -1;
	dist = (2 * fabs((double)l->dist_x) - fabs((double)l->dist_y));
	while (++inc < fabs((double)l->dist_y))
	{
		l->start_y += point0;
		if (dist < 0)
			dist += (2 * fabs((double)l->dist_x));
		else
		{
			l->start_x++;
			dist += (2 * fabs((double)l->dist_x)) - (2 * fabs((double)
						l->dist_y));
		}
		img_pixel_put(&strc->img, l->start_x, l->start_y, color);
	}
}

static void	drawline(t_line *line, t_strc *strc, int color)
{
	line->dist_x = line->end_x - line->start_x;
	line->dist_y = line->end_y - line->start_y;
	if (fabs((double)line->dist_x) > fabs((double)line->dist_y))
		minor_slope(line, strc, color);
	else
		bigger_slope(line, strc, color);
}

void	bresenham(t_vector *point1, t_vector *point2, t_strc *strc, int color)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (point1->x < point2->x)
	{
		line->start_x = point1->x;
		line->end_x = point2->x;
		line->start_y = point1->y;
		line->end_y = point2->y;
	}
	else
	{
		line->end_x = point1->x;
		line->start_x = point2->x;
		line->end_y = point1->y;
		line->start_y = point2->y;
	}
	drawline(line, strc, color);
	free(line);
}
