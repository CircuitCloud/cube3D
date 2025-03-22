/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:19:44 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/22 16:16:07 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw_rectangle(t_map *map, double begin, double end, int x)
{
	int y;
	int color;
	
	color = 0xFF0000FF;
	y = 0;
	while (y < map->height)
	{
		if (y >= begin && y <= end)
			mlx_put_pixel(map->img, x, y, color);
		y++;
	}
}

void render_wall(t_map *map, t_ray ray, int x)
{
	int window_projection;
	double proj_distance;
	double proj_wall_height;
	double begin;
	double end;
	
	window_projection = map->width / 2;
	proj_distance = window_projection / tan(FOV / 2);
	proj_wall_height = (TILESIZE / ray.distance) * proj_distance;
	begin = (map->height / 2 ) - proj_wall_height / 2;
	end = begin + proj_wall_height;
	draw_rectangle(map, begin, end, x);
}
