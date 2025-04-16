/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:16:47 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/17 00:40:22 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
void ll(void)
{
	system("leaks cub3D");
}

int main(int ac, char **av)
{
	t_map		map;
	// mlx_t		*mlx;
	// mlx_image_t	*img;
	int			x;
	int			y;

	x =0 ;
	y = 0;
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
	map.width = WIDTH;
	map.height = HEIGHT;
	map.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 1);
	if (!map.mlx)
        return (printf("failed to init mlx\n"), 1);
	map.img = mlx_new_image(map.mlx, WIDTH, HEIGHT);
	if (!map.img)
        return (printf("failed to create new img\n"), 1);
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
	printf("%s   %d  %s\n", map.id->path, map.id->colors[1], map.id->identifier);
	// draw_player(&map, img);
	load_textures(&map);
	set_rays_angle(&map);
	mlx_key_hook(map.mlx, update_player_p, &map);
	mlx_loop(map.mlx);
	invalid_map_3("finished\n", &map, 1);
	ft_cleanup(&map);
	return (0); 
}
