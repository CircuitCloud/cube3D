/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:16:47 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/24 07:26:41 by ykamboua         ###   ########.fr       */
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

void	animate_sprite(void *param)
{
	t_anim *sprite = (t_anim *)param;

	sprite->frame_timer++;
	if (sprite->frame_timer >= sprite->frame_speed)
	{
		sprite->frame_timer = 0;
		sprite->current = (sprite->current + 1) % 4;

		if (sprite->img)
			mlx_delete_image(sprite->mlx, sprite->img);

		sprite->img = mlx_texture_to_image(sprite->mlx, sprite->frames[sprite->current]);

		if (sprite->img)
			mlx_image_to_window(sprite->mlx, sprite->img, sprite->x, sprite->y);
	}
}

int main(int ac, char **av)
{
	t_map		map;
	int			x;
	int			y;
	t_anim fire;

	x =0 ;
	y = 0;
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
	load_textures(&map);

	// fire.mlx = map.mlx;
	// fire.frames[0] = mlx_load_png("textures/tile0-removebg-preview.png");
	// fire.frames[1] = mlx_load_png("textures/tile1-removebg-preview.png");
	// fire.frames[2] = mlx_load_png("textures/tile2-removebg-preview.png");
	// fire.frames[3] = mlx_load_png("textures/tile3-removebg-preview.png");

	// fire.current = 0;
	// fire.frame_timer = 0;
	// fire.frame_speed = 20;
	// fire.x = (map.width / 2) - (map.player_texture->width / 2);
	// fire.y = map.height / 1.5; 
	// fire.img = mlx_texture_to_image(map.mlx, fire.frames[0]);
	// mlx_image_to_window(map.mlx, fire.img, fire.x, fire.y);
	mlx_image_to_window(map.mlx, map.img, 0, 0);
	set_rays_angle(&map);
	mlx_loop_hook(map.mlx, update_player_loop, &map);
	// draw_minimap(&map);
	// mlx_loop_hook(map.mlx, (void (*)(void *))animate_sprite, &fire);
	// mlx_mouse_hook(map, mouse_rotate);
	mlx_loop(map.mlx);
	invalid_map_3("finished\n", &map, 1);
	ft_cleanup(&map);
	return (0);
}
