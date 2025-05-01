/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:23:19 by ykamboua          #+#    #+#             */
/*   Updated: 2025/05/01 23:11:57 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	draw_mini_player(t_map *map)
{
	int			ppx;
	int			ppy;
	uint32_t	color;

	color = (99 << 24) | (55 << 16) | (11 << 8) | 255;
	ppx = MP_OFFSET_X + map->player.move_x 
		* MP_SCALE + map->player.x * MP_TILE_SPACE;
	ppy = MP_OFFSET_Y + map->player.move_y 
		* MP_SCALE + map->player.y * MP_TILE_SPACE;
	draw_filled_circle(map->img, ppx, ppy, color);
}

void	cant_draw_mini_map(t_map *map)
{
	ft_cleanup(map);
	printf("Error: Unable to load the minimap. Map size exceeds the limit🤏\n");
	exit(1);
}
void	draw_mini_map(t_map *map)
{
	uint32_t	color;
	int			x;
	int			y;
	int			px;
	int			py;

	y = -1;
	if(map->row > 100)
		cant_draw_mini_map(map);
	while (++y < (int)map->row)
	{
		x = -1;
		while (++x < (int)ft_strlen(map->cmap[y]))
		{
			if((int)ft_strlen(map->cmap[y])> 100)
				cant_draw_mini_map(map);
			px = MP_OFFSET_X + x * TILESIZE * MP_SCALE + x * MP_TILE_SPACE;
			py = MP_OFFSET_Y + y * TILESIZE * MP_SCALE + y * MP_TILE_SPACE;
			if (map->cmap[y][x] == '1')
				color = (0 << 24) | (0 << 16) | (0 << 8) | 255;
			else if (map->cmap[y][x] == '0' || map->cmap[y][x] == 'o'
				|| map->cmap[y][x] == map->player.direction)
				color = (176 << 24) | (159 << 16) | (149 << 8) | 255;
			else if (map->cmap[y][x] == 'D')
				color = 0x26F0D4;
			draw_tile_pixels(map->img, px, py, color);
		}
	}
	draw_mini_player(map);
}
