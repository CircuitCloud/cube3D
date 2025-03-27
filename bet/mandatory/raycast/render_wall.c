/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:19:44 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/27 12:39:13 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw_rectangle(t_map *map, double begin, double end, int x)
{
	int y;
	int color;

	color = 0xFFFFFF01;
	y = 0;
	while (y < map->height)
	{
		if (y >= begin && y <= end)
			mlx_put_pixel(map->img, x, y, color);
		y++;
	}
}

void	render_wall(t_map *map, t_ray ray, int x)
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
	 draw_wall_with_texture(map, ray, x, begin, end);
	// draw_rectangle(map, begin, end, x);
}
