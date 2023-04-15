/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:13:01 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/15 02:28:23 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_strc	strc;

	if (argc == 2 && ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) != 0)
	{
		load_game(&strc, argv[1]);
		mlx_hook(strc.game.window_ptr, 17, 0, exit_game, &strc);
		mlx_expose_hook(strc.game.window_ptr, render, &strc);
		mlx_loop_hook(strc.game.mlx_ptr, render, &strc);
		mlx_loop(strc.game.mlx_ptr);
		return (0);
	}
	else
	{
		printf("Error\nwrong syntax or wrong map extention\n");
		exit(1);
	}
}
