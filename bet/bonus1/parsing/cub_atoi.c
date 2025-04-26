/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:56:30 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/24 10:29:22 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
