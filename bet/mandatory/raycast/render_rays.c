/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:39:36 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/29 21:39:08 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_floor_ceil(t_map *map)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < map->height)
	{
		j = 0;
		if (i < map->height / 2)
			color = get_c_f_color(map, 1);
		else
			color = get_c_f_color(map, 0);
		while (j < map->width)
			mlx_put_pixel(map->img, j++, i, color);
		i++;
	}
}

void	check_distance(t_map *map, int i, double distance1)
{
	if (map->ray[i].distance > distance1)
	{
		map->ray[i].distance = distance1;
		map->ray[i].hit_vertical = 1;
		map->ray[i].wall_hit_x = map->ray[i].ver_hit_x;
		map->ray[i].wall_hit_y = map->ray[i].ver_hit_y;
	}
	else
	{
		map->ray[i].hit_vertical = 0;
		map->ray[i].wall_hit_x = map->ray[i].hor_hit_x;
		map->ray[i].wall_hit_y = map->ray[i].hor_hit_y;
	}
}

void	set_rays_angle(t_map *map)
{
	int		i;
	double	agl;
	double	distance1;
	int		x;
	int		y;

	i = 0;
	map->rays_number = map->width;
	draw_floor_ceil(map);
	while (i < map->rays_number)
	{
		if (i == 0)
			agl = map->player.rot_angle - (map->fov / 2);
		else
			agl += map->fov_angle;
		map->ray[i].ray_angle = agl;
		ray_look_direction(&map->ray[i].ray_angle, &map->ray[i]);
		map->ray[i].distance = horizontal_distance(map, &map->ray[i]);
		distance1 = vertical_distance(map, &map->ray[i]);
		check_distance(map, i, distance1);
		texture_coord(map, i);
		i++;
	}
	render_pov(map);
}
