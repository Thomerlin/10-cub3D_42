/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:44:44 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/03 22:43:59 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_strc *strc)
{
	mlx_destroy_window(strc->game.mlx_ptr, strc->game.wind_ptr);
	mlx_destroy_display(strc->game.mlx_ptr);
	free(strc->game.mlx_ptr);
	exit(0);
	return (0);
}

void	exit_map_error(t_strc *strc)
{
	int	inx;

	inx = 0;
	while (strc->map.map[inx])
	{
		free(strc->map.map[inx]);
		inx++;
	}
	free(strc->map.map);
	ft_printf("map is wrong\n");
	exit(1);
}
