/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:38:44 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/26 09:41:21 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void load_sprite_frames(t_map *map)
{
	int	i;

	i = 0;
	char *paths[4] = 
	{
		"textures/frame0.png",
		"textures/frame1.png",
		"textures/frame2.png",
		"textures/frame3.png"
	};
	map->player_sprite.frames = malloc(sizeof(t_texture *) * 4);
	if (!map->player_sprite.frames)
	{
		printf("alloocatiooon d sppprite frames\n");
		// freee
		exit(1);
	}
	while (i < 4)
	{
		map->player_sprite.frames[i] = load_texture(paths[i]);
		i++;
	}
	map->player_sprite.current_frame = 0;
	map->player_sprite.last_frame_time = 0;
}

void update_player_loop(void *param)
{
	t_map *map;
	double current_time;

	map = (t_map *)param;
	current_time = mlx_get_time();
	if (current_time - map->player_sprite.last_frame_time > 0.2)
	{
		map->player_sprite.current_frame++;
		if (map->player_sprite.current_frame >= 4)
			map->player_sprite.current_frame = 0;
		map->player_sprite.last_frame_time = current_time;
	}
	handle_key(map);
	render_pov(map);
}
