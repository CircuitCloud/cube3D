/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_text_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:14:57 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/30 00:32:54 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	comp_dir(t_identifier *id, char *s)
{
	while (id && id->identifier)
	{
		if (!ft_strcmp(s, id->identifier))
			return (1);
		id = id->next;
	}
	return (0);
}

char	**colors_helper(char *line, int *commas, int *i)
{
	int		j;
	char	*str;
	char	**split_numbers;

	j = 0;
	str = ft_strchr(line, ' ');
	while (str && str[j])
	{
		if (str[j] == ',')
			(*commas)++;
		j++;
	}
	split_numbers = ft_split(str, ',');
	while (split_numbers && split_numbers[*i])
		(*i)++;
	return (split_numbers);
}

void	colors_(t_map *map, t_identifier *new, char *line)
{
	int		i;
	int		err;
	int		range;
	int		commas;

	i = 0;
	commas = 0;
	map->split_numbers = NULL;
	new->identifier = ft_strdup(map->splited[0]);
	map->split_numbers = colors_helper(line, &commas, &i);
	if (commas != 2 || i-- != 3)
		invalid_map(COMMAS_NUMBER, map, new, line);
	alloc_check(map, new, line);
	while (i >= 0 && map->split_numbers && map->split_numbers[i])
	{
		range = cub_atoi(map->split_numbers[i], &err);
		if (err == 0 && (range >= 0 && range <= 255))
			new->colors[i] = range;
		else
			invalid_map(OUT_OF_RANGE, map, new, line);
		i--;
	}
	free_splited(map->split_numbers);
	map->split_numbers = NULL;
}

void	parse_textures_util(t_map *map, int i, char *line)
{
	t_identifier	*new;

	new = cub_lstnew();
	if (i == 2 && ((!ft_strcmp("NO", map->splited[0])
				|| !ft_strcmp("SO", map->splited[0])
				|| !ft_strcmp("WE", map->splited[0])
				|| !ft_strcmp("EA", map->splited[0])) 
			&& !comp_dir(map->id, map->splited[0])))
	{
		new->identifier = ft_strdup(map->splited[0]);
		new->path = ft_strdup(map->splited[1]);
	}
	else if (i <= 6 && ((!ft_strcmp("F", map->splited[0])
				|| !ft_strcmp("C", map->splited[0])) 
			&& !comp_dir(map->id, map->splited[0])))
		colors_(map, new, line);
	else
		invalid_map(INVALID_TEXTURES, map, new, line);
	cub_lstadd_back(&map->id, new);
	map->row++;
}
