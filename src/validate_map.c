/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:59:08 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/09 23:16:19 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bool	check_text_data(char **textures, t_strc *strc)
{
	strc->map.no_textu = open(textures[0], O_RDONLY);
	if (strc->map.no_textu < 0)
		return (FALSE);
	if (!ft_strncmp(".xpm", textures[0], 5))
		return (FALSE);
	strc->map.so_textu = open(textures[1], O_RDONLY);
	if (strc->map.so_textu < 0)
		return (FALSE);
	if (!ft_strncmp(".xpm", textures[1], 5))
		return (FALSE);
	strc->map.we_textu = open(textures[2], O_RDONLY);
	if (strc->map.we_textu < 0)
		return (FALSE);
	if (!ft_strncmp(".xpm", textures[2], 5))
		return (FALSE);
	strc->map.ea_textu = open(textures[3], O_RDONLY);
	if (strc->map.ea_textu < 0)
		return (FALSE);
	if (!ft_strncmp(".xpm", textures[3], 5))
		return (FALSE);
	return (TRUE);
}

void	check_map_break_line(char *map_line, t_strc *strc)
{
	if (ft_strnstr(map_line, "\n\n", ft_strlen(map_line)) || *map_line == '\0')
		exit_map_error(strc, BREAK_ERROR, map_line, FREE_CHAR);
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

void	check_map(t_strc *strc)
{
	int	x;
	int	y;

	y = 0;
	while (strc->map.map[y])
	{
		x = 0;
		while (strc->map.map[y][x])
		{
			if (ft_strchr("NSEW0", strc->map.map[y][x]))
			{
				if (check_vertical(strc->map.map, x, y) == FALSE)
					exit_map_error(strc, ERROR_WALL, NULL, FREE_MATRIX);
				if (check_horizontal(strc->map.map, x, y) == FALSE)
					exit_map_error(strc, ERROR_WALL, NULL, FREE_MATRIX);
			}
			x++;
		}
		y++;
	}
}
