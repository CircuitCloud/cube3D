/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:23:19 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/28 23:21:12 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_mini_player(t_map *map)
{
	int	ppx;
	int	ppy;

	ppx = MP_OFFSET_X + map->player.move_x 
		* MP_SCALE + map->player.x * MP_TILE_SPACE;
	ppy = MP_OFFSET_Y + map->player.move_y 
		* MP_SCALE + map->player.y * MP_TILE_SPACE;
	draw_filled_circle(map->img, ppx, ppy, 0xFF0000FF);
}

void	draw_mini_map(t_map *map)
{
	uint32_t	color;
	int			x;
	int			y;
	int			px;
	int			py;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < ft_strlen(map->cmap[y]))
		{
			px = MP_OFFSET_X + x * TILESIZE * MP_SCALE + x * MP_TILE_SPACE;
			py = MP_OFFSET_Y + y * TILESIZE * MP_SCALE + y * MP_TILE_SPACE;
			if (map->cmap[y][x] == '1')
				color = 0xFFB347;
			else if (map->cmap[y][x] == '0')
				color = 0xFFFFFFFF;
			draw_tile_pixels(map->img, px, py, color);
			x++;
		}
		y++;
	}
	draw_mini_player(map);
}
