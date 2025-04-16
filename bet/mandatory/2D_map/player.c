/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:28:56 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/17 00:40:47 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"

// void draw_player(t_map *map, mlx_image_t *img)
// {
//     int	rad = 4;
//     int px;
//     int py;
// 	double rot_angle;
// 	int line_x;
// 	int line_y;

// 	if (!map || !img)
// 	{
// 		fprintf(stderr, "Error: NULL pointer in draw_player\n");
// 		return; // or exit(1);
// 	}


// 	px = map->player.move_x;
// 	py = map->player.move_y;
//     rot_angle = map->player.rot_angle;
//     line_x= px + (cos(rot_angle) * 30);
//     line_y = py + (sin(rot_angle) * 30);
//     if (!map)
//     {
//         printf("Error: map is NULL\n");
//         exit(1);
//     }
//     draw_filled_circle(img, px, py, rad, 0xFF0000FF);
// }

void	handle_key(mlx_key_data_t key, t_map *map)
{
	if (!map || !map->mlx)
    	return;
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
	else if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->player.walk_direc = 1;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->player.walk_direc = -1;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		map->player.strafe_direc = -1;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		map->player.strafe_direc = 1;
    if (mlx_is_key_down(map->mlx, MLX_KEY_E))
		return(ft_cleanup(map), exit(0));
}

int	find_wall(t_map *map, double x, double y)
{
	int	grid_x;
	int	grid_y;

	if (map->cmap[(int)((y - PLAYER_RADIUS) / TILESIZE)][(int)(x / TILESIZE)] == '1' ||
		map->cmap[(int)((y + PLAYER_RADIUS) / TILESIZE)][(int)(x / TILESIZE)] == '1' ||
		map->cmap[(int)(y / TILESIZE)][(int)((x - PLAYER_RADIUS) / TILESIZE)] == '1' ||
		map->cmap[(int)(y / TILESIZE)][(int)((x + PLAYER_RADIUS) / TILESIZE)] == '1')
		return (1);
	return (0);
}

void update_player_p(mlx_key_data_t key, void *param)
{
	t_map	*map;
	double	rotation_speed;
	double	move_speed;
	double	move_x;
	double	move_y;
	double	strafe_x;
	double	strafe_y;
	double	new_x;
	double	new_y;

	if (!param)
		return(printf("Error: invalid map parameter\n"), exit(1));
	map = (t_map *)param;
	if (!map || !map->mlx)
		return(printf("Error: invalid map parameter\n"), exit(1));
	rotation_speed = 2 * (M_PI / 180);
	move_speed = 4;
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
        printf("🧟 Collision detected! Player can't move to new position❌\n");
	if (map->player.turn_direc || map->player.walk_direc || map->player.strafe_direc)
	{
		if (map->img)
			mlx_delete_image(map->mlx, map->img);
		map->img = mlx_new_image(map->mlx, map->width, map->height);
		if (!map->img)
		{
			free_textures(map);
			//free_rays
            printf("Error: Failed to create new image.\n");
            exit(1);
        }
		mlx_image_to_window(map->mlx, map->img, 0, 0);
		set_rays_angle(map);
	}
}
