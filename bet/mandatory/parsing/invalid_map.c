/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:56:27 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/05 14:32:27 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void free_linked_list(t_identifier *id, int flag)
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
			if (flag == 1)
			{
				free(id);
				return ;
			}
			id = id->next;
		}
		if (new_head)
			free(new_head);
}

void invalid_map(char *message, t_map *map, char **s_numbers, t_identifier *new)
{
	if (map)
	{
		if (map->splited)
			free_splited(map->splited);
		if (s_numbers)
			free_splited(s_numbers);
		if (map->id) 
			free_linked_list(map->id, 0);
	}
	if (new)
		free_linked_list(new, 1);
	write(2, "Error\nInvalid Map :", 20);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	close(map->fd);
	exit(1);
}
