/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:20:34 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/11 17:37:04 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_player(char **map_char, int x, int y, t_strc *strc)
{
	if (ft_strchr("NSWE", map_char[y][x]))
	{
		strc->player.pos.x = x;
		strc->player.pos.y = y;
		strc->player.player_num++;
		strc->player.player_dir = map_char[y][x];
	}
	if (strc->player.player_num > 1)
		exit_map_error(strc, MUCH_PLAYER_ERROR, NULL, FREE_MAP);
}

void	check_chars(t_strc *strc, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSWE01 ", map[y][x]) == NULL)
				exit_map_error(strc, WRONG_CHAR, NULL, FREE_MAP);
			validate_player(strc->map.map, x, y, strc);
			x++;
		}
		y++;
	}
	if (strc->player.player_num == 0)
		exit_map_error(strc, "missing player", NULL, FREE_MAP);
}
