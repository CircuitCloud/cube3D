/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:16:47 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/26 07:24:50 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	mlx_image_to_window(map.mlx, map.img, 0, 0);
	map.ray = malloc(sizeof(t_ray) * map.width);
	// map.player.move_x = map.player.x * TILESIZE;
	// map.player.move_y = map.player.y * TILESIZE;
	map.player.move_x = map.player.x * TILESIZE + TILESIZE / 2;
	map.player.move_y = map.player.y * TILESIZE + TILESIZE / 2;
	printf("%d  %d  \n", map.player.move_x, map.player.move_y);
	if (map.player.direction == 'N')
		map.player.rot_angle = 3 * M_PI_2;
	else if (map.player.direction == 'S')
		map.player.rot_angle = M_PI_2;
	else if (map.player.direction == 'E')
		map.player.rot_angle = 0;
	else
		map.player.rot_angle = M_PI;
	// draw_player(&map, img);
	// draw_mini_map(&map);
	load_textures(&map);
	set_rays_angle(&map);
	mlx_loop_hook(map.mlx, update_player_loop, &map);
	mlx_loop(map.mlx);
	invalid_map_3("finished\n", &map, 1);
	ft_cleanup(&map);
	return (0);
}
