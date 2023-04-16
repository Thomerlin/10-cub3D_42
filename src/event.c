/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:50:39 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/15 21:28:53 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_pressed(int key, t_strc *strc)
{
	if (key == XK_Escape)
		exit_game(strc);
	if (key == XK_w)
		strc->player.move = UP;
	if (key == XK_s)
		strc->player.move = DOWN;
	if (key == XK_a)
		strc->player.move = LEFT;
	if (key == XK_d)
		strc->player.move = RIGHT;
	if (key == XK_Left)
		strc->player.turn = LEFT;
	if (key == XK_Right)
		strc->player.turn = RIGHT;
	return (0);
}

int	key_unpressed(int key, t_strc *strc)
{
	if (key == XK_w)
		strc->player.move = STOP;
	if (key == XK_s)
		strc->player.move = STOP;
	if (key == XK_a)
		strc->player.move = STOP;
	if (key == XK_d)
		strc->player.move = STOP;
	if (key == XK_Left)
		strc->player.turn = STOP;
	if (key == XK_Right)
		strc->player.turn = STOP;
	return (0);
}
