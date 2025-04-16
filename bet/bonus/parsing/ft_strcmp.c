/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:35:10 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/24 10:31:00 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_strcmp(char *dest, char *src)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if (!dest || !src)
		return (1);
	while (dest[i] || src[i])
	{
		if ((unsigned char)dest[i] != (unsigned char)src[i])
			return ((unsigned char)dest[i] - (unsigned char)src[i]);
		i++;
	}
	return (0);
}
