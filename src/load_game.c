/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:54:48 by llopes-n          #+#    #+#             */
/*   Updated: 2023/03/01 04:16:13 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_game(t_strc *strc)
{
	strc->game.mlx = mlx_init();
	strc->game.wind = mlx_new_window(strc->game.mlx, 400, 400, "Cub3D");
}
