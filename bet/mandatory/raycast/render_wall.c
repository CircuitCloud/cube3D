/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:19:44 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/28 02:12:19 by ykamboua         ###   ########.fr       */
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


int	get_texture_pixel(t_map *map, t_ray ray, int tex_y)
{
	int	color;
	int	tex_x;
	int	texture_index;
	t_texture *texture;

	// Determine texture index based on ray direction
	if (ray.hit_vertical)
		texture_index = (cos(ray.ray_angle) > 0) ? EAST_TEXTURE : WEST_TEXTURE;
	else
		texture_index = (sin(ray.ray_angle) > 0) ? SOUTH_TEXTURE : NORTH_TEXTURE;

	// Ensure textures are loaded
	texture = map->text_buffer[texture_index];
	if (!texture || !texture->adr)
		return (0xFF000000); // Return black if no texture is found

	// Ensure texture coordinates are within bounds
	tex_x = ray.texture_x;
	tex_y = tex_y;

	if (tex_x < 0) tex_x = 0;
	if (tex_x >= texture->width) tex_x = texture->width - 1;
	if (tex_y < 0) tex_y = 0;
	if (tex_y >= texture->height) tex_y = texture->height - 1;

	// Fetch pixel color from texture
	color = texture->adr[tex_y * texture->width + tex_x];

	return (color);
}


void	render_wall(t_map *map, t_ray ray, int x)
{
	int		window_projection;
	double	proj_distance;
	double	proj_wall_height;
	int		begin;
	int		end;
	int		y;
	int		tex_y;
	int		color;

	window_projection = map->width / 2;
	proj_distance = window_projection / tan(FOV / 2);
	proj_wall_height = (TILESIZE / ray.distance) * proj_distance;

	begin = (map->height / 2) - proj_wall_height / 2;
	end = begin + proj_wall_height;

	// Ensure the wall is within screen bounds
	if (begin < 0)
		begin = 0;
	if (end > map->height)
		end = map->height;

	y = begin;
	while (y < end)
	{
		// Map the screen pixel `y` to a texture `tex_y`
		tex_y = ((y - begin) * TILESIZE) / (end - begin);

		// Get the texture color (assuming you have textures stored in `map->textures`)
		color = get_texture_pixel(map, ray, tex_y);

		// Put the pixel on the screen (replace with your image buffer function if needed)
		mlx_put_pixel(map->img, x, y, color);


		y++;
	}
}


// void	render_wall(t_map *map, t_ray ray, int x)
// {
// 	int window_projection;
// 	double proj_distance;
// 	double proj_wall_height;
// 	double begin;
// 	double end;

// 	window_projection = map->width / 2;
// 	proj_distance = window_projection / tan(FOV / 2);
// 	proj_wall_height = (TILESIZE / ray.distance) * proj_distance;
// 	begin = (map->height / 2 ) - proj_wall_height / 2;
// 	end = begin + proj_wall_height;
// 	//  draw_wall_with_texture(map, ray, x, begin, end);
// 	draw_rectangle(map, begin, end, x);
// }
