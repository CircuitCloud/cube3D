/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:15:50 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/30 00:30:53 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	draw_filled_circle(mlx_image_t *img, int cx, int cy, int color)
{
	int	x;
	int	y;
	int	radius;

	radius = 4;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius) 
		{
			if (x * x + y * y <= radius * radius)
				mlx_put_pixel(img, cx + x, cy + y, color);
			x++;
		}
		y++;
	}
}

void	draw_tile_pixels(mlx_image_t *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < TILESIZE * MP_SCALE)
	{
		j = 0;
		while (j < TILESIZE * MP_SCALE)
		{
			mlx_put_pixel(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
