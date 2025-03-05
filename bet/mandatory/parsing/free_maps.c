/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:32:24 by cahaik            #+#    #+#             */
/*   Updated: 2025/02/24 13:19:12 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void free_maps(t_map *map, int flag)
{
	size_t i = 0;
	// free linked list of directions
	if (flag == 1 && map->cmap)
	{
		while (i < map->row + 1)
			free(map->cmap[i++]);
		free(map->cmap);
	}
}
