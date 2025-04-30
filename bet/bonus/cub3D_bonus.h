/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:17:04 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/30 00:48:12 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../MLX/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../getnextline/get_next_line.h"
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <assert.h>
# include <sys/time.h> 

# define OUT_OF_RANGE " numbers not whithin range required"
# define COMMAS_NUMBER " commas number or less/more than numbers required"
# define INVALID_TEXTURES " invalid textures"
# define NEWLINE_MAP " newline inside map lines"
# define PARSE_LINE " (parse_line)"
# define POSITION_OF_ZERO " invalid position(direction or 0)"
# define PLAYER_POSITION " invalid palyer's position"
# define PLAYER_NUMBER " More/Less than one player"
# define TILESIZE 64
# define WIDTH 1024
# define HEIGHT 1024
# define RES 5
# define RAYS_NUMBER 1024
# define PLAYER_RADIUS 31.5
# define TEXTURE_SIZE 64
# define NUM_TEXTURES 4 
# define NORTH_TEXTURE 0
# define SOUTH_TEXTURE 1
# define EAST_TEXTURE 2
# define WEST_TEXTURE 3
# define DOOR_TEXTURE 4
# define MP_TILE_SPACE 4
# define MP_SCALE 0.1
# define MP_OFFSET_X 20
# define MP_OFFSET_Y 100
# define ROTATION_SPEED 0.0349
# define ROTATION_SPEED_MOUSE 0.002
# define MOVE_SPEED 4

typedef struct s_identifier
{
	char				*identifier;
	int					*colors;
	char				*path;
	struct s_identifier	*next;
}	t_identifier;

typedef struct s_player
{
	double	move_x;
	double	move_y;
	double	rot_angle;
	char	direction;
	bool	first_time;
	int		x;
	int		y;
	int		move_speed;
	int		turn_direc;
	int		walk_direc;
	int		steeps;
	int		strafe_direc;
	int32_t	mouse_x;
	int32_t	mouse_y;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	int		ray_x;
	int		ray_y;
	int		down;
	int		up;
	int		right;
	int		left;
	int		x_h_wall;
	int		y_h_wall;
	int		x_v_wall;
	int		y_v_wall;
	double	step_y;
	double	step_x;
	double	distance;
	bool	f_point_h;
	bool	f_point_v;
	int		is_door;
	int		is_ver_door;
	int		is_hor_door;
	int		hit_vertical;
	double	wall_x;
	int		texture_x;
	int		texture;
	double	wall_hit_x;
	double	wall_hit_y;
	double	ver_hit_x;
	double	ver_hit_y;
	double	hor_hit_x;
	double	hor_hit_y;
	int		texture_width;
}	t_ray;

typedef struct s_texture
{
	mlx_texture_t	*img;
	uint32_t		*adr;
	int				width;
	int				height;
	int				vertical_hit_x;
	int				vertical_hit_y;
	int				horizontal_hit_x;
	int				horizontal_hit_y;
}	t_texture;

typedef struct s_sprite 
{
	t_texture	**frames;
	mlx_image_t	*img;
	double		last_frame_time;
	int			current_frame;
	int			x;
	int			y;
	int			frame_timer;
	int			frame_speed;
}	t_sprite;

typedef struct s_map
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	size_t			row;
	int				width;
	int				height;
	int				fd;
	int				index;
	char			**cmap;
	char			**splited;
	int				rays_number;
	char			**split_numbers;
	bool			door_hook;
	int				floor_colors[3];
	int				ceil_colors[3];
	int				mouse_locked;
	double			new_x;
	double			new_y;
	double			proj_wall_height;
	double			fov;
	double			fov_angle;
	t_ray			*ray;
	t_identifier	*id;
	t_player		player;
	t_texture		*text_buffer[NUM_TEXTURES];
	t_texture		*player_texture;
	t_texture		*door_texture;
	t_sprite		player_sprite;
}	t_map;

t_map			parse(char *mapname);
t_identifier	*cub_lstnew();
t_identifier	*free_linked_list(t_identifier *id, int flag);
void			bad_alloc(t_map* map);
void			free_maps(t_map *map, int flag);
void			fd_check(char* name, t_map *m, int flag);
void			invalid_map(char *ms, t_map *map, t_identifier *new, char *line);
void			parse_textures(char *filename, t_map* map);
void			parse_map(char *filename, t_map* map);
void			p_directions(t_map* map, int n_players);
void			cub_lstadd_back(t_identifier **lst, t_identifier *new);
void			free_splited(char **splited);
void			parse_textures_util(t_map *map, int i,char* line);
char			*convert_to_space(char *str);
int				parse_line(char *line, int row, int rw, int len);
int				ft_strcmp(char *dest, char *src);
int				cub_atoi(char *str, int *err);
int				wall_existance_h(t_map *map, double x, double y, int index);
int				wall_existance_v(t_map *map, double x, double y, int index);
void			set_rays_angle(t_map *map);
void			ray_look_direction(double *angle, t_ray *ray);
void			render_wall(t_map *map, t_ray ray, int x);
void			alloc_check(t_map *map, t_identifier *new, char *line);
void			invalid_map_2(char *message, t_map *map, char *line, char *pureline);
void			invalid_map_3(char *message, t_map *map, int flag);
double			horizontal_distance(t_map *map, t_ray *ray, int index);
double			vertical_distance(t_map *map, t_ray *ray, int index);
void			draw_filled_circle(mlx_image_t *img, int cx, int cy, int color);
void			draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color);
void			draw_player(t_map *map, mlx_image_t *img);
int				find_wall(t_map *map, double x, double y);
int				get_texture_pixel(t_map *map, t_ray ray, int tex_y);
void			draw_wall_with_texture(t_map *map, t_ray ray, int x, double begin, double end);
void			which_texture(t_map *map, int index);
uint32_t		get_pixel_color(t_texture *texture, int x, int y, t_map *map);
void			load_textures(t_map *map);
void			render_player(t_map *map);
void			ft_cleanup(t_map *map);
void			render_pov(t_map *map);
void			free_textures(t_map *map);
void			texture_coord(t_map *map, int i);
void			update_player_loop(void *param);
void			draw_mini_map(t_map *map);
void			load_sprite_frames(t_map *map);
void			animate_sprite(void *param);
uint32_t		get_c_f_color(t_map *map, int c);
void			ft_hook_mouse(void *param);
void			draw_mini_player(t_map *map);
t_texture		*load_texture(const char *path, t_map *map);
void			steep_y_check(t_ray *ray);
void			steep_x_check(t_ray *ray);
void			handle_key(t_map *map);
void			draw_tile_pixels(mlx_image_t *img, int x, int y, int color);
#endif