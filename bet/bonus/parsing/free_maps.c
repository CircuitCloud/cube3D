/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:32:24 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/30 00:32:42 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	free_maps(t_map *map, int flag)
{
	size_t	i;

	i = 0;
	if (flag == 1 && map->cmap)
	{
		while (i < map->row + 1)
			free(map->cmap[i++]);
		free(map->cmap);
	}
}
