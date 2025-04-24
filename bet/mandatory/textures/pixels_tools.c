/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:37:01 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/24 06:49:42 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"

int	get_texture_pixel(t_map *map, t_ray ray, int tex_y)
{
	int			tex_x;
	int			texture_index;
	uint8_t		*pixels;
	int			index;
	uint8_t		r, g, b, a;
	uint32_t	color;
	t_texture	*texture;

	texture = map->text_buffer[ray.texture];
	if (!texture || !texture->img || !texture->img->pixels)
		return (0xFF000000); // transsssprnt
	tex_x = ray.texture_x;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= texture->width) 
		tex_x = texture->width - 1;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= texture->height) tex_y = texture->height - 1;
	pixels = texture->img->pixels;
	index = (tex_y * texture->width + tex_x) * 4;
	r = pixels[index + 0];
	g = pixels[index + 1];
	b = pixels[index + 2];
	a = pixels[index + 3];
	color = (r << 24) | (g << 16) | (b << 8) | a;
	return (color);
}

uint32_t get_pixel_color(t_texture *texture, int x, int y, t_map *map)
{
	uint8_t *pixels;
	uint8_t r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	int		index;

	if(texture)
	{
		pixels = texture->img->pixels;
		index = (y * texture->width + x) * 4;
		r = pixels[index + 0];
		g = pixels[index + 1];
		b = pixels[index + 2];
		a = pixels[index + 3];
	}
	else 
	{
		r = map->id->colors[0];
		g = map->id->colors[1];
		b = map->id->colors[2];
	}
	return (r << 24) | (g << 16) | (b << 8) | a;
}
