/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:25:58 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/30 00:32:35 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	update_movements(t_map *map)
{
	double	move_x;
	double	move_y;
	double	strafe_x;
	double	strafe_y;

	map->player.rot_angle += map->player.turn_direc * ROTATION_SPEED;
	if (map->player.rot_angle < 0)
		map->player.rot_angle += 2 * M_PI;
	if (map->player.rot_angle > 2 * M_PI)
		map->player.rot_angle -= 2 * M_PI;
	move_x = cos(map->player.rot_angle) * map->player.walk_direc * MOVE_SPEED;
	move_y = sin(map->player.rot_angle) * map->player.walk_direc * MOVE_SPEED;
	strafe_x = cos(map->player.rot_angle + M_PI_2) 
		* map->player.strafe_direc * MOVE_SPEED;
	strafe_y = sin(map->player.rot_angle + M_PI_2) 
		* map->player.strafe_direc * MOVE_SPEED;
	map->new_x = map->player.move_x + move_x + strafe_x;
	map->new_y = map->player.move_y + move_y + strafe_y;
	if (!find_wall(map, map->new_x, map->new_y))
	{
		map->player.move_x = map->new_x;
		map->player.move_y = map->new_y;
	}
}

void	redraw_map(t_map *map)
{
	static double	old_x;
	static double	old_y;
	static double	old_angle;

	old_x = 0;
	old_y = 0;
	old_angle = 0;
	if (map->player.move_x != old_x || map->player.move_y != old_y 
		|| map->player.rot_angle != old_angle)
	{
		old_x = map->player.move_x;
		old_y = map->player.move_y;
		old_angle = map->player.rot_angle;
		if (map->img)
			mlx_delete_image(map->mlx, map->img);
		map->img = mlx_new_image(map->mlx, map->width, map->height);
		if (!map->img)
		{
			ft_cleanup(map);
			exit(1);
		}
		set_rays_angle(map);
		draw_mini_map(map);
		mlx_image_to_window(map->mlx, map->img, 0, 0);
	}
}

void	update_player_loop(void *param)
{
	t_map	*map;

	if (!param)
		return ;
	map = (t_map *)param;
	handle_key(map);
	update_movements(map);
	redraw_map(map);
}
