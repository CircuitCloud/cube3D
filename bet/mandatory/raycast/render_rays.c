/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:39:36 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/22 16:32:20 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw_floor_ceil(t_map *map)
{
	int i = 0;
	int j = 0;
	int color = 0;
	
	while (i < map->height)
	{
		j = 0;
		if (i < map->height / 2)
			color = 0xFFB347;
		else
			color = 0xFFFFFFFF;
		while (j < map->width)
			mlx_put_pixel(map->img, j++, i, color);
		i++;
	}
}

void set_rays_angle(t_map *map)
{
	int i;
	int px;
	int py;
	int x;
	int y;
	double fr_angle;
	double agl;
	double distance1;
	double distance2;
	int rays;

	i = 0;
	fr_angle = map->player.rot_angle - FOV/2;
	px = map->player.move_x;
	py = map->player.move_y;
	rays = map->width;
	draw_floor_ceil(map);
	while (i < rays)
	{
		if (i == 0)
			agl = fr_angle;
		else
			agl += ANGLE;
		map->ray[i].ray_angle = agl;
		ray_look_direction(&map->ray[i].ray_angle, &map->ray[i]);
		distance1 = horizontal_distance(map, map->ray[i]);
		distance2 = vertical_distance(map, map->ray[i]);
		if (distance1 <= distance2)
			map->ray[i].distance = distance1;
		else
			map->ray[i].distance = distance2;
		// x = px + (cos(map->ray[i].ray_angle) * map->ray[i].distance);
		// y = py + (sin(map->ray[i].ray_angle) * map->ray[i].distance);
		// draw_line(map->img, px, py, x, y, 0);
		render_wall(map, map->ray[i], i);
		i++;
	}
}
