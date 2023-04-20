/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:13:01 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/20 04:35:04 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_strc	strc;

	ft_memset(&strc, 0, sizeof(t_strc));
	if (argc == 2 && ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) != 0)
	{
		load_game(&strc, argv[1]);
		mlx_hook(strc.game.window_ptr, 17, 0, exit_game, &strc);
		mlx_loop_hook(strc.game.mlx_ptr, render, &strc);
		mlx_hook(strc.game.window_ptr, KeyPress, KeyPressMask, key_pressed,
			&strc);
		mlx_hook(strc.game.window_ptr, KeyRelease, KeyReleaseMask,
			key_unpressed, &strc);
		mlx_loop(strc.game.mlx_ptr);
		return (0);
	}
	else
	{
		printf("Error\nwrong syntax or wrong map extention\n");
		exit(1);
	}
}
