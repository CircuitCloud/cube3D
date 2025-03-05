/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:24:10 by cahaik            #+#    #+#             */
/*   Updated: 2025/02/23 12:41:16 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void bad_alloc(t_map *map, int flag)
{
	if (flag == 1)
		free_maps(map, 0);
	write(2, "Error\n**Allocation Failed**\n", 29);
	close(map->fd);
	exit (1);	
}
