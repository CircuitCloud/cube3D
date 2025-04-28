/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:14:33 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/28 16:16:35 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
	if (map->ceiling_texture)
		free_texture(map->ceiling_texture);
	if (map->floor_texture)
		free_texture(map->floor_texture);
}

void	ft_cleanup(t_map *map)
{
	free_textures(map);
	//free_ray
	mlx_delete_image(map->mlx, map->img);
	mlx_close_window(map->mlx);
}
