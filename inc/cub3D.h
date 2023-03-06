/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:13:29 by llopes-n          #+#    #+#             */
/*   Updated: 2023/03/05 20:25:45 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <X11/keysymdef.h>
# include <X11/X.h>
# include <mlx.h>
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*wind;
	void	*mlx;
}	t_game;

typedef struct s_map
{
	int		no_textu;
	int		so_textu;
	int		we_textu;
	int		ea_textu;
	char	**cord;
	int		path;
	int		x_start;
}	t_map;

typedef enum s_bool
{
	TRUE,
	FALSE
}	t_bool;

typedef struct s_strc
{
	t_game	game;
	t_map	map;
}	t_strc;

int		exit_game(t_strc *strc);
void	load_game(t_strc *strc, char *map_path);
#endif