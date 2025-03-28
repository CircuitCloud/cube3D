/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:24:29 by ykamboua          #+#    #+#             */
/*   Updated: 2025/03/28 02:11:28 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"

// void	load_texture(t_map *map, char *path, int index)
// {
// 	t_texture	img;
// 	int	x;
// 	int	y;
    
//     img.img = mlx_load_png(path);
// 	if (!img.img)
//     {
//         printf("opppsssyyyy e4or: Failed to load texture %s\n", path);
//         exit(1);
//     }
//     unsigned int *adr = (unsigned int *)mlx_get_data_addr(img.img, &x, &y, &img.bpp);

//     map->text_buffer[index] = malloc(sizeof(int) * (x * y));
// 	if (!map->text_buffer[index])
//     {
//         printf("Error: Memory allocation failed\n");
//         exit(1);
//     }
//     int i = 0;
//     while (i < (x * y))
//     {
//         map->text_buffer[index][i] = img.adr[i];
//         i++;
//     }
//     mlx_delete_texture(img.img);
// }


uint32_t mix_pixel_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (a << 24 | b << 16 | g << 8 | r);
}


t_texture	*load_texture(char *path)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
	{
		printf("Error: Failed to allocate texture\n");
		exit(1);
	}

	texture->img = mlx_load_png(path);
	if (!texture->img)
	{
		printf("Error: Failed to load texture %s\n", path);
		exit(1);
	}

	texture->width = texture->img->width;
	texture->height = texture->img->height;
	texture->adr = (uint32_t *)texture->img->pixels;

	return (texture);
}

void load_textures(t_map *map)
{
    int i;
    char *paths[4];

    paths[NORTH_TEXTURE] = "../hh.jpeg";
    paths[SOUTH_TEXTURE] = "../hh.jpeg";
    paths[EAST_TEXTURE]  = "../hh.jpeg";
    paths[WEST_TEXTURE]  = "../hh.jpeg";

    i = 0;
    while (i < 4)
    {
        map->text_buffer[i] = load_texture(paths[i]);  // Store the texture in the array
        i++;
    }
}


// void    load_textures(t_map *map)
// {
//     int i;
//     char *paths[4];

//     i = 0;
// 	paths[0] = "../hh.jpeg";
// 	paths[1] = "../hh.jpeg";
// 	paths[2] = "../hh.jpeg";
// 	paths[3] = "../hh.jpeg";
//     while (i < 4)
//     {
//         load_texture(paths[i]);
//         i++;
//     }
// }

uint32_t	get_pixel(t_texture *texture, int x, int y)
{
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0x000000FF);
	return (texture->adr[y * texture->width + x]);
}


// int get_texture_pixel(int **texture_buff, int x, int y, int index)
// {
// 	int	p_index;

//     if(x < 0 || x >= TEXTURE_SIZE || y < 0 || y >= TEXTURE_SIZE)
//     {
//         return 0x000000;
//     }
//     p_index = (y * TEXTURE_SIZE) + x;
// 	return (texture_buff[index][p_index]);
// }

void draw_wall_with_texture(t_map *map, t_ray ray, int x, double begin, double end)
{
    int y;
    int texture_color;
    int texture_y;

    // Loop through the wall slice (from begin to end)
    for (y = begin; y < end; y++)
    {
        // Calculate the texture Y coordinate based on the wall slice height
        texture_y = (y - begin) / (end - begin) * TEXTURE_SIZE;

        // Get the color from the texture at (texture_x, texture_y)
        // texture_color = get_texture_pixel(map->text_buffer, ray.texture_x, texture_y, ray.texture);

        // Draw the pixel on the screen (with texture color)
        mlx_put_pixel(map->img, x, y, texture_color);
    }
}
