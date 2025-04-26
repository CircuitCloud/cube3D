/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:39:36 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/26 04:29:21 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// void draw_floor_ceil(t_map *map)
// {
// 	int i = 0;
// 	int j = 0;
// 	int color = 0;
	
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		if (i < map->height / 2)
// 			color = 0x000000;
// 		else
// 			color = 0x808000;
// 		while (j < map->width)
// 			mlx_put_pixel(map->img, j++, i, color);
// 		i++;
// 	}
// }

void draw_floor_ceil(t_map *map)
{
	int i;
	int j;
	int tex_x;
	int	tex_y;
	uint32_t color;
	t_ray dummy_ray;

	i = 0;
	j  = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i < map->height / 2)//dyel celling
			{
				tex_x = j % map->ceiling_texture->width;
				tex_y = i % map->ceiling_texture->height;
				dummy_ray.texture_x = tex_x;
				// if(ft_strcmp(map->id->identifier, "C") && map->id->colors[0])
				// 	color = get_pixel_color(NULL, tex_x, tex_y, map);
				// else
					color = get_pixel_color(map->ceiling_texture, tex_x, tex_y, map);
				mlx_put_pixel(map->img, j, i, color);
			}
			else
			{
				tex_x = j % map->floor_texture->width;
				tex_y = (i - map->height / 2) % map->floor_texture->height;
				dummy_ray.texture_x = tex_x;
				color = 0x000000;
				// color = get_pixel_color(map->floor_texture, tex_x, tex_y);
				mlx_put_pixel(map->img, j, i, color);
			}
			j++;
		}
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
		// printf("HORizo: dist=%.2f, hit=(%.2f, %.2f)\n", map->ray[i].distance, map->ray[i].hor_hit_x, map->ray[i].hor_hit_y);
	}
	else
	{
		map->ray[i].hit_vertical = 0;
		map->ray[i].wall_hit_x = map->ray[i].hor_hit_x;
		map->ray[i].wall_hit_y = map->ray[i].hor_hit_y;
		// printf("VER: dist=%.2f, hit=(%.2f, %.2f)\n", distance1, map->ray[i].ver_hit_x, map->ray[i].ver_hit_y);

	}
}

void	set_rays_angle(t_map *map)
{
	int		i;
	double	fr_angle;
	double	agl;
	double	distance1;
	int		x;
	int		y;

	i = 0;
	map->rays_number = map->width;
	fr_angle = map->player.rot_angle - (FOV / 2);
	draw_floor_ceil(map);
	// draw_debug_player_dot(map);
	while (i < map->rays_number)
	{
		if (i == 0)
			agl = fr_angle;
		else
			agl += ANGLE;
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
