/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 01:47:11 by ykamboua          #+#    #+#             */
/*   Updated: 2025/03/27 13:46:41 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../cub3D.h"

void	which_texture(t_map *map, int index)
{
	if(map->ray[index].hit_vertical)
	{
		if(cos(map->ray[index].ray_angle) > 0)
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

//__________calculate_texture_x
void	x_cordianets(t_ray *ray)
{
	if(ray->hit_vertical)
		ray->texture_x = fmod(ray->y_v_wall, TEXTURE_SIZE);
	else
		ray->texture_x = fmod(ray->x_h_wall, TEXTURE_SIZE);
	ray->texture_x = (ray->texture_x / TEXTURE_SIZE) * NUM_TEXTURES;
}

