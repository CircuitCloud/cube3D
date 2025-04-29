/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:15:50 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/29 12:29:24 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"

void	draw_filled_circle(mlx_image_t *img, int cx, int cy, int color)
{
	int x;
	int y;
 	int radius;

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
	while (i < TILESIZE * MP_SCALE) //MINIMAP_SCALE undeclared
	{
		j = 0;
		while (j < TILESIZE * MP_SCALE) // MINIMAP_SCALE undeclared
		{
			mlx_put_pixel(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
