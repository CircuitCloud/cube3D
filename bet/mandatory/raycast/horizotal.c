/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizotal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:24:41 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/29 15:18:48 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	wall_existance(t_map *map, double x, double y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)((x) / TILESIZE);
	grid_y = (int)((y) / TILESIZE);
	if (!map || grid_y < 0 || grid_x < 0 || grid_y >= (int)map->row 
		|| !map->cmap[grid_y] || grid_x >= (int)ft_strlen(map->cmap[grid_y]))
		return (0);
	else if (map->cmap[grid_y][grid_x] == '1')
		return (0);
	else
		return (1);
}

double	horizontal_helper_y(t_ray ray, double *y, double y_f, double x_f)
{
	double	x;

	if (ray.up)
		(*y) = (floor(y_f / TILESIZE) * TILESIZE) - 0.0000000001;
	else if (ray.down)
		(*y) = (floor(y_f / TILESIZE) * TILESIZE) + TILESIZE;
	x = x_f + (((*y) - y_f) / tan(ray.ray_angle));
	return (x);
}

void	horizontal_helper_x(t_ray ray, double *y, double *x)
{
	(*y) += ray.step_y;
	(*x) += (ray.step_y / tan(ray.ray_angle));
}

double	horizontal_distance(t_map *map, t_ray *ray)
{
	double	x;
	double	y;
	double	x_f;
	double	y_f;

	ray->f_point_h = false;
	x_f = map->player.move_x;
	y_f = map->player.move_y;
	x = x_f;
	y = y_f;
	if (ray->up)
		ray->step_y = -TILESIZE;
	else
		ray->step_y = TILESIZE;
	while (y >= 0 && y <= map->row * TILESIZE && x >= 0 && x < ft_strlen(map->cmap[((int)y / TILESIZE)]) * TILESIZE)
	{
		if (!wall_existance(map, x, y))
			return (ray->hor_hit_x = x, ray->hor_hit_y = y, sqrt(pow(x - x_f, 2) + pow(y - y_f, 2)));
		if (!ray->f_point_h)
			x = horizontal_helper_y(*ray, &y, y_f, x_f);
		else
			horizontal_helper_x(*ray, &y, &x);
		ray->f_point_h = true; 
	}
	return (ray->hor_hit_x = x, ray->hor_hit_y = y, sqrt(pow(x - x_f, 2) + pow(y - y_f, 2)));
}
