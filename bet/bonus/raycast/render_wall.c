/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:19:44 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/26 20:19:14 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_rectangle(t_map *map, double begin, double end, int x, int color)
{
	int	y;
	// int	color;

	// color = 0x808080;
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
	int		window_projection;
	double	proj_distance;
	double	proj_wall_height;
	double	begin;
	double	end;
	int		y;
	int		tex_y;
	int		color;

	ray.distance *= cos(map->player.rot_angle - ray.ray_angle);
	window_projection = (map->width / 2);
	proj_distance = window_projection / tan(FOV / 2);
	proj_wall_height = (TILESIZE / ray.distance) * proj_distance;
	begin = (map->height / 2) - (proj_wall_height / 2);
	end = begin + proj_wall_height;
	y = begin;
	while (y < end)
	{
		if (y >= 0 && y < map->height)
		{
			if (ray.is_door)
				color  = 0x228B22;
			else
			{
				tex_y = ((y - begin) * map->text_buffer[ray.texture]->height) / (end - begin);
				color = get_texture_pixel(map, ray, tex_y);
			}
				mlx_put_pixel(map->img, x, y, color);
		}
		y++;
	}
}
