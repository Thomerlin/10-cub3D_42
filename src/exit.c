/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:44:44 by llopes-n          #+#    #+#             */
/*   Updated: 2023/03/01 04:01:52 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_strc *strc)
{
	mlx_destroy_window(strc->game.mlx, strc->game.wind);
	mlx_destroy_display(strc->game.mlx);
	free(strc->game.mlx);
	exit (0);
	return (0);
}
