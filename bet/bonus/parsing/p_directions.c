/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_directions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:00:18 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/26 19:57:36 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	doors_check(t_map *map, int i, int j)
{
	if (map->cmap[i - 1][j] == '1' && map->cmap[i + 1][j] == '1' 
		&& map->cmap[i][j + 1] == '0' && map->cmap[i][ j+ 1] == '0')
			return (0);
	else if (map->cmap[i - 1][j] == '0' && map->cmap[i + 1][j] == '0'
		&& map->cmap[i][j + 1] == '1' && map->cmap[i][j+1] == '1')
			return (0);
	return (1);
}

int	z_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	n_zero_check(t_map *map, int i, int j, int flag)
{
	int	nxlen;
	int	prvlen;

	nxlen = ft_strlen(map->cmap[i + 1]);
	prvlen = ft_strlen(map->cmap[i - 1]);
	if (!map->cmap[i + 1] || j >= nxlen || !map->cmap[i + 1][j]
	|| !map->cmap[i - 1] || j >= prvlen || !map->cmap[i - 1][j]
	|| z_space(map->cmap[i + 1][j]) 
	|| z_space(map->cmap[i - 1][j]) || z_space(map->cmap[i][j + 1]) 
	|| z_space(map->cmap[i][j - 1]))
		invalid_map_3(POSITION_OF_ZERO, map, 0);
	if (flag == 2 && doors_check(map, i, j))
		invalid_map_3("Doors check!!", map, 0);
	if (flag == 1)
	{
		if (nxlen - 1 < j && prvlen - 1 < j)
			invalid_map_3(PLAYER_POSITION, map, 0);
		else
		{
			map->player.y = i;
			map->player.x = j;
			map->player.direction = map->cmap[i][j];
		}
	}
}

void	p_directions(t_map *map, int n_players)
{
	int	j;
	int	i;

	i = 0;
	while (map && map->cmap[i])
	{
		j = 0;
		while (j < ft_strlen(map->cmap[i]) && map->cmap[i][j])
		{
			if (map->cmap[i][j] == 'N' || map->cmap[i][j] == 'S' || 
				map->cmap[i][j] == 'W' || map->cmap[i][j] == 'E')
			{
				n_zero_check(map, i, j, 1);
				n_players++;
			}
			else if (map->cmap[i][j] == '0')
				n_zero_check(map, i, j, 0);
			else if (map->cmap[i][j] == 'D')
				n_zero_check(map, i, j, 2);
			j++;
		}
		i++;
	}
	if (n_players != 1)
		invalid_map_3(PLAYER_NUMBER, map, 0);
}
