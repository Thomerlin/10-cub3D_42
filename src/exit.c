/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:44:44 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/22 16:50:45 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_img(t_strc *strc)
{
	mlx_destroy_image(strc->game.mlx_ptr, strc->img.ptr);
	if (strc->map.no_text.ptr)
		mlx_destroy_image(strc->game.mlx_ptr, strc->map.no_text.ptr);
	if (strc->map.so_text.ptr)
		mlx_destroy_image(strc->game.mlx_ptr, strc->map.so_text.ptr);
	if (strc->map.ea_text.ptr)
		mlx_destroy_image(strc->game.mlx_ptr, strc->map.ea_text.ptr);
	if (strc->map.we_text.ptr)
		mlx_destroy_image(strc->game.mlx_ptr, strc->map.we_text.ptr);
}

int	exit_game(t_strc *strc)
{
	ft_free_char_matrix(&strc->map.map);
	destroy_img(strc);
	mlx_destroy_window(strc->game.mlx_ptr, strc->game.window_ptr);
	mlx_destroy_display(strc->game.mlx_ptr);
	free(strc->game.mlx_ptr);
	free(strc->map.no_text.path);
	free(strc->map.so_text.path);
	free(strc->map.we_text.path);
	free(strc->map.ea_text.path);
	exit(0);
	return (0);
}

void	exit_text_error(t_strc *strc)
{
	ft_free_char_matrix(&strc->map.map);
	destroy_img(strc);
	mlx_destroy_window(strc->game.mlx_ptr, strc->game.window_ptr);
	mlx_destroy_display(strc->game.mlx_ptr);
	free(strc->game.mlx_ptr);
	if (strc->map.no_text.path)
		free(strc->map.no_text.path);
	if (strc->map.so_text.path)
		free(strc->map.so_text.path);
	if (strc->map.we_text.path)
		free(strc->map.we_text.path);
	if (strc->map.ea_text.path)
		free(strc->map.ea_text.path);
	ft_printf("wrong texture path\n");
	exit(0);
}

void	exit_map_error(t_map *map, char *message, char **str, int exit_mode)
{
	if (map->no_text.path)
		free(map->no_text.path);
	if (map->so_text.path)
		free(map->so_text.path);
	if (map->we_text.path)
		free(map->we_text.path);
	if (map->ea_text.path)
		free(map->ea_text.path);
	if (exit_mode == FREE_MAP)
		ft_free_char_matrix(&map->map);
	else if (exit_mode == FREE_STR)
	{
		free (*str);
		*str = NULL;
	}
	ft_printf("%s\n", message);
	exit(1);
}
