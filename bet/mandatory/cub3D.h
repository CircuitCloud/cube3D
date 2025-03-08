/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:17:04 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/08 15:17:46 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../MLX/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include "../getnextline/get_next_line.h"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_identifier
{
	char *identifier;
	int *colors;
	char *path;
	struct s_identifier *next;
} t_identifier;

typedef struct s_player
{
	int x;
	int y;
	char direction;
} t_player;

typedef struct s_map
{
	int fd;
	size_t row;
	char **cmap;
	char **splited;
	t_identifier *id;
	t_player player;
} t_map;


void parse(char *mapname);
int parse_line(char *line, int row, int rw);
void bad_alloc(t_map* map);
void free_maps(t_map *map, int flag);
void fd_check(char* name, t_map *m, int flag);
void invalid_map(char *message, t_map *map, char **s_numbers, t_identifier *new);
void parse_textures(char *filename, t_map* map);
void parse_map(char *filename, t_map* map);
void p_directions(t_map* map, int n_players);
void cub_lstadd_back(t_identifier **lst, t_identifier *new);
t_identifier	*cub_lstnew();
void free_splited(char **splited);
int ft_strcmp(char *dest, char *src);
int cub_atoi(char *str, int *err);
void parse_textures_util(t_map *map);
void free_linked_list(t_identifier *id, int flag);
#endif


//max height and width of the window