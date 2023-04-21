/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:58:00 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/20 21:45:46 by llopes-n         ###   ########.fr       */
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
	if (strc->player.turn_left == LEFT)
	{
		rotate_vector(&strc->player.dir, 3);
		rotate_vector(&strc->player.camera.plane, 3);
	}
	if (strc->player.turn_right == RIGHT)
	{
		rotate_vector(&strc->player.dir, 357);
		rotate_vector(&strc->player.camera.plane, 357);
	}
}

void	collision(t_strc *strc, double y, double x)
{
	double		pos_y_tmp;

	pos_y_tmp = strc->player.pos.y;
	if (strc->map.map[(int)floor(y)][(int)floor(strc->player.pos.x)] == '0')
		strc->player.pos.y = y;
	if (strc->map.map[(int)floor(pos_y_tmp)][(int)floor(x)] == '0')
		strc->player.pos.x = x;
}

void	move(t_strc *strc)
{
	t_vector	dir_tmp;

	dir_tmp.x = strc->player.dir.x;
	dir_tmp.y = strc->player.dir.y;
	if (strc->player.move_up == UP)
		collision(strc, strc->player.pos.y + dir_tmp.y * 0.05,
			strc->player.pos.x + dir_tmp.x * 0.05);
	if (strc->player.move_down == DOWN)
		collision(strc, strc->player.pos.y - dir_tmp.y * 0.05,
			strc->player.pos.x - dir_tmp.x * 0.05);
	if (strc->player.move_left == LEFT)
		collision(strc, strc->player.pos.y + dir_tmp.x * 0.05,
			strc->player.pos.x - dir_tmp.y * 0.05);
	if (strc->player.move_right == RIGHT)
		collision(strc, strc->player.pos.y - dir_tmp.x * 0.05,
			strc->player.pos.x + dir_tmp.y * 0.05);
	look(strc);
}
