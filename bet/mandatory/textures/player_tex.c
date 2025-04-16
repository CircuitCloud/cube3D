/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 06:20:04 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/17 00:02:34 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	render_pov_tex(t_map *map, int screen_x, int screen_y)
{
	int			x;
	int			y;
	int			draw_x;
	int			draw_y;
	uint32_t	color;

	x = 0;
	y = 0;
	while (y < map->player_texture->height)
	{
		x = 0;
		while (x < map->player_texture->width)
		{
			color = map->player_texture->adr[y * map->player_texture->width + x];
			if (color >> 24 != 0x00)
			{
				draw_x = screen_x + x;
				draw_y = screen_y + y;
				if (draw_x >= 0 && draw_x < map->width && draw_y >= 0 && draw_y < map->height)
					((uint32_t *)map->img->pixels)[draw_y * map->width + draw_x] = color;
			}
			x++;
		}
		y++;
	}
}

void	render_pov(t_map *map)
{
	int			screen_x;
	int			screen_y;

	if (!map || !map->img)
		return(printf("Error: NULL pointer in render_gun\n"), exit(1));
	screen_x = (map->width / 2) - (map->player_texture->width / 2);
	screen_y = map->height / 1.5; 
	if (screen_x < 0)
		screen_x = 0;
	if (screen_y < 0)
		screen_y = 0;
	render_pov_tex(map, screen_x, screen_y);
}
