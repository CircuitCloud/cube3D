/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:01:00 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/25 11:07:10 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_map	parse(char *mapname)
{
	t_map	map;
	int		n_players;

	n_players = 0;
	ft_bzero(&map, sizeof(t_map));
	parse_textures(mapname, &map);
	parse_map(mapname, &map);
	p_directions(&map, n_players);
	return (map);
}
