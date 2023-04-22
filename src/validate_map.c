/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:59:08 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/22 17:21:14 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bool	check_data(char **data, t_map *map)
{
	int	inx;

	inx = 0;
	if (!data[0] || !data[1] || map->no_text.path || map->so_text.path || \
		map->we_text.path || map->ea_text.path)
		return (FALSE);
	while (inx <= 3)
	{
		if (!ft_strncmp(".xpm", data[inx], 5))
			return (FALSE);
		inx++;
	}
	if (get_map_colors(&map->floor, data, 4) == FALSE)
		return (FALSE);
	if (get_map_colors(&map->sky, data, 5) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	get_rgb(t_rgb *map_rgb, char **rgb)
{
	map_rgb->r = ft_atoi(rgb[0]);
	map_rgb->g = ft_atoi(rgb[1]);
	map_rgb->b = ft_atoi(rgb[2]);
	if (map_rgb->r > 255 || map_rgb->g > 255 || map_rgb->b > 255)
	{
		ft_free_char_matrix(&rgb);
		return (FALSE);
	}
	return (TRUE);
}

void	check_map_break_line(char *map_line, t_map *map, char **data)
{
	if (ft_strnstr(map_line, "\n\n", ft_strlen(map_line)) || *map_line == '\0')
	{
		ft_free_char_matrix(&data);
		exit_map_error(map, BREAK_ERROR, &map_line, FREE_STR);
	}
}

t_bool	check_vertical_and_horizontal(char **map, int x, int y)
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
	if (x == 0 || x == (int)ft_strlen(map[y]) - 1)
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
				if (check_vertical_and_horizontal(map->map, x, y) == FALSE)
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
