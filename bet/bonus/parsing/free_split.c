/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:21:54 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/25 10:10:53 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_splited(char **splited)
{
	int	i;

	i = 0;
	if (splited)
	{
		while (splited[i])
		{
			free(splited[i]);
			splited[i] = NULL;
			i++;
		}
		free(splited);
		splited = NULL;
	}
}
