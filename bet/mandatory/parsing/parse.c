/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:01:00 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/09 21:45:45 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_map parse(char *mapname)//intead of void -> t_map return value
{
	t_map map;
	int n_players = 0;
	
	ft_bzero(&map, sizeof(t_map));
	parse_textures(mapname ,&map);
	parse_map(mapname, &map);
	p_directions(&map, n_players);
	return (map);
}
