/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:18:32 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/20 01:28:54 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bool	is_map(char *line)
{
	int	inx;

	inx = 0;
	while (line[inx])
	{
		if (ft_strncmp("11", &line[inx], 3) == 0)
			return (TRUE);
		if (ft_strncmp("01", &line[inx], 3) == 0)
			return (TRUE);
		if (ft_strncmp("10", &line[inx], 3) == 0)
			return (TRUE);
		if (ft_strncmp(" 01", &line[inx], 3) == 0)
			return (TRUE);
		if (ft_strncmp(" 10", &line[inx], 3) == 0)
			return (TRUE);
		if (ft_strncmp(" 11", &line[inx], 3) == 0)
			return (TRUE);
		inx++;
	}
	return (FALSE);
}

t_bool	read_map(t_map *map, char *gnl_buffer, int *file_path)
{
	char	*map_line;
	char	*map_buffer;

	if (ft_strncmp("\n\0", gnl_buffer, 3) == 0 || gnl_buffer == NULL)
		exit_map_error(map, "Map is missing", gnl_buffer, FREE_STR);
	map_line = ft_strdup("");
	while (TRUE)
	{
		if (!gnl_buffer)
			break ;
		map_buffer = map_line;
		map_line = ft_strjoin(map_buffer, gnl_buffer);
		free(map_buffer);
		free(gnl_buffer);
		gnl_buffer = get_next_line(*file_path);
	}
	free(gnl_buffer);
	close(*file_path);
	check_map_break_line(map_line, map);
	map->map = ft_split(map_line, '\n');
	free(map_line);
	return (TRUE);
}

char	*check_map_line(char *map_line, char **info, int *file_path)
{
	int		inx;

	while (map_line && is_map(map_line) == FALSE)
	{
		inx = 0;
		while (map_line[inx])
		{
			if (ft_strncmp("NO", &map_line[inx], 3) == 0)
				info[0] = ft_strtrim(map_line, "NO \n");
			else if (ft_strncmp("SO", &map_line[inx], 3) == 0)
				info[1] = ft_strtrim(map_line, "SO \n");
			else if (ft_strncmp("WE", &map_line[inx], 3) == 0)
				info[2] = ft_strtrim(map_line, "WE \n");
			else if (ft_strncmp("EA", &map_line[inx], 3) == 0)
				info[3] = ft_strtrim(map_line, "EA \n");
			else if (ft_strncmp("F", &map_line[inx], 3) == 0)
				info[4] = ft_strtrim(map_line, "F \n");
			else if (ft_strncmp("C", &map_line[inx], 3) == 0)
				info[5] = ft_strtrim(map_line, "C \n");
			inx++;
		}
		free(map_line);
		map_line = get_next_line(*file_path);
	}
	return (map_line);
}

void	get_map_colors(t_map *map, char **data)
{
	char	**rgb;

	rgb = ft_split(data[4], ',');
	map->floor.r = ft_atoi(rgb[0]);
	map->floor.g = ft_atoi(rgb[1]);
	map->floor.b = ft_atoi(rgb[2]);
	ft_free_char_matrix(&rgb);
	rgb = ft_split(data[5], ',');
	map->sky.r = ft_atoi(rgb[0]);
	map->sky.g = ft_atoi(rgb[1]);
	map->sky.b = ft_atoi(rgb[2]);
	ft_free_char_matrix(&rgb);
	map->floor.color = get_rgb(map->floor.r, map->floor.g, map->floor.b);
	map->sky.color = get_rgb(map->sky.r, map->sky.g, map->sky.b);
}

t_bool	map_data(t_map *map, t_player *player, int *file_path)
{
	char	*map_data;
	char	**info;

	info = malloc(sizeof(char *) * 7);
	info[6] = NULL;
	map_data = get_next_line(*file_path);
	map_data = check_map_line(map_data, info, file_path);
	if (check_data(info, map) == FALSE)
	{
		ft_free_char_matrix(&info);
		exit_map_error(map, TEXT_ERROR, NULL, 0);
	}
	ft_free_char_matrix(&info);
	read_map(map, map_data, file_path);
	check_map(map, player);
	return (TRUE);
}
