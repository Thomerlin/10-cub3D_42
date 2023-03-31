/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:59:08 by llopes-n          #+#    #+#             */
/*   Updated: 2023/03/30 22:33:17 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bool	check_text_data(char **textures, t_strc *strc)
{
	if (textures[0] != NULL && ft_strncmp(".xpm", textures[0], 5))
	{
		strc->map.no_textu = open(textures[0], O_RDONLY);
		if (strc->map.no_textu < 0)
			return (FALSE);
	}
	if (textures[1] != NULL && ft_strncmp(".xpm", textures[1], 5))
	{
		strc->map.so_textu = open(textures[1], O_RDONLY);
		if (strc->map.so_textu < 0)
			return (FALSE);
	}
	if (textures[2] != NULL && ft_strncmp(".xpm", textures[2], 5))
	{
		strc->map.we_textu = open(textures[2], O_RDONLY);
		if (strc->map.we_textu < 0)
			return (FALSE);
	}
	if (textures[3] != NULL && ft_strncmp(".xpm", textures[3], 5))
	{
		strc->map.ea_textu = open(textures[3], O_RDONLY);
		if (strc->map.ea_textu < 0)
			return (FALSE);
	}
	return (TRUE);
}

void	check_map_break_line(char *map_line, t_strc *strc)
{
	if (ft_strnstr(map_line, "\n\n", ft_strlen(map_line)) || *map_line == '\0')
	{
		free(map_line);
		exit_game(strc);
	}
}

int	wall_posix(char *map_line, int posix_mode)
{
	int	inx;

	inx = 0;
	while (map_line[inx] && posix_mode == 0)
	{
		if (map_line[inx] == '1')
			return (inx);
		if (map_line[inx] == '0')
			return (-1);
		inx++;
	}
	inx = ft_strlen(map_line) - 1;
	while (map_line[inx] && posix_mode == 1)
	{
		if (map_line[inx] == '1')
			return (inx);
		if (map_line[inx] == '0')
			return (-1);
		inx--;
	}
	return (-1);
}

t_bool	check_lef_wall(char **map, int start_wall, int y_inx, int next_wall)
{
	if (!map[y_inx + 1])
		return (TRUE);
	next_wall = wall_posix(map[y_inx + 1], 0);
	if (next_wall == -1)
		return (FALSE);
	if (next_wall < start_wall)
	{
		while (start_wall > next_wall)
		{
			if (map[y_inx + 1][start_wall] != '1')
				return (FALSE);
			start_wall--;
		}
	}
	else if (next_wall > start_wall)
	{
		while (start_wall < next_wall)
		{
			if (map[y_inx][start_wall + 1] != '1')
				return (FALSE);
			start_wall++;
		}
	}
	return (check_lef_wall(map, start_wall, y_inx + 1, next_wall));
}

t_bool	check_rig_wall(char **map, int start_wall, int y_inx, int next_wall)
{
	if (!map[y_inx + 1])
		return (TRUE);
	next_wall = wall_posix(map[y_inx + 1], 1);
	if (next_wall == -1)
		return (FALSE);
	if (next_wall < start_wall)
	{
		while (start_wall > next_wall)
		{
			if (map[y_inx][start_wall - 1] != '1')
				return (FALSE);
			start_wall--;
		}
	}
	else if (next_wall > start_wall)
	{
		while (start_wall < next_wall)
		{
			if (map[y_inx + 1][start_wall] != '1')
				return (FALSE);
			start_wall++;
		}
	}
	return (check_rig_wall(map, start_wall, y_inx + 1, next_wall));
}

void	check_map_is_close(t_strc *strc)
{
	int	wall_psx;

	wall_psx = wall_posix(strc->map.map[0], 0);
	if (check_lef_wall(strc->map.map, wall_psx, 0, 0) == FALSE)
		exit_map_error(strc);
	wall_psx = wall_posix(strc->map.map[0], 1);
	if (check_rig_wall(strc->map.map, wall_psx, 0, 0) == FALSE)
		exit_map_error(strc);
}
