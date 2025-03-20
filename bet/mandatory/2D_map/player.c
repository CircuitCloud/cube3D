/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:28:56 by ykamboua          #+#    #+#             */
/*   Updated: 2025/03/20 02:44:46 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"


void draw_player(t_map *map, mlx_image_t *img)
{
    int rad = 4;
    int px;
    int py;
	double rot_angle;
	int line_x;
	int line_y;

	px = map->player.move_x;
	py = map->player.move_y;
    rot_angle = map->player.rot_angle;
    line_x= px + (cos(rot_angle) * 30);
    line_y = py + (sin(rot_angle) * 30);
    if (!map)
    {
        printf("Error: map is NULL\n");
        exit(1);
    }
    draw_filled_circle(img, px, py, rad, 0xFF0000FF);
}

void	handle_key(mlx_key_data_t key, t_map *map)
{
	map->player.turn_direc = 0;
	map->player.walk_direc = 0;
	map->player.strafe_direc = 0;
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->player.turn_direc = -1;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->player.turn_direc = 1;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_W))
		map->player.walk_direc = 1;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		map->player.walk_direc = -1;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		map->player.strafe_direc = -1;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		map->player.strafe_direc = 1;
}

void update_player_p(mlx_key_data_t key, void *param)
{
	t_map *map;
	double rotation_speed;
	double move_speed;
	double old_x;
	double old_y;
	double move_x;
	double move_y;
	double strafe_x;
	double strafe_y;
	double new_x;
	double new_y;

	if (!param)
		return;
	map = (t_map *)param;
	rotation_speed = 2 * (M_PI / 180);
	move_speed = 1.5;
	old_x = map->player.move_x;
	old_y = map->player.move_y;
	handle_key(key, map);
	map->player.rot_angle += map->player.turn_direc * rotation_speed;
	move_x = cos(map->player.rot_angle) * map->player.walk_direc * move_speed;
	move_y = sin(map->player.rot_angle) * map->player.walk_direc * move_speed;
	strafe_x = cos(map->player.rot_angle + M_PI_2) * map->player.strafe_direc * move_speed;
	strafe_y = sin(map->player.rot_angle + M_PI_2) * map->player.strafe_direc * move_speed;
	new_x = map->player.move_x + move_x + strafe_x;
	new_y = map->player.move_y + move_y + strafe_y;
    if (!find_wall(map, new_x, new_y))
    {
        map->player.move_x = new_x;
        map->player.move_y = new_y;
    }
    else
        printf("LAAAAAA3dAAAAAASS\n");
	if (map->player.turn_direc || map->player.walk_direc || map->player.strafe_direc)
	{
		mlx_delete_image(map->mlx, map->img);
		map->img = mlx_new_image(map->mlx, map->width, map->height);
		draw_map(map);
		draw_player(map, map->img);
		set_rays_angle(map);
	}
}

