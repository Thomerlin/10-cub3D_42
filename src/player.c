/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:58:00 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/16 02:57:43 by tyago-ri         ###   ########.fr       */
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
		rotate_vector(&strc->player.dir, 355);
		rotate_vector(&strc->player.camera.plane, 355);
	}
	if (strc->player.turn == RIGHT)
	{
		rotate_vector(&strc->player.dir, 5);
		rotate_vector(&strc->player.camera.plane, 5);
	}
}

void	move(t_strc *strc)
{
	if (strc->player.move == UP)
	{
		// strc->player.pos.y -= 0.1 * strc->player.dir.y
		// strc->player.pos.y += 0.1 * strc->player.dir.y

		t_vector	pos_tmp;
		double		pos_y_tmp;

		pos_tmp.y = strc->player.pos.y - 0.1 * -strc->player.dir.y;
		pos_tmp.x = strc->player.pos.x + 0.1 * strc->player.dir.x;
		pos_y_tmp = strc->player.pos.y;
		
		if (strc->map.map[(int)floor(pos_tmp.y)]\
		[(int)floor(strc->player.pos.x)] == '0')
			strc->player.pos.y = pos_tmp.y;
		if (strc->map.map[(int)floor(pos_y_tmp)][(int)floor(pos_tmp.x)] == '0')
			strc->player.pos.x = pos_tmp.x;
	}
	if (strc->player.move == DOWN)
	{
		// strc->player.pos.y -= 0.1 * strc->player.dir.y;
		// strc->player.pos.x -= 0.1 * strc->player.dir.x;
		t_vector	pos_tmp;
		double		pos_y_tmp;

		pos_tmp.y = strc->player.pos.y - 0.1 * strc->player.dir.y;;
		pos_tmp.x = strc->player.pos.x - 0.1 * strc->player.dir.x;
		pos_y_tmp = strc->player.pos.y;
		
		if (strc->map.map[(int)floor(pos_tmp.y)]\
		[(int)floor(strc->player.pos.x)] == '0')
			strc->player.pos.y = pos_tmp.y;
		if (strc->map.map[(int)floor(pos_y_tmp)][(int)floor(pos_tmp.x)] == '0')
			strc->player.pos.x = pos_tmp.x;
	}
	if (strc->player.move == LEFT)
	{
		// strc->player.pos.y -= 0.1 * strc->player.dir.x;
		// strc->player.pos.x += 0.1 * strc->player.dir.y;
		t_vector	pos_tmp;
		double		pos_y_tmp;

		pos_tmp.y = strc->player.pos.y - 0.1 * strc->player.dir.x;
		pos_tmp.x = strc->player.pos.x + 0.1 * strc->player.dir.y;
		pos_y_tmp = strc->player.pos.y;
		
		if (strc->map.map[(int)floor(pos_tmp.y)]\
		[(int)floor(strc->player.pos.x)] == '0')
			strc->player.pos.y = pos_tmp.y;
		if (strc->map.map[(int)floor(pos_y_tmp)][(int)floor(pos_tmp.x)] == '0')
			strc->player.pos.x = pos_tmp.x;
	}
	if (strc->player.move == RIGHT)
	{
		// strc->player.pos.y += 0.1 * strc->player.dir.x;
		// strc->player.pos.x -= 0.1 * strc->player.dir.y;
		t_vector	pos_tmp;
		double		pos_y_tmp;

		pos_tmp.y = strc->player.pos.y + 0.1 * strc->player.dir.x;;
		pos_tmp.x = strc->player.pos.x - 0.1 * strc->player.dir.y;
		pos_y_tmp = strc->player.pos.y;
		
		if (strc->map.map[(int)floor(pos_tmp.y)]\
		[(int)floor(strc->player.pos.x)] == '0')
			strc->player.pos.y = pos_tmp.y;
		if (strc->map.map[(int)floor(pos_y_tmp)][(int)floor(pos_tmp.x)] == '0')
			strc->player.pos.x = pos_tmp.x;
	}
	look(strc);
}
