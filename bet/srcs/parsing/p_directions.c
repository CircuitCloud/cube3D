/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_directions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:00:18 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/02 12:44:14 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void n_zero_check(t_map *map, int i , int j, int flag)
{
	if (!map->cmap[i + 1][j] || !map->cmap[i - 1][j] || map->cmap[i + 1][j] == ' ' || 
		map->cmap[i - 1][j] == ' ' || map->cmap[i][j + 1] == ' ' || map->cmap[i][j - 1] == ' ')
			exit (1);// invalid_map(" invalid position(direction or 0)", map, 1);
	if (flag == 1)
	{
		if (ft_strlen(map->cmap[i + 1]) - 2 < (size_t)j && ft_strlen(map->cmap[i - 1]) - 2 < (size_t)j)
			exit (1); //invalid_map(" invalid palyer's position", map, 1);
		else
		{
			map->player.x = i;
			map->player.y = j;
			map->player.direction= map->cmap[i][j];
		}
	}
}

void p_directions(t_map* map, int n_players)
{
	int j;
	int i = 0;
	int len = 0;
	while (map->cmap[i])
	{
		j = 0;
		len = ft_strlen(map->cmap[i]);
		while ((j < len - 1) && map->cmap[i][j])
		{
			if (map->cmap[i][j] == 'N' || map->cmap[i][j] == 'S' || 
				map->cmap[i][j] == 'W' || map->cmap[i][j] == 'E')
			{
				n_zero_check(map, i, j, 1);
				n_players++;
			}
			else if (map->cmap[i][j] == '0')
				n_zero_check(map, i, j, 0);
			j++;
		}
		i++;
	}
	if (n_players != 1)
		exit (1); //invalid_map(" More/Less than one player", map, 1);
}
