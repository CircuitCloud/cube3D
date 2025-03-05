/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:16:02 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/02 13:27:15 by cahaik           ###   ########.fr       */
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
		if (map->row < 6)
		{
			i = 0;
			if (len > 1)
			{
				map->splited = ft_split(line, ' ');
				while (map->splited && map->splited[i])
					i++;
				if (i != 2 )
					exit(1); //invalid_map_textures(" invalid directions (number of element in the line)", map, NULL, splited_line);
			parse_textures_util(map);
			free(line);
			free_splited(map->splited);
			}
		}
		else if (len != 1)
			break;
	}
	count_rows(map, line);
}
//norm