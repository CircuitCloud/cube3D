/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:24:29 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/16 23:40:06 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"

t_texture	*load_texture(const char *path)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
	{
		//freee && exit
		printf("Error: Failed to allocate texture\n");
		exit(1);
	}
	texture->img = mlx_load_png(path);
	if (!texture->img)
	{
		//freee && exitttt
		printf("E4ror: ffailed to load texture %s\n", path);
		exit(1);
	}
	texture->width = texture->img->width;
	texture->height = texture->img->height;
	texture->adr = (uint32_t *)texture->img->pixels;
	printf("loaded texture: %s -> al WIDTH: %d, &&& HEIGHT: %d\n", path, texture->width, texture->height);
	return (texture);
}


int	load_walls(t_map *map)
{
	t_identifier	*current;

    if (!map || !map->id)
	{
        printf("Error: map or map->id is NULL\n");
        return (1);
    }
	current = map->id;
	while (current && current->identifier)
	{
		if(!ft_strcmp(current->identifier, "NO"))
			map->text_buffer[NORTH_TEXTURE] = load_texture(current->path);
		if(!ft_strcmp(current->identifier, "SO"))
			map->text_buffer[SOUTH_TEXTURE] = load_texture(current->path);
		if(!ft_strcmp(current->identifier, "WE"))
			map->text_buffer[WEST_TEXTURE] = load_texture(current->path);
		if(!ft_strcmp(current->identifier, "EA"))
			map->text_buffer[EAST_TEXTURE] = load_texture(current->path);
		current = current->next;
	}
	printf("aahahaaa\n");
	return(0);
}

void load_textures(t_map *map)
{
	load_walls(map);
	map->player_texture = load_texture("textures/3essa.png");
	map->ceiling_texture = load_texture("textures/openart-image_6sCiqmgt_1744752491452_raw.png");
	map->floor_texture = load_texture("textures/openart-image_x49WIgMa_1744751845454_raw.png");
}
