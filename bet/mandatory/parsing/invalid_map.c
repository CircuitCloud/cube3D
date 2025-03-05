/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:56:27 by cahaik            #+#    #+#             */
/*   Updated: 2025/02/24 13:43:18 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void free_linked_list(t_identifier *id)
{
	t_identifier *new_head = id;
	
		while (id)
		{
			if (id->identifier)
				free(id->identifier);
			if (id->path)
				free(id->path);
			if (id->colors)
				free(id->colors);
			id = id->next;
		}
		if (new_head)
			free(new_head);
}

void invalid_map_textures(char *message, t_map *map, char** comma_split, char **splited)
{
	char *concat = strcat("Error\nInvalid Map :", message);
	write (2, concat, ft_strlen(concat));//need to create strcat
	free_splited(splited);
	free_splited(comma_split);
	free_linked_list(map->id);
	exit(1);
}

void invalid_map(char *message, t_map *map, int flag)
{
	char *concat = strcat("Error\nInvalid Map :", message);
	write(2, concat, strlen(concat));
	if (flag == 1)
		free_maps(map, 1);
	else
		free_maps(map, 0);
	close(map->fd);
	write(1, "\n", 1);
	exit(1);
}
