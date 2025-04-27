/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:18:47 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/28 00:47:58 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"



#include <math.h>  // for fmod and PI

// Define the rotation speed and the width/height constants
#define ROTATION_SPEED 0.001


void ft_hook_mouse(void *param)
{
    t_map *map;
    float delta_x;

    map = (t_map *)param;

    // Ensure the map is valid and the window is set
    if (!map || !map->mlx)
        return;

    // Hide the cursor and get its current position
    mlx_set_cursor_mode(map->mlx, MLX_MOUSE_HIDDEN);
    mlx_get_mouse_pos(map->mlx, &map->player.mouse_x, &map->player.mouse_y);

    // Calculate the change in the x-coordinate of the mouse (delta_x)
    delta_x = map->player.mouse_x - (WIDTH / 2);

    // Update the player's angle based on the mouse movement
    map->player.rot_angle += delta_x * ROTATION_SPEED;

    // Normalize the angle to keep it within [0, 2 * PI]
    map->player.rot_angle = fmod(map->player.rot_angle, 2 * M_PI);
    if (map->player.rot_angle < 0)
        map->player.rot_angle += 2 * M_PI;

    // Re-center the mouse at the window's center for continuous rotation
    mlx_set_mouse_pos(map->mlx, WIDTH / 2, HEIGHT / 2);
}



// void rotate_with_mouse(int x, int y, t_map *map)
// {
//     static int last_x = -1;
//     static int last_y = -1;
//     float angle_delta;
    
//     if (last_x == -1 && last_y == -1)  // First frame, initialize last_x, last_y
//     {
//         last_x = x;
//         last_y = y;
//         return;
//     }

//     // Calculate how much the mouse has moved in the X axis (horizontal movement)
//     angle_delta = (x - last_x) * 0.005;  // Sensitivity factor (0.005 is arbitrary)

//     // Update the player's angle (assuming player's angle is in radians)
//     map->player.rot_angle += angle_delta;

//     // Optionally, clamp the angle to keep it within bounds (optional)
//     if (map->player.rot_angle > 2 * M_PI)
//         map->player.rot_angle -= 2 * M_PI;
//     if (map->player.rot_angle < 0)
//         map->player.rot_angle += 2 * M_PI;

//     // Update last_x and last_y for the next frame
//     last_x = x;
//     last_y = y;
// }


// // Mouse event callback function
// int mouse_move(int x, int y, t_map *map)
// {
//     rotate_with_mouse(x, y, map);
//     return 0;  // No need to return anything
// }

// void game_loop(t_map *map)
// {
//     // Call the mouse movement callback function for the game loop
//     mlx_hook(map->mlx_window, 6, 0, mouse_move, map);

//     // Other game loop tasks (update game logic, render scene, etc.)
// }
