/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:28:56 by ykamboua          #+#    #+#             */
/*   Updated: 2025/03/15 10:40:20 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"


void draw_player(t_map *map, mlx_image_t *img, int f)
{
    int rad = 4;
	
    int px = map->player.x ;
    int py = map->player.y ;

    double rot_angle = map->player.rot_angle;
    int line_x = px + (cos(rot_angle) * 30);
    int line_y = py + (sin(rot_angle) * 30);

    if (!map)
    {
        printf("Error: map is NULL\n");
        exit(1);
    }
    draw_filled_circle(img, px, py, rad, 0xFF0000FF);
    draw_line(img, px, py, line_x, line_y, 0xFF0000FF);
}


void	handle_key(mlx_key_data_t key, t_map *map)
{
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
		else if (key.key == MLX_KEY_W || key.key == MLX_KEY_S)
			map->player.walk_direc = 0;
		else if (key.key == MLX_KEY_A || key.key == MLX_KEY_D)
			map->player.strafe_direc = 0;
	}
}



void update_player_p(mlx_key_data_t key, void *param)
{
	if (!param)
		return;
	t_map *map = (t_map *)param;
	// draw_map(map);
	// draw_player(map, map->img, 1);

	double rotation_speed = 2 * (M_PI / 180);
	double move_speed = 1.5;
	double old_x = map->player.x;
	double old_y = map->player.y;

	// keeys
	handle_key(key, map);
	map->player.rot_angle += map->player.turn_direc * rotation_speed;
	double move_x = cos(map->player.rot_angle) * map->player.walk_direc * move_speed;
	double move_y = sin(map->player.rot_angle) * map->player.walk_direc * move_speed;

	double strafe_x = cos(map->player.rot_angle + M_PI_2) * map->player.strafe_direc * move_speed;
	double strafe_y = sin(map->player.rot_angle + M_PI_2) * map->player.strafe_direc * move_speed;

	double new_x = map->player.x + move_x + strafe_x;
	double new_y = map->player.y + move_y + strafe_y;
	////waalllls check(to add)-------&& find_wall(*map, (int)(new_x / TILESIZE), (int)(new_y / TILESIZE))&& !find_wall(*map, new_x, new_y)
    if (new_x >= 0 && new_x < map->width * TILESIZE && new_y >= 0 && new_y < map->height * TILESIZE )
    {
        map->player.x = new_x;
        map->player.y = new_y;
    }
    else
    {
        printf("Out of bounds! X: %.2f, Y: %.2f\n", new_x, new_y);
    }
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	draw_map(map);
	draw_player(map, map->img, 1);
}

