/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:15:50 by ykamboua          #+#    #+#             */
/*   Updated: 2025/03/15 10:41:37 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

void	draw_filled_circle(mlx_image_t *img, int cx, int cy, int radius, int color)
{
	int x;
	int y;
	double angle;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius) 
		{
			if (x * x + y * y <= radius * radius)
				mlx_put_pixel(img, cy + y, cx + x, color);
			x++;
		}
		y++;
	}
}

void    draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = (x0 < x1) ? 1 : -1;//is it 
	sy = (y0 < y1) ? 1 : -1;
	err = dx - dy;
	while (1)
    {
		mlx_put_pixel(img, y0, x0, color);
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = err * 2;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_tile_pixels(mlx_image_t *img, int x, int y, int color)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;

	while (i < TILESIZE - 1)
	{
		j = 0;
		while (j < TILESIZE - 1)
		{
			mlx_put_pixel(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = 0;
	y = 0;
	while (y < map->row)
    {
		x = 0;
		// printf("%d\n", map.player.x);
		// printf("%d\n", map.player.y);
        while (x < ft_strlen(map->cmap[0]) - 1)
        {
			px = x * TILESIZE;
			py = y * TILESIZE;
			if (map->cmap[y][x] == '1')
			{
				//  printf("drawing wall at (%d, %d)\n", px, py);
            	draw_tile_pixels(map->img, px, py, 0xFFFFFFFF);
			}
			else if (map->cmap[y][x] == '0')
            	draw_tile_pixels(map->img, px, py, 0xFFB347);
			else
				// printf("%d\n", find_wall(map,  px,  py));
   				draw_tile_pixels(map->img, px, py, 0xFF00FF);
			x++;
        }
		y++;
    }
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}

