/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:44:44 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/15 02:34:18 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_strc *strc)
{
	ft_free_char_matrix(&strc->map.map);
	mlx_destroy_image(strc->game.mlx_ptr, strc->img.ptr);
	mlx_destroy_window(strc->game.mlx_ptr, strc->game.window_ptr);
	mlx_destroy_display(strc->game.mlx_ptr);
	free(strc->game.mlx_ptr);
	exit(0);
	return (0);
}

void	exit_map_error(t_strc *strc, char *message, char *str, int exit_mode)
{
	if (exit_mode == FREE_MAP)
		ft_free_char_matrix(&strc->map.map);
	else if (exit_mode == FREE_STR)
		free (str);
	ft_printf("%s\n", message);
	exit(1);
}
