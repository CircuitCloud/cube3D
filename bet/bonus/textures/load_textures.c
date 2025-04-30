/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:24:29 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/30 01:27:24 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

t_texture	*load_texture(const char *path, t_map *map)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
	{
		ft_cleanup(map);
		printf("Error: Failed to allocate texture\n");
		exit(1);
	}
	texture->img = mlx_load_png(path);
	if (!texture->img)
	{
		ft_cleanup(map);
		printf("Error: Failed to load texture %s\n", path);
		exit(1);
	}
	texture->width = texture->img->width;
	texture->height = texture->img->height;
	texture->adr = (uint32_t *)texture->img->pixels;
	return (texture);
}

int	load_walls(t_map *map)
{
	t_identifier	*current;

	current = map->id;
	while (current && current->identifier)
	{
		if (!ft_strcmp(current->identifier, "NO"))
			map->text_buffer[NORTH_TEXTURE] = load_texture(current->path, map);
		if (!ft_strcmp(current->identifier, "SO"))
			map->text_buffer[SOUTH_TEXTURE] = load_texture(current->path, map);
		if (!ft_strcmp(current->identifier, "WE"))
			map->text_buffer[WEST_TEXTURE] = load_texture(current->path, map);
		if (!ft_strcmp(current->identifier, "EA"))
			map->text_buffer[EAST_TEXTURE] = load_texture(current->path, map);
		current = current->next;
	}
	return (0);
}

void	load_textures(t_map *map)
{
	load_walls(map);
	map->player_texture = 
		load_texture("textures/s0.png", map);
	map->door_texture = load_texture("textures/bb.png", map);
	load_sprite_frames(map);
}
