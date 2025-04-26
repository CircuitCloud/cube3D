/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:16:02 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/25 10:02:20 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	count_rows(t_map *map)
{
	char	*line;

	map->row = 1;
	map->index--;
	line = get_next_line(map->fd);
	while (line)
	{
		map->row++;
		free(line);
		line = get_next_line(map->fd);
	}
	close(map->fd);
}

void	little_free(t_map *map, char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	(void)map;
	free_splited(map->splited);
}

int	parse_text_helper(t_map *map, char **line)
{
	int		i;
	char	*newline;

	i = 0;
	map->index++;
	newline = ft_strtrim(*line, "\n");
	free(*line);
	*line = convert_to_space(newline);
	free(newline);
	map->splited = ft_split(*line, ' ');
	while (map->splited && map->splited[i])
		i++;
	return (i);
}

void	parse_textures(char *filename, t_map *map)
{
	int		i;
	char	*line;

	fd_check(filename, map, 0);
	line = get_next_line(map->fd);
	while (line)
	{
		i = parse_text_helper(map, &line);
		if (map->row < 6)
		{
			if (i != 0)
				parse_textures_util(map, i, line);
		}
		else if (i != 0)
		{
			little_free(map, line);
			break ;
		}
		little_free(map, line);
		line = get_next_line(map->fd);
	}
	count_rows(map);
}
