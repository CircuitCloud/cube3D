/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:15:50 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/15 17:01:29 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"

void	draw_filled_circle(mlx_image_t *img, int cx, int cy, int radius, int color)
{
	int x;
	int y;

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
    float dx;
    float dy;
    int steps;
    float x_inc;
    float y_inc;
    float x;
    float y;
	int	i;

	dx = x1 - x0;
	dy = y1 - y0;
	steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	x  = x0;
	y = y0;
	i = 0;
    while (i <= steps)
    {
        mlx_put_pixel(img, round(x), round(y), color);
        x += x_inc;
        y += y_inc;
		i++;
    }
}

void	draw_tile_pixels(mlx_image_t *img, int x, int y, int color)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < MINIMAP_TILE - 1)
	{
		j = 0;
		while (j < MINIMAP_TILE - 1)
		{
			mlx_put_pixel(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_map *map)
{
	int x;
	int	y;
	int px;
	int	py;
	int ppx;
	int ppy;
	int ray_length;
	double ray_x;
	double ray_y;
	uint32_t color;

	y = 0;
	x = 0;
	while (y < (int)map->row)
	{
		x  = 0;
		while (x < (int)ft_strlen(map->cmap[y]) - 1)
		{
			px = x * MINIMAP_TILE;
			py = y * MINIMAP_TILE;
			if (map->cmap[y][x] == '1')
				color = 0xFFB347;
			else if (map->cmap[y][x] == '0')
				color = 0xBBBBBBFF;
			else
				color = 0x00000000;
			draw_tile_pixels(map->img, px, py, color);
			x++;
		}
		y++;
	}
	ppx = map->player.move_x * MINIMAP_SCALE;
	ppy = map->player.move_y * MINIMAP_SCALE;
	// draw_tile_pixels(map->img, ppx - 2, ppy - 2, 0xFF0000FF); // red dot
	draw_filled_circle(map->img, ppx - 2, ppy - 2, 4 ,0xFF0000FF);
	ray_length = MINIMAP_TILE;
	ray_x = ppx + cos(map->player.rot_angle) * ray_length;
	ray_y = ppy + sin(map->player.rot_angle) * ray_length;
	draw_line(map->img, ppx, ppy, ray_x, ray_y, 0xFF0000FF); // green ray
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = 0;
	y = 0;
	while (y < (int)map->row)
    {
		x = 0;
        while (x < (int)ft_strlen(map->cmap[y]) - 1)
        {
			px = x * TILESIZE;
			py = y * TILESIZE;
			if (map && y < (int)map->row && map->cmap[y] && map->cmap[y][x] == '1')
			{
				//  printf("drawing wall at (%d, %d)\n", px, py);
            	// draw_tile_pixels(map->img, px, py, 0xFFFFFFFF);
			}
			else if (map->cmap[y][x] == '0' || map->cmap[y][x] == map->cmap[map->player.y][map->player.x])
            	// draw_tile_pixels(map->img, px, py, 0xFFB347);
			// commenteta hitax manhtajux n3adelula xi color u
			//zidt player mot3u ytlewn nhal 0
			// else
			// 	// printf("%d\n", find_wall(map,  px,  py));
   			// 	draw_tile_pixels(map->img, px, py, 0xFF00FF);
			x++;
        }
		y++;
    }
	// mlx_image_to_window(map->mlx, map->img, 0, 0);
}

