/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:24:36 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/17 13:47:21 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double vertical_distance(t_map *map, t_ray ray)
{
	double x_f ;
	double y_f ;
	double step_x;
	double y;
	double x;
	double prev_x;
	double prev_y;
	bool f_point;
	
	f_point = false;
	x_f = map->player.move_x;
	y_f = map->player.move_y;
	x = x_f;
	y = y_f;
	int wall;
	if (ray.right)
		step_x = TILESIZE;
	else
		step_x = -TILESIZE;
	while (x_f < WIDTH && y_f <= HEIGHT && x <= WIDTH && y <= HEIGHT)
	{
		wall = wall_existance(map, x, y);
			if (!wall)
				return (sqrt(pow(x - x_f, 2) + pow(y - y_f, 2)));
		if (!f_point)
		{
			if (ray.right)
				x = (floor(x_f / TILESIZE) * TILESIZE) + TILESIZE;
			else if (ray.left)
				x = (floor(x_f / TILESIZE) * TILESIZE) - 0.0000000001;
			y = y_f + (tan(ray.ray_angle) * (x - x_f));
			f_point = true; 
		}
		else
		{
			x += step_x;
			y += (step_x * tan(ray.ray_angle));
		}
	}
	return (sqrt(pow(x - x_f, 2) + pow(y - y_f, 2)));
}
