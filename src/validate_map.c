/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:59:08 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/18 20:11:30 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bool	check_text_data(char **textures, t_map *map)
{
	map->no_text.int_path = open(textures[0], O_RDONLY);
	if (map->no_text.int_path < 0)
		return (FALSE);
	if (!ft_strncmp(".xpm", textures[0], 5))
		return (FALSE);
	map->so_text.int_path = open(textures[1], O_RDONLY);
	if (map->so_text.int_path < 0)
		return (FALSE);
	if (!ft_strncmp(".xpm", textures[1], 5))
		return (FALSE);
	map->we_text.int_path = open(textures[2], O_RDONLY);
	if (map->we_text.int_path < 0)
		return (FALSE);
	if (!ft_strncmp(".xpm", textures[2], 5))
		return (FALSE);
	map->ea_text.int_path = open(textures[3], O_RDONLY);
	if (map->ea_text.int_path < 0)
		return (FALSE);
	if (!ft_strncmp(".xpm", textures[3], 5))
		return (FALSE);
	return (TRUE);
}

void	check_map_break_line(char *map_line, t_map *map)
{
	if (ft_strnstr(map_line, "\n\n", ft_strlen(map_line)) || *map_line == '\0')
		exit_map_error(map, BREAK_ERROR, map_line, FREE_STR);
}

t_bool	check_vertical(char **map, int x, int y)
{
	int	line_len;

	line_len = 0;
	while (map[line_len])
		line_len++;
	if (y == 0 || y == line_len - 1)
		return (FALSE);
	if (ft_strchr("NSEW10", map[y + 1][x]) == NULL)
		return (FALSE);
	if (ft_strchr("NSEW10", map[y - 1][x]) == NULL)
		return (FALSE);
	return (TRUE);
}

t_bool	check_horizontal(char **map, int x, int y)
{
	if (y == 0 || y + 1 == (int)ft_strlen(map[y]))
		return (FALSE);
	if (ft_strchr("NSEW10", map[y][x + 1]) == NULL)
		return (FALSE);
	if (ft_strchr("NSEW10", map[y][x - 1]) == NULL)
		return (FALSE);
	return (TRUE);
}

void	check_map(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (ft_strchr("NSEW0", map->map[y][x]))
			{
				get_player_data(map, player, x, y);
				if (check_vertical(map->map, x, y) == FALSE)
					exit_map_error(map, ERROR_WALL, NULL, FREE_MAP);
				if (check_horizontal(map->map, x, y) == FALSE)
					exit_map_error(map, ERROR_WALL, NULL, FREE_MAP);
			}
			x++;
		}
		y++;
	}
	if (player->player_num > 1)
		exit_map_error(map, MUCH_PLAYER_ERROR, NULL, FREE_MAP);
	if (player->player_num == 0)
		exit_map_error(map, "missing player", NULL, FREE_MAP);
}
