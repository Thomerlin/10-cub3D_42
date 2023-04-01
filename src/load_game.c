/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:54:48 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/01 00:19:32 by llopes-n         ###   ########.fr       */
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

t_bool	read_map(t_strc *strc, char *gnl_buffer)
{
	char	*map_line;
	char	*map_buffer;

	if (ft_strncmp("\n\0", gnl_buffer, 3) == 0 || gnl_buffer == NULL)
		return (FALSE);
	map_line = ft_strdup("");
	while (TRUE)
	{
		if (!gnl_buffer)
			break ;
		map_buffer = map_line;
		map_line = ft_strjoin(map_buffer, gnl_buffer);
		free(map_buffer);
		free(gnl_buffer);
		gnl_buffer = get_next_line(strc->map.path);
	}
	free(gnl_buffer);
	close(strc->map.path);
	check_map_break_line(map_line);
	strc->map.map = ft_split(map_line, '\n');
	free(map_line);
	return (TRUE);
}

t_bool	map_data(t_strc *strc)
{
	char	*map_data;
	char	**textures;

	textures = malloc(sizeof(char) * 5);
	map_data = get_next_line(strc->map.path);
	while (map_data && is_map(map_data) == FALSE)
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
	check_text_data(textures, strc);
	read_map(strc, map_data);
	check_map_is_close(strc);
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
