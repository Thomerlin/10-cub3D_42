/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:18:32 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/22 16:32:04 by llopes-n         ###   ########.fr       */
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

void	read_map(t_map *map, char *gnl_buffer, int *file_path, char **data)
{
	char	*map_line;
	char	*map_buffer;

	if (ft_strncmp("\n\0", gnl_buffer, 3) == 0 || gnl_buffer == NULL)
		exit_map_error(map, "Map is missing", &gnl_buffer, FREE_STR);
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
	check_map_break_line(map_line, map, data);
	map->map = ft_split(map_line, '\n');
	free(map_line);
}

char	*check_map_line(char *map_line, char **data, int *file_path)
{
	int		inx;

	while (map_line && is_map(map_line) == FALSE)
	{
		inx = 0;
		while (map_line[inx])
		{
			if (ft_strncmp("NO", &map_line[inx], 3) == 0)
				data[0] = ft_strtrim(map_line, "NO \n");
			else if (ft_strncmp("SO", &map_line[inx], 3) == 0)
				data[1] = ft_strtrim(map_line, "SO \n");
			else if (ft_strncmp("WE", &map_line[inx], 3) == 0)
				data[2] = ft_strtrim(map_line, "WE \n");
			else if (ft_strncmp("EA", &map_line[inx], 3) == 0)
				data[3] = ft_strtrim(map_line, "EA \n");
			else if (ft_strncmp("F", &map_line[inx], 3) == 0)
				data[4] = ft_strtrim(map_line, "F \n");
			else if (ft_strncmp("C", &map_line[inx], 3) == 0)
				data[5] = ft_strtrim(map_line, "C \n");
			inx++;
		}
		free(map_line);
		map_line = get_next_line(*file_path);
	}
	return (map_line);
}

t_bool	get_map_colors(t_rgb *map_rgb, char **data, int data_inx)
{
	int		inx;
	char	**rgb;

	inx = 0;
	rgb = ft_split(data[data_inx], ',');
	if (!rgb[0] || !rgb[1] || !rgb[2])
	{
		ft_free_char_matrix(&rgb);
		return (FALSE);
	}
	while (rgb[inx])
	{
		if (ft_strlen(rgb[inx]) > 3 || ft_strisdigit(rgb[inx]) == -1)
		{
			ft_free_char_matrix(&rgb);
			return (FALSE);
		}
		inx++;
	}
	if (get_rgb(map_rgb, rgb) == FALSE)
		return (FALSE);
	ft_free_char_matrix(&rgb);
	map_rgb->color = decode_rgb(map_rgb->r, map_rgb->g, map_rgb->b);
	return (TRUE);
}

t_bool	map_data(t_map *map, t_player *player, int *file_path)
{
	char	*map_data;
	char	**data;

	data = malloc(sizeof(char *) * 7);
	data[6] = NULL;
	map_data = get_next_line(*file_path);
	map_data = check_map_line(map_data, data, file_path);
	read_map(map, map_data, file_path, data);
	if (check_data(data, map) == FALSE)
	{
		ft_free_char_matrix(&data);
		exit_map_error(map, TEXT_ERROR, NULL, 1);
	}
	ft_free_char_matrix(&data);
	check_map(map, player);
	return (TRUE);
}
