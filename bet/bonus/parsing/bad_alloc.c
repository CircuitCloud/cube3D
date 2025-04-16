/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:24:10 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/24 10:42:04 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	bad_alloc(t_map *map)
{
	if (!map->cmap)
	{
		if (map && map->id) 
			free_linked_list(map->id, 0);
		write(2, "Error\n**Allocation Failed**\n", 29);
		close(map->fd);
		exit (1);
	}
}

void	alloc_check(t_map *map, t_identifier *new, char *line)
{
	new->colors = malloc(sizeof(int) * 3);
	if (!new->colors)
	{
		invalid_map(" numbers allocation failed\n", map, new, line);
		exit(1);
	}
}
