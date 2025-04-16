/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:49:29 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/25 11:05:28 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	count_spaces(char *str, int len)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 0;
	while (i < len && str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			spaces++;
		i++;
	}
	if (len == spaces)
		return (1);
	return (0);
}

void	parse_map_helper(t_map *map, int *skiped, int *j, char *line)
{
	int		len;
	char	*pureline;

	pureline = NULL;
	if ((*skiped) >= map->index)
	{
		pureline = ft_strtrim(line, "\n");
		len = ft_strlen(pureline);
		if (len == 0 || count_spaces(pureline, len))
		{
			if ((*j) != 0)
				invalid_map_2(NEWLINE_MAP, map, line, pureline);
		}
		else
		{
			if (parse_line(pureline, map->row, (*j), len))
				invalid_map_2(PARSE_LINE, map, line, pureline);
			else
				map->cmap[(*j)++] = ft_strdup(pureline);
		}
		free(pureline);
	}
	else if ((*skiped) < map->index)
		(*skiped)++;
}

void	parse_map(char *filename, t_map *map)
{
	int		j;
	int		skiped;
	char	*line;

	j = 0;
	skiped = 0;
	fd_check(filename, map, 1);
	map->cmap = malloc(sizeof(char *) * (map->row + 1));
	ft_bzero(map->cmap, sizeof(char *) * (map->row + 1));
	bad_alloc(map);
	line = get_next_line(map->fd);
	while (line)
	{
		parse_map_helper(map, &skiped, &j, line);
		free(line);
		line = get_next_line(map->fd);
	}
	map->cmap[j] = NULL;
	close(map->fd);
}
