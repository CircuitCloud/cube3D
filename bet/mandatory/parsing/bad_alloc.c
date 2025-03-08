/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:24:10 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/08 15:20:56 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void bad_alloc(t_map *map)
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
