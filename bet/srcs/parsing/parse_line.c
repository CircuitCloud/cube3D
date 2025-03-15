/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:54:23 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/02 13:45:26 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// int parse_line(char *line, int row, int rw)
// {
// 	int len;
// 	int i = 0;
// 	len = ft_strlen(line);
// 	if (rw == 0 || rw == row)
// 	{
// 		while (i < len - 1)
// 		{
// 			if (line[i] != ' ' && line[i] != '1')
// 				return (1);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (i < len - 1)
// 		{
// 			if (((i == 0 || i == len - 2) && (line[i] != '1' && line[i] != ' ' )))
// 					return (1);
// 			else
// 			{
// 				if (line[i] != '1' && line[i] != ' ' && line[i]  != '0' && 
// 					line[i] != 'N'&& line[i] != 'S'&& line[i] != 'W'&& line[i] != 'E')
// 					return (1);
// 			}
// 			i++;
// 		}
// 	}
// 	return (0);
// }

int	check_character(char c, int len, int i)
{
	if ((i == 0 || i == len - 2) && (c != '1' && c != ' '))
		return (1);
	else if (c != '1' && c != ' ' && c != '0' && c != 'N'
		&& c != 'S' && c != 'W' && c != 'E')
		return (1);
	return (0);
}

int	parse_line(char *line, int row, int rw)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(line);
	if (rw == 0 || rw == row)
	{
		while (i < len - 1)
		{
			if (line[i] != ' ' && line[i] != '1')
				return (1);
			i++;
		}
	}
	else
	{
		while (i < len - 1)
		{
			if (check_character(line[i], len, i))
				return (1);
			i++;
		}
	}
	return (0);
}
