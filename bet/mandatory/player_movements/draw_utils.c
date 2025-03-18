/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:15:50 by ykamboua          #+#    #+#             */
/*   Updated: 2025/03/17 21:28:58 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"

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
				mlx_put_pixel(img, cx + x, cy + y, color);
			x++;
		}
		y++;
	}
}

// void    draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color)
// {
// 	int dx;
// 	int dy;
// 	int sx;
// 	int sy;
// 	int err;

// 	dx = abs(x1 - x0);
// 	dy = abs(y1 - y0);
// 	// i guess if y0 == y1 ===> sy = 0 same for x
// 	sx = (x0 < x1) ? 1 : -1;//is it 
// 	sy = (y0 < y1) ? 1 : -1;
// 	if (x0 == x1)
// 		sx = 0;
// 	if (y0 == y1)
// 		sy = 0;
// 	err = dx - dy;
// 	while (1)
//     {
// 		mlx_put_pixel(img, x0, y0, color);
// 		if (x0 == x1 && y0 == y1)
// 			break;
// 		int e2 = err * 2;
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			x0 += sx;
// 		}
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			y0 += sy;
// 		}
// 	}
// }

void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color)
{
    float dx = x1 - x0;
    float dy = y1 - y0;
    int steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    float x_inc = dx / steps;
    float y_inc = dy / steps;
    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; i++)
    {
        mlx_put_pixel(img, round(x), round(y), color);
        x += x_inc;
        y += y_inc;
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
			else if (map->cmap[y][x] == '0' || map->cmap[y][x] == map->cmap[map->player.y][map->player.x])
            	draw_tile_pixels(map->img, px, py, 0xFFB347);
			// commenteta hitax manhtajux n3adelula xi color u
			//zidt player mot3u ytlewn nhal 0
			// else
			// 	// printf("%d\n", find_wall(map,  px,  py));
   			// 	draw_tile_pixels(map->img, px, py, 0xFF00FF);
			x++;
        }
		y++;
    }
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}

