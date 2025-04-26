/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:24:36 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/26 20:04:21 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double	vertical_helper_y(t_ray ray, double *x, double y_f, double x_f)
{
	double	y;

	if (ray.right)
		(*x) = (floor(x_f / TILESIZE) * TILESIZE) + TILESIZE;
	else if (ray.left)
		(*x) = (floor(x_f / TILESIZE) * TILESIZE) - 0.0000000001;
	y = y_f + (tan(ray.ray_angle) * ((*x) - x_f));
	return (y);
}

void	vertical_helper_x(t_ray ray, double *y, double *x)
{
	(*x) += ray.step_x;
	(*y) += (ray.step_x * tan(ray.ray_angle));
}

double	vertical_distance(t_map *map, t_ray *ray, int index)
{
	double	x;
	double	y;
	double	x_f;
	double	y_f;

	ray->f_point_v = false;
	x_f = map->player.move_x;
	y_f = map->player.move_y;
	x = x_f;
	y = y_f;
	if (ray->right)
		ray->step_x = TILESIZE;
	else
		ray->step_x = -TILESIZE;
	while (y >= 0 && y < map->row * TILESIZE && x >= 0 && x < ft_strlen(map->cmap[((int)y / TILESIZE)]) * TILESIZE)
	{
		if (!wall_existance(map, x, y, index))
			return (ray->ver_hit_x = x, ray->ver_hit_y = y, sqrt(pow(x - x_f, 2) + pow(y - y_f, 2)));
		if (!ray->f_point_v)
			y = vertical_helper_y(*ray, &x, y_f, x_f);
		else
			vertical_helper_x(*ray, &y, &x);
		ray->f_point_v = true; 
	}
	return (ray->ver_hit_x = x, ray->ver_hit_y = y, sqrt(pow(x - x_f, 2) + pow(y - y_f, 2)));
}
