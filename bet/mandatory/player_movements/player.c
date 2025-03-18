/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:28:56 by ykamboua          #+#    #+#             */
/*   Updated: 2025/03/17 21:48:40 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"


void draw_player(t_map *map, mlx_image_t *img, int f)
{
    int rad = 4;
    int px;
    int py;

	// had l move.x u move y bax maybqaxi yjumpi ya3ni bihum t3aweto lmoves dyal player
	// m initializiyin fl main 
	
	px = map->player.move_x;
	py = map->player.move_y;

	// rot_angle initializitu fl main depending on wax N S W E
    double rot_angle = map->player.rot_angle;
    int line_x = px + (cos(rot_angle) * 30);
    int line_y = py + (sin(rot_angle) * 30);
    if (!map)
    {
        printf("Error: map is NULL\n");
        exit(1);
    }
    draw_filled_circle(img, px, py, rad, 0xFF0000FF);

	// commentet had line bax ntlaq bzf d rays fl main
	
    // draw_line(img, px, py, line_x, line_y, 0xFF0000FF);
}


void	handle_key(mlx_key_data_t key, t_map *map)
{
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
	if (!param)
		return;
	t_map *map = (t_map *)param;
	// draw_map(map);
	// draw_player(map, map->img, 1);
	
	double rotation_speed = 2 * (M_PI / 180);
	double move_speed = 1.5;
	double old_x = map->player.move_x;
	double old_y = map->player.move_y;

	// keeys
	handle_key(key, map);
	map->player.rot_angle += map->player.turn_direc * rotation_speed;
	double move_x = cos(map->player.rot_angle) * map->player.walk_direc * move_speed;
	double move_y = sin(map->player.rot_angle) * map->player.walk_direc * move_speed;

	double strafe_x = cos(map->player.rot_angle + M_PI_2) * map->player.strafe_direc * move_speed;
	double strafe_y = sin(map->player.rot_angle + M_PI_2) * map->player.strafe_direc * move_speed;

	double new_x = map->player.move_x + move_x + strafe_x;
	double new_y = map->player.move_y + move_y + strafe_y;
	////waalllls check(to add)-------&& find_wall(*map, (int)(new_x / TILESIZE), (int)(new_y / TILESIZE))&& !find_wall(*map, new_x, new_y)
    if (!find_wall(map, new_x, new_y))
    {
        map->player.move_x = new_x;
        map->player.move_y = new_y;
    }
    else
        printf("Out of bounds! X: %.2f, Y: %.2f\n", new_x, new_y);
	if (map->player.turn_direc || map->player.walk_direc || map->player.strafe_direc)
	{
		mlx_delete_image(map->mlx, map->img);
		map->img = mlx_new_image(map->mlx, map->width, map->height);
		draw_map(map);
		draw_player(map, map->img, 1);
		set_rays_angle(map);
	}
}

