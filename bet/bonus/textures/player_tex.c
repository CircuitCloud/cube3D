/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 06:20:04 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/30 00:33:03 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	render_pov_tex(t_map *map, int screen_x, int screen_y)
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	uint32_t	c;

	y = 0;
	while (y < map->player_texture->height)
	{
		x = 0;
		while (x < map->player_texture->width)
		{
			c = map->player_sprite.frames[map->player_sprite.current_frame]
				->adr[y * map->player_texture->width + x];
			if (c >> 24 != 0x00)
			{
				dx = screen_x + x;
				dy = screen_y + y;
				if (dx >= 0 && dx < map->width && dy >= 0 && dy < map->height)
					((uint32_t *)map->img->pixels)[dy * map->width + dx] = c;
			}
			x++;
		}
		y++;
	}
}

void	render_pov(t_map *map)
{
	int	screen_x;
	int	screen_y;

	screen_x = (map->width / 2) - (map->player_sprite.frames
		[map->player_sprite.current_frame]->width / 2);
	screen_y = map->height / 1.5; 
	if (screen_x < 0)
		screen_x = 0;
	if (screen_y < 0)
		screen_y = 0;
	render_pov_tex(map, screen_x, screen_y);
}
