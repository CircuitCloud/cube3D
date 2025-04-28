/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:37:01 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/28 21:01:46 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	fill_c_f_arrays(t_map *map)
{
	t_identifier	*current;

	current = map->id;
	while (current)
	{
		if (!ft_strcmp("F", current->identifier))
		{
			map->floor_colors[0] = current->colors[0];
			map->floor_colors[1] = current->colors[1];
			map->floor_colors[2] = current->colors[2];
		}
		if (!ft_strcmp("C", current->identifier))
		{
			map->ceil_colors[0] = current->colors[0];
			map->ceil_colors[1] = current->colors[1];
			map->ceil_colors[2] = current->colors[2];
		}
		current = current->next;
	}
}

uint32_t	get_c_f_color(t_map *map, int c)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	fill_c_f_arrays(map);
	if (c)
	{
		r = map->ceil_colors[0];
		g = map->ceil_colors[1];
		b = map->ceil_colors[2];
	}
	else
	{
		r = map->floor_colors[0];
		g = map->floor_colors[1];
		b = map->floor_colors[2];
	}
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}

uint32_t	get_pixel_color(t_texture *texture, int x, int y, t_map *map)
{
	int		index;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	if (texture)
	{
		index = (y * texture->width + x) * 4;
		r = texture->img->pixels[index + 0];
		g = texture->img->pixels[index + 1];
		b = texture->img->pixels[index + 2];
		a = texture->img->pixels[index + 3];
	}
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

int	get_texture_pixel(t_map *map, t_ray ray, int tex_y)
{
	int			tex_x;
	int			index;
	uint32_t	color;
	t_texture	*texture;

	texture = map->text_buffer[ray.texture];
	if (!texture || !texture->img || !texture->img->pixels)
		return (0xFF000000);
	tex_x = ray.texture_x;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= texture->width) 
		tex_x = texture->width - 1;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= texture->height)
		tex_y = texture->height - 1;
	color = get_pixel_color(texture, tex_x, tex_y, map);
	return (color);
}
