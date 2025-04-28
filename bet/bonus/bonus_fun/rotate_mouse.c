/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:18:47 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/28 22:45:36 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_hook_mouse(void *param)
{
	t_map	*map;
	double	delta_x;

	map = (t_map *)param;
	if (!map || !map->mlx)
		return ;
	mlx_set_cursor_mode(map->mlx, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(map->mlx, &map->player.mouse_x, &map->player.mouse_y);
	delta_x = map->player.mouse_x - (WIDTH / 2);
	map->player.rot_angle += delta_x * ROTATION_SPEED;
	map->player.rot_angle = fmod(map->player.rot_angle, 2 * M_PI);
	if (map->player.rot_angle < 0)
		map->player.rot_angle += 2 * M_PI;
	mlx_set_mouse_pos(map->mlx, WIDTH / 2, HEIGHT / 2);
}
