/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:49:29 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/02 13:46:28 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// void parse_map(char *filename, t_map* map)
// {
// 	int j = 0;
// 	char *line = NULL;
// 	size_t len = 0;
// 	size_t skiped = 0;
	
// 	fd_check(filename, map, 1);
// 	map->cmap = malloc(sizeof(char *) * (map->row + 1));
// 	if (!map->cmap)
// 		bad_alloc(map, 1);
// 	while ((line = get_next_line(map->fd)))
// 	{
// 		len = ft_strlen(line);
// 		if (skiped > 5)
// 		{
// 			if (len == 1)
// 			{
// 				if (j != 0)
// 					exit (1); //invalid_map(" (newline inside map lines)", map, 1);
// 				continue;
// 			}
// 			else
// 			{
// 				if (parse_line(line, map->row, j))
// 					exit (1); //invalid_map(" (parse_line)", map, 1);
// 				else
// 				{
// 					map->cmap[j] = strdup(line);
// 					j++;
// 				}
// 			}
// 		}
// 		else if (len > 1)
// 				skiped++;
// 		free(line);
// 	}
// 	map->cmap[j] = NULL;
// 	close(map->fd);
// }

void parse_map(char *filename, t_map* map)
{
	int j = 0;
	char *line = NULL;
	int len = 0;
	int skiped = 0;
	
	fd_check(filename, map, 1);
	map->cmap = malloc(sizeof(char *) * (map->row + 1));
	if (!map->cmap)
		bad_alloc(map, 1);
	while ((line = get_next_line(map->fd)))
	{
		len = ft_strlen(line);
		if (skiped > 5)
		{
			if (len == 1)
			{
				if (j != 0)
					exit (1); //invalid_map(" (newline inside map lines)", map, 1);
				continue;
			}
			else
			{
				if (parse_line(line, map->row, j))
					exit (1); //invalid_map(" (parse_line)", map, 1);
				else
				{
					map->cmap[j] = strdup(line);
					j++;
				}
			}
		}
		else if (len > 1)
				skiped++;
		free(line);
	}
	map->cmap[j] = NULL;
	close(map->fd);
}
