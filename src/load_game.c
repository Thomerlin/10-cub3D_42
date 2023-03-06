/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:54:48 by llopes-n          #+#    #+#             */
/*   Updated: 2023/03/05 22:47:06 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bool	is_map(char *line)
{
	int	inx;

	inx = 0;
	while (line[inx])
	{
		if (ft_strncmp("11", line, 3) == 0)
			return (TRUE);
		if (ft_strncmp("01", line, 3) == 0)
			return (TRUE);
		if (ft_strncmp("10", line, 3) == 0)
			return (TRUE);
		if (ft_strncmp(" 01", line, 3) == 0)
			return (TRUE);
		if (ft_strncmp(" 10", line, 3) == 0)
			return (TRUE);
		if (ft_strncmp(" 11", line, 3) == 0)
			return (TRUE);
		inx++;
	}
	return (FALSE);
}

t_bool	check_map_data(char **textures, t_strc *strc)
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

t_bool	map_data(t_strc *strc)
{
	char	*map_data;
	char	**textures;

	textures = malloc(sizeof(char) * 5);
	map_data = get_next_line(strc->map.path);
	while (map_data && is_map(map_data))
	{
		if (ft_strncmp("NO", map_data, 3) == 0)
			textures[0] = ft_strtrim(map_data, "NO \n");
		else if (ft_strncmp("SO", map_data, 3) == 0)
			textures[1] = ft_strtrim(map_data, "SO \n");
		else if (ft_strncmp("WE", map_data, 3) == 0)
			textures[2] = ft_strtrim(map_data, "WE \n");
		else if (ft_strncmp("EA", map_data, 3) == 0)
			textures[3] = ft_strtrim(map_data, "EA \n");
		free(map_data);
		map_data = get_next_line(strc->map.path);
	}
	return (TRUE);
}

t_bool	load_map(char *map_path, t_strc *strc)
{
	strc->map.path = open(map_path, O_RDONLY);
	map_data(strc);
	return (TRUE);
}

void	load_game(t_strc *strc, char *map_path)
{
	load_map(map_path, strc);
	strc->game.mlx = mlx_init();
	strc->game.wind = mlx_new_window(strc->game.mlx, 400, 400, "Cub3D");
}
