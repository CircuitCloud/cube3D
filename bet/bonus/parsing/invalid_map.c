/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:56:27 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/30 00:32:46 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

t_identifier	*free_linked_list(t_identifier *id, int flag)
{
	t_identifier	*tmp;

	(void)flag;
	while (id)
	{
		if (id->identifier)
			free(id->identifier);
		if (id->path)
			free(id->path);
		if (id->colors)
			free(id->colors);
		tmp = id;
		id = id->next;
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

void	invalid_map(char *ms, t_map *map, t_identifier *new, char *line)
{
	if (line)
		free(line);
	if (map)
	{
		if (map->splited)
			free_splited(map->splited);
		if (map->split_numbers)
			free_splited(map->split_numbers);
		if (map->id) 
			map->id = free_linked_list(map->id, 0);
	}
	if (new)
		free_linked_list(new, 1);
	write(2, "Error\nInvalid Map :", 20);
	write(2, ms, ft_strlen(ms));
	write(2, "\n", 1);
	close(map->fd);
	exit(1);
}

void	invalid_map_2(char *message, t_map *map, char *line, char *pureline)
{
	int	i;

	i = 0;
	if (line)
		free(line);
	if (pureline)
		free(pureline);
	if (map)
	{
		if (map->id) 
			map->id = free_linked_list(map->id, 0);
		while (map->cmap && map->cmap[i])
		{
			free(map->cmap[i]);
			i++;
		}
		if (map->cmap)
			free(map->cmap);
		map->cmap = NULL;
	}
	write(2, "Error\nInvalid Map :", 20);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	close(map->fd);
	exit(1);
}

void	invalid_map_3(char *message, t_map *map, int flag)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->id)
			map->id = free_linked_list(map->id, 0);
		while (map->cmap && map->cmap[i])
		{
			free(map->cmap[i]);
			map->cmap[i] = NULL;
			i++;
		}
		if (map->cmap)
			free(map->cmap);
	}
	if (flag == 0)
	{
		write(2, "Error\nInvalid Map :", 20);
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
		exit(1);
	}
	else
		write(1, message, ft_strlen(message));
}
