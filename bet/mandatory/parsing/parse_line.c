/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:54:23 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/23 15:17:22 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_character(char c, int len, int i)
{
	if ((i == 0 || i == len - 1) && (c != '1' && c != ' ' && c != '\t'))
		return (1);
	else if (c != '1' && c != ' ' && c != '\t' && c != '0' && c != 'N'
		&& c != 'S' && c != 'W' && c != 'E')
		return (1);
	return (0);
}

int	parse_line(char *line, int row, int rw, int len)
{
	int		i;

	i = 0;
	if (rw == 0 || rw == row -1)
	{
		while (i < len && line[i])
		{
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '1')
				return (1);
			i++;
		}
	}
	else
	{
		while (i < len && line[i])
		{
			if (check_character(line[i], len, i))
				return (1);
			i++;
		}
	}
	return (0);
}
