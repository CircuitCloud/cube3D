/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:23:19 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/28 22:46:09 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw_mini_map(t_map *map)
{
	int x, y, px, py;
	int ppx, ppy;
	uint32_t color;
	int start_x = map->player.x - 5;
	int start_y = map->player.y - 5;
	int end_x = map->player.x + 5;
	int end_y = map->player.y + 5;
	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < ft_strlen(map->cmap[y]))
		{
			px = MINIMAP_OFFSET_X + x * TILESIZE * MINIMAP_SCALE + x * MINIMAP_TILE_SPACE;
			py = MINIMAP_OFFSET_Y + y * TILESIZE * MINIMAP_SCALE + y * MINIMAP_TILE_SPACE;
			if (map->cmap[y][x] == '1')
				color = 0xFFB347;
			else if (map->cmap[y][x] == '0')
				color = 0xFFFFFFFF;
			else
				color = 0x00000000;
			draw_tile_pixels(map->img, px, py, color);
			x++;
		}
		y++;
	}
	ppx = MINIMAP_OFFSET_X + map->player.move_x * MINIMAP_SCALE + map->player.x * MINIMAP_TILE_SPACE;
	ppy = MINIMAP_OFFSET_Y + map->player.move_y * MINIMAP_SCALE + map->player.y * MINIMAP_TILE_SPACE;
	draw_filled_circle(map->img, ppx, ppy , 0xFF0000FF);
}
