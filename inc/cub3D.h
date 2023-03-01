/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:13:29 by llopes-n          #+#    #+#             */
/*   Updated: 2023/03/01 04:02:07 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <X11/keysymdef.h>
# include <X11/X.h>
# include <mlx.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_game
{
	void	*wind;
	void	*mlx;
}	t_game;

typedef struct s_strc
{
	t_game	game;
}	t_strc;

int		exit_game(t_strc *strc);
void	load_game(t_strc *strc);
#endif