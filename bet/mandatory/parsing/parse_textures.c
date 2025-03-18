/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:16:02 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/13 11:57:28 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void count_rows(t_map *map)
{
	char *line;
	
	map->row = 1;
	map->index--;
	line = get_next_line(map->fd);
	while (line)
	{
		map->row++;
		free(line);
		line = get_next_line(map->fd);
	}
	//free line
	close(map->fd);
}

void parse_textures(char *filename, t_map* map)
{
	int i;
	char *line;
	char *newline;
	
	fd_check(filename, map, 0);
	while ((line = get_next_line(map->fd)))
	{
		i = 0;
		map->index++;
		newline = ft_strtrim(line, "\n");
		free(line);
		line = convert_to_space(newline);
		free(newline);
		map->splited = ft_split(line, ' ');
		while (map->splited && map->splited[i])
			i++;
		if (map->row < 6)
		{
			if (i == 0)
				continue;
			else
				parse_textures_util(map, i, line);
		}
		else if (i != 0)
			break;
		free(line);
		free_splited(map->splited);
	}
	free(line);
	free_splited(map->splited);
	count_rows(map);
}
