/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:28:56 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/30 00:32:36 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	find_wall(t_map *map, double x, double y)
{
	double	padding;
	int		left;
	int		right;
	int		top;
	int		bottom;

	padding = 5;
	left = (int)((x - padding) / TILESIZE);
	right = (int)((x + padding) / TILESIZE);
	top = (int)((y - padding) / TILESIZE);
	bottom = (int)((y + padding) / TILESIZE);
	if (!map || !map->cmap)
		return (1);
	if (top < 0 || left < 0 || bottom >= map->height 
		|| right >= (int)ft_strlen(map->cmap[bottom]))
		return (1);
	if (map->cmap[top][left] == '1' || map->cmap[top][left] == 'D' ||
		map->cmap[top][right] == '1' || map->cmap[top][right] == 'D' 
		|| map->cmap[bottom][left] == '1' || map->cmap[bottom][left] == 'D' ||
		map->cmap[bottom][right] == '1' || map->cmap[bottom][right] == 'D')
		return (1);
	return (0);
}

int	player_in_door(t_map *map)
{
	int	i;
	int	j;
	int	lenx;

	i = 0;
	if (map && map->cmap)
	{
		while (i < map->row && map->cmap[i])
		{
			j = 0;
			lenx = ft_strlen(map->cmap[i]);
			while (j < lenx && map->cmap[i][j])
			{
				if (map->cmap[i][j] == 'o' && i == (int)(map->player.move_y 
					/ TILESIZE) && j == (int)(map->player.move_x / TILESIZE))
				{
					write(2, "can't close the doors\n", 50);
					return (1);
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}

void	open_close_doors(t_map *map, int flag)
{
	int	i;
	int	j;
	int	lenx;

	i = 0;
	if (map && map->cmap)
	{
		while (i < map->row && map->cmap[i])
		{
			j = 0;
			lenx = ft_strlen(map->cmap[i]);
			while (j < lenx && map->cmap[i][j])
			{
				if (flag == 0 && map->cmap[i][j] == 'D')
					map->cmap[i][j] = 'o';
				else if (flag == 1 && map->cmap[i][j] == 'o')
					map->cmap[i][j] = 'D';
				j++;
			}
			i++;
		}
	}
	map->door_hook = true;
}

void	exit_(t_map *map)
{
	ft_cleanup(map);
	exit(0);
}

void	handle_key(t_map *map)
{
	map->player.turn_direc = 0;
	map->player.walk_direc = 0;
	map->player.strafe_direc = 0;
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->player.turn_direc = -1;
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->player.turn_direc = 1;
	if (mlx_is_key_down(map->mlx, MLX_KEY_W) 
		|| mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->player.walk_direc = 1;
	if (mlx_is_key_down(map->mlx, MLX_KEY_S) 
		|| mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->player.walk_direc = -1;
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		map->player.strafe_direc = -1;
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		map->player.strafe_direc = 1;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		exit_(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_O))
		open_close_doors(map, 0);
	if (mlx_is_key_down(map->mlx, MLX_KEY_C) && !player_in_door(map))
		open_close_doors(map, 1);
	if (mlx_is_key_down(map->mlx, MLX_KEY_TAB))
		map->mouse_locked = !map->mouse_locked;
}
