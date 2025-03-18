/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizotal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:24:41 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/17 13:47:28 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int wall_existance(t_map *map, double x, double y)
{
	int grid_x;
	int grid_y;

	grid_x = (int) x / TILESIZE;
	grid_y = (int) y / TILESIZE;
	
	if (!map || grid_y < 0 || grid_x < 0 || grid_y >= map->row || !map->cmap[grid_y] || grid_x >= ft_strlen(map->cmap[grid_y]))
		return (0);
	else if (map->cmap[grid_y][grid_x] == '1')
		return (0);
	else
		return (1);
}

double horizontal_distance(t_map *map, t_ray ray)
{
	double x_f ;
	double y_f ;
	double step_y;
	double y;
	double x;
	double wall;
	bool f_point;
	
	f_point = false;
	x_f = map->player.move_x;
	y_f = map->player.move_y;
	x = x_f;
	y = y_f;
	if (ray.up)
		step_y = -TILESIZE;
	else
		step_y = TILESIZE;
	while (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		wall = wall_existance(map, x, y);
		if (!wall)
			return (sqrt(pow(x - x_f, 2) + pow(y - y_f, 2)));
		if (!f_point)
		{
			if (ray.up)
				y = (floor(y_f / TILESIZE) * TILESIZE) - 0.0000000001;
			else if (ray.down)
				y = (floor(y_f / TILESIZE) * TILESIZE) + TILESIZE;
			x = x_f + ((y - y_f) / tan(ray.ray_angle));
			f_point = true; 
		}
		else
		{
			y += step_y;
			x += (step_y / tan(ray.ray_angle));
		}
	}
	return (sqrt(pow(x - x_f, 2) + pow(y - y_f, 2)));
}
