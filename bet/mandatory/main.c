/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:16:47 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/12 14:29:03 by ykamboua         ###   ########.fr       */
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
	sx = (x0 < x1) ? 1 : -1;//is it 
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
	{
		// printf("walldetected at grid (%d, %d) ::::pos (%d, %d)\n", grid_x, grid_y, x, y);
    	return (1);
	}
	return (0);
}


void draw_player(t_map *map, mlx_image_t *img)
{
	if (!map)
	{
		fprintf(stderr, "Error: map is NULL\n");
		exit(EXIT_FAILURE);
	}

	int rad = 4;
	int px = (map->player.y * TILESIZE) + (TILESIZE / 2);
	int py = (map->player.x * TILESIZE) + (TILESIZE / 2);

	draw_filled_circle(img, px, py, rad, 0xFF0000FF);

	double rot_angle = map->player.rot_angle;
	int line_x = px + (cos(rot_angle) * 30);
	int line_y = py + (sin(rot_angle) * 30);
	draw_line(img, px, py, line_x, line_y, 0xFF0000FF);
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
			if(map->cmap[y][x] == '1')
			{
				//  printf("drawing wall at (%d, %d)\n", px, py);
            	draw_tile_pixels(map->img, px, py,  0x019137);
			}
			else if(map->cmap[y][x] == '0')
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

void clear_player(t_map *map, mlx_image_t *img)
{
	draw_filled_circle(img, map->player.x, map->player.y, 4, 0x000000FF);
}


void update_player_p(mlx_key_data_t key, void *param)
{
	if (!param)
		return;
	t_map *map = (t_map *)param;
	draw_map(map);
	draw_player(map, map->img);
	double rotation_speed = 2 * (M_PI / 180);
	double move_speed = 1.5;

	double old_x = map->player.x;
	double old_y = map->player.y;

	if (key.action == MLX_PRESS)
	{
		if (key.key == MLX_KEY_LEFT)
			map->player.turn_direc = -1;
		else if (key.key == MLX_KEY_RIGHT)
			map->player.turn_direc = 1;
		else if (key.key == MLX_KEY_W)
			map->player.walk_direc = 1;
		else if (key.key == MLX_KEY_S)
			map->player.walk_direc = -1;
		else if (key.key == MLX_KEY_A)
			map->player.strafe_direc = -1;
		else if (key.key == MLX_KEY_D)
			map->player.strafe_direc = 1;
	}
	else if (key.action == MLX_RELEASE)
	{
		if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT)
			map->player.turn_direc = 0;
		if (key.key == MLX_KEY_W || key.key == MLX_KEY_S)
			map->player.walk_direc = 0;
		if (key.key == MLX_KEY_A || key.key == MLX_KEY_D)
			map->player.strafe_direc = 0;
	}

	map->player.rot_angle += map->player.turn_direc * rotation_speed;

	double move_x = cos(map->player.rot_angle) * map->player.walk_direc * move_speed;
	double move_y = sin(map->player.rot_angle) * map->player.walk_direc * move_speed;

	double strafe_x = cos(map->player.rot_angle + M_PI_2) * map->player.strafe_direc * move_speed;
	double strafe_y = sin(map->player.rot_angle + M_PI_2) * map->player.strafe_direc * move_speed;
	double new_x = map->player.x + move_x + strafe_x;
	double new_y = map->player.y + move_y + strafe_y;
	////waalllls check(to add)-------&& find_wall(*map, (int)(new_x / TILESIZE), (int)(new_y / TILESIZE))
	if (new_x >= 0 && new_x < map->width && new_y >= 0 && new_y < map->height )
	{
		map->player.x = new_x;
		map->player.y = new_y;
	}
	else
	{
		printf("outof bounds! X: %.2f, Y: %.2f\n", new_x, new_y);
	}

	mlx_delete_image(map->mlx, map->img);

	map->img = mlx_new_image(map->mlx, map->width, map->height);

	draw_map(map);
	
	draw_player(map, map->img);
	
}



void	handle_key()
{
	exit(0);
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
	printf("%d\n", map.player.x);
	printf("%d\n", map.player.y);
	int x =0 ;
	int y = 0;
	int	width = ((ft_strlen(map.cmap[0]) - 1) * TILESIZE);
	int height = (map.row * TILESIZE);
	map.width =width;
	map.height = height;

	mlx = mlx_init(width, height, "9yob3d", 1);
	if (!mlx)
        return (printf("mlx\n"), 1);
	img = mlx_new_image(mlx, width, height);
	if (!img)
        return (printf("img\n"), 1);
	map.mlx = mlx;
	map.img = img;
	
	draw_map(&map);
	draw_player(&map, img);
	mlx_key_hook(mlx, update_player_p, &map);
	mlx_loop(mlx);
	return (0);
}

