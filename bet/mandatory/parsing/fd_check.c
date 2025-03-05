/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:48:10 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/02 13:25:17 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void fd_check(char *name, t_map *map, int flag)
{
	map->fd = open(name, O_RDONLY);
	if (map->fd < 0)
	{
		if (flag == 1)
			free_maps(map, 0);
		write(2, "Error\n**failed to open the map**\n",34);//perror
		exit(1);
	}
}
