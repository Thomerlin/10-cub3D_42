/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:58:00 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/16 03:36:48 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	rad(double num)
{
	return (((num * M_PI) / 180));
}

void	rotate_vector(t_vector *vector, double ang)
{
	double	temp_x;

	temp_x = vector->x;
	vector->x = vector->x * cos(rad(ang)) + vector->y * -sin(rad(ang));
	vector->y = temp_x * sin(rad(ang)) + vector->y * cos(rad(ang));
}

void	look(t_strc *strc)
{
	if (strc->player.turn == LEFT)
	{
		rotate_vector(&strc->player.dir, 357);
		rotate_vector(&strc->player.camera.plane, 357);
	}
	if (strc->player.turn == RIGHT)
	{
		rotate_vector(&strc->player.dir, 3);
		rotate_vector(&strc->player.camera.plane, 3);
	}
}

void	collision(t_strc *strc, double y, double x)
{
	double	pos_y_tmp;

	pos_y_tmp = strc->player.pos.y;
	if (strc->map.map[(int)floor(y)] \
	[(int)floor(strc->player.pos.x)] == '0')
		strc->player.pos.y = y;
	if (strc->map.map[(int)floor(pos_y_tmp)][(int)floor(x)] == '0')
		strc->player.pos.x = x;
}

void	move(t_strc *strc)
{
	if (strc->player.move == UP)
		collision(strc, strc->player.pos.y + 0.05 * strc->player.dir.y, \
		strc->player.pos.x + 0.05 * strc->player.dir.x);
	if (strc->player.move == DOWN)
		collision(strc, strc->player.pos.y - 0.05 * strc->player.dir.y, \
		strc->player.pos.x - 0.05 * strc->player.dir.x);
	if (strc->player.move == LEFT)
		collision(strc, strc->player.pos.y - 0.05 * strc->player.dir.x, \
		strc->player.pos.x + 0.05 * strc->player.dir.y);
	if (strc->player.move == RIGHT)
		collision(strc, strc->player.pos.y + 0.05 * strc->player.dir.x, \
		strc->player.pos.x - 0.05 * strc->player.dir.y);
	look(strc);
}
