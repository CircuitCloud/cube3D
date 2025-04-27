/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:38:44 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/28 00:12:34 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


#include <sys/time.h> 

long get_current_time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void animate_sprite(void *param)
{
    t_map *map;
    static long last_frame_time = 0;
    long current_time;

    map = (t_map *)param;
    current_time = get_current_time_ms();
    if (current_time - last_frame_time >= map->player_sprite.frame_speed)
    {
        last_frame_time = current_time;
        map->player_sprite.current_frame = (map->player_sprite.current_frame + 1) % 4;
    }
}

void load_sprite_frames(t_map *map)
{
    int i;

    i = 0;
    char *paths[4] = 
    {
        "textures/tile0-removebg-preview.png",
        "textures/tile1-removebg-preview.png",
        "textures/tile2-removebg-preview.png",
        "textures/tile3-removebg-preview.png"
    };

    map->player_sprite.frames = malloc(sizeof(t_texture *) * 4);
    if (!map->player_sprite.frames)
    {
        printf("allocation error\n");
        exit(1);
    }
    while (i < 4)
    {
        map->player_sprite.frames[i] = load_texture(paths[i]);
        i++;
    }

    map->player_sprite.current_frame = 0;
    map->player_sprite.frame_speed = 100;  // Adjust animation speed (in ms)
    map->player_sprite.x = (map->width / 2) - (map->player_texture->width / 2);  // Center sprite
    map->player_sprite.y = map->height / 1.5;  // Place sprite lower in the window
}












