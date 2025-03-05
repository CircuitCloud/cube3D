/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:16:02 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/05 14:29:35 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void count_rows(t_map *map, char *line)
{
	map->row = 0;
	while (line)
	{
		map->row++;
		free(line);
		line = get_next_line(map->fd);
	}
	close(map->fd);
}

void parse_textures(char *filename, t_map* map)
{
	int i;
	int len;
	char *line;
	
	fd_check(filename, map, 0);
	while ((line = get_next_line(map->fd)))
	{
		len = ft_strlen(line);
		if (map->row < 6 && len > 1)
		{
			i = 0;
			map->splited = ft_split(line, ' ');
			free(line);
			while (map->splited && map->splited[i])
				i++;
			if (i != 2 )
				invalid_map(" invalid directions (number of element in the line)", map, NULL, NULL);
			parse_textures_util(map);
			free_splited(map->splited);
		}
		else if (len != 1)
			break;
	}
	count_rows(map, line);
}
