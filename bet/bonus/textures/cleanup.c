/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:14:33 by ykamboua          #+#    #+#             */
/*   Updated: 2025/05/01 18:05:43 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	free_texture(t_texture *texture)
{
	if (!texture)
		return ;
	if (texture->img)
	{
		mlx_delete_texture(texture->img);
		texture->img = NULL;
	}
	texture->adr = NULL;
	free(texture);
}

void	free_textures(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < NUM_TEXTURES)
	{
		if (map->text_buffer[i])
		{
			free_texture(map->text_buffer[i]);
			map->text_buffer[i] = NULL;
		}
		i++;
	}
	if (map->player_texture)
		free_texture(map->player_texture);
	if (map->door_texture)
		free_texture(map->door_texture);
}

void	free_sprite(t_sprite *sprite)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (sprite->frames[i])
			free_texture(sprite->frames[i]);
		i++;
	}
	if (sprite->frames)
		free(sprite->frames);
}

void	exit_(t_map *map)
{
	ft_cleanup(map);
	exit(0);
}

void	ft_cleanup(t_map *map)
{
	free_textures(map);
	if (map->player_sprite.frames)
		free_sprite(&map->player_sprite);
	if (map->ray)
		free(map->ray);
	invalid_map_3("cleanup", map, 1);
	if (map->img)
		mlx_delete_image(map->mlx, map->img);
	mlx_close_window(map->mlx);
}
