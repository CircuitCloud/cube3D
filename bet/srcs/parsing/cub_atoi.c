/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:56:30 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/02 13:00:47 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int cub_atoi(char *str, int *err)
{
	int i;
	int len;
	int n;

	n = 0;
	i = 0;
	*err = 0;
	len = ft_strlen(str);
	if (str && len > 3)
		return ( *err = 1, n);
	len = 0;
	while (str && str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]))
			return (*err = 1, n);
		n = (n * 10) + (str[i] - '0');
		len++;
		i++;
	}
	if (len == 0)
		return ( *err = 1, n);
	return (n);
}
