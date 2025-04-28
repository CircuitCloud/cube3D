/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:23:19 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/28 16:11:16 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


#define MINIMAP_OFFSET_X 20
#define MINIMAP_OFFSET_Y 100

void draw_minimap_border(t_map *map)
{
    int width = map->row * (TILESIZE * MINIMAP_SCALE + MINIMAP_TILE_SPACE);
    int height = map->row * (TILESIZE * MINIMAP_SCALE + MINIMAP_TILE_SPACE);
    draw_rectangle(map,  MINIMAP_OFFSET_X - 5,  MINIMAP_OFFSET_Y - 5, width + 270, height + 10, 0xCCCCCCFF); 
}

// void draw_mini_map(t_map *map)
// {
//     int x, y;
//     int start_x, start_y, end_x, end_y;
//     int px, py;
//     int ppx, ppy;
//     uint32_t color;

//     int map->player.x = map->player.x;
//     int player_tile_y = map->player.y;

//     // Define the area around the player
//     start_x = player_tile_x - 5;
//     start_y = player_tile_y - 5;
//     end_x = player_tile_x + 5;
//     end_y = player_tile_y + 5;

//     y = start_y;
//     while (y <= end_y)
//     {
//         x = start_x;
//         while (x <= end_x)
//         {
//             if (y >= 0 && y < map->row && x >= 0 && x < ft_strlen(map->cmap[y])) // check if inside map
//             {
//                 px = (x - start_x) * TILESIZE * MINIMAP_SCALE + (x - start_x) * MINIMAP_TILE_SPACE;
//                 py = (y - start_y) * TILESIZE * MINIMAP_SCALE + (y - start_y) * MINIMAP_TILE_SPACE;

//                 if (map->cmap[y][x] == '1')
//                     color = 0xFFB347; // wall
//                 else if (map->cmap[y][x] == '0')
//                     color = 0xFFFFFFFF; // floor
//                 else
//                     color = 0x00000000; // nothing

//                 draw_tile_pixels(map->img, px, py, color);
//             }
//             x++;
//         }
//         y++;
//     }

//     //     ppx = MINIMAP_OFFSET_X + map->player.move_x * MINIMAP_SCALE + map->player.x * MINIMAP_TILE_SPACE;
// //     ppy = MINIMAP_OFFSET_Y + map->player.move_y * MINIMAP_SCALE + map->player.y * MINIMAP_TILE_SPACE;
// //     draw_filled_circle(map->img, ppx, ppy , 4, 0xFF0000FF);
//     // Draw the player in the center
//     ppx = (5 * (TILESIZE * MINIMAP_SCALE + MINIMAP_TILE_SPACE)) + (TILESIZE * MINIMAP_SCALE) / 2 ;
//     ppy = (5 * (TILESIZE * MINIMAP_SCALE + MINIMAP_TILE_SPACE)) + (TILESIZE * MINIMAP_SCALE) / 2 ;
//     draw_filled_circle(map->img, ppx, ppy, 4, 0xFF0000FF);
// }


void draw_mini_map(t_map *map)
{
    int x, y, px, py;
    int ppx, ppy;
    uint32_t color;

    int start_x = map->player.x - 5;
    int start_y = map->player.y - 5;
    int end_x = map->player.x + 5;
    int end_y = map->player.y + 5;


    y = 0;
    while (y < map->row)
    {
        x = 0;
        while (x < ft_strlen(map->cmap[y]))
        {
            px = MINIMAP_OFFSET_X + x * TILESIZE * MINIMAP_SCALE + x * MINIMAP_TILE_SPACE;
            py = MINIMAP_OFFSET_Y + y * TILESIZE * MINIMAP_SCALE + y * MINIMAP_TILE_SPACE;
            if (map->cmap[y][x] == '1')
                color = 0xFFB347;
            else if (map->cmap[y][x] == '0')
                color = 0xFFFFFFFF;
            else
                color = 0x00000000;
            draw_tile_pixels(map->img, px, py, color);
            x++;
        }
        y++;
    }

    ppx = MINIMAP_OFFSET_X + map->player.move_x * MINIMAP_SCALE + map->player.x * MINIMAP_TILE_SPACE;
    ppy = MINIMAP_OFFSET_Y + map->player.move_y * MINIMAP_SCALE + map->player.y * MINIMAP_TILE_SPACE;
    draw_filled_circle(map->img, ppx, ppy , 0xFF0000FF);
}
