/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:50:39 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/18 00:19:32 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_pressed(int key, t_strc *strc)
{
	if (key == XK_Escape || key == XK_q)
		exit_game(strc);
	if (key == XK_w)
		strc->player.move_up = UP;
	if (key == XK_s)
		strc->player.move_down = DOWN;
	if (key == XK_a)
		strc->player.move_left = LEFT;
	if (key == XK_d)
		strc->player.move_right = RIGHT;
	if (key == XK_Left)
		strc->player.turn_left = LEFT;
	if (key == XK_Right)
		strc->player.turn_right = RIGHT;
	return (0);
}

int	key_unpressed(int key, t_strc *strc)
{
	if (key == XK_w)
		strc->player.move_up = STOP;
	if (key == XK_s)
		strc->player.move_down = STOP;
	if (key == XK_a)
		strc->player.move_left = STOP;
	if (key == XK_d)
		strc->player.move_right = STOP;
	if (key == XK_Left)
		strc->player.turn_left = STOP;
	if (key == XK_Right)
		strc->player.turn_right = STOP;
	return (0);
}
