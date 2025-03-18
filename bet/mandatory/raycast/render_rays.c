/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:39:36 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/17 13:22:46 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
	double distance;

	i = 0;
	fr_angle = map->player.rot_angle - FOV/2;
	px = map->player.move_x;
	py = map->player.move_y;
	while (i < RAYS_NUMBER)
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
			distance = distance1;
		else
			distance = distance2;
		x = px + (cos(map->ray[i].ray_angle) * distance);
		y = py + (sin(map->ray[i].ray_angle) * distance);
		if (x < 0 || y < 0)
		{
			printf("hna\n");
			exit(1);
		}
		draw_line(map->img, px, py, x, y, 0xFF0000FF);
		i++;
	}
}
