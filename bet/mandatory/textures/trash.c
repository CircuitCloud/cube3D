
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