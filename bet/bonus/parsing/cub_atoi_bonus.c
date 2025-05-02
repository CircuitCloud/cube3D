/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:56:30 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/30 00:32:41 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	cub_atoi(char *original, int *err)
{
	int		i;
	int		n;
	int		len;
	int		cpy;
	char	*new;

	n = 0;
	i = 0;
	*err = 0;
	len = 0;
	new = ft_strtrim(original, " ");
	while (new && new[i])
	{
		if (!ft_isdigit(new[i]))
			return (free(new), *err = 1, n);
		cpy = n;
		n = (n * 10) + (new[i] - '0');
		if (cpy > n)
			return (free(new), *err = 1, n);
		len++;
		i++;
	}
	if (len == 0)
		return (free(new), *err = 1, n);
	return (free(new), n);
}
