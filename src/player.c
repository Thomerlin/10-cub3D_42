/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:58:00 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/11 15:41:05 by tyago-ri         ###   ########.fr       */
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

void	rotate_player(t_strc *strc, int x, int y)
{
	if (strc->map.map[x][y] == 'N')
	{
		rotate_vector(&strc->player.dir, 270);
		rotate_vector(&strc->player.camera.plane, 270);
	}
	if (strc->map.map[x][y] == 'E')
	{
		rotate_vector(&strc->player.dir, 180);
		rotate_vector(&strc->player.camera.plane, 180);
	}
	if (strc->map.map[x][y] == 'S')
	{
		rotate_vector(&strc->player.dir, 90);
		rotate_vector(&strc->player.camera.plane, 90);
	}
}

void	get_player_data(t_strc *strc, int x, int y)
{
	strc->player.pos.x = x + 0.5;
	strc->player.pos.y = y + 0.5;
	strc->player.dir.x = 0;
	strc->player.dir.y = -1;
	strc->player.camera.plane.x = 0.66;
	strc->player.camera.plane.y = 0;
	strc->player.camera.pixel.x = 0;
	strc->player.camera.pixel.y = 0;
	rotate_player(strc, x, y);
	strc->map.map[x][y] = '0';
}
