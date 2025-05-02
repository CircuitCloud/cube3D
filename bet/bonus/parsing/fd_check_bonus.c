/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:48:10 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/30 00:32:41 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	fd_check(char *name, t_map *map, int flag)
{
	map->fd = open(name, O_RDONLY);
	if (map->fd < 0)
	{
		if (flag == 1)
		{
			if (map && map->id) 
				free_linked_list(map->id, 0);
		}
		write(2, "Error\n**failed to open the map**\n", 34);
		exit(1);
	}
}
