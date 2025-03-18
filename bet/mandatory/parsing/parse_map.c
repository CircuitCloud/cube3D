/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:49:29 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/13 13:17:27 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int count_spaces(char *str, int len)
{
	int i;
	int spaces;
	
	i = 0;
	spaces = 0;
	while(i < len && str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			spaces++;
		i++;
	}
	if (len == spaces)
		return (1);
	return (0);
}
void parse_map(char *filename, t_map* map)
{
	int j = 0;
	char *line = NULL;
	int len = 0;
	int skiped = 0;
	char *pureline = NULL;
	
	fd_check(filename, map, 1);
	map->cmap = malloc(sizeof(char *) * (map->row + 1));
	bad_alloc(map);
	while ((line = get_next_line(map->fd)))
	{
		if (skiped >= map->index)
		{
			pureline = ft_strtrim(line, "\n");
			free(line);
			len = ft_strlen(pureline);
			if (len == 0 ||  count_spaces(pureline, len))
			{
				if (j != 0)
					exit (1); //invalid_map(" (newline inside map lines)", map, 1);
				continue;
			}
			else
			{
				if (parse_line(pureline, map->row, j, len))
					exit (1); //invalid_map(" (parse_line)", map, 1);
				else
				{
					map->cmap[j] = ft_strdup(pureline);
					j++;
				}
			}
			free(pureline);
			continue;
		}
		else if (skiped < map->index)
			skiped++;
		free(line);
	}
	map->cmap[j] = NULL;
	close(map->fd);
}
