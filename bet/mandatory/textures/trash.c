
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



// void	handle_key(t_map *map, int *move_x, int *move_y)
// {
// 	double	move_speed = 4;
// 	double	rotation_speed = 2 * (M_PI / 180);
	
// 	if (!map || !map->mlx)
// 		return;

// 	map->player.turn_direc = 0;
// 	map->player.walk_direc = 0;
// 	map->player.strafe_direc = 0;

// 	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
// 	{
// 		map->player.rot_angle -= rotation_speed;
// 		// map->player.turn_direc = -1;
// 	}
// 	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
// 	{
// 		map->player.rot_angle += rotation_speed;
// 		// map->player.turn_direc = 1;
// 	}
// 	if (mlx_is_key_down(map->mlx, MLX_KEY_W) || mlx_is_key_down(map->mlx, MLX_KEY_UP))
// 	{
// 		(*move_x) += cos(map->player.rot_angle) * move_speed;
// 		(*move_y) += sin(map->player.rot_angle) * move_speed;
// 		// map->player.walk_direc = 1;
// 	}
// 	else if (mlx_is_key_down(map->mlx, MLX_KEY_S) || mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
// 	{
// 		(*move_x) -= cos(map->player.rot_angle) * move_speed;
// 		(*move_y) -= sin(map->player.rot_angle) * move_speed;
// 		// map->player.walk_direc = 1;
// 	}
// 	else if (mlx_is_key_down(map->mlx, MLX_KEY_A))
// 	{
// 		(*move_x) -= cos(map->player.rot_angle + M_PI_2) * move_speed;
// 		(*move_y) -= sin(map->player.rot_angle + M_PI_2) * move_speed;
// 		// map->player.strafe_direc = -1;
// 	}
// 	else if (mlx_is_key_down(map->mlx, MLX_KEY_D))
// 	{
// 		(*move_x) += cos(map->player.rot_angle + M_PI_2) * move_speed;
// 		(*move_y) += sin(map->player.rot_angle + M_PI_2) * move_speed;
// 		// map->player.strafe_direc = 1;
// 	}

// 	if (mlx_is_key_down(map->mlx, MLX_KEY_E))
// 		ft_cleanup(map), exit(0);
// }




// int find_wall(t_map *map, double x, double y)
// {
// 	int grid_x;
// 	int grid_y;

// 	grid_y = (int)(y / TILESIZE);
// 	grid_x = (int)(x / TILESIZE);
// 	if (grid_x < 0 || grid_y < 0 || grid_x >= (map->width / TILESIZE) || grid_y >= (map->height / TILESIZE))
// 		return (1);
// 	if (map->cmap[grid_y][grid_x] == '1')
// 		return (1);
// 	return (0);
// }


// void	draw_map(t_map *map)
// {
// 	int	x;
// 	int	y;
// 	int	px;
// 	int	py;

// 	x = 0;
// 	y = 0;
// 	while (y < (int)map->row)
//     {
// 		x = 0;
//         while (x < (int)ft_strlen(map->cmap[y]) - 1)
//         {
// 			px = x * TILESIZE;
// 			py = y * TILESIZE;
// 			if (map && y < (int)map->row && map->cmap[y] && map->cmap[y][x] == '1')
// 			{
// 				//  printf("drawing wall at (%d, %d)\n", px, py);
//             	// draw_tile_pixels(map->img, px, py, 0xFFFFFFFF);
// 			}
// 			else if (map->cmap[y][x] == '0' || map->cmap[y][x] == map->cmap[map->player.y][map->player.x])
//             	// draw_tile_pixels(map->img, px, py, 0xFFB347);
// 			// commenteta hitax manhtajux n3adelula xi color u
// 			//zidt player mot3u ytlewn nhal 0
// 			// else
// 			// 	// printf("%d\n", find_wall(map,  px,  py));
//    			// 	draw_tile_pixels(map->img, px, py, 0xFF00FF);
// 			x++;
//         }
// 		y++;
//     }
// 	mlx_image_to_window(map->mlx, map->img, 0, 0);
// }



///////////////BONUS///////////////////
// void	load_sprite_frames(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	char *paths[4] = 
// 	{
// 		"textures/tile0-removebg-preview.png",
// 		"textures/tile1-removebg-preview.png",
// 		"textures/tile2-removebg-preview.png",
// 		"textures/tile3-removebg-preview.png"
// 	};

// 	map->player_sprite.frames = malloc(sizeof(t_texture *) * 4);
// 	if (!map->player_sprite.frames)
// 	{
// 		printf("allocation error\n");
// 		exit(1);
// 	}
// 	while (i < 4)
// 	{
// 		map->player_sprite.frames[i] = load_texture(paths[i]);
// 		i++;
// 	}
// 	map->player_sprite.current_frame = 0;
// 	map->player_sprite.frame_timer = 0;
// 	map->player_sprite.frame_speed = 20; // adjustspeeeed
// 	map->player_sprite.last_frame_time = 0;
// 	map->player_sprite.x = (map->width / 2) - (map->player_texture->width / 2);
// 	map->player_sprite.y = map->height / 1.5;
// 	// map->player_sprite.img = mlx_texture_to_image(map->mlx, map->player_sprite.frames[0]->img);
// 	// mlx_image_to_window(map->mlx, map->player_sprite.img, map->player_sprite.x, map->player_sprite.y);
// }
// #include <sys/time.h>  // For getting time
// long get_current_time_ms()
// {
//     struct timeval tv;
//     gettimeofday(&tv, NULL);
//     return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
// }


// // void	animate_sprite(void *param)
// // {
// // 	t_map	*map;

// // 	map = (t_map *)param;
// // 	map->player_sprite.frame_timer++;
// // 	if (map->player_sprite.frame_timer >= map->player_sprite.frame_speed)
// // 	{
// // 		map->player_sprite.frame_timer = 0;
// // 		map->player_sprite.current_frame = (map->player_sprite.current_frame + 1) % 4;




		
// // 		// if (map->player_sprite.img)
// // 		// 	mlx_delete_image(map->mlx, map->player_sprite.img);
// // 		// map->player_sprite.img = mlx_texture_to_image(map->mlx,map->player_sprite.frames[map->player_sprite.current_frame]->img);
// // 		// if (map->player_sprite.img)
// // 		// 	mlx_image_to_window(map->mlx, map->player_sprite.img, map->player_sprite.x, map->player_sprite.y);
// // 	}
// // }






// void animate_sprite(void *param)
// {
//     t_map		*map;
//     static long	last_frame_time = 0;
//     long		current_time;

//     map = (t_map *)param;
//     current_time = get_current_time_ms();
//     if (current_time - last_frame_time >= map->player_sprite.frame_speed)
//     {
//         last_frame_time = current_time;
//         map->player_sprite.current_frame = (map->player_sprite.current_frame + 1) % 4;

//         
//         // map->player_sprite.img = mlx_texture_to_image(map->mlx, map->player_sprite.frames[map->player_sprite.current_frame]->img);

//         // // Draw the sprite on the window
//         // if (map->player_sprite.img)
//         // {
//         //     mlx_image_to_window(map->mlx, map->player_sprite.img, map->player_sprite.x, map->player_sprite.y);
//         // }
//     }
// }

