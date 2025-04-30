/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:19:44 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/30 00:32:58 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	render_wall_helper(t_map *map, t_ray ray)
{
	int		window_projection;
	double	proj_distance;

	ray.distance *= cos(map->player.rot_angle - ray.ray_angle);
	window_projection = (map->width / 2);
	proj_distance = window_projection / tan(map->fov / 2);
	map->proj_wall_height = (TILESIZE / ray.distance) * proj_distance;
}

void	render_wall(t_map *map, t_ray ray, int x)
{
	double	begin;
	double	end;
	int		y;
	int		tex_y;
	int		color;

	render_wall_helper(map, ray);
	begin = (map->height / 2) - (map->proj_wall_height / 2);
	end = begin + map->proj_wall_height;
	y = begin;
	while (y < end)
	{
		if (y >= 0 && y < map->height)
		{
			if (ray.is_door)
				tex_y = ((y - begin) * map->door_texture->height) 
					/ (end - begin);
			else
				tex_y = ((y - begin) * map->text_buffer[ray.texture]->height)
					/ (end - begin);
			color = get_texture_pixel(map, ray, tex_y);
			mlx_put_pixel(map->img, x, y, color);
		}
		y++;
	}
}
