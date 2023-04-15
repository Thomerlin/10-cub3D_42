/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:58:00 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/15 02:27:00 by llopes-n         ###   ########.fr       */
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
	if (strc->map.map[y][x] == 'E')
	{
		rotate_vector(&strc->player.dir, 90);
		rotate_vector(&strc->player.camera.plane, 90);
	}
	else if (strc->map.map[y][x] == 'S')
	{
		rotate_vector(&strc->player.dir, 180);
		rotate_vector(&strc->player.camera.plane, 180);
	}
	else if (strc->map.map[y][x] == 'W')
	{
		rotate_vector(&strc->player.dir, 270);
		rotate_vector(&strc->player.camera.plane, 270);
	}
	else if (strc->map.map[y][x] == 'N')
	{
		rotate_vector(&strc->player.dir, 0);
		rotate_vector(&strc->player.camera.plane, 0);
	}
}

void	get_player_data(t_strc *strc, int x, int y)
{
	if (ft_strchr("NSEW", strc->map.map[y][x]))
	{
		strc->player.pos.x = x + 0.5;
		strc->player.pos.y = y + 0.5;
		strc->player.dir.x = 0;
		strc->player.dir.y = -1;
		strc->player.camera.plane.x = 0.66;
		strc->player.camera.plane.y = 0;
		strc->player.camera.pixel.x = 0;
		strc->player.camera.pixel.y = 0;
		strc->player.player_num++;
		rotate_player(strc, x, y);
		strc->map.map[y][x] = '0';
	}
}
