/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 01:47:11 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/29 15:07:42 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	which_texture(t_map *map, int index)
{
	if (map->ray[index].hit_vertical)
	{
		if (cos(map->ray[index].ray_angle) > 0)
			map->ray[index].texture = EAST_TEXTURE;
		else
			map->ray[index].texture = WEST_TEXTURE;
	}
	else
	{
		if (sin(map->ray[index].ray_angle) > 0)
			map->ray[index].texture = SOUTH_TEXTURE;
		else
			map->ray[index].texture = NORTH_TEXTURE;
	}
}

void	texture_coord(t_map *map, int i)
{
	double		hit_coord;
	double		wall_x;
	t_texture	*tex;

	which_texture(map, i);
	if (map->ray[i].is_door)
		tex = map->door_texture;
	else
		tex = map->text_buffer[map->ray[i].texture];
	if (map->ray[i].hit_vertical)
		hit_coord = map->ray[i].wall_hit_y;
	else
		hit_coord = map->ray[i].wall_hit_x;
	wall_x = fmod(hit_coord, TILESIZE) / TILESIZE;
	// if (wall_x < 0.01)//n9dr nmss7ha
	// 	wall_x = 0.01;
	// if (wall_x > 0.99)
	// 	wall_x = 0.99;
	map->ray[i].wall_x = wall_x;
	map->ray[i].texture_x = (int)(wall_x * tex->width);
	if ((map->ray[i].hit_vertical && cos(map->ray[i].ray_angle) > 0) 
		|| (!map->ray[i].hit_vertical && sin(map->ray[i].ray_angle) < 0))
		map->ray[i].texture_x = tex->width - map->ray[i].texture_x - 1;
	render_wall(map, map->ray[i], i);
}
