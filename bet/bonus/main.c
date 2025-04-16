/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:16:47 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/15 23:06:09 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int find_wall(t_map *map, double x, double y)
{
	int grid_x;
	int grid_y;

	grid_y = (int)(y / TILESIZE);
	grid_x = (int)(x / TILESIZE);
	if (grid_x < 0 || grid_y < 0 || grid_x >= (map->width / TILESIZE) || grid_y >= (map->height / TILESIZE))
		return (1);
	if (map->cmap[grid_y][grid_x] == '1')
		return (1);
	return (0);
}
void ll(void)
{
	system("leaks cub3D");
}

void mouse_rotate(double xpos, double ypos, void *param)
{
	t_map *map = (t_map *)param;
	static double last_x;
	double delta_x;
	double sensitivity;
	
	last_x = WIDTH / 2;
	delta_x = xpos - last_x;
	sensitivity = 0.003;
	last_x = xpos;
	map->player.rot_angle += delta_x * sensitivity;
	if (map->player.rot_angle < 0)
		map->player.rot_angle += 2 * M_PI;
	else if (map->player.rot_angle > 2 * M_PI)
		map->player.rot_angle -= 2 * M_PI;
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
	set_rays_angle(map);
	draw_minimap(map);
}



int main(int ac, char **av)
{
	t_map	map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	// int	width;
	// int height;
	int x =0 ;
	int y = 0;

	// atexit(ll);
	if (ac == 2)
	{
		if (ft_strcmp(".cub", ft_strrchr(av[1], '.')))
			return (write(1, "**Invalid Map Name**\n", 21), 1);
		map = parse(av[1]);
	}
	else
	{
		write(1, "**PARAMETERS ERROR**\n", 21);
		return(1);
	}
	// width = ((ft_strlen(map.cmap[0]) - 1) * TILESIZE);
	// height = (map.row * TILESIZE);
	map.width = WIDTH;
	map.height = HEIGHT;
	mlx = mlx_init( WIDTH, HEIGHT, "BONUS_", 1);
	if (!mlx)
        return (printf("mlx\n"), 1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
        return (printf("img\n"), 1);
	map.mlx = mlx;
	map.img = img;
	map.ray = malloc(sizeof(t_ray) * map.width);
	// matnsax lfree dyal rays
	// draw_map(&map);
	mlx_image_to_window(map.mlx, map.img, 0, 0);
	map.player.move_x = map.player.x * TILESIZE + TILESIZE / 2;
	map.player.move_y = map.player.y * TILESIZE + TILESIZE / 2;
	if (map.player.direction == 'N')
		map.player.rot_angle = 3 * M_PI_2;
	else if (map.player.direction == 'S')
		map.player.rot_angle = M_PI_2;
	else if (map.player.direction == 'E')
		map.player.rot_angle = 0;
	else
		map.player.rot_angle = M_PI;
	// draw_player(&map, img);
	load_textures(&map);
	set_rays_angle(&map);
	draw_minimap(&map);
	// mlx_image_to_window(map.mlx, map.img, 0, 0);
	mlx_key_hook(mlx, update_player_p, &map);

// mlx_cursor_hook(mlx, mouse_rotate, &map);
// mlx_set_cursor_mode(mlx, MLX_MOUSE_HIDDEN);
// mlx_set_cursor_mode(mlx, MLX_MOUSE_DISABLED);  // like FPS-style


	mlx_loop(mlx);
	invalid_map_3("finished\n", &map, 1);
	return (0); 
}
