/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:16:47 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/12 08:29:29 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


// void	draw_circle(mlx_image_t *img, int cx, int cy, int radius, int color)
// {
//     int x, y;
//     double angle;
	
// 	angle = 0;
//     while (angle < 360)
//     {
//         x = cx + radius * cos(angle * M_PI / 180);
//         y = cy + radius * sin(angle * M_PI / 180);
// 		angle += 0.5;
//         mlx_put_pixel(img, x, y, color);
//     }
// }


// void	draw_filled_circle(mlx_image_t *img, int cx, int cy, int radius, int color)
// {
//     int x, y;
//     double angle;

//     int new_radius = radius * 1.9;
// 	y = -new_radius;
	
//     while ( y <= new_radius) 
//     {
// 		x = -new_radius;
//         while (x <= new_radius) 
//         {
//             if (x * x + y * y <= new_radius * new_radius) // Inside circle condition
//                 mlx_put_pixel(img, cx + x, cy + y, color);
// 				x++;
//         }
// 		y++;
//     }
// }

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

void    draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color)
{
    int dx;
    int dy;
    int sx;
    int sy;
    int err;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	err = dx - dy;
    while (1)
    {
        mlx_put_pixel(img, x0, y0, color);
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


// #include <math.h>  // For sin() and cos()
// #include "mlx.h"

// void	draw_circle(mlx_image_t *img, int cx, int cy, int radius, int color)
// {
//     double angle;
//     int x, y;

//     for (angle = 0; angle < 360; angle += 0.5) // Smaller step for smoothness
//     {
//         x = cx + radius * cos(angle * M_PI / 180);
//         y = cy + radius * sin(angle * M_PI / 180);
//         mlx_put_pixel(img, x, y, color);
//     }
// }


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
int	find_wall(t_map map, int x, int y)
{
	int grid_x;
	int grid_y;

	grid_x = x / TILESIZE;
	grid_y = y / TILESIZE;

	if (grid_x < 0 || grid_x >= ft_strlen(map.cmap[0]) || grid_y < 0 || grid_y >= map.row)
		return (0);
	if (map.cmap[grid_y][grid_x] == '1')
    	return (1);
	return (0);
}

void	draw_player(t_map map, mlx_image_t *img, int *px, int *py)
{

	int	rad;
	int	WIDTH = ((ft_strlen(map.cmap[0]) - 1) * TILESIZE);
	int HEIGHT = (map.row * TILESIZE);
	
	
	
	double	rot_angle;

	px = WIDTH  / 2;
	py = HEIGHT / 2;
	rad = 4;
	rot_angle = 45 * (M_PI / 180);
	draw_filled_circle(img, px, py, rad, 0xFF0000FF);
	draw_line(img, px, py, (px + (cos(rot_angle) * 50)),(py + (sin(rot_angle) * 50)) , 0xFF0000FF);
}

void	update_player_p(mlx_key_data_t key, void *param, int *rot_angle, t_map map, mlx_image_t *img)
{
	int	turn_direc;
	int	walk_direc;
	int	move_speed;
	double	rotation_speed = 2 * (M_PI /180);
	int	steeps;
	
	turn_direc = 0;
	walk_direc = 0;
	move_speed = 0;
	int	px;
	int	py;
	
	(void)param;

	if(key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		turn_direc = -1;
	if(key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		turn_direc = 1;
	if(key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		walk_direc = 1;
	if(key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		walk_direc = -1;
	steeps = walk_direc * move_speed;
	
	*rot_angle += turn_direc * rotation_speed;
	px += cos(*rot_angle) * steeps;
	py += sin(*rot_angle) * steeps;
	draw_player(map, img, &px, &py);

	// if(key.key == MLX_KEY_ESCAPE)
	// 	printf("lolp\n");
}
void	handle_key()
{

	exit(0);
}

int handle_key(mlx_key_data_t key, void *param)
{
    static int px = 400;  // Initial player position
    static int py = 300;  // Initial player position
    static double rot_angle = 0;  // Initial rotation angle
    t_map map = *((t_map*)param);
    mlx_t *mlx = mlx_get_data_addr(param); // Get mlx instance
    mlx_image_t *img = mlx_get_data_addr(mlx); // Get image pointer

    // Update player position and rotation based on key press
    update_player_p(key, param, &px, &py, &rot_angle, map);

    // Clear the screen and redraw everything
    mlx_clear_window(mlx, mlx_get_window(mlx));
    draw_player(map, img, px, py, rot_angle);

    mlx_image_to_window(mlx, img, 0, 0);  // Redraw image on window

    return (0);
}

int main(int ac, char **av)
{
	// mlx_t *win = mlx_init(500, 500, "Chaima", false);
	// mlx_image_t *img = mlx_new_image(win, 500, 500);
	// mlx_image_to_window(win, img, 0, 0);
	// mlx_loop(win);
	t_map	map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	map.mlx = mlx;
	
	if (ac == 2)
	{
		if (ft_strcmp(".cub", ft_strrchr(av[1], '.')))
			return (write(1, "**Invalid Map Name**\n", 21), 1);
		map = parse(av[1]);
	}
	else
	{
		write(1, "**PARAMETERS ERROR**\n", 21);
		return(1);
	}
	int x =0 ;
	int y = 0;
	int	px;
	int	py;
	int	WIDTH = ((ft_strlen(map.cmap[0]) - 1) * TILESIZE);
	int HEIGHT = (map.row * TILESIZE);
	mlx = mlx_init(WIDTH, HEIGHT, "9yob3d", 1);
	if (!mlx)
        return (printf("mlx\n"), 1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
        return (printf("img\n"), 1);
    // while (y < map.row)
    // {
	// 	x = 0;
    //     while (x < ft_strlen(map.cmap[0]) - 1)
    //     {
	// 		px = x * TILESIZE;
	// 		py = y * TILESIZE;
	// 		if(map.cmap[y][x] == '1')
    //         	draw_tile_pixels(img, px, py,  0x019137);
	// 		else if(map.cmap[y][x] == '0')
    //         	draw_tile_pixels(img, px, py, 0xFFB347);
	// 		else
	// 			// printf("%d\n", find_wall(map,  px,  py));
   	// 			draw_tile_pixels(img, px, py, 0xFF00FF);
	// 		x++;
    //     }
	// 	y++;
    // }
	// mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, handle_key, NULL);
	mlx_loop(mlx);
	return (0);
}
