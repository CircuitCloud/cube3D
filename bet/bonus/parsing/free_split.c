/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:21:54 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/30 00:32:43 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

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
