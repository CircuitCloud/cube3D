/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:15:50 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/15 23:02:52 by ykamboua         ###   ########.fr       */
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

void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color)
{
    float	dx;
    float	dy;
    int		steps;
    float	x_inc;
    float	y_inc;
    float	x;
    float	y;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	x = x0;
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

// void	draw_map(t_map *map)
// {
// 	int	x;
// 	int	y;
// 	int	px;
// 	int	py;

// 	x = 0;
// 	y = 0;
// 	while (y < (int)map->row)
//     {
// 		x = 0;
//         while (x < (int)ft_strlen(map->cmap[y]) - 1)
//         {
// 			px = x * TILESIZE;
// 			py = y * TILESIZE;
// 			if (map && y < (int)map->row && map->cmap[y] && map->cmap[y][x] == '1')
// 			{
// 				//  printf("drawing wall at (%d, %d)\n", px, py);
//             	// draw_tile_pixels(map->img, px, py, 0xFFFFFFFF);
// 			}
// 			else if (map->cmap[y][x] == '0' || map->cmap[y][x] == map->cmap[map->player.y][map->player.x])
//             	// draw_tile_pixels(map->img, px, py, 0xFFB347);
// 			// commenteta hitax manhtajux n3adelula xi color u
// 			//zidt player mot3u ytlewn nhal 0
// 			// else
// 			// 	// printf("%d\n", find_wall(map,  px,  py));
//    			// 	draw_tile_pixels(map->img, px, py, 0xFF00FF);
// 			x++;
//         }
// 		y++;
//     }
// 	mlx_image_to_window(map->mlx, map->img, 0, 0);
// }

