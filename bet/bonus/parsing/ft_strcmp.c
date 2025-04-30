/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:35:10 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/30 00:32:45 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

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
