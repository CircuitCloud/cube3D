/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:16:47 by cahaik            #+#    #+#             */
/*   Updated: 2025/05/01 18:13:35 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	by_by(t_map *map)
{
	ft_cleanup(map);
	exit (1);
}

void	main_helper(t_map *map)
{
	map->width = WIDTH;
	map->height = HEIGHT;
	map->fov = (60 * (M_PI / 180));
	map->fov_angle = (map->fov / (map->width - 1));
	map->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!map->mlx)
	{
		invalid_map_3("failed to init mlx\n", map, 1);
		exit(1);
	}
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->img)
		by_by(map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
	map->player.move_x = map->player.x * TILESIZE + TILESIZE / 2;
	map->player.move_y = map->player.y * TILESIZE + TILESIZE / 2;
	if (map->player.direction == 'N')
		map->player.rot_angle = 3 * M_PI_2;
	else if (map->player.direction == 'S')
		map->player.rot_angle = M_PI_2;
	else if (map->player.direction == 'E')
		map->player.rot_angle = 0;
	else
		map->player.rot_angle = M_PI;
}

int	main(int ac, char **av)
{
	t_map		map;

	if (ac == 2)
	{
		if (ft_strcmp(".cub", ft_strrchr(av[1], '.')))
			return (write(1, "Error:\n**Invalid Map Name**\n", 28), 1);
		map = parse(av[1]);
	}
	else
		return (write(1, "Error:\n**PARAMETERS ERROR**\n", 28), 1);
	main_helper(&map);
	map.ray = malloc(sizeof(t_ray) * map.width);
	load_textures(&map);
	set_rays_angle(&map);
	mlx_loop_hook(map.mlx, update_player_loop, &map);
	mlx_loop(map.mlx);
	ft_cleanup(&map);
	return (0);
}
