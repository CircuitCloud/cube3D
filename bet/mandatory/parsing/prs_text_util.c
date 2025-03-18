/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_text_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:14:57 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/13 11:14:43 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int comp_dir(t_identifier *id, char *s)
{
	while (id && id->identifier)
	{
		if (!ft_strcmp(s, id->identifier))
			return (1);
		id = id->next;
	}
	return (0);
}

void colors_(t_map *map, t_identifier *new, char *line)
{
	int i;
	int err;
	int range;
	int commas;
	char **split_numbers;
	char *str;

	i = 0;
	commas = 0;
	split_numbers = NULL;
	new->identifier = ft_strdup(map->splited[0]);
	str = ft_strchr(line, ' ');
	while (str && str[i])
	{
		if (str[i] == ',')
			commas++;
		i++;
	}
	split_numbers = ft_split(str, ',');
	i = 0;
	while (split_numbers && split_numbers[i])
		i++;
	if (commas != 2 || i != 3)
	{
		free(line);
		invalid_map(" commas number or less/more than numbers required", map, split_numbers, new);
	}
	new->colors = malloc(sizeof(int) * 3);// allocation check
	i--;
	while (i >= 0 && split_numbers[i])
	{
		range = cub_atoi(split_numbers[i], &err);
		if (err == 0 && (range >= 0 && range <= 255))
			new->colors[i] = range;
		else
		{
			free(line);
			invalid_map(" numbers not whithin range required", map, split_numbers, new);
		}
		i--;
	}
	free_splited(split_numbers);
}

void parse_textures_util(t_map *map, int i, char *line)
{
	t_identifier *new;
	
	new = cub_lstnew();
	if (i == 2 && ((!ft_strcmp("NO", map->splited[0]) || 
	!ft_strcmp("SO", map->splited[0]) 
	||  !ft_strcmp("WE", map->splited[0])
	|| !ft_strcmp("EA", map->splited[0])) && !comp_dir(map->id, map->splited[0])))
	{
		new->identifier = ft_strdup(map->splited[0]);
		new->path = ft_strdup(map->splited[1]);
	}
	else if (i <= 6 && ((!ft_strcmp("F", map->splited[0])  || 
			!ft_strcmp("C", map->splited[0])) && !comp_dir(map->id, map->splited[0])))
		colors_(map, new,line);
	else
		invalid_map(" invalid textures", map, NULL, new);
	cub_lstadd_back(&map->id, new);
	map->row++;
}
