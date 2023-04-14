/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:18:32 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/13 22:53:30 by llopes-n         ###   ########.fr       */
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

t_bool	read_map(t_strc *strc, char *gnl_buffer)
{
	char	*map_line;
	char	*map_buffer;

	if (ft_strncmp("\n\0", gnl_buffer, 3) == 0 || gnl_buffer == NULL)
		exit_map_error(strc, "Map is missing", gnl_buffer, FREE_STR);
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
	check_map_break_line(map_line, strc);
	strc->map.map = ft_split(map_line, '\n');
	free(map_line);
	return (TRUE);
}

char	*check_map_line(char *map_line, char **textures, t_map map)
{
	int	inx;

	while (map_line && is_map(map_line) == FALSE)
	{
		inx = 0;
		while (map_line[inx])
		{
			if (ft_strncmp("NO", &map_line[inx], 3) == 0)
				textures[0] = ft_strtrim(map_line, "NO \n");
			else if (ft_strncmp("SO", &map_line[inx], 3) == 0)
				textures[1] = ft_strtrim(map_line, "SO \n");
			else if (ft_strncmp("WE", &map_line[inx], 3) == 0)
				textures[2] = ft_strtrim(map_line, "WE \n");
			else if (ft_strncmp("EA", &map_line[inx], 3) == 0)
				textures[3] = ft_strtrim(map_line, "EA \n");
			inx++;
		}
		free(map_line);
		map_line = NULL;
		map_line = get_next_line(map.path);
	}
	return (map_line);
}

t_bool	map_data(t_strc *strc)
{
	char	*map_data;
	char	**textures;

	textures = malloc(sizeof(char *) * 4);
	map_data = get_next_line(strc->map.path);
	map_data = check_map_line(map_data, textures, strc->map);
	if (check_text_data(textures, strc) == FALSE)
	{
		ft_free_char_matrix(&textures);
		exit_map_error(strc, TEXT_ERROR, NULL, 0);
	}
	read_map(strc, map_data);
	check_map(strc);
	return (TRUE);
}
